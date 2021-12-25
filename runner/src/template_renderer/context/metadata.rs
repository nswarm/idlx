use crate::util;
use anyhow::{anyhow, Result};
use serde::{Deserialize, Serialize};
use std::path::{Path, PathBuf};

#[derive(Serialize, Deserialize)]
pub struct MetadataContext {
    // Relative path to this directory.
    directory: String,

    // Names of files in this directory, without extensions.
    file_names: Vec<String>,

    // Names of tiles in this directory, with extensions.
    file_names_with_ext: Vec<String>,

    // Names of directories in this directory.
    subdirectories: Vec<String>,

    #[serde(skip)]
    directory_path: PathBuf,
}

impl MetadataContext {
    pub fn with_relative_dir(directory: &Path) -> Result<Self> {
        let context = Self {
            directory: directory
                .to_str()
                .ok_or(anyhow!(
                    "Cannot create MetadataContext, dir path is not valid: {:?}",
                    directory
                ))?
                .to_string(),
            file_names: vec![],
            file_names_with_ext: vec![],
            subdirectories: vec![],
            directory_path: directory.to_path_buf(),
        };
        Ok(context)
    }

    pub fn relative_dir(&self) -> &Path {
        &self.directory_path
    }

    pub fn push_file(&mut self, path: &Path) -> Result<()> {
        if self.is_direct_child(path)? {
            let file_name = util::file_name_or_error(path)?;
            self.file_names_with_ext.push(file_name);
            let file_name_no_ext = util::file_name_or_error(&path.with_extension(""))?;
            self.file_names.push(file_name_no_ext);
        }
        Ok(())
    }

    pub fn push_subdirectory(&mut self, path: &Path) -> Result<()> {
        if self.is_direct_child(path)? {
            let dir_name = util::file_name_or_error(path)?;
            self.subdirectories.push(dir_name);
        }
        Ok(())
    }

    fn is_direct_child(&self, path: &Path) -> Result<bool> {
        Ok(match util::path_parent_or_error(path) {
            Ok(parent) => parent == self.directory_path,
            Err(_) => false,
        })
    }
}

#[cfg(test)]
mod tests {
    mod push_file {
        use crate::template_renderer::context::MetadataContext;
        use anyhow::Result;
        use std::path::PathBuf;

        #[test]
        fn direct_child() -> Result<()> {
            let root = PathBuf::from("root");
            let mut context = MetadataContext::with_relative_dir(&root)?;
            context.push_file(&root.join("file.txt"))?;
            assert_eq!(context.file_names.get(0), Some(&"file".to_string()));
            Ok(())
        }

        #[test]
        fn not_direct_child() -> Result<()> {
            let root = PathBuf::from("root");
            let mut context = MetadataContext::with_relative_dir(&root)?;
            context.push_file(&root.join("sub/file.txt"))?;
            assert!(context.file_names.is_empty());
            Ok(())
        }

        #[test]
        fn also_adds_no_ext_file_name() -> Result<()> {
            let root = PathBuf::from("root");
            let mut context = MetadataContext::with_relative_dir(&root)?;
            context.push_file(&root.join("file.txt"))?;
            assert_eq!(context.file_names.get(0), Some(&"file".to_string()));
            assert_eq!(
                context.file_names_with_ext.get(0),
                Some(&"file.txt".to_string())
            );
            Ok(())
        }
    }

    mod push_subdirectory {
        use crate::template_renderer::context::MetadataContext;
        use anyhow::Result;
        use std::path::PathBuf;

        #[test]
        fn direct_child() -> Result<()> {
            let root = PathBuf::from("root");
            let mut context = MetadataContext::with_relative_dir(&root)?;
            context.push_subdirectory(&root.join("sub"))?;
            assert_eq!(context.subdirectories.get(0), Some(&"sub".to_string()));
            Ok(())
        }

        #[test]
        fn not_direct_child() -> Result<()> {
            let root = PathBuf::from("root");
            let mut context = MetadataContext::with_relative_dir(&root)?;
            context.push_subdirectory(&root.join("sub/other"))?;
            assert!(context.subdirectories.is_empty());
            Ok(())
        }
    }

    mod direct_child {
        use crate::template_renderer::context::MetadataContext;
        use anyhow::Result;
        use std::path::PathBuf;

        #[test]
        fn valid() -> Result<()> {
            let root = PathBuf::from("root");
            let context = MetadataContext::with_relative_dir(&root)?;
            assert!(context.is_direct_child(&root.join("anything"))?);
            Ok(())
        }

        #[test]
        fn invalid_too_deep() -> Result<()> {
            let root = PathBuf::from("root");
            let context = MetadataContext::with_relative_dir(&root)?;
            assert!(!context.is_direct_child(&root.join("sub/other"))?);
            Ok(())
        }

        #[test]
        fn invalid_too_high() -> Result<()> {
            let root = PathBuf::from("root/sub");
            let context = MetadataContext::with_relative_dir(&root)?;
            assert!(!context.is_direct_child(&PathBuf::from("root"))?);
            Ok(())
        }

        #[test]
        fn invalid_different_root() -> Result<()> {
            let root = PathBuf::from("root/sub");
            let context = MetadataContext::with_relative_dir(&root)?;
            assert!(!context.is_direct_child(&PathBuf::from("anything"))?);
            Ok(())
        }
    }
}

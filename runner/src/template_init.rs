use crate::template_renderer::{RendererConfig, FILE_TEMPLATE_NAME, TEMPLATE_EXT};
use crate::{util, DisplayNormalized, CONFIG_FILE_NAME};
use anyhow::{anyhow, Result};
use std::fs;
use std::io::Write;
use std::path::Path;

pub fn initialize_template_dir(dir: &Path) -> Result<()> {
    util::create_dir_or_error(dir)?;
    if fs::read_dir(dir)?.count() > 0 {
        return Err(anyhow!(
            "Target directory '{}' is not empty.",
            dir.display_normalized()
        ));
    }
    write_config(dir)?;
    write_file_template(dir)?;
    Ok(())
}

fn write_config(path: &Path) -> Result<()> {
    let config_file = util::create_file_or_error(&path.join(CONFIG_FILE_NAME))?;
    let config = RendererConfig::default();
    serde_json::to_writer_pretty(config_file, &config)?;
    Ok(())
}

fn write_file_template(path: &Path) -> Result<()> {
    let mut config_file =
        util::create_file_or_error(&path.join(FILE_TEMPLATE_NAME).with_extension(TEMPLATE_EXT))?;
    let contents = r#"{{!
This is the root template file for most idlx template output.

See the example templates for usage examples: https://github.com/nswarm/idlx/tree/main/examples/input

Context data objects for information on what data is available in this template: https://github.com/nswarm/idlx/tree/main/runner/src/template_renderer/context

For more information on Handlebars: https://handlebarsjs.com/guide/
}}
"#;
    config_file.write_all(contents.as_bytes())?;
    Ok(())
}

#[cfg(test)]
mod tests {
    use crate::template_renderer::{RendererConfig, FILE_TEMPLATE_NAME, TEMPLATE_EXT};
    use crate::{initialize_template_dir, CONFIG_FILE_NAME};
    use anyhow::Result;
    use std::fs;
    use std::io::Read;
    use tempfile::tempdir;

    #[test]
    fn writes_config_file() -> Result<()> {
        let tempdir = tempdir()?;
        initialize_template_dir(tempdir.path())?;
        let config_file = fs::File::open(tempdir.path().join(CONFIG_FILE_NAME))?;
        let result: Result<RendererConfig, serde_json::Error> =
            serde_json::from_reader(config_file);
        assert!(result.is_ok());
        Ok(())
    }

    #[test]
    fn writes_file_template_file() -> Result<()> {
        let tempdir = tempdir()?;
        initialize_template_dir(tempdir.path())?;
        let mut template_file = fs::File::open(
            tempdir
                .path()
                .join(FILE_TEMPLATE_NAME)
                .with_extension(TEMPLATE_EXT),
        )?;
        let mut result = String::new();
        template_file.read_to_string(&mut result)?;
        assert!(!result.is_empty());
        Ok(())
    }
}
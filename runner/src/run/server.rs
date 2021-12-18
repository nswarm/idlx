use crate::run::util;
use crate::{Config, Lang};
use anyhow::Result;

const SUPPORTED_LANGUAGES: [Lang; 0] = [];

pub fn supported_languages() -> &'static [Lang] {
    &SUPPORTED_LANGUAGES
}

pub fn run(config: &Config, _input_files: &Vec<String>) -> Result<()> {
    util::check_languages_supported("server", &config.server, &supported_languages())?;
    util::create_output_dirs(&config.server)?;
    Ok(())
}
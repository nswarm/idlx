#![forbid(unsafe_code)]

use anyhow::Result;

fn main() -> Result<()> {
    generator::generate()
}

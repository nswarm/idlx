use crate::template_renderer::context::RenderedField;
use crate::template_renderer::renderer_config::RendererConfig;
use crate::util;
use anyhow::Result;
use prost_types::DescriptorProto;
use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize)]
pub struct MessageContext<'a> {
    name: &'a str,

    /// Must be rendered and supplied externally.
    pub fields: Vec<RenderedField>,
}

impl<'a> MessageContext<'a> {
    pub fn new(message: &'a DescriptorProto, _config: &RendererConfig) -> Result<Self> {
        let context = Self {
            name: name(message)?,
            fields: Vec::new(),
        };
        Ok(context)
    }
}

fn name(message: &DescriptorProto) -> Result<&str> {
    util::str_or_error(&message.name, || "Message has no 'name'".to_string())
}

#[cfg(test)]
mod tests {
    use crate::template_renderer::context::message::MessageContext;
    use crate::template_renderer::renderer_config::RendererConfig;
    use anyhow::Result;
    use prost_types::DescriptorProto;

    #[test]
    fn name() -> Result<()> {
        let config = RendererConfig::default();
        let msg_name = "msg_name".to_string();
        let mut message = default_message();
        message.name = Some(msg_name.clone());
        let context = MessageContext::new(&message, &config)?;
        assert_eq!(context.name, msg_name);
        Ok(())
    }

    #[test]
    fn missing_name_errors() {
        let config = RendererConfig::default();
        let message = default_message();
        let result = MessageContext::new(&message, &config);
        assert!(result.is_err());
    }

    fn default_message() -> DescriptorProto {
        DescriptorProto {
            name: None,
            field: vec![],
            extension: vec![],
            nested_type: vec![],
            enum_type: vec![],
            extension_range: vec![],
            oneof_decl: vec![],
            options: None,
            reserved_range: vec![],
            reserved_name: vec![],
        }
    }
}

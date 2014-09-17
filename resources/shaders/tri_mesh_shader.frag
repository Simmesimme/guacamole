@include "shaders/common/header.glsl"

@include "shaders/common/gua_fragment_shader_input.glsl"

@include "shaders/common/gua_camera_uniforms.glsl"
@include "shaders/common/gua_object_uniforms.glsl"

@material_uniforms

layout(location=0) out vec3 gua_out_color;
layout(location=1) out vec3 gua_out_pbr;
layout(location=2) out vec3 gua_out_normal;

@include "shaders/common/gua_global_variable_declaration.glsl"

@material_method_declarations

void main() {

@include "shaders/common/gua_global_variable_assignment.glsl"

@material_method_calls

  gua_out_color     = gua_color;
  gua_out_pbr       = vec3(gua_emissivity, gua_shinyness/100, gua_specularity);
  gua_out_normal    = gua_normal*0.5+0.5;
}
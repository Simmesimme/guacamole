@include "shaders/common/header.glsl"

in vec3 gua_normal;

layout(location=0) out vec3 gua_out_color;
layout(location=1) out vec3 gua_out_pbr;
layout(location=2) out vec3 gua_out_normal;

void main() {
  gua_out_color     = vec3(1, 1, 0);
  gua_out_pbr       = vec3(0.5, 0.5, 0.5);
  gua_out_normal    = gua_normal;
}

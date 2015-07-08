@include "common/header.glsl"

@include "shaders/common/gua_camera_uniforms.glsl"
@include "common/heat.glsl"

flat in uint cellsize;

// output
layout(location=0) out vec3 gua_out_color;

void main() {
  float intensity = log2(cellsize) / 6.0;
  // gua_out_color = vec3(0.5, 0.2, 0.2) * (1-intensity) + vec3(0.2) * intensity;
  // gua_out_color = 0.5*(vec3(1, 0.1, 0.1) * (1-intensity) + vec3(0.1, 1, 0.1) * intensity);
  gua_out_color = heat(intensity)*0.2;
}

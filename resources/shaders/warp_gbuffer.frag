/******************************************************************************
 * guacamole - delicious VR                                                   *
 *                                                                            *
 * Copyright: (c) 2011-2013 Bauhaus-Universität Weimar                        *
 * Contact:   felix.lauer@uni-weimar.de / simon.schneegans@uni-weimar.de      *
 *                                                                            *
 * This program is free software: you can redistribute it and/or modify it    *
 * under the terms of the GNU General Public License as published by the Free *
 * Software Foundation, either version 3 of the License, or (at your option)  *
 * any later version.                                                         *
 *                                                                            *
 * This program is distributed in the hope that it will be useful, but        *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License   *
 * for more details.                                                          *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with this program. If not, see <http://www.gnu.org/licenses/>.             *
 *                                                                            *
 ******************************************************************************/

@include "common/header.glsl"
@include "common/gua_camera_uniforms.glsl"
@include "common/gua_gbuffer_input.glsl"
@include "common/heat.glsl"
@include "gbuffer_warp_modes.glsl"

uniform bool warp_left_eye;

// -----------------------------------------------------------------------------
#if WARP_MODE == WARP_MODE_GRID_DEPTH_THRESHOLD || WARP_MODE == WARP_MODE_GRID_SURFACE_ESTIMATION || WARP_MODE == WARP_MODE_GRID_ADVANCED_SURFACE_ESTIMATION || WARP_MODE == WARP_MODE_GRID_NON_UNIFORM_SURFACE_ESTIMATION
// -----------------------------------------------------------------------------

flat in uint cellsize;
in vec2 texcoords;

// output
layout(location=0) out vec3 gua_out_color;

void main() {
  #if @debug_cell_colors@ == 1
    float intensity = log2(cellsize) / 5.0;
    gua_out_color =  heat(intensity)*0.4+0.2;
  #else
    gua_out_color = gua_get_color(texcoords);
  #endif
}


// -----------------------------------------------------------------------------
#else // all other modes -------------------------------------------------------
// -----------------------------------------------------------------------------

in vec3 color;
in vec3 normal;

// output
layout(location=0) out vec3 gua_out_color;

void main() {
  gua_out_color = color;
}

#endif

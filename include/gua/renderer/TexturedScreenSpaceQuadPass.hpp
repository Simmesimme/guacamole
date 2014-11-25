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

#ifndef GUA_TEXTURED_SCREEN_SPACE_QUAD_PASS_HPP
#define GUA_TEXTURED_SCREEN_SPACE_QUAD_PASS_HPP

#include <gua/renderer/PipelinePass.hpp>
#include <gua/renderer/ShaderProgram.hpp>

// external headers
#include <scm/gl_core/buffer_objects.h>

#include <typeindex>
#include <memory>
#include <unordered_map>

namespace gua {

class GUA_DLL TexturedScreenSpaceQuadPassDescription : public PipelinePassDescription {
 public:
  TexturedScreenSpaceQuadPassDescription();
  PipelinePassDescription* make_copy() const override;
  friend class Pipeline;
 protected:
  PipelinePass make_pass(RenderContext const&) override;
};

}

#endif  // GUA_TEXTURED_SCREEN_SPACE_QUAD_PASS_HPP

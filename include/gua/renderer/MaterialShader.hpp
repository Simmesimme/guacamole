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

#ifndef GUA_MATERIAL_SHADER_HPP
#define GUA_MATERIAL_SHADER_HPP

#include <gua/renderer/MaterialShaderDescription.hpp>
#include <gua/renderer/Material.hpp>
#include <gua/renderer/GeometryResource.hpp>
#include <gua/renderer/ShaderProgram.hpp>
#include <gua/utils/string_utils.hpp>

#include <typeindex>
#include <sstream>
#include <iostream>

namespace gua {

class MaterialShader {
 public:

  MaterialShader(std::string const& name, MaterialShaderDescription const& desc);

  MaterialShaderDescription const& get_description() const;

  std::string const&      get_name()             const;
  Material const  get_new_instance()     const;
  Material const& get_default_instance() const;
  Material&       get_default_instance();

  ShaderProgram* get_shader(GeometryResource const& for_type,
                            std::string const& geometry_v_shader,
                            std::string const& geometry_f_shader);

  void apply_uniforms(RenderContext const& ctx,
                      ShaderProgram* shader,
                      Material const& overwrite) const;


  void print_shaders() const;

 private:

  std::string compile_description(std::list<MaterialShaderMethod> const& passes,
                                  std::string const& shader_source) const;

  MaterialShaderDescription desc_;

  std::unordered_map<std::type_index, ShaderProgram*> shaders_;

  Material default_instance_;
};

}

#endif  // GUA_MATERIAL_SHADER_HPP

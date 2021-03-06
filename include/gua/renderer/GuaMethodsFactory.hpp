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

#ifndef GUA_GUA_METHODS_FACTORY_HPP
#define GUA_GUA_METHODS_FACTORY_HPP

// guacamole headers
#include <gua/renderer/ShadingModel.hpp>

// external headers
#include <string>
#include <vector>
#include <unordered_map>

namespace gua {

class GuaMethodsFactory {
 public:
  std::string const get_sampler_casts() const;
  std::string const get_material_id() const;
  std::string const get_depth() const;
  std::string const get_position() const;

 private:
  void resolve_includes(std::string& shader_source) const;
};

}

#endif  // GUA_GUA_METHODS_FACTORY_HPP

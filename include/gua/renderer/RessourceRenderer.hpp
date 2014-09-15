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

#ifndef GUA_RESSOURCE_RENDERER_HPP
#define GUA_RESSOURCE_RENDERER_HPP

// guacamole_headers
#include <gua/renderer/GeometryResource.hpp>
#include <gua/renderer/Material.hpp>

namespace gua {

class Pipeline;

class GUA_DLL RessourceRenderer {
 public:

   virtual void draw(std::shared_ptr<GeometryResource> const& object,
                     std::shared_ptr<Material> const& material,
                     MaterialInstance const& material_overwrite,
                     math::mat4 const& transformation,
                     Pipeline* pipe) const = 0;

};

}

#endif  // GUA_RESSOURCE_RENDERER_HPP

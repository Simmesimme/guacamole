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

// class header
#include <gua/physics/BoxShape.hpp>

// external headers
#include <BulletCollision/CollisionShapes/btCompoundShape.h>
#include <BulletCollision/CollisionShapes/btBoxShape.h>

namespace gua {
namespace physics {

////////////////////////////////////////////////////////////////////////////////

BoxShape::BoxShape(const math::vec3& half_extents)
    : CollisionShape(true, true, true),
      half_extents_(half_extents) {
  create_box(math::vec3_to_btVector3(half_extents));
}

////////////////////////////////////////////////////////////////////////////////

BoxShape::BoxShape(float x, float y, float z)
    : CollisionShape(true, true, true),
      half_extents_(x, y, z) {
  create_box(btVector3(x, y, z));
}

////////////////////////////////////////////////////////////////////////////////

BoxShape::BoxShape(float half_extent)
    : CollisionShape(true, true, true),
      half_extents_(half_extent, half_extent, half_extent) {
  create_box(btVector3(half_extent, half_extent, half_extent));
}

////////////////////////////////////////////////////////////////////////////////

BoxShape::~BoxShape() { delete shape_; }

////////////////////////////////////////////////////////////////////////////////

math::vec3 const& BoxShape::get_half_extents() const {
  return half_extents_;
}

////////////////////////////////////////////////////////////////////////////////

void BoxShape::set_half_extents(math::vec3 const& half_extents) {
  half_extents_ = half_extents;
  if (shape_)
    delete shape_;

  create_box(math::vec3_to_btVector3(half_extents_));
}

////////////////////////////////////////////////////////////////////////////////

void BoxShape::create_box(const btVector3& half_extents) {
  shape_ = new btBoxShape(half_extents);
}

////////////////////////////////////////////////////////////////////////////////

/* virtual */ void BoxShape::construct_dynamic(
    btCompoundShape* bullet_shape,
    const btTransform& base_transform) {
  bullet_shape->addChildShape(base_transform, shape_);
}

////////////////////////////////////////////////////////////////////////////////

/* virtual */ btCollisionShape* BoxShape::construct_static() { return shape_; }

////////////////////////////////////////////////////////////////////////////////

}
}

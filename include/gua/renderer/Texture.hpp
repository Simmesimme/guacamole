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

#ifndef GUA_TEXTURE_HPP
#define GUA_TEXTURE_HPP

// guacamole headers
#include <gua/platform.hpp>
#include <gua/renderer/RenderContext.hpp>
#include <gua/math/math.hpp>
#include <gua/utils/logger.hpp>

// external headers
#include <string>
#include <vector>

#if GUA_COMPILER == GUA_COMPILER_MSVC&& GUA_COMPILER_VER <= 1600
#include <boost/thread.hpp>
#else
#include <mutex>
#include <thread>
#endif

namespace gua {

/**
 * A class representing a texture.
 *
 * This class allows to load texture data from a file and bind the
 * texture to an OpenGL context.
 */
class Texture {
 public:

  /**
   * Constructor.
   *
   * This constructs a new texture with the given parameters.
   *
   * \param width            The width of the resulting texture.
   * \param height           The height of the resulting texture.
   * \param color_format     The color format of the resulting
   *                         texture.
   * \param state_descripton The sampler state for the loaded texture.
   */
  Texture(unsigned width,
          unsigned height,
          scm::gl::data_format color_format,
          std::vector<void*> const& data,
          unsigned mipmap_layers = 1,
          scm::gl::sampler_state_desc const& state_descripton =
              scm::gl::sampler_state_desc(scm::gl::FILTER_MIN_MAG_LINEAR,
                                          scm::gl::WRAP_CLAMP_TO_EDGE,
                                          scm::gl::WRAP_CLAMP_TO_EDGE));

  /**
   * Constructor.
   *
   * This constructs a new texture with the given parameters.
   *
   * \param width            The width of the resulting texture.
   * \param height           The height of the resulting texture.
   * \param color_format     The color format of the resulting
   *                         texture.
   * \param state_descripton The sampler state for the loaded texture.
   */
  Texture(unsigned width,
          unsigned height,
          scm::gl::data_format color_format = scm::gl::FORMAT_RGB_32F,
          unsigned mipmap_layers = 1,
          scm::gl::sampler_state_desc const& state_descripton =
              scm::gl::sampler_state_desc(scm::gl::FILTER_MIN_MAG_MIP_LINEAR,
                                          scm::gl::WRAP_CLAMP_TO_EDGE,
                                          scm::gl::WRAP_CLAMP_TO_EDGE));

  /**
   * Constructor.
   *
   * This constructs a new texture from a given file.
   *
   * \param file             The file which contains the texture data.
   * \param state_descripton The sampler state for the loaded texture.
   */
  Texture(std::string const& file,
          bool generate_mipmaps = false,
          scm::gl::sampler_state_desc const& state_descripton =
              scm::gl::sampler_state_desc(scm::gl::FILTER_ANISOTROPIC,
                                          scm::gl::WRAP_REPEAT,
                                          scm::gl::WRAP_REPEAT));

  virtual ~Texture();

  void generate_mipmaps(RenderContext const& context);

  /**
   *
   */
  virtual math::vec2ui const get_handle(RenderContext const& context) const;

  /**
   * Get the schism texture.
   *
   * \param context          The context for which the texture should be
   *                         returned.
   * \return                 A pointer to the schism texture.
   */
  virtual scm::gl::texture_2d_ptr const& get_buffer(
      RenderContext const& context) const;

  void make_resident(RenderContext const& context) const;
  void make_non_resident(RenderContext const& context) const;
  void make_non_resident() const;

  ///@{
  /**
   * Gets the size.
   *
   * Returns the size of the Texture.
   */
  unsigned width() const;
  unsigned height() const;
  ///@}

 protected:
  mutable unsigned width_, height_, mipmap_layers_;
  scm::gl::data_format color_format_;
  scm::gl::sampler_state_desc state_descripton_;
  mutable std::vector<scm::gl::texture_2d_ptr> textures_;
  mutable std::vector<scm::gl::sampler_state_ptr> sampler_states_;
  mutable std::vector<scm::gl::render_context_ptr> render_contexts_;

#if GUA_COMPILER == GUA_COMPILER_MSVC&& GUA_COMPILER_VER <= 1600
  mutable boost::mutex upload_mutex_;
#else
  mutable std::mutex upload_mutex_;
#endif
  virtual void upload_to(RenderContext const& context) const;

  std::vector<void*> data_;
  std::string file_name_;

 private:

};

}
#endif  // GUA_TEXTURE_HPP

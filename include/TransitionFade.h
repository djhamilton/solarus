/*
 * Copyright (C) 2006-2014 Christopho, Solarus - http://www.solarus-games.org
 * 
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_TRANSITION_FADE_H
#define SOLARUS_TRANSITION_FADE_H

#include "Common.h"
#include "Transition.h"
#include "lowlevel/Color.h"

namespace solarus {

/**
 * \brief Fade in or fade out transition effect.
 *
 * TODO separate both behaviors in two classes (color and opacity).
 */
class TransitionFade: public Transition {

  public:

    TransitionFade(Direction direction, Surface& dst_surface);
    ~TransitionFade();

    void set_delay(uint32_t delay);

    void start();
    bool is_colored() const;
    const Color& get_color() const;
    void set_color(const Color& color);
    void clear_color();
    bool is_started() const;
    bool is_finished() const;
    void notify_suspended(bool suspended);
    void update();
    void draw(Surface& surface);

  private:

    bool finished;
    int alpha_start;
    int alpha_limit;
    int alpha_increment;
    int alpha; // current alpha value of the surface

    uint32_t next_frame_date;
    uint32_t delay;

    Surface* dst_surface;
    bool colored;
    Color transition_color;

};

}

#endif


/*! \file engine.cpp
*/
#include "engine.hpp"
#include "timer.hpp"

namespace blit {

  void (*init)()                                = nullptr;
  void (*update)(uint32_t time)                 = nullptr;
  void (*render)(uint32_t time)                 = nullptr;
  void (*set_screen_mode)(screen_mode new_mode) = nullptr;
  uint32_t (*now)()   = nullptr;
  void (*debug)(std::string message) = nullptr;

  surface null_surface(nullptr, pixel_format::RGB565, size(0, 0));
  surface &fb = null_surface;

  uint32_t update_rate_ms = 10;
  uint32_t pending_update_time = 0;

  uint32_t render_rate_ms = 25;
  uint32_t pending_render_time = 0;

  uint32_t last_tick_time = 0;

  void tick(uint32_t time) {

    if (last_tick_time == 0) {
      last_tick_time = time;
    }

    // update timers
    update_timers(time);

    // catch up on updates if any pending
    pending_update_time += (time - last_tick_time);
    while (pending_update_time >= update_rate_ms) {
      update(time - pending_update_time); // create fake timestamp that would have been accurate for the update event
      pending_update_time -= update_rate_ms;
    }

    // render if new frame due
    pending_render_time += (time - last_tick_time);
    if (pending_render_time >= render_rate_ms) {
      render(time);
      pending_render_time -= render_rate_ms;
    }

    last_tick_time = time;
  }

}

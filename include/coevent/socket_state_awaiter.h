#pragma once

#include <coroutine>

#include "coevent/event.h"
#include "coevent/socket.h"

namespace coevent {
class [[nodiscard]] socket_state_awaiter {
 public:
   socket_state_awaiter(coevent::socket& socket, short what);

   short await_resume() const noexcept;

   bool await_ready() const noexcept { return false; }

   void await_suspend(std::coroutine_handle<> coroutine);
 private:
  coevent::socket& socket_;
  coevent::event event_;
  std::coroutine_handle<> coroutine_{nullptr};
  short what_;
  short state_what_;

  static void on_state_change(int file_descriptor, short what, void* context) noexcept;
};
} // namespace coevent

#pragma once

#include <atomic>
#include <coroutine>

namespace coevent {
class detached_task_handle {
 public:
   explicit detached_task_handle(std::coroutine_handle<> coroutine) noexcept;

   bool finish() noexcept;
 private:
   std::atomic<bool> finished_{false};
   std::coroutine_handle<void> coroutine_;
};
} // namespace coevent

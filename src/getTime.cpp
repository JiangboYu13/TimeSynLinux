#include "getTime.h"
template <typename PrecisionDuration>
int64_t AsInt64(const Duration &duration) {
  return std::chrono::duration_cast<PrecisionDuration>(duration).count();
}
double ToSecond(const Timestamp &timestamp) {
  return static_cast<double>(AsInt64<nanos>(timestamp.time_since_epoch())) *
         1e-9;
}
Timestamp SystemNow() {
    return std::chrono::time_point_cast<Duration>(
        std::chrono::system_clock::now());
}
double NowInSeconds() { return ToSecond(SystemNow()); }

#pragma once 
#include <chrono>
#include <iostream>
using Duration = std::chrono::nanoseconds;
using Timestamp = std::chrono::time_point<std::chrono::system_clock, Duration>;
using nanos = std::chrono::nanoseconds;
using micros = std::chrono::microseconds;
using millis = std::chrono::milliseconds;
using seconds = std::chrono::seconds;
using minutes = std::chrono::minutes;
using hours = std::chrono::hours;
template <typename PrecisionDuration>
int64_t AsInt64(const Duration &duration);

double ToSecond(const Timestamp &timestamp);

Timestamp SystemNow();

double NowInSeconds();

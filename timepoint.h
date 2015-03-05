#ifndef TIMEPOINT_H
#define TIMEPOINT_H

#include <iostream>
#include <chrono>

class TimePoint
{
  std::chrono::milliseconds point;
public:
  TimePoint();

  TimePoint(std::wistream& input);

  void parseFrom(std::wistream& input);
  void printTo(std::wostream& output) const;

  void shift(const std::chrono::milliseconds& shift);
};

inline std::wostream& operator<<(std::wostream& output, const TimePoint& time_point)
{
  time_point.printTo(output);
  return output;
}

inline std::wistream& operator>>(std::wistream& input, TimePoint& time_point)
{
  time_point.parseFrom(input);
  return input;
}


#endif // TIMEPOINT_H

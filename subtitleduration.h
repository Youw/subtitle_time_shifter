#ifndef SUBTITLEDURATION_H
#define SUBTITLEDURATION_H

#include "timepoint.h"

#include <iostream>
#include <chrono>

class SubtitleDuration
{
  TimePoint from, to;
public:
  SubtitleDuration();
  SubtitleDuration(std::wistream& input);

  void parseFrom(std::wistream& input);
  void printTo(std::wostream& output) const;

  void shift(const std::chrono::milliseconds& shift);
};

inline std::wostream& operator<<(std::wostream& output, const SubtitleDuration& time_duration)
{
  time_duration.printTo(output);
  return output;
}

inline std::wistream& operator>>(std::wistream& input, SubtitleDuration& time_duration)
{
  time_duration.parseFrom(input);
  return input;
}

#endif // SUBTITLEDURATION_H

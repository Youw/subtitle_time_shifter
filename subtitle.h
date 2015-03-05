#ifndef SUBTITLE_H
#define SUBTITLE_H

#include "subtitleduration.h"

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

class Subtitle
{
  int id;
  SubtitleDuration subtitle_duration;
  std::vector<std::wstring> lines;
public:
  Subtitle();

  Subtitle(std::wistream& input);

  void parseFrom(std::wistream& input);
  void printTo(std::wostream& output) const;

  void shift(const std::chrono::milliseconds& shift);
};

inline std::wostream& operator<<(std::wostream& output, const Subtitle& subtitle)
{
  subtitle.printTo(output);
  return output;
}

inline std::wistream& operator>>(std::wistream& input, Subtitle& subtitle)
{
  subtitle.parseFrom(input);
  return input;
}

#endif // SUBTITLE_H

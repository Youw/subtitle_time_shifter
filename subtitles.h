#ifndef SUBTITLES_H
#define SUBTITLES_H

#include "subtitle.h"

#include <chrono>
#include <iostream>
#include <vector>

class Subtitles
{
  std::vector<Subtitle> subtitles;
public:
  Subtitles();

  Subtitles(std::wistream& input);

  void parseFrom(std::wistream& input);
  void printTo(std::wostream& output) const;

  void shiftAll(const std::chrono::milliseconds& shift);
};

inline std::wostream& operator<<(std::wostream& output, const Subtitles& subtitles)
{
  subtitles.printTo(output);
  return output;
}

inline std::wistream& operator>>(std::wistream& input, Subtitles& subtitles)
{
  subtitles.parseFrom(input);
  return input;
}

#endif // SUBTITLES_H

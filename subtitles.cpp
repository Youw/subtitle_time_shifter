#include "subtitles.h"

Subtitles::Subtitles()
{

}

Subtitles::Subtitles(std::wistream& input)
{
  parseFrom(input);
}


void Subtitles::parseFrom(std::wistream& input)
{
  try {
    while(input) {
        Subtitle buf;
        input >> buf;
        subtitles.push_back(buf);
      }
  } catch(...) {

  }
  subtitles.shrink_to_fit();
}

void Subtitles::printTo(std::wostream& output) const
{
  for(auto& subtitle: subtitles) {
      output << subtitle << std::endl;
    }
}

void Subtitles::shiftAll(const std::chrono::milliseconds& shift)
{
  for(auto& subtitle: subtitles) {
      subtitle.shift(shift);
    }
}

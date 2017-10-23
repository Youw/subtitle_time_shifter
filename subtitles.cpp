#include "subtitles.h"

#include <iostream>
#include <stdexcept>

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
  } catch (const NoSubtitles &) {
    // done
  }  catch (const std::exception &e) {
    std::wclog << "Error reading subtitle " << subtitles.size() + 1 << ": " << e.what() << std::endl;
  }
  std::wclog << "Read " << subtitles.size() << " entries." << std::endl;
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

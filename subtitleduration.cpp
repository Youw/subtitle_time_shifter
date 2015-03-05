#include "subtitleduration.h"

#include <stdexcept>

SubtitleDuration::SubtitleDuration()
{

}

SubtitleDuration::SubtitleDuration(std::wistream& input)
{
  parseFrom(input);
}

void SubtitleDuration::parseFrom(std::wistream& input)
{
  std::wstring temp;
  input >> from >> temp;
  if(temp!=L"-->") {
      throw std::invalid_argument("Cannot parse time duration.");
    }
  input >> to;
  std::getline(input,temp);
  if(temp!=L"") {
      throw std::invalid_argument("Subtitle file format error.");
    }
}

void SubtitleDuration::printTo(std::wostream& output) const
{
  output << from << " --> " << to;
}

void SubtitleDuration::shift(const std::chrono::milliseconds& shift)
{
  from.shift(shift);
  to.shift(shift);
}


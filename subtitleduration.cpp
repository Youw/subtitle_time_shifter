#include "subtitleduration.h"

#include <stdexcept>
#include <sstream>

SubtitleDuration::SubtitleDuration()
{

}

SubtitleDuration::SubtitleDuration(std::wistream& input)
{
  parseFrom(input);
}

void SubtitleDuration::parseFrom(std::wistream& input)
{
  std::wstring buf;
  std::getline(input, buf);

  std::wstringstream tmp_stream(buf, std::ios::in);

  std::wstring temp;
  tmp_stream >> from >> temp;
  if(temp != L"-->")
  {
      throw std::runtime_error("Cannot parse time duration.");
  }
  tmp_stream >> to;

  std::getline(tmp_stream, temp);
  if (tmp_stream)
      for (auto ch: temp)
          if (!isspace(ch))
          {
              std::wclog << "Warning: unexpected ending: '" << temp << "'" << std::endl;
              break;
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

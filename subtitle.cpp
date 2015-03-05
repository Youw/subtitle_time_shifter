#include "subtitle.h"

#include <algorithm>
#include <cctype>
#include <functional>
#include <locale>
#include <stdexcept>

#include <sstream>

// trim from start
static inline std::wstring &ltrim(std::wstring &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::wstring &rtrim(std::wstring &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::wstring &trim(std::wstring &s) {
        return ltrim(rtrim(s));
}

Subtitle::Subtitle()
{

}

Subtitle::Subtitle(std::wistream& input)
{
  parseFrom(input);
}

void Subtitle::parseFrom(std::wistream& input)
{
  std::wstring buf;
  do {
      std::getline(input,buf);
      buf = trim(buf);
    } while (buf==L"" && input);
  try {
    id = std::stoi(buf);
  } catch (std::invalid_argument&) {
    throw std::invalid_argument("Error parsing subtitle id.");
  }

  input >> subtitle_duration;

  std::getline(input,buf);
  buf=trim(buf);
  while(buf!=L"" && input) {
      lines.push_back(buf);
      std::getline(input,buf);
      buf=trim(buf);
    }

  lines.shrink_to_fit();
}

void Subtitle::printTo(std::wostream& output) const
{
  output << id << std::endl
         << subtitle_duration << std::endl;
  for(auto& line: lines) {
      output << line << std::endl;
    }
}

void Subtitle::shift(const std::chrono::milliseconds& shift)
{
  subtitle_duration.shift(shift);
}

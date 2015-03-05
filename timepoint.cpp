#include "timepoint.h"

#include <string>
#include <iomanip>

TimePoint::TimePoint()
{

}

TimePoint::TimePoint(std::wistream& input)
{
  parseFrom(input);
}

void TimePoint::parseFrom(std::wistream& input)
{
  std::wstring temp;
  std::getline(input,temp,L':');
  point = std::chrono::hours(std::stoi(temp));

  std::getline(input,temp,L':');
  point += std::chrono::minutes(std::stoi(temp));

  std::getline(input,temp,L',');
  point += std::chrono::seconds(std::stoi(temp));

  input >> temp;
  point += std::chrono::milliseconds(std::stoi(temp));
}

void TimePoint::printTo(std::wostream& output) const
{
  long long all = point.count();

  int mili = all%1000;
  all /= 1000;

  int sec = all%60;
  all /= 60;

  int min = all%60;
  all /= 60;

  int hours = all;

  output << std::setfill(L'0') << std::right <<
            std::setw(2) << hours << L':' <<
            std::setw(2) << min << L':' <<
            std::setw(2) << sec << ',' <<
            std::setw(3) << mili;
}

void TimePoint::shift(const std::chrono::milliseconds& shift)
{
  point += shift;
}

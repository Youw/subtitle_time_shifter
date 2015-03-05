#include <chrono>
#include <iostream>
#include <stdexcept>

#include "subtitles.h"

char* program_name = nullptr;

void printError(const std::string& text)
{
  std::cerr << "error: " << text << std::endl << std::endl;
}

void printHelp()
{
  std::cerr << "Usage:" << std::endl
            << program_name << " addsec|addmilli <valid value>" << std::endl;
}



int main(int argc, char** argv)
{  
  program_name = argv[0];
  if(argc!=3) {
      printHelp();
      return 0;
    }

  std::chrono::milliseconds shift_for_subtitles(0);

  try {
    if(argv[1]==std::string("addsec")) {
        shift_for_subtitles = std::chrono::seconds(std::stoi(std::string(argv[2])));
      } else if(argv[1]==std::string("addmilli")) {
        shift_for_subtitles = std::chrono::milliseconds(std::stoi(std::string(argv[2])));
      } else {
        printError("Invalid parameter.");
        printHelp();
      }
  } catch (std::invalid_argument&) {
    printError("Error parsing argument...");
    printHelp();
    return 0;
  }

  Subtitles test(std::wcin);
  test.shiftAll(shift_for_subtitles);
  std::wcout << test << std::endl;
  return 0;
}


#include <chrono>
#include <fstream>
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
            << program_name << " (addsec|addmilli) <valid value> <in filename> (<out filename> | -)" << std::endl;
}



int main(int argc, char** argv)
{  
  program_name = argv[0];
  if(argc < 5) {
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
        return 1;
      }
  } catch (std::invalid_argument&) {
    printError("Error parsing argument...");
    printHelp();
    return 1;
  }

  Subtitles subtitles;

  if (argc < 3)
      subtitles.parseFrom(std::wcin);
  else
  {
      std::wfstream file(argv[3], std::ios::in);
      if (!file.is_open())
      {
          printError(std::string("Cannot open '") + argv[3] + "'");
          return 1;
      }
      subtitles.parseFrom(file);
  }

  const char *out_filename = argv[4] == std::string("-") ? argv[3] : argv[4];

  subtitles.shiftAll(shift_for_subtitles);
  {
    std::wfstream file(out_filename, std::ios::out);
    if (!file.is_open())
    {
        printError(std::string("Cannot open '") + out_filename + "'");
        return 1;
    }
    file << subtitles << std::endl;
  }

  return 0;
}


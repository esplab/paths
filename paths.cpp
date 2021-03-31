#include <iostream> /* printf */
#include <stdlib.h> /* getenv */
#include <string>
#include <vector>
#include <sys/stat.h>

bool pathExists(const std::string &s)
{
  struct stat buffer;
  return (stat(s.c_str(), &buffer) == 0);
}

std::vector<std::string> split(std::string to_split, std::string delims)
{

  std::vector<std::string> results;
  size_t pos1 = 0,
         pos2 = 0;

  do
  {
    pos1 = to_split.find_first_of(delims, pos2);
    if (pos1 == pos2)
    {
      pos2++;
      results.push_back("");
      continue;
    }
    if (pos1 == std::string::npos)
    {
      results.push_back(to_split.substr(pos2));
      break;
    }
    results.push_back(to_split.substr(pos2, pos1 - pos2));
    pos2 = pos1 + 1;
  } while (pos1 != std::string::npos);

  return results;
}

int main()
{

  std::string systemPath = getenv("PATH");
  std::vector<std::string> folders = split(systemPath, ":");

  std::string red = "\033[1;31m";
  std::string green = "\033[1;32m";
  std::string reset = "\033[0m";
  bool exist;

  for (auto part : folders)
  {

    exist = pathExists(part);

    if (!exist)
    {
      std::cout << red;
    }
    else
    {
      std::cout << green;
    }

    std::cout << part;

    std::cout << reset << std::endl;
  }

  return 0;
}

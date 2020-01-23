#include <iostream> /* printf */
#include <stdlib.h> /* getenv */
#include <string>
#include <vector>
#include <sys/stat.h>

bool IsPathExist(const std::string &s)
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
  std::string delimiter = ":";
  std::vector<std::string> folders;

  folders = split(systemPath, delimiter);

  for (auto part : folders)
  {
    if (!IsPathExist(part))
    {
      std::cout << "*";
    }

    std::cout << part << std::endl;
  }

  return 0;
}
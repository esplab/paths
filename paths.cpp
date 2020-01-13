/* getenv example: getting path */
// build with:
// g++ paths.cpp -o paths -lboost_system -lboost_filesystem

#include <iostream> /* printf */
#include <stdlib.h> /* getenv */
#include <string>
#include <vector>
#include "boost/filesystem.hpp"

std::vector<std::string> split(std::string s, std::string delimiter)
{
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
  {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

int main()
{

  std::string systemPath = getenv("PATH");

  std::string delimiter = ":";

  std::vector<std::string> folders = split(systemPath, delimiter);

  for (auto part : folders)
  {

    boost::filesystem::path p(part);

    if (!boost::filesystem::exists(p))
    {
      std::cout << "*";
    }

    std::cout << part << std::endl;
  }

  return 0;
}
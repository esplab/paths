/* getenv example: getting path */
// build with:
// g++ paths.cpp -o paths -lboost_system -lboost_filesystem

#include <iostream> /* printf */
#include <stdlib.h> /* getenv */
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

int main()
{

  std::string systemPath = getenv("PATH");

  std::string delimiter = ":";

  // std::vector<std::string> folders = split(systemPath, delimiter);

  std::vector<std::string> folders;

  boost::split(folders, systemPath, boost::is_any_of(delimiter));

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
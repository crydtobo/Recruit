
  
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <tuple>
#include <map>
#include <vector>
#include <cstdlib>

std::tuple<int, int> amountOfwords(std::ifstream &file);
std::tuple<int, int> numbersOfFilesAndFolders(const std::string &path);
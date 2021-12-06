#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <tuple>
#include <map>
#include <vector>
#include <thread>

std::tuple<int, int> amountOfwords(std::ifstream &file);
std::map<std::string, std::vector<int>> open_file(const std::string &path);
#pragma once
#include "../config/config.hpp"
#include <string>
using std::string;

string generateID(unsigned short length = Precision::kID_DEFAULT_LENGTH);
string hashPassword(const string& password);
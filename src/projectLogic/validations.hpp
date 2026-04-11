#pragma once 
#include <string>
#include "../config/config.hpp"
using std::string;

bool verifyPassword(const string& entered_password , const string& real_password);
Response checkAdminByPassword(const string& user_name , const string& password);
Response isAdminPresentById(const string& id);
Response isTeamPresentById(const string& id);


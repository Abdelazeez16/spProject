#pragma once 
#include <string>
#include "../config/config.hpp"
using std::string;

// A function that checks if the hashed version of the entered password matches the real hashed password.
// @param entered_password the password entered by the user trying to log in
// @param real_password the actual hashed password stored in the system for the user
// @return true if the entered password is correct, false otherwise
bool verifyPassword(const string& entered_password , const string& real_password);

// A function that checks if an admin with a given id exists in the system.
Response checkAdminByPassword(const string& user_name , const string& password);

// A function that checks if a team with a given id exists in the system.
Response isAdminPresentById(const string& id);

// A function that checks if a team with a given id exists in the system.
Response isTeamPresentById(const string& id);

// A function that checks if a judge with a given id exists in the system.
Response isJudgePresentById(const string& id);
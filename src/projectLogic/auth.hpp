#pragma once
#include "../config/config.hpp"
#include <string>
using std::string;

// A function that handles the login flow for an admin user.
// @param user_name the username of the admin trying to log in
// @param password the password of the admin trying to log in
// @return a Response object containing the result of the login attempt,
// including the logged in admin's data if the login is successful, and an appropriate status code if the login fails
Response loginAdmin(const string& user_name , const string& password);

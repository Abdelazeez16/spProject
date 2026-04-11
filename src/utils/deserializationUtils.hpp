#pragma once
#include <string>
#include "../config/config.hpp"
using std::string;

// deserialization utility functions

// Converts a team string into a Team struct.
// @param team_string The string to deserialize.
// @return The deserialized Team struct.
Team deserializeTeam(const string& serialized_team);

// Converts a judge string into a Judge struct.
// @param judge_string The string to deserialize.
// @return The deserialized Judge struct.
Judge deserializeJudge(const string& serialized_judge);

// Converts an evaluation string into an Evaluation struct.
// @param evaluation_string The string to deserialize.
// @return The deserialized Evaluation struct.
Evaluation deserializeEvaluation(const string& serialized_evaluation);

// Converts an admin string into an Admin struct.
// @param admin_string The string to deserialize.
// @return The deserialized Admin struct.
Admin deserializeAdmin(const string& admin_string);

/*****************************************************************/

// A function to deserialize an array of teams from a string and store it in the provided team array.
// @param team_arr_str The string containing the serialized array of teams.
// @param team_arr The array to store the deserialized teams.
// @return The number of teams deserialized and stored in the team array.
int deserializeTeamArrStr(const string& team_arr_str , Team* team_arr); 

// A function to deserialize an array of judges from a string and store it in the provided judge array.
// @param judge_arr_str The string containing the serialized array of judges.
// @param judge_arr The array to store the deserialized judges.
// @return The number of judges deserialized and stored in the judge array.
int deserializeJudgeArrStr(const string& judge_arr_str , Judge* judge_arr);
// A function to deserialize an array of evaluations from a string and store it in the provided evaluation array.
// @param evaluation_arr_str The string containing the serialized array of evaluations.
// @param evaluation_arr The array to store the deserialized evaluations.
// @return The number of evaluations deserialized and stored in the evaluation array.
int deserializeEvalArrStr(const string& evaluation_arr_str , Evaluation* evaluation_arr);

// A function to deserialize an array of admins from a string and store it in the provided admin array.
// @param admin_arr_str The string containing the serialized array of admins.
// @param admin_arr The array to store the deserialized admins.
// @return The number of admins deserialized and stored in the admin array.
int deserializeAdminArrStr(const string& admin_arr_str , Admin* admin_arr);
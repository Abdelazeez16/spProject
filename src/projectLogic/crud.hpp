#pragma once
#include "../config/config.hpp"
#include <string>
using std::string;

// A function that registers a new team with the given details and adds it to the teams array.
// @param team_name the name of the team to register
// @param university_name the name of the university the team belongs to
// @param number_of_members the number of members in the team
// @param project_title the title of the team's project
void registerNewTeam(const string& team_name, const string& university_name, unsigned short int number_of_members, const string& project_title);

// A function that retrieves the details of a team with a given id.
// @param id the id of the team to retrieve
// @return a Response object containing the team's data if found, and an appropriate status code if not found
Response getTeamById(const string& id);

// A function that modifies the details of a team with a given id.
// @param id the id of the team to modify
// @param team_name the new name of the team
// @param university_name the new name of the university the team belongs to
// @param number_of_members the new number of members in the team
// @param project_title the new title of the team's project
// @return a Response object containing the modified team's data if the modification is successful, and an appropriate status code if the team is not found
Response modifyTeamById(const string& id ,const string& team_name, const string& university_name, unsigned short int number_of_members, const string& project_title);

// A function that sets the project title of a team with a given id.
// @param id the id of the team to set its project title
// @param project_title the new title of the team's project
// @return a Response object containing the modified team's data if the modification is successful, and an appropriate status code if the team is not found
Response submitProjectByTeamId(const string& id , const string& project_title);

// A function that adds a new evaluation for a team by a judge with the given scores.
// @param team_id the id of the team to add the evaluation for
// @param judge_id the id of the judge adding the evaluation
// @param innovation_score the innovation score given by the judge
// @param technical_score the technical score given by the judge
// @param presentation_score the presentation score given by the judge
// @return a Response object containing the added evaluation's data if the addition is successful, and an appropriate status code if the team or judge is not found
Response AddEvaluation(const string& team_id, const string& judge_id, unsigned short innovation_score, unsigned short technical_score, unsigned short presentation_score);
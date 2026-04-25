#pragma once
#include <string>
using std::string;


// A function that calculates the final score of a team based on its evaluations and returns it.
// @param team_id the id of the team to calculate its final score
// @return the final score of the team with the given id
float calculateFinalScore(const string& team_id);

// A function that sorts the teams in the teams array based on their final scores in descending order.
void sortTeams ();

// A function that assigns ranks to all teams in the teams array based on their final scores, with the highest score getting rank 1.
void rankAllTeams ();
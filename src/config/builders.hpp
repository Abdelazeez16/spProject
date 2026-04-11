#include "config.hpp"
#include <string>
using std::string;

// A function to create a new Team struct
// @param team_name The name of the team.
// @param university_name The name of the university the team belongs to.
// @param number_of_members The number of members in the team.
// @param project_title The title of the team's project.
// @return A new Team struct with the provided information and generated team_id, final_score set
Team createTeam(const string& team_name, const string& university_name, 
                    unsigned short int number_of_members, const string& project_title);
//update team
Team updateTeam(Team team_to_update,const string& team_name, const string& university_name, unsigned short int number_of_members, const string& project_title);
// A function to create a new Judge struct
// @param name The name of the judge.
// @param specialty The specialty of the judge.
// @param username The username for the judge's account.
// @param password The password for the judge's account (will be hashed).
// @return A new Judge struct with the provided information and generated judge_id, hashed password
Judge createJudge(const string& name, const string& specialty,
                     const string& username, const string& password);

// A function to create a new Evaluation struct
// @param team_id The ID of the team being evaluated.
// @param judge_id The ID of the judge providing the evaluation.
// @param innovation_score The score for innovation.
// @param technical_score The score for technical aspects.
// @param presentation_score The score for presentation.
// @return A new Evaluation struct with the provided information
Evaluation createEvaluation(const string& team_id, const string& judge_id, unsigned short int innovation_score,
                             unsigned short int technical_score, unsigned short int presentation_score);

// A function to create a new Admin struct
// @param name The name of the admin.
// @param username The username for the admin's account.
// @param password The password for the admin's account (will be hashed).
// @return A new Admin struct with the provided information and generated admin_id, hashed password
Admin createAdmin(const string& name, const string& username, const string& password);
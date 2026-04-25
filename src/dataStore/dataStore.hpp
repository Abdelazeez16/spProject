#pragma once
#include "../config/config.hpp"
#include <string>
using std::string;

// A function that loads the data of all entities (teams, judges, evaluations, admins) from their respective database files into the in-memory arrays.
// This function should be called at the start of the program to initialize the data store.
// It reads the serialized data from the database files, deserializes it
void loadData();

// A function that saves the data of all entities (teams, judges, evaluations, admins) from the in-memory arrays to their respective database files.
// This function should be called at the end of the program to persist any changes made to the data store during the program's execution.
// It serializes the data in the in-memory arrays and writes it to the database files.
void saveData();
/***************************************************************************/

// A function that sets the current user of the program to a given team, judge, or admin.
// This function is used to keep track of the currently logged in user, which can be either a team, a judge, or an admin. It updates the current_user variable with the appropriate user
void setCurrentUsr(Team& team);
// A function that sets the current user of the program to a given team, judge, or admin.
// This function is used to keep track of the currently logged in user, which can be either a team, a judge, or an admin. It updates the current_user variable with the appropriate user
void setCurrentUsr(Judge& judge);
// A function that sets the current user of the program to a given team, judge, or admin.
// This function is used to keep track of the currently logged in user, which can be either a team, a judge, or an admin. It updates the current_user variable with the appropriate user
void setCurrentUsr(Admin& admin);

// A function that returns the current user of the program, which can be either a team, a judge, or an admin.
// @return a CurrentUser struct containing a pointer to the current user and their role type
CurrentUser getCurrentUsr();


/*************************************************************************/

// A function that returns the number of teams currently stored in the data store.
unsigned int getNumberOfTeams();

// A function that returns the number of judges currently stored in the data store.
unsigned int getNumberOfJudges();

// A function that returns the number of evaluations currently stored in the data store.
unsigned int getNumberOfEvaluations();

// A function that returns the number of admins currently stored in the data store.
unsigned int getNumberOfAdmins();

/****************************************************************************/
// A function that returns the team at a given index in the teams array.
// @param index the index of the team to return
// @return the team at the given index
const Team& getTeamAt(unsigned int index);

// A function that returns the judge at a given index in the judges array.
// @param index the index of the judge to return
// @return the judge at the given index
const Judge& getJudgeAt(unsigned int index);

// A function that returns the evaluation at a given index in the evaluations array.
// @param index the index of the evaluation to return
// @return the evaluation at the given index
const Evaluation& getEvalAt(unsigned int index);

// A function that returns the admin at a given index in the admins array.
// @param index the index of the admin to return
// @return the admin at the given index
const Admin& getAdminAt(unsigned int index);
/**************************************************************************/

// A function that returns the index of the team with a given id in the teams array.
// @param id the id of the team to find
// @return the index of the team with the given id, or -1 if not found
short getTeamIdxById(const string& id);

// A function that returns the index of the evaluation with a given id in the evaluations array.
// @param id the id of the evaluation to find
// @return the index of the evaluation with the given id, or -1 if not found
short getJudgeIdxById(const string& id);

// A function that returns the index of the judge with a given id in the judges array.
// @param id the id of the judge to find
// @return the index of the judge with the given id, or -1 if not found
short getEvalIdxById(const string& id);

// A function that returns the index of the admin with a given id in the admins array.
// @param id the id of the admin to find
// @return the index of the admin with the given id, or -1 if not found
short getAdminIdxById(const string& id);

/*************************************************************************/

// A function that sets the team at a given index in the teams array to a given team.
// @param team the team to set at the given index
// @param index the index at which to set the team
void setTeamAt(const Team& team , unsigned int index);

// A function that sets the judge at a given index in the judges array to a given judge.
// @param judge the judge to set at the given index
// @param index the index at which to set the judge
void setJudgeAt(const Judge& judge , unsigned int index);

// A function that sets the evaluation at a given index in the evaluations array to a given evaluation.
// @param evaluation the evaluation to set at the given index
// @param index the index at which to set the evaluation
void setEvalAt(const Evaluation& evaluation , unsigned int index);

// A function that sets the admin at a given index in the admins array to a given admin.
// @param admin the admin to set at the given index
// @param index the index at which to set the admin
void setAdminAt(const Admin& admin , unsigned int index);

/*************************************************************************/

// A function that sets the rank of the team at a given index in the teams array to a given rank.
// @param idx the index of the team to set its rank
// @param rank the rank to set for the team at the given index
void setTeamRank(unsigned short idx,unsigned short rank);
#pragma once
#include "../config/config.hpp"
#include <string>
using std::string;

void loadData();
void saveData();
/***************************************************************************/
void setCurrentUsr(Team& team);
void setCurrentUsr(Judge& judge);
void setCurrentUsr(Admin& admin);

CurrentUser getCurrentUsr();


/*************************************************************************/
unsigned int getNumberOfTeams();

unsigned int getNumberOfJudges();

unsigned int getNumberOfEvaluations();

unsigned int getNumberOfAdmins();

/****************************************************************************/
const Team& getTeamAt(unsigned int index);

const Judge& getJudgeAt(unsigned int index);

const Evaluation& getEvalAt(unsigned int index);

const Admin& getAdminAt(unsigned int index);
/**************************************************************************/
short getTeamIdxById(const string& id);
short getEvalIdxById(const string& id);
/*************************************************************************/
void setTeamAt(const Team& team , unsigned int index);

void setJudgeAt(const Judge& judge , unsigned int index);
void setEvalAt(const Evaluation& evaluation , unsigned int index);

void setAdminAt(const Admin& admin , unsigned int index);

void setTeamRank(unsigned short idx,unsigned short rank);
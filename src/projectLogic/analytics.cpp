#include <iostream>
#include "../dataStore/dataStore.hpp"
#include "compute.hpp"
#include <string>
using std::string;
using std::cout;
using std::endl;

void displayFinalReport()
{
    // calculate all scores for all teams
    rankAllTeams();
    for(int i=0;i<getNumberOfTeams();i++)
    {
        cout<<"Team: "<<getTeamAt(i).team_name_<<endl;
        cout<<"Project: "<<getTeamAt(i).project_title_<<endl;
        cout<<"Score: "<<getTeamAt(i).final_score_<<endl;
        cout<<"Rank: "<<getTeamAt(i).rank_<<endl;
        cout<<"------------------"<<endl;
    }
    cout<<"Winner team: "<<getTeamAt(0).team_name_<<endl;
}
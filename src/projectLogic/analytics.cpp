#include <iostream>
#include "../dataStore/dataStore.hpp"
#include "compute.hpp"
#include <string>
using std::string;
using std::cout;
using std::endl;

void displayFinalReport()
{
    for(int i=0;i<getNumberOfTeams();i++)
    {
        cout<<"Team: "<<getTeamAt(i).team_name_<<endl;
        cout<<"Project: "<<getTeamAt(i).project_title_<<endl;
        cout<<"Score: "<<getTeamAt(i).final_score_<<endl;
        cout<<"Rank: "<<getTeamAt(i).rank_<<endl;
        cout<<"------------------"<<endl;
    }
    sortTeams();
    cout<<"Rank: "<<getTeamAt(0).rank_<<endl;
}
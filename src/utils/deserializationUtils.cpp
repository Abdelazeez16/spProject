#include "../config/config.hpp"
#include "conversionUtils.hpp"
#include "stringUtils.hpp"
#include "deserializationUtils.hpp"

/* deserialize Entity functions */

// Converts a team string into a Team struct.
Team deserializeTeam(const string& serialized_team)
{
    Team team = {};

    if (countChar('|' , serialized_team) == 0) return team;

    string serialized_team_members[NumOfMembers::kNUM_OF_TEAM_MEMBERS] = {};

    splitString(serialized_team , '|' , serialized_team_members);

    team.team_id_ = serialized_team_members[0];
    team.team_name_ = serialized_team_members[1];
    team.university_name_ = serialized_team_members[2];
    team.number_of_members_ = numAstr(serialized_team_members[3]);
    team.project_title_ = serialized_team_members[4];
    team.final_score_ = floatStr(serialized_team_members[5]);
    team.rank_ = numAstr(serialized_team_members[6]);

    return team;
}


// Converts a judge string into a Judge struct.
Judge deserializeJudge(const string& serialized_judge)
{
    Judge judge = {};

    if (countChar('|' , serialized_judge) == 0) return judge;

    string serialized_judge_members[NumOfMembers::kNUM_OF_JUDGE_MEMBERS] = {};

    splitString(serialized_judge , '|' , serialized_judge_members);

    judge.judge_id_ = serialized_judge_members[0];
    judge.name_ = serialized_judge_members[1];
    judge.specialty_ = serialized_judge_members[2];
    judge.username_ = serialized_judge_members[3];
    judge.password_ = serialized_judge_members[4];
    
    return judge;
}


// Converts an evaluation string into an Evaluation struct.
Evaluation deserializeEvaluation(const string& serialized_evaluation)
{
    Evaluation evaluation = {};

    if (countChar('|' , serialized_evaluation) == 0) return evaluation;

    string serialized_evaluation_members[NumOfMembers::kNUM_OF_EVALUATION_MEMBERS] = {};

    splitString(serialized_evaluation , '|' , serialized_evaluation_members);

    evaluation.evaluation_id_ = serialized_evaluation_members[0];
    evaluation.team_id_ = serialized_evaluation_members[1];
    evaluation.judge_id_ = serialized_evaluation_members[2];
    evaluation.innovation_score_ = numAstr(serialized_evaluation_members[3]);
    evaluation.technical_score_ = numAstr(serialized_evaluation_members[4]);
    evaluation.presentation_score_ = numAstr(serialized_evaluation_members[5]);
    evaluation.total_score_ = numAstr(serialized_evaluation_members[6]);

    return evaluation;
}


// Converts an admin string into an Admin struct.
Admin deserializeAdmin(const string& admin_string)
{
    Admin admin = {};

    if (countChar('|' , admin_string) == 0) return admin;

    string serialized_admin_members[NumOfMembers::kNUM_OF_ADMIN_MEMBERS] = {};

    splitString(admin_string , '|' , serialized_admin_members);

    admin.admin_id_ = serialized_admin_members[0];
    admin.username_ = serialized_admin_members[1];
    admin.password_ = serialized_admin_members[2];

    return admin;
}
/***************************************************************/

int deserializeTeamArrStr(const string& des_team_arr , Team* team_arr)
{
    string team_arr_str = des_team_arr;
    int number_of_teams = countChar('\n',team_arr_str);

    for (int i = 0; i < number_of_teams; i++)
    {
        string team_str = substr( f_cutSubString(team_arr_str,0,indexOfChar('\n',team_arr_str)) , 0 , indexOfChar('\n',team_arr_str)-1 );
        team_arr[i] = deserializeTeam(team_str);
    }
    return number_of_teams;
}

int deserializeJudgeArrStr(const string& des_judge_arr , Judge* judge_arr)
{
    string judge_arr_str = des_judge_arr;
    int number_of_judges = countChar('\n',judge_arr_str);

    for (int i = 0; i < number_of_judges; i++)
    {
        string judge_str = substr( f_cutSubString(judge_arr_str,0,indexOfChar('\n',judge_arr_str)) , 0 , indexOfChar('\n',judge_arr_str)-1 );
        judge_arr[i] = deserializeJudge(judge_str);
    }
    return number_of_judges;
}

int deserializeEvalArrStr(const string& des_evaluation_arr , Evaluation* evaluation_arr)
{
    string evaluation_arr_str = des_evaluation_arr;
    int number_of_evaluations = countChar('\n',evaluation_arr_str);

    for (int i = 0; i < number_of_evaluations; i++)
    {
        string evaluation_str = substr( f_cutSubString(evaluation_arr_str,0,indexOfChar('\n',evaluation_arr_str)) , 0 , indexOfChar('\n',evaluation_arr_str)-1 );
        evaluation_arr[i] = deserializeEvaluation(evaluation_str);
    }   
    return number_of_evaluations;
}

int deserializeAdminArrStr(const string& des_admin_arr , Admin* admin_arr)
{
    string admin_arr_str = des_admin_arr;
    int number_of_admins = countChar('\n',admin_arr_str);

    for (int i = 0; i < number_of_admins; i++)
    {
        string admin_str = substr( f_cutSubString(admin_arr_str,0,indexOfChar('\n',admin_arr_str)) , 0 , indexOfChar('\n',admin_arr_str)-1 );
        admin_arr[i] = deserializeAdmin(admin_str);
    }
    return number_of_admins;
}
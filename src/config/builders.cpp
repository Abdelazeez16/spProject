#include "builders.hpp"
#include "config.hpp"
#include "../utils/otherUtils.hpp"
#include <string>
using std::string;

string generateTeamId()
{
    return "team_" + generateID();
}
string generateJudgeId()
{
    return "judge_" + generateID();
}
string generateEvalId()
{
    return "eval_" + generateID();
}
string generateAdminId()
{
    return "admin_" + generateID();
}

Team createTeam(const string& team_name, const string& university_name, unsigned short number_of_members, const string& project_title)
{
    Team team;
    team.team_id_ = generateTeamId();
    team.team_name_ = team_name;
    team.project_title_ = project_title;
    team.university_name_ = university_name;
    team.number_of_members_ = number_of_members;
    team.final_score_ = 0.0f;
    team.rank_ = 0;
    return team;
}
Team updateTeam(Team team_to_update,const string& team_name, const string& university_name, unsigned short number_of_members, const string& project_title)
{
    Team team;
    team.team_id_ = team_to_update.team_id_;
    team.team_name_ = team_name;
    team.project_title_ = project_title;
    team.university_name_ = university_name;
    team.number_of_members_ = number_of_members;
    team.final_score_ = team_to_update.final_score_;
    team.rank_ = team_to_update.rank_;
    return team;
}

Judge createJudge(const string& name, const string& specialty, const string& username, const string& password)
{
    Judge judge;
    judge.judge_id_ = generateJudgeId();
    judge.name_ = name;
    judge.specialty_ = specialty;
    judge.username_ = username;
    judge.password_ = hashPassword(password);
    return judge;
}

Evaluation createEvaluation(const string& team_id, const string& judge_id, unsigned short innovation_score, unsigned short technical_score, unsigned short presentation_score)
{
    Evaluation evaluation;
    evaluation.evaluation_id_ = generateEvalId();
    evaluation.team_id_ = team_id;
    evaluation.judge_id_ = judge_id;
    evaluation.innovation_score_ = innovation_score;
    evaluation.technical_score_ = technical_score;
    evaluation.presentation_score_ = presentation_score;
    evaluation.total_score_ = innovation_score + technical_score + presentation_score;
    return evaluation;
}

Admin createAdmin(const string& name, const string& username, const string& password)
{
    Admin admin;
    admin.admin_id_ = generateAdminId();
    admin.username_ = username;
    admin.password_ = hashPassword(password);
    return admin;
}
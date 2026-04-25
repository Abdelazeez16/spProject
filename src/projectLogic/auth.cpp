#include "auth.hpp"
#include "../dataStore/dataStore.hpp"
#include "validations.hpp"
#include <string>
using std::string;





Response loginAdmin(const string& user_name , const string& password)
{
    // check if the admin exists and the password is correct
    Response check_response = checkAdminByPassword(user_name,password);

    Response response = {check_response.content_ptr_, ProgramTypes::ADMIN, check_response.status_};

    Status::StatusType status = check_response.status_;
    // if the login is successful set the current user to the logged in admin   
    switch (status)
    {
    case Status::STATUS_200_OK:
        setCurrentUsr(*(Admin*)check_response.content_ptr_);
        return response;
        break;
    case Status::STATUS_404_NOT_FOUND:
        return response;
        break;
    default:
        break;
    }
    return response;
}

// bool signUpAdmin(const string& user_name , const string& password)
// {
//     return true;
// }
#include "MainWindow.h"
#include "LoginDialog.h"
#include "../../dataStore/dataStore.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    loadData();

    LoginDialog login;
    login.setStartupMode(true);
    if (login.exec() != QDialog::Accepted)
        return 0;

    MainWindow w;
    w.setInitialLoggedInState(true);
    w.show();
    return app.exec();
}
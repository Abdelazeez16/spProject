#pragma once
#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = nullptr);

    // Call with true on app startup to hide the Cancel button
    void setStartupMode(bool startup);

private slots:
    void attemptLogin();

private:
    QLineEdit  *m_usernameEdit;
    QLineEdit  *m_passwordEdit;
    QLabel     *m_errorLabel;
    QPushButton *m_loginBtn;
    QPushButton *m_cancelBtn;
};

#include "LoginDialog.h"
#include "../../projectLogic/auth.hpp"
#include "../../config/config.hpp"
#include <QGraphicsDropShadowEffect>
#include <QScreen>
#include <QApplication>

static const QString DIALOG_STYLE = R"(
QDialog {
    background: #07090f;
    border-radius: 20px;
}
QWidget#cardWidget {
    background: rgba(13, 21, 37, 0.98);
    border-radius: 18px;
    border: 1px solid rgba(56, 189, 248, 0.2);
}
QLabel#titleLabel {
    color: #f1f5f9;
    font-size: 24px;
    font-weight: 700;
    font-family: 'Segoe UI';
}
QLabel#subLabel {
    color: #475569;
    font-size: 13px;
    font-family: 'Segoe UI';
}
QLabel#fieldLabel {
    color: #38bdf8;
    font-size: 12px;
    font-weight: 600;
    font-family: 'Segoe UI';
    letter-spacing: 0.5px;
}
QLabel#errorLabel {
    color: #f87171;
    font-size: 12px;
    font-family: 'Segoe UI';
}
QLineEdit {
    background: rgba(15, 23, 42, 0.8);
    color: #e2e8f0;
    border: 1px solid rgba(56, 189, 248, 0.15);
    border-radius: 10px;
    padding: 12px 16px;
    font-size: 14px;
    font-family: 'Segoe UI';
    min-height: 20px;
}
QLineEdit:focus {
    border: 1px solid rgba(56, 189, 248, 0.6);
    background: rgba(15, 23, 42, 0.95);
}
QLineEdit::placeholder {
    color: #334155;
}
QPushButton#loginBtn {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
        stop:0 #0ea5e9, stop:1 #6366f1);
    color: white;
    border: none;
    border-radius: 10px;
    padding: 14px;
    font-size: 14px;
    font-weight: bold;
    font-family: 'Segoe UI';
    min-height: 24px;
}
QPushButton#loginBtn:hover {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
        stop:0 #38bdf8, stop:1 #818cf8);
}
QPushButton#loginBtn:pressed {
    padding: 15px 12px;
}
QPushButton#cancelBtn {
    background: transparent;
    color: #475569;
    border: 1px solid rgba(56, 189, 248, 0.12);
    border-radius: 10px;
    padding: 12px;
    font-size: 13px;
    font-family: 'Segoe UI';
    min-height: 20px;
}
QPushButton#cancelBtn:hover {
    background: rgba(56, 189, 248, 0.06);
    border: 1px solid rgba(56, 189, 248, 0.3);
    color: #94a3b8;
}
)";

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Code Horses");
    setMinimumSize(480, 560);
    setFixedSize(500, 580);
    setStyleSheet(DIALOG_STYLE);
    setWindowFlags(Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground, false);

    if (QScreen *screen = QApplication::primaryScreen()) {
        QRect geo = screen->availableGeometry();
        move((geo.width() - width()) / 2, (geo.height() - height()) / 2);
    }

    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    outerLayout->setContentsMargins(0, 0, 0, 0);
    outerLayout->setAlignment(Qt::AlignCenter);

    QWidget *card = new QWidget(this);
    card->setObjectName("cardWidget");
    card->setFixedSize(460, 540);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(60);
    shadow->setColor(QColor(56, 189, 248, 50));
    shadow->setOffset(0, 12);
    card->setGraphicsEffect(shadow);

    QVBoxLayout *layout = new QVBoxLayout(card);
    layout->setContentsMargins(44, 44, 44, 44);
    layout->setSpacing(16);


    QLabel *title = new QLabel("Welcome Back");
    title->setObjectName("titleLabel");
    title->setAlignment(Qt::AlignCenter);
    layout->addWidget(title);

    QLabel *sub = new QLabel("Sign in to access the admin panel");
    sub->setObjectName("subLabel");
    sub->setAlignment(Qt::AlignCenter);
    sub->setWordWrap(true);
    layout->addWidget(sub);

    layout->addSpacing(6);

    QLabel *userLbl = new QLabel("USERNAME");
    userLbl->setObjectName("fieldLabel");
    layout->addWidget(userLbl);
    m_usernameEdit = new QLineEdit;
    m_usernameEdit->setPlaceholderText("Enter your username");
    m_usernameEdit->setMinimumHeight(46);
    layout->addWidget(m_usernameEdit);

    QLabel *passLbl = new QLabel("PASSWORD");
    passLbl->setObjectName("fieldLabel");
    layout->addWidget(passLbl);
    m_passwordEdit = new QLineEdit;
    m_passwordEdit->setPlaceholderText("Enter your password");
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    m_passwordEdit->setMinimumHeight(46);
    connect(m_passwordEdit, &QLineEdit::returnPressed, this, &LoginDialog::attemptLogin);
    layout->addWidget(m_passwordEdit);

    m_errorLabel = new QLabel("");
    m_errorLabel->setObjectName("errorLabel");
    m_errorLabel->setAlignment(Qt::AlignCenter);
    m_errorLabel->setMinimumHeight(18);
    layout->addWidget(m_errorLabel);

    layout->addSpacing(4);

    m_loginBtn = new QPushButton("Sign In →");
    m_loginBtn->setObjectName("loginBtn");
    m_loginBtn->setCursor(Qt::PointingHandCursor);
    m_loginBtn->setMinimumHeight(50);
    connect(m_loginBtn, &QPushButton::clicked, this, &LoginDialog::attemptLogin);
    layout->addWidget(m_loginBtn);

    m_cancelBtn = new QPushButton("Cancel");
    m_cancelBtn->setObjectName("cancelBtn");
    m_cancelBtn->setCursor(Qt::PointingHandCursor);
    m_cancelBtn->setMinimumHeight(44);
    connect(m_cancelBtn, &QPushButton::clicked, this, &QDialog::reject);
    layout->addWidget(m_cancelBtn);

    outerLayout->addWidget(card);
}

void LoginDialog::setStartupMode(bool startup)
{
    m_cancelBtn->setVisible(!startup);
}

void LoginDialog::attemptLogin()
{
    QString username = m_usernameEdit->text().trimmed();
    QString password = m_passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        m_errorLabel->setText("Please fill in all fields!");
        return;
    }

    Response res = loginAdmin(username.toStdString(), password.toStdString());

    switch (res.status_) {
    case Status::STATUS_200_OK:
        accept();
        break;
    case Status::STATUS_401_UNAUTHORIZED:
        m_errorLabel->setText("Incorrect password!");
        m_passwordEdit->clear();
        break;
    case Status::STATUS_404_NOT_FOUND:
        m_errorLabel->setText("Username not found!");
        break;
    default:
        m_errorLabel->setText("Login failed. Please try again!");
        break;
    }
}

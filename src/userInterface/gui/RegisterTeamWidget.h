#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>

class RegisterTeamWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RegisterTeamWidget(QWidget *parent = nullptr);

signals:
    void teamRegistered(const QString &message);

private slots:
    void onSubmit();

private:
    QLineEdit   *m_nameEdit    = nullptr;
    QLineEdit   *m_uniEdit     = nullptr;
    QSpinBox    *m_membersSpin = nullptr;
    QLineEdit   *m_projectEdit = nullptr;
    QLabel      *m_errorLabel  = nullptr;
    QPushButton *m_submitBtn   = nullptr;
};

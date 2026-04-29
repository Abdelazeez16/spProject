#include "RegisterTeamWidget.h"
#include "../../projectLogic/crud.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>

static const QString FORM_STYLE = R"(
QWidget#formCard {
    background: rgba(13,20,38,0.92);
    border-radius: 20px;
    border: 1px solid rgba(255,255,255,0.09);
}
QLabel#formTitle {
    color: #f1f5f9;
    font-size: 22px;
    font-weight: 700;
    font-family: 'Segoe UI', Arial;
}
QLabel#formSub {
    color: #4a5568;
    font-size: 13px;
    font-family: 'Segoe UI', Arial;
}
QLabel#fieldLabel {
    color: #818cf8;
    font-size: 11px;
    font-weight: 700;
    font-family: 'Segoe UI', Arial;
    letter-spacing: 1px;
}
QLabel#errorLabel {
    color: #f87171;
    font-size: 12px;
    font-family: 'Segoe UI', Arial;
}
QLineEdit, QSpinBox {
    background: rgba(7,9,18,0.85);
    color: #e2e8f0;
    border: 1px solid rgba(255,255,255,0.09);
    border-radius: 10px;
    padding: 11px 14px;
    font-size: 13px;
    font-family: 'Segoe UI', Arial;
}
QLineEdit:focus, QSpinBox:focus {
    border: 1px solid rgba(99,102,241,0.55);
    background: rgba(7,9,22,0.95);
}
QSpinBox::up-button, QSpinBox::down-button {
    background: rgba(99,102,241,0.1);
    border: none;
    width: 18px;
}
QPushButton#submitBtn {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
        stop:0 #6366f1, stop:1 #4f46e5);
    color: white;
    border: none;
    border-radius: 10px;
    padding: 13px;
    font-size: 14px;
    font-weight: bold;
    font-family: 'Segoe UI', Arial;
}
QPushButton#submitBtn:hover {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
        stop:0 #818cf8, stop:1 #6366f1);
}
QPushButton#submitBtn:pressed { padding: 14px 12px; }
)";

RegisterTeamWidget::RegisterTeamWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background:#070b18;");
    QVBoxLayout *outerL = new QVBoxLayout(this);
    outerL->setContentsMargins(0, 0, 0, 0);

    QScrollArea *scroll = new QScrollArea;
    scroll->setWidgetResizable(true);
    scroll->setStyleSheet("QScrollArea{border:none;background:#070b18;}");

    QWidget *inner = new QWidget;
    inner->setStyleSheet("background:#070b18;");
    QVBoxLayout *innerL = new QVBoxLayout(inner);
    innerL->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    innerL->setContentsMargins(24, 24, 24, 24);

    QWidget *card = new QWidget;
    card->setObjectName("formCard");
    card->setStyleSheet(FORM_STYLE);
    card->setMaximumWidth(540);
    card->setMinimumWidth(400);

    QVBoxLayout *cardL = new QVBoxLayout(card);
    cardL->setContentsMargins(40, 36, 40, 36);
    cardL->setSpacing(14);


    QLabel *title = new QLabel("Register New Team");
    title->setStyleSheet("background-color: transparent;");
    title->setObjectName("formTitle");
    title->setAlignment(Qt::AlignCenter);
    cardL->addWidget(title);

    QLabel *sub = new QLabel("Fill in the team details to participate in the hackathon");
    sub->setStyleSheet("background-color: transparent;");
    sub->setObjectName("formSub");
    sub->setAlignment(Qt::AlignCenter);
    sub->setWordWrap(true);
    cardL->addWidget(sub);
    cardL->addSpacing(8);

    auto addField = [&](const QString &label, QLineEdit *&edit, const QString &ph) {
        QLabel *lbl = new QLabel(label);
        lbl->setStyleSheet("background-color: transparent;");
        lbl->setObjectName("fieldLabel");
        cardL->addWidget(lbl);
        edit = new QLineEdit;
        edit->setPlaceholderText(ph);
        cardL->addWidget(edit);
    };

    addField("TEAM NAME",    m_nameEdit,    "e.g. ByteMasters");
    m_nameEdit->setStyleSheet("background-color: transparent;");
    addField("UNIVERSITY",   m_uniEdit,     "e.g. Cairo University");
    m_uniEdit->setStyleSheet("background-color: transparent;");

    QLabel *membLbl = new QLabel("NUMBER OF MEMBERS");
    membLbl->setStyleSheet("background-color: transparent;");
    membLbl->setObjectName("fieldLabel");
    cardL->addWidget(membLbl);
    m_membersSpin = new QSpinBox;
    m_membersSpin->setRange(1, 20);
    m_membersSpin->setValue(1);
    m_membersSpin->setStyleSheet(
        "QSpinBox{background:rgba(7,9,18,0.0);color:#e2e8f0;"
        "border:1px solid rgba(255,255,255,0.09);border-radius:10px;"
        "padding:11px 14px;font-size:13px;}"
        "QSpinBox:focus{border:1px solid rgba(99,102,241,0.55);}"
        "QSpinBox::up-button,QSpinBox::down-button{"
        "background:rgba(99,102,241,0.1);border:none;width:20px;}");
    cardL->addWidget(m_membersSpin);

    addField("PROJECT TITLE", m_projectEdit, "Brief project description");
    m_projectEdit->setStyleSheet("background-color: transparent;");

    m_errorLabel = new QLabel("");
    m_errorLabel->setStyleSheet("background-color: transparent;");
    m_errorLabel->setObjectName("errorLabel");
    m_errorLabel->setAlignment(Qt::AlignCenter);
    cardL->addWidget(m_errorLabel);

    m_submitBtn = new QPushButton("Register Team");
    m_submitBtn->setObjectName("submitBtn");
    m_submitBtn->setCursor(Qt::PointingHandCursor);
    connect(m_submitBtn, &QPushButton::clicked, this, &RegisterTeamWidget::onSubmit);
    cardL->addWidget(m_submitBtn);

    innerL->addWidget(card, 0, Qt::AlignHCenter);
    scroll->setWidget(inner);
    outerL->addWidget(scroll);
}

void RegisterTeamWidget::onSubmit()
{
    QString name    = m_nameEdit->text().trimmed();
    QString uni     = m_uniEdit->text().trimmed();
    int     members = m_membersSpin->value();
    QString project = m_projectEdit->text().trimmed();

    if (name.isEmpty() || uni.isEmpty() || project.isEmpty()) {
        m_errorLabel->setText("Please fill in all fields!");
        return;
    }

    registerNewTeam(
        name.toStdString(),
        uni.toStdString(),
        static_cast<unsigned short>(members),
        project.toStdString()
    );

    m_nameEdit->clear();
    m_uniEdit->clear();
    m_membersSpin->setValue(1);
    m_projectEdit->clear();
    m_errorLabel->clear();

    emit teamRegistered("Team registered successfully!");
}

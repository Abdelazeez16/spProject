#include "JudgesWidget.h"
#include "../../dataStore/dataStore.hpp"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QMap>

static QMap<QString,QString> specialtyColor = {
    {"AI",                   "#EBF2EB"},
    {"Cybersecurity",        "#EBF2EB"},
    {"Robotics",             "#EBF2EB"},
    {"Software Engineering", "#EBF2EB"},
    {"Data Science",         "#EBF2EB"},
    };

JudgesWidget::JudgesWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background:#070b18;");
    QVBoxLayout *mainL = new QVBoxLayout(this);
    mainL->setContentsMargins(28, 28, 28, 28);

    QScrollArea *scroll = new QScrollArea;
    scroll->setWidgetResizable(true);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setStyleSheet("QScrollArea{border:none;background:#070b18;}");

    m_gridWidget = new QWidget;
    m_gridWidget->setStyleSheet("background:#070b18;");
    m_grid = new QGridLayout(m_gridWidget);
    m_grid->setSpacing(16);
    m_grid->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    // Make all 3 columns stretch equally so cards fill available width
    for (int c = 0; c < 3; ++c)
        m_grid->setColumnStretch(c, 1);

    scroll->setWidget(m_gridWidget);
    mainL->addWidget(scroll);
    refresh();
}

void JudgesWidget::refresh()
{
    QLayoutItem *item;
    while ((item = m_grid->takeAt(0))) { delete item->widget(); delete item; }

    int n = getNumberOfJudges();
    int col = 0, row = 0;

    for (int i = 0; i < n; ++i) {
        const Judge &j = getJudgeAt(i);
        QString spec    = QString::fromStdString(j.specialty_);
        QString color   = specialtyColor.value(spec, "#EBF2EB");
        QString bgColor = "#e56d08";

        QWidget *card = new QWidget;
        card->setObjectName("judgeCard");
        // Fixed height, width stretches with the column
        card->setFixedHeight(245);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        card->setStyleSheet(
            "QWidget#judgeCard{"
            "background:rgba(13,20,38,0.85);border-radius:16px;"
            "border:1px solid rgba(255,255,255,0.08);}"
            "QWidget#judgeCard:hover{"
            "border:1px solid rgba(229,109,8,0.4);"
            "background:rgba(15,22,44,0.95);}");

        QVBoxLayout *cl = new QVBoxLayout(card);
        cl->setContentsMargins(20, 20, 20, 20);
        cl->setSpacing(12);

        // Avatar row
        QHBoxLayout *ar = new QHBoxLayout;
        ar->setSpacing(10);

        QLabel *av = new QLabel("J");
        av->setFixedSize(50, 50);
        av->setAlignment(Qt::AlignCenter);
        av->setStyleSheet(QString(
                              "font-size:22px;background:%1;border-radius:12px;")
                              .arg(bgColor));

        QWidget *info = new QWidget;
        info->setStyleSheet("background:transparent;");
        QVBoxLayout *il = new QVBoxLayout(info);
        il->setContentsMargins(0, 0, 0, 0);
        il->setSpacing(3);
        QLabel *nm = new QLabel(QString::fromStdString(j.name_));
        nm->setStyleSheet("color:#f1f5f9;font-size:14px;font-weight:700;background:transparent;font-family:'Segoe UI',Arial;");
        nm->setWordWrap(false);
        QLabel *un = new QLabel("@" + QString::fromStdString(j.username_));
        un->setStyleSheet("color:#94a3b8;font-size:11px;background:transparent;");
        un->setWordWrap(false);
        il->addWidget(nm);
        il->addWidget(un);

        ar->addWidget(av);
        ar->addWidget(info, 1);
        cl->addLayout(ar);

        // Badge row
        QHBoxLayout *br = new QHBoxLayout;
        QLabel *badge = new QLabel(spec);
        badge->setStyleSheet(QString(
                                 "color:%1;background:%2;border-radius:10px;"
                                 "padding:3px 10px;font-size:11px;font-weight:700;letter-spacing:0.3px;"
                                 "font-family:'Segoe UI',Arial;")
                                 .arg(color).arg(bgColor));
        QLabel *jid = new QLabel(QString::fromStdString(j.judge_id_));
        jid->setStyleSheet("color:#334155;font-size:11px;background:transparent;");
        br->addWidget(badge);
        br->addStretch();
        br->addWidget(jid);
        cl->addLayout(br);

        cl->addStretch();

        m_grid->addWidget(card, row, col);
        col++;
        if (col >= 3) { col = 0; row++; }
    }

    if (n == 0) {
        QLabel *empty = new QLabel("No judges registered yet");
        empty->setStyleSheet("color:#334155;font-size:14px;background:transparent;");
        empty->setAlignment(Qt::AlignCenter);
        m_grid->addWidget(empty, 0, 0);
    }
}
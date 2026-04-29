#include "TeamsWidget.h"
#include "../../dataStore/dataStore.hpp"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QFrame>

TeamsWidget::TeamsWidget(QWidget *parent) : QWidget(parent)
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

void TeamsWidget::refresh()
{
    QLayoutItem *item;
    while ((item = m_grid->takeAt(0))) { delete item->widget(); delete item; }

    int n = getNumberOfTeams();
    int col = 0, row = 0;

    for (int i = 0; i < n; ++i) {
        const Team &t = getTeamAt(i);

        QWidget *card = new QWidget;
        card->setObjectName("teamCard");
        // Fixed height, width stretches with the column
        card->setFixedHeight(245);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        card->setStyleSheet(
            "QWidget#teamCard{"
            "  background: rgba(13,20,38,0.85);"
            "  border-radius: 16px;"
            "  border: 1px solid rgba(255,255,255,0.08);"
            "}"
            "QWidget#teamCard:hover{"
            "  border: 1px solid rgba(99,102,241,0.4);"
            "  background: rgba(15,22,44,0.95);"
            "}");

        QVBoxLayout *cl = new QVBoxLayout(card);
        cl->setContentsMargins(22, 22, 22, 22);
        cl->setSpacing(10);

        // Header
        QHBoxLayout *hl = new QHBoxLayout;
        hl->setSpacing(10);

        QWidget *nameW = new QWidget;
        nameW->setStyleSheet("background:transparent;");
        QVBoxLayout *nl = new QVBoxLayout(nameW);
        nl->setContentsMargins(0, 0, 0, 0);
        nl->setSpacing(4);
        QLabel *name = new QLabel(QString::fromStdString(t.team_name_));
        name->setStyleSheet("color:#f1f5f9;font-size:15px;font-weight:700;background:transparent;font-family:'Segoe UI',Arial;");
        name->setWordWrap(false);
        QLabel *tid = new QLabel(QString::fromStdString(t.team_id_));
        tid->setStyleSheet("color:rgba(99,102,241,0.7);font-size:11px;background:transparent;letter-spacing:0.5px;");
        nl->addWidget(name);
        nl->addWidget(tid);
        hl->addWidget(nameW, 1);

        if (t.final_score_ >= 0) {
            QWidget *scoreBox = new QWidget;
            scoreBox->setFixedSize(70, 58);
            scoreBox->setStyleSheet(
                "background:rgba(99,102,241,0.09);"
                "border:1px solid rgba(99,102,241,0.28);"
                "border-radius:10px;");
            QVBoxLayout *sl = new QVBoxLayout(scoreBox);
            sl->setContentsMargins(0, 6, 0, 6);
            sl->setSpacing(0);
            QLabel *sv = new QLabel(QString::number(t.final_score_, 'f', 1));
            sv->setStyleSheet("color:#818cf8;font-size:20px;font-weight:800;background:transparent;font-family:'Segoe UI',Arial;border:none;");
            sv->setAlignment(Qt::AlignCenter);
            QLabel *ss = new QLabel("score");
            ss->setStyleSheet("color:#4a5568;font-size:10px;letter-spacing:0.5px;background:transparent;border:none;");
            ss->setAlignment(Qt::AlignCenter);
            sl->addWidget(sv);
            sl->addWidget(ss);
            hl->addWidget(scoreBox);
        }
        cl->addLayout(hl);

        QFrame *div = new QFrame;
        div->setFrameShape(QFrame::HLine);
        div->setStyleSheet("color:#1a2234;background:#1a2234;max-height:1px;");
        cl->addWidget(div);
        cl->addSpacing(4);

        auto addRow = [&](const QString &ic, const QString &text) {
            QLabel *rowLbl = new QLabel(ic + "  " + text);
            rowLbl->setStyleSheet("color:#4a5568;font-size:12px;background:transparent;font-family:'Segoe UI',Arial;");
            rowLbl->setWordWrap(false);
            cl->addWidget(rowLbl);
        };

        addRow("University name: ", QString::fromStdString(t.university_name_));
        addRow("Project title: ", QString::fromStdString(t.project_title_));
        addRow("number of members: ", QString::number(t.number_of_members_) + " members");
        if (t.rank_ > 0)
            addRow("", "Rank #" + QString::number(t.rank_));

        cl->addStretch();
        m_grid->addWidget(card, row, col);
        col++;
        if (col >= 3) { col = 0; row++; }
    }

    if (n == 0) {
        QLabel *empty = new QLabel("No teams registered yet");
        empty->setStyleSheet("color:#334155;font-size:14px;background:transparent;");
        empty->setAlignment(Qt::AlignCenter);
        m_grid->addWidget(empty, 0, 0);
    }
}
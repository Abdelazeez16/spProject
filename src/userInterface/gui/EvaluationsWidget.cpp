#include "EvaluationsWidget.h"
#include "../../dataStore/dataStore.hpp"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <Qt>

EvaluationsWidget::EvaluationsWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background:#070b18;");
    QVBoxLayout *mainL = new QVBoxLayout(this);
    mainL->setContentsMargins(28, 28, 28, 28);

    m_table = new QTableWidget(this);
    m_table->setColumnCount(7);
    m_table->setHorizontalHeaderLabels(
        {"ID", "Team", "Judge", "Innovation", "Technical", "Presentation", "Total"});

    m_table->setStyleSheet(R"(
        QTableWidget {
            background: rgba(13,20,38,0.85);
            color: #e2e8f0;
            border: 1px solid rgba(255,255,255,0.08);
            border-radius: 16px;
            gridline-color: #1a2234;
            font-size: 13px;
            font-family: 'Segoe UI', Arial;
        }
        QTableWidget::item {
            padding: 8px 14px;
            border: none;
            background: transparent;
        }
        QTableWidget::item:selected {
            background: rgba(99,102,241,0.1);
            color: #f1f5f9;
        }
        QHeaderView::section {
            background: rgba(7,9,18,0.95);
            color: #818cf8;
            font-size: 11px;
            font-weight: 700;
            letter-spacing: 1px;
            padding: 12px 14px;
            border: none;
            border-bottom: 1px solid rgba(99,102,241,0.18);
            font-family: 'Segoe UI', Arial;
        }
        QScrollBar:vertical {
            background: #0a0f1e;
            width: 5px;
            border-radius: 3px;
        }
        QScrollBar::handle:vertical {
            background: rgba(99,102,241,0.35);
            border-radius: 3px;
        }
        QScrollBar::handle:vertical:hover {
            background: rgba(99,102,241,0.6);
        }
    )");

    m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_table->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    m_table->verticalHeader()->hide();
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_table->setAlternatingRowColors(true);
    m_table->setShowGrid(false);

    mainL->addWidget(m_table);
    refresh();
}

void EvaluationsWidget::refresh()
{
    int n = getNumberOfEvaluations();
    m_table->setRowCount(n);

    for (int i = 0; i < n; ++i) {
        const Evaluation &ev = getEvalAt(i);
        QString teamName  = QString::fromStdString(ev.team_id_);
        QString judgeName = QString::fromStdString(ev.judge_id_);
        for (int j = 0; j < getNumberOfTeams(); ++j)
            if (getTeamAt(j).team_id_ == ev.team_id_)
                teamName = QString::fromStdString(getTeamAt(j).team_name_);
        for (int j = 0; j < getNumberOfJudges(); ++j)
            if (getJudgeAt(j).judge_id_ == ev.judge_id_)
                judgeName = QString::fromStdString(getJudgeAt(j).name_);

        auto makeItem = [](const QString &text, const QString &color = "#e2e8f0") {
            QTableWidgetItem *item = new QTableWidgetItem(text);
            item->setForeground(QColor(color));
            item->setTextAlignment(Qt::AlignCenter);
            return item;
        };

        m_table->setItem(i, 0, makeItem(QString::fromStdString(ev.evaluation_id_), "#818cf8"));
        m_table->setItem(i, 1, makeItem(teamName));
        m_table->setItem(i, 2, makeItem(judgeName, "#94a3b8"));
        m_table->setItem(i, 3, makeItem(QString::number(ev.innovation_score_) + "/10", "#a78bfa"));
        m_table->setItem(i, 4, makeItem(QString::number(ev.technical_score_)  + "/10", "#60a5fa"));
        m_table->setItem(i, 5, makeItem(QString::number(ev.presentation_score_) + "/10", "#34d399"));

        int total         = ev.total_score_;
        QString color     = total >= 25 ? "#34d399" : total >= 20 ? "#fb923c" : "#f87171";
        QTableWidgetItem *totalItem = makeItem(QString("%1/30").arg(total), color);
        QFont f = totalItem->font();
        f.setBold(true);
        totalItem->setFont(f);
        m_table->setItem(i, 6, totalItem);
        m_table->setRowHeight(i, 46);
    }
}

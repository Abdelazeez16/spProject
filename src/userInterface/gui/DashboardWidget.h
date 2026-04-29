#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class DashboardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardWidget(QWidget *parent = nullptr);
    void refresh();

private:
    void buildUI();

    QLabel  *m_statValues[4] = {};
    QWidget *m_topTeamsContent    = nullptr;
    QWidget *m_recentEvalsContent = nullptr;
};

#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class TeamsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TeamsWidget(QWidget *parent = nullptr);
    void refresh();

private:
    QGridLayout *m_grid       = nullptr;
    QWidget     *m_gridWidget = nullptr;
};

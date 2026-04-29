#pragma once
#include <QWidget>
#include <QGridLayout>

class JudgesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit JudgesWidget(QWidget *parent = nullptr);
    void refresh();

private:
    QGridLayout *m_grid       = nullptr;
    QWidget     *m_gridWidget = nullptr;
};

#pragma once
#include <QWidget>
#include <QTableWidget>

class EvaluationsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EvaluationsWidget(QWidget *parent = nullptr);
    void refresh();

private:
    QTableWidget *m_table = nullptr;
};

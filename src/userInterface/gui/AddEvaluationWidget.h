#pragma once
#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>

class AddEvaluationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AddEvaluationWidget(QWidget *parent = nullptr);

    void refresh();
    void setAdminMode(bool isAdmin);

signals:
    void evalAdded(const QString &message);

private slots:
    void onSubmit();
    void updateTotal();

private:
    void buildLockedUI();
    void buildFormUI();

    // Locked view
    QWidget     *m_lockedWidget = nullptr;

    // Form view
    QWidget     *m_formWidget   = nullptr;
    QComboBox   *m_teamCombo    = nullptr;
    QComboBox   *m_judgeCombo   = nullptr;
    QSlider     *m_innovSlider  = nullptr;
    QSlider     *m_techSlider   = nullptr;
    QSlider     *m_presSlider   = nullptr;
    QLabel      *m_innovVal     = nullptr;
    QLabel      *m_techVal      = nullptr;
    QLabel      *m_presVal      = nullptr;
    QLabel      *m_totalLabel   = nullptr;
    QLabel      *m_errorLabel   = nullptr;
    QPushButton *m_submitBtn    = nullptr;

    bool m_isAdmin = false;
};

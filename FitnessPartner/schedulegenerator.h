#ifndef SCHEDULEGENERATOR_H
#define SCHEDULEGENERATOR_H

#include <QDialog>
#include <QCalendarWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ScheduleGenerator; }
QT_END_NAMESPACE

class ScheduleGenerator : public QDialog {
    Q_OBJECT

public:
    explicit ScheduleGenerator(QWidget *parent = nullptr);
    ~ScheduleGenerator();

    int getDifficulty() const;
    QMap<QDate, QString> generateSchedule() const;

private slots:
    void onAccepted();

private:
    Ui::ScheduleGenerator *ui;
    int difficulty = 1;
};

#endif // SCHEDULEGENERATOR_H

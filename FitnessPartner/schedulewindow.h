#ifndef SCHEDULEWINDOW_H
#define SCHEDULEWINDOW_H

#include <QDialog>
#include <QMap>

namespace Ui {
class ScheduleWindow;
}

class ScheduleWindow : public QDialog {
    Q_OBJECT

public:
    explicit ScheduleWindow(QWidget *parent = nullptr);
    ~ScheduleWindow();
    int getSelectedDifficulty() const;
    QMap<QString, QStringList> getExercises() const;

private:
    Ui::ScheduleWindow *ui;
    QMap<QString, QStringList> exercisesByArea;
    void loadExercises();
};

#endif // SCHEDULEWINDOW_H

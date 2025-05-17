#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QRandomGenerator>
#include <QDebug>
#include <QInputDialog>
#include <QDate>
#include <QVBoxLayout>
#include <QDialogButtonBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT


public:
    explicit MainWindow(const QString &username, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDateSelected();
    void on_saveButton_clicked();
    void on_logoutButton_clicked();
    void on_generateExercisesButton_clicked();
    void on_deleteButton_clicked();
    void on_clearButton_clicked();
    void on_moveButton_clicked();

signals:
    void logoutRequested();

private:
    Ui::MainWindow *ui;
    QString username;
    QString getNotesFilePath() const;
    void loadNote(const QDate &date);
    void saveNote(const QDate &date, const QString &text);
    void clearNote(const QDate &date);
    QMap<QString, QStringList> loadExercises();
    QSet<QDate> getDatesWithNotes() const;
    int selectDifficulty();
    void clear();
    int random(int);
    void moveSchedule(const QDate& fromDate, const QDate& toDate);
    QDate lastDate;
};

#endif // MAINWINDOW_H

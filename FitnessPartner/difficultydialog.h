#ifndef DIFFICULTYDIALOG_H
#define DIFFICULTYDIALOG_H

#include <QDialog>

namespace Ui {
class DifficultyDialog;
}

class DifficultyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DifficultyDialog(QWidget *parent = nullptr);
    ~DifficultyDialog();

    int selectedDifficulty() const;

private slots:
    void onButtonClicked(int level);

private:
    Ui::DifficultyDialog *ui;
    int m_difficulty = 1;
};

#endif // DIFFICULTYDIALOG_H

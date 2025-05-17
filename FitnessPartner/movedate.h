#ifndef MOVEDATE_H
#define MOVEDATE_H
#include <QDialog>

namespace Ui {
class MoveDate;
}

class MoveDate : public QDialog
{
    Q_OBJECT

public:
    explicit MoveDate(QWidget *parent = nullptr);
    ~MoveDate();

    int selectedDifficulty() const;  // Возвращает выбранную сложность (1-4)

private slots:
    void onButtonClicked(int level);

private:
    Ui::MoveDate *ui;
    int m_difficulty = 1;  // Значение по умолчанию
};

#endif // DIFFICULTYDIALOG_H

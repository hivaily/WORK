#include "difficultydialog.h"
#include "ui_difficultydialog.h"

DifficultyDialog::DifficultyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DifficultyDialog)
{
    ui->setupUi(this);
    setWindowTitle("Выбор сложности");

    // Подключаем кнопки
    connect(ui->level1Button, &QPushButton::clicked, [this]() { onButtonClicked(1); });
    connect(ui->level2Button, &QPushButton::clicked, [this]() { onButtonClicked(2); });
    connect(ui->level3Button, &QPushButton::clicked, [this]() { onButtonClicked(3); });
    connect(ui->level4Button, &QPushButton::clicked, [this]() { onButtonClicked(4); });
}

DifficultyDialog::~DifficultyDialog()
{
    delete ui;
}

void DifficultyDialog::onButtonClicked(int level)
{
    m_difficulty = level;
    accept();
}

int DifficultyDialog::selectedDifficulty() const
{
    return m_difficulty;
}

#include "schedulegenerator.h"
#include "ui_schedulegenerator.h"
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QMap>
#include <QDate>

ScheduleGenerator::ScheduleGenerator(QWidget *parent) :
    QDialog(parent), ui(new Ui::ScheduleGenerator) {
    ui->setupUi(this);
    setWindowTitle("Генератор расписания");
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ScheduleGenerator::onAccepted);
}

ScheduleGenerator::~ScheduleGenerator() {
    delete ui;
}

int ScheduleGenerator::getDifficulty() const {
    return difficulty;
}

void ScheduleGenerator::onAccepted() {
    difficulty = ui->difficultySpinBox->value();
}

QMap<QDate, QString> ScheduleGenerator::generateSchedule() const {
    QMap<QDate, QString> schedule;
    QDate currentDate = QDate::currentDate();

    // Базовые тренировки по областям
    QStringList neckExercises = {"Наклоны головы", "Повороты головы", "Круговые движения"};
    QStringList armsExercises = {"Отжимания", "Подтягивания", "Подъем гантелей"};
    QStringList coreExercises = {"Скручивания", "Планка", "Подъем ног"};
    QStringList legsExercises = {"Приседания", "Выпады", "Ягодичный мостик"};

    // Интенсивность в зависимости от сложности
    int exercisesPerDay = qMin(2 + difficulty, 5);
    int daysPerWeek = qMin(3 + difficulty, 6);

    for (int week = 0; week < 4; ++week) {
        for (int day = 0; day < daysPerWeek; ++day) {
            QDate trainingDate = currentDate.addDays(week * 7 + day);
            QStringList dailyExercises;

            // Чередуем группы мышц
            switch(day % 4) {
            case 0: dailyExercises = neckExercises; break;
            case 1: dailyExercises = armsExercises; break;
            case 2: dailyExercises = coreExercises; break;
            case 3: dailyExercises = legsExercises; break;
            }

            // Формируем текст тренировки
            QString trainingText;
            for (int i = 0; i < qMin(exercisesPerDay, dailyExercises.size()); ++i) {
                trainingText += dailyExercises[i] + "\n";
            }

            schedule[trainingDate] = trainingText.trimmed();
        }
    }

    return schedule;
}


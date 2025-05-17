#include "mainwindow.h"
#include "schedulegenerator.h"
#include "ui_mainwindow.h"
#include "difficultydialog.h"


MainWindow::MainWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), username(username) {
    ui->setupUi(this);
    setWindowTitle("Fitness Partner - " + username);
    QPixmap BG(":/mainbg/img/maxresdefault.jpg");
    int w = ui->BG->width();
    int h = ui->BG->width();
    ui->BG->setPixmap(BG.scaled(w,h));
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged,
            this, &MainWindow::onDateSelected);
    connect(ui->calendarWidget, &QCalendarWidget::clicked,
            [this](const QDate &date){ lastDate = date; });


}

MainWindow::~MainWindow() {
    delete ui;
}

int MainWindow::random(int baseCount) {                         // вспомогательная функция генерации случайного числа упражнений
    return baseCount + QRandomGenerator::global()->bounded(5);
}

QString MainWindow::getNotesFilePath() const {  // вспомогательная функция создания и нахождения папки файлов расписания
    QDir dir("notes");
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    return "notes/" + username + "_notes.txt";
}

int MainWindow::selectDifficulty()      // вспомогательная функция выбора сложности тренировок
{
    DifficultyDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        return dialog.selectedDifficulty();
    }
    return 1;
}


void MainWindow::loadNote(const QDate &date) {      // функция вывода расписания по дате
    QFile file(getNotesFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->notesEdit->clear();
        return;
    }

    QString fullNote;
    bool foundDate = false;
    QTextStream in(&file);
    in.setCodec("UTF-8");

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.startsWith(date.toString("yyyy-MM-dd") + "|")) {
            foundDate = true;
            fullNote = line.section('|', 1);
            continue;
        }

        if (foundDate && !line.isEmpty() && !line.contains("|")) {
            fullNote += "\n" + line;
        }
        else if (foundDate && line.contains("|")) {
            break;
        }
    }

    file.close();
    ui->notesEdit->setText(foundDate ? fullNote : "");
}

void MainWindow::saveNote(const QDate &date, const QString &text) {     // функция записи расписания в дату
    QString filePath = getNotesFilePath();
    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл для записи!");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.startsWith(date.toString("yyyy-MM-dd"))) {
            lines.append(line);
        }
    }

    if (!text.isEmpty()) {
        lines.append(date.toString("yyyy-MM-dd") + "|" + text);
    }

    file.resize(0);
    QTextStream out(&file);
    out.setCodec("UTF-8");
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();
}



void MainWindow::onDateSelected() {                 // вспомогательная функция выбранной даты
    loadNote(ui->calendarWidget->selectedDate());
}


void MainWindow::clearNote(const QDate &date) {     // функция очистки расписания по дате
    if (!date.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Не выбрана дата!");
        return;
    }

    QString filePath = getNotesFilePath();
    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    bool deleting = false;
    bool dateFound = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith(date.toString("yyyy-MM-dd") + "|")) {
            deleting = true;
            dateFound = true;
            continue;
        }
        if (deleting && line.contains("|")) {
            deleting = false;
        }
        if (!deleting) {
            lines.append(line);
        }
    }
    if (dateFound) {
        file.resize(0);
        QTextStream out(&file);
        out.setCodec("UTF-8");
        for (const QString &line : lines) {
            out << line << "\n";
        }


}
}


void MainWindow::on_saveButton_clicked() {                          // слот кнопки редактирования
    QDate selectedDate = ui->calendarWidget->selectedDate();
    QString text = ui->notesEdit->toPlainText();
    if (!selectedDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Не выбрана дата!");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение",
                                QString("Отредактировать запись?"),
                                QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        clearNote(ui->calendarWidget->selectedDate());
        QMessageBox::information(this, "Успех", "Запись отредактирована!");
        saveNote(selectedDate, text);
    }
}


void MainWindow::on_logoutButton_clicked() {            // слот кнопки выхода из аккаунта
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", "Выйти из аккаунта?",
                                 QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit logoutRequested();
        this->close();
    }
}

QMap<QString, QStringList> MainWindow::loadExercises() {        // вспомогательная функция подгрузки базы упражнений
    QMap<QString, QStringList> exercises;
    QFile file("exercises.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (line.isEmpty()) continue;
            QStringList parts = line.split(" | ");
            if (parts.size() == 2) {
                exercises[parts[0]].append(parts[1]);
            }
        }
        file.close();
    }
    return exercises;
}

void MainWindow::on_generateExercisesButton_clicked()       // слот создания расписания
{
    QMap<QString, QStringList> exercises = loadExercises();
    if (exercises.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл упражнений не найден или пуст!");
        return;
    }
    clear();
    int difficulty = selectDifficulty();
    if (difficulty < 1 || difficulty > 4) {
        QMessageBox::warning(this, "Ошибка", "Некорректный уровень сложности!");
        return;
    }

    bool ok;
    int weeksCount = QInputDialog::getInt(this, "Планирование",
                                       "На сколько недель создать расписание?",
                                       1, 1, 12, 1, &ok);
    if (!ok) return;

    const QStringList requiredAreas = {"шея", "руки", "торс", "ноги"};
    for (const QString &area : requiredAreas) {
        if (!exercises.contains(area) || exercises[area].size() < 3) {
            QMessageBox::warning(this, "Ошибка",
                QString("Не хватает упражнений для области: %1 (нужно минимум 3)").arg(area));
            return;
        }
    }


    int workoutsPerWeek = (difficulty <= 2) ? 3 : 4;
    int exercisesPerArea = (difficulty <= 2) ? 2 : 3;
    int baseCount = 10 + difficulty * 4;

    QDate today = QDate::currentDate();
    QDate startDate = today.addDays(8 - today.dayOfWeek());

    QList<QDate> allWorkoutDates;
    for (int week = 0; week < weeksCount; ++week) {
        QList<QDate> weekDates;
        QDate weekStart = startDate.addDays(week * 7);

        for (int day = 0; day < 7; ++day) {
            weekDates.append(weekStart.addDays(day));
        }

        std::shuffle(weekDates.begin(), weekDates.end(), *QRandomGenerator::global());
        allWorkoutDates.append(weekDates.mid(0, workoutsPerWeek));
    }

    for (const QDate &date : allWorkoutDates) {
        QString workoutText;

        for (const QString &area : requiredAreas) {
            QStringList areaExercises = exercises[area];
            std::shuffle(areaExercises.begin(), areaExercises.end(), *QRandomGenerator::global());

            workoutText += area + ":\n";
            for (int i = 0; i < exercisesPerArea; ++i) {
                int count = baseCount + QRandomGenerator::global()->bounded(5);
                workoutText += QString(" - %1 (%2 раз)\n").arg(areaExercises[i]).arg(count);
            }
            workoutText += "\n";
        }

        saveNote(date, workoutText.trimmed());
    }

    QMessageBox::information(this, "Готово",
                           QString("Тренировки успешно запланированы на %1 недель(и)!").arg(weeksCount));
}

void MainWindow::on_deleteButton_clicked() // слот удаления записи
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение",
                                QString("Удалить всю запись"),
                                QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        clearNote(ui->calendarWidget->selectedDate());
        ui->notesEdit->clear();

    }
}

void MainWindow::clear() // очистка расписания
{
    QString filePath = getNotesFilePath();
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.close();
    }
    else {
        QMessageBox::critical(this, "Ошибка",
                            "Не удалось очистить файл расписания!\n" + file.errorString());
    }
}






void MainWindow::on_clearButton_clicked() // слот очистки расписания
{
    QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this, "Подтверждение",
                                   "Вы действительно хотите очистить всё расписание?",
                                   QMessageBox::Yes | QMessageBox::No);

       if (reply == QMessageBox::No) {
           return;
       }
    clear();
    QMessageBox::information(this, "Готово", "Расписание успешно очищено");
}

void MainWindow::moveSchedule(const QDate& fromDate, const QDate& toDate) // функция переноса расписания на другой день
{
    if (!fromDate.isValid() || !toDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректные даты");
        return;
    }

    clearNote(toDate);
    clearNote(fromDate);
    QString text = ui->notesEdit->toPlainText();
    saveNote(toDate, text);



    QMessageBox::information(this, "Готово",
                           QString("Тренировка перенесена с %1 на %2")
                           .arg(fromDate.toString("dd.MM.yyyy"))
                           .arg(toDate.toString("dd.MM.yyyy")));
}

void MainWindow::on_moveButton_clicked()                    // слот кнопки переноса расписания
{
    if (!lastDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Сначала выберите дату в календаре");
        return;
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Перенос тренировки");
    QVBoxLayout *layout = new QVBoxLayout(&dialog);


    QLabel *infoLabel = new QLabel(
        QString("Перенос тренировки с %1 на:").arg(lastDate.toString("dd.MM.yyyy")),
        &dialog
    );
    layout->addWidget(infoLabel);

    QCalendarWidget *calendar = new QCalendarWidget(&dialog);
    calendar->setMinimumDate(QDate::currentDate().addDays(1));
    calendar->setMaximumDate(QDate::currentDate().addYears(1));
    layout->addWidget(calendar);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        &dialog
    );
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QDate newDate = calendar->selectedDate();
        if (newDate.isValid()) {
            moveSchedule(lastDate, newDate);
        }
    }
}

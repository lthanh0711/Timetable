#include "searchui.h"
#include "ui_searchui.h"

SearchUI::SearchUI(SubjectVec subjectList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchUI),
    subjectList(subjectList)
{
    ui->setupUi(this);
    showMaximized();

    ui->comboBox->addItem("Mã HP");
    ui->comboBox->addItem("Mã lớp");
    ui->comboBox->addItem("Tên HP");

    Timetable timetable{ subjectList };
    reload(timetable);
}

SearchUI::~SearchUI()
{
    delete ui;
}

void SearchUI::on_pushButton_clicked()
{
    // Lay du lieu tu nguoi dung
    QString currentChoice = ui->comboBox->currentText();
    QString currentText = ui->lineEdit->text();
    string input = currentText.toStdString();

    // Tao vector cac mon hoc can hien thi
    SubjectVec subjectToDisplay;

    if (currentText == "") {
        // Hien thi ra TableView
        Timetable timetable{ subjectList };
        reload(timetable);
        return;
    }

    if (currentChoice == "Mã HP") {
        for (Subject sub : subjectList) {
            if (sub.get_ma_hp() == input) {
                subjectToDisplay.push_back(sub);
            }
        }
        if (!subjectToDisplay.empty()) {
            // Hien thi ra TableView
            Timetable tempTimetable{ subjectToDisplay };
            reload(tempTimetable);
        }
        else {
            QMessageBox::warning(this, "Lỗi" ,"Không tìm được lớp có mã học phần trên");
        }
    }
    else if (currentChoice == "Mã lớp") {
        for (Subject sub : subjectList) {
            if (QString::number(sub.get_ma_lop()) == currentText) {
                subjectToDisplay.push_back(sub);
            }
        }
        if (!subjectToDisplay.empty()) {
            // Hien thi ra TableView
            Timetable tempTimetable{ subjectToDisplay };
            reload(tempTimetable);
        }
        else {
            QMessageBox::warning(this, "Lỗi" ,"Không tìm được lớp có mã lớp trên");
        }
    }
    else {
        for (Subject sub : subjectList) {
            if (sub.get_name().find(input) != std::string::npos) {
                subjectToDisplay.push_back(sub);
            }
        }
        if (!subjectToDisplay.empty()) {
            // Hien thi ra TableView
            Timetable tempTimetable{ subjectToDisplay };
            reload(tempTimetable);
        }
        else {
            QMessageBox::warning(this, "Lỗi" ,"Không tìm được lớp có tên trên");
        }
    }
}

void SearchUI::reload(Timetable timetable) {
    DisplayModel *displayModel = new DisplayModel(timetable, this);
    ui->tableView->setModel(displayModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
}


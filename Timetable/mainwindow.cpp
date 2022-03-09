#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Timetable& timetable, SubjectVec subjectList, QWidget *parent)
    : QMainWindow(parent),
      subjectList(subjectList),
      timetable(timetable),
      ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    setFixedSize(width(), height());
    setWindowFlags(windowFlags() | Qt::CustomizeWindowHint |
                                   Qt::WindowMinimizeButtonHint |
                                   Qt::WindowCloseButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Tim kiem mon hoc
    secondDialog = new SearchUI(subjectList);
    secondDialog->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    thirdDialog = new TKB(timetable, subjectList);
    thirdDialog->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    write_csv(timetable);
    QMessageBox::information(this, "Thông báo" ,"File đã được tạo.");
}


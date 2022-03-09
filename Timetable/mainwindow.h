#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CustomDataTypes.h"
#include "searchui.h"
#include "tkb.h"
#include "CSV.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(Timetable& timetable, SubjectVec subjectList, QWidget *parent = nullptr);
    ~MainWindow();

private:

    SubjectVec subjectList;
    Timetable timetable;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    SearchUI *secondDialog;
    TKB *thirdDialog;
};
#endif // MAINWINDOW_H

#ifndef TKB_H
#define TKB_H

#include <QDialog>
#include "CustomDataTypes.h"
#include "displaymodel.h"

namespace Ui {
class TKB;
}

// KHAI BAO CLASS
class TKB : public QDialog
{
    Q_OBJECT

public:
    explicit TKB(Timetable& timetable, SubjectVec subjectList, QWidget *parent = nullptr);
    ~TKB();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TKB *ui;

    SubjectVec subjectList;
    Timetable *timetable;
    void reload();
};

// KHAI BAO HAM
Subject findSubjectInMainFile(vector<Subject> list, int ma_lop);

#endif // TKB_H

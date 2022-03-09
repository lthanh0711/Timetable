#ifndef SEARCHUI_H
#define SEARCHUI_H

#include <QDialog>
#include "CustomDataTypes.h"
#include "displaymodel.h"

namespace Ui {
class SearchUI;
}

class SearchUI : public QDialog
{
    Q_OBJECT

public:
    explicit SearchUI(SubjectVec subjectList, QWidget *parent = nullptr);
    ~SearchUI();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchUI *ui;

    SubjectVec subjectList;
    void reload(Timetable timetable);
};

#endif // SEARCHUI_H

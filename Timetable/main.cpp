#include "mainwindow.h"
#include "CustomDataTypes.h"
#include "CSV.h"
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    // KHOI TAO DU LIEU
    full_data data = read_csv(":/new/prefix1/Raw.csv");

    // Danh sach cac mon hoc co san
    SubjectVec mainTB;

    // Nhap du lieu ve tung mon hoc vao danh sach
    for (const row_data &row : data) {
        Subject sub{ row };
        if (sub.get_buoi_so() == 1) {
            mainTB.push_back(sub);
        }
        else {
            mainTB.back().insert(sub);
        }
    }

    // TKB CHINH
    Timetable tkb;

    // HIEN THI MAN HINH
    QApplication a(argc, argv);
    MainWindow w = MainWindow(tkb, mainTB);
    w.show();
    return a.exec();
}

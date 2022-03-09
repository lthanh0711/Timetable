#include "tkb.h"
#include "ui_tkb.h"

TKB::TKB(Timetable& timetable, SubjectVec subjectList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TKB),
    subjectList(subjectList),
    timetable(&timetable)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::CustomizeWindowHint |
                                   Qt::WindowMinimizeButtonHint |
                                   Qt::WindowCloseButtonHint);
    showMaximized();
    ui->comboBox->addItem("Thêm lớp");
    ui->comboBox->addItem("Xóa lớp");
    reload();
}

TKB::~TKB()
{
    delete ui;
}

void TKB::on_pushButton_clicked()
{
    // Du lieu nhan vao
    QString currentText = ui->lineEdit->text();
    QString currentChoice = ui->comboBox->currentText();

    // The ok pointer is used for error reporting
    bool ok;
    int inputNum = currentText.toInt(&ok);

    if (currentChoice == "Thêm lớp") {
        Subject requestedSub{ findSubjectInMainFile(subjectList, inputNum) };
            if (requestedSub.isNil) {
                QMessageBox::warning(this, "Lỗi" ,"Mã lớp không hợp lệ.");
                return;
            }

            for (Subject sub : timetable->getList()) {
                if (sub.get_ma_lop() == inputNum) {
                    QMessageBox::warning(this, "Lỗi" ,"Lớp học đã được thêm vào trước đó.");
                    return;
                }
            }
            if (!timetable->insertNewSubjectWithTime(requestedSub)) {
                QMessageBox::warning(this, "Lỗi" ,"Lớp học bị trùng thời gian.");
                return;
            }
            else {
                // IN RA MAN HINH TKB VOI LOP VUA DUOC THEM
                reload();
            }
    }
    else {
        bool isFinished{ 0 };
            for (Subject sub : timetable->getList()) {
                if (sub.get_ma_lop() == inputNum) {
                    isFinished = 1;
                    timetable->removeFromList(inputNum);
                    reload();
                    return;
                }
            }
            if (!isFinished) QMessageBox::warning(this, "Lỗi" ,"Lớp học với mã lớp trên không nằm trong thời khóa biểu của bạn.");
    }
}

void TKB::reload() {
    DisplayModel *displayModel = new DisplayModel(*timetable, this);
    ui->tableView->setModel(displayModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
}


Subject findSubjectInMainFile(vector<Subject> list, int ma_lop) {
    for (Subject sub : list) {
        if (sub.get_ma_lop() == ma_lop) return sub;
    }
    Subject nilReturn{ true };
    return nilReturn;
}

#include "CSV.h"
#include "CustomDataTypes.h"

full_data read_csv(string input) {
    // Vecto luu du lieu
    full_data result;

    QFile file(QString::fromStdString(input));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }

    bool firstLine { true };
    while (!file.atEnd()) {
        // Doc tung dong
        string line = QString(file.readLine()).toStdString();
        // Loai bo ky tu thua
        line.pop_back();
        line.pop_back();
        // Bo qua dong tieu de
        if (firstLine) {
            firstLine = false;
            continue;
        }
        // Lay tung ky tu cach nhau boi dau phay
        stringstream ss(line);
        row_data r;
        while (ss.good()) {
            string substr{};
            getline(ss, substr, ',');
            r.push_back(substr);
        }
        result.push_back(r);
    }
    file.close();
    return result;
}

void write_csv(Timetable timetable) {
    ofstream oFile;
    oFile.open("TKB.csv");
    oFile << "Ma lop, Ma HP, Ten HP, So tin, Phong, Can TN, Lop, Buoi so, Thoi gian, Thu\n";
    for (Subject sub : timetable.getList()) {
        oFile << sub.oneLineData() << '\n';
        if (sub.hasMoreThanOneClass()) {
            for (Subject sub2 : sub.get_buoi_sau()) {
                oFile << sub2.oneLineData() << '\n';
            }
        }
    }
    oFile.close();
}

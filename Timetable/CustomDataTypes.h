#ifndef CUSTOMDATATYPES_H
#define CUSTOMDATATYPES_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <bitset>
#include <QDebug>
#include <QMessageBox>

using namespace std;

using full_data = vector<vector<string>>;
using row_data = vector<string>;
using customTime_t = array<bitset<12>, 7>;

class Subject
{
private:
    int ma_lop{};
    string ma_hp{};
    string ten_hp{};
    int khoi_luong{};
    int buoi_so{};
    int thu{};
    string thoi_gian{};
    string phong{};
    bool can_tn{};
    string classType{};

    vector<Subject> buoi_sau{};

    customTime_t time_data{};

public:
    // Ham khoi tao thong thuong
    Subject(row_data input);

    // Ham khoi tao de tao phan tu rong
    Subject(bool input);
    bool isNil{};

    bool hasMoreThanOneClass();
    void insert(Subject subject);

    vector<Subject> get_buoi_sau();

    int get_ma_lop();
    string get_ma_hp();
    string get_name();
    int get_so_tin();
    string get_phong();
    bool get_TN();
    string get_lop();
    int get_buoi_so();
    string get_thoi_gian();
    int get_thu();
    customTime_t get_time_data();

    string oneLineData();
};

using SubjectVec = vector<Subject>;

class Timetable {
private:
    customTime_t timeList{};
    vector<Subject> subjectList{};

public:
    // TAO THOI KHOA BIEU CHO SINH VIEN
    Timetable();
    bool insertNewSubjectWithTime(Subject sub);

    // TAO THOI KHOA BIEU DE IN
    Timetable(SubjectVec subjectList);


    bool isEmpty();
    vector<Subject> getList() const;
    void removeFromList(int ma_lop);
};


#endif // CUSTOMDATATYPES_H

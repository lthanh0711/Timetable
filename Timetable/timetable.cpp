#include "CustomDataTypes.h"


Timetable::Timetable() {
    for (int i{ 0 }; i < 7; i++) timeList[i] = 0b000000000000;
}

Timetable::Timetable(SubjectVec inputList) {
    for (Subject sub : inputList) {
        subjectList.push_back(sub);
        if (sub.hasMoreThanOneClass()) {
            for (const Subject &sub2 : sub.get_buoi_sau()) subjectList.push_back(sub2);;
        }
    }
}

bool Timetable::isEmpty() {
    return subjectList.empty();
}

bool Timetable::insertNewSubjectWithTime(Subject sub) {
    // Neu truoc do chua them lop nao
    if (isEmpty()) {
        subjectList.push_back(sub);
        if (sub.hasMoreThanOneClass()) {
            for (Subject sub2 : sub.get_buoi_sau()) subjectList.push_back(sub2);
        }
        timeList = sub.get_time_data();
        return 1;
    }

    customTime_t sub_time_data{ sub.get_time_data() };

    // Kiem tra xem lop hoc can add khong bi trung thoi gian voi cac lop truoc do
    bool canAddToList{ true };
    for (int i{ 0 }; i < 7; i++) {
        if ((timeList[i] & sub_time_data[i]) != 0b000000000000) {
            canAddToList = false;
            break;
        }
    }
    if (canAddToList) {
        subjectList.push_back(sub);
        if (sub.hasMoreThanOneClass()) {
            for (Subject sub2 : sub.get_buoi_sau()) subjectList.push_back(sub2);
        }
        for (int i{ 0 }; i < 7; i++) {
            timeList[i] = timeList[i] | sub_time_data[i];
        }
    }
    return canAddToList;
}


vector<Subject> Timetable::getList() const {
    return subjectList;
}

void Timetable::removeFromList(int ma_lop) {
    subjectList.erase(
        std::remove_if(
            subjectList.begin(), subjectList.end(),
            [=](Subject sub){ return sub.get_ma_lop() == ma_lop;}
        ),
        subjectList.end()
    );

}


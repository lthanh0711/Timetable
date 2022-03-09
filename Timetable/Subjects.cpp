#include "CustomDataTypes.h"

bitset<12> convertTime(string input) {
    bitset<12> output{};
    if (input == "0645-0815") output = 0b110000000000;
    else if (input == "0645-0910") output = 0b111000000000;
    else if (input == "0645-1005") output = 0b111100000000;
    else if (input == "0825-1005") output = 0b001100000000;
    else if (input == "0825-1100") output = 0b001110000000;
    else if (input == "0825-1145") output = 0b001111000000;
    else if (input == "0920-1145") output = 0b000111000000;
    else if (input == "1015-1145") output = 0b000011000000;
    else if (input == "1230-1400") output = 0b000000110000;
    else if (input == "1230-1455") output = 0b000000111000;
    else if (input == "1230-1550") output = 0b000000111100;
    else if (input == "1410-1550") output = 0b000000001100;
    else if (input == "1410-1645") output = 0b000000001110;
    else if (input == "1410-1730") output = 0b000000001111;
    else if (input == "1505-1645") output = 0b000000000110;
    else if (input == "1505-1730") output = 0b000000000111;
    else if (input == "1600-1730") output = 0b000000000011;
    else output = 0b000000000000;
    return output;
}

Subject::Subject(row_data input) {
    // Ma lop
    ma_lop = stoi(input.at(0));
    // Ma HP
    ma_hp = input.at(1);
    // Ten HP
    ten_hp = input.at(2);
    // So tin
    khoi_luong = input.at(3)[0] - '0';
    if (input.at(3)[1] >= '0' && input.at(3)[1] <= '9') khoi_luong = (input.at(3)[0] - '0') * 10 + (input.at(3)[1] - '0');
    // Buoi so
    buoi_so = input.at(4)[0] - '0';
    if (input.at(4) == "NULL") buoi_so = 1;
    // Thu
    thu = input.at(5)[0] - '0';
    if (input.at(5) == "NULL") thu = 1;
    // Thoi gian
    thoi_gian = input.at(6);
    // Phong
    phong = input.at(10);
    // Can TN
    can_tn = (input.at(11) == "TN") ? 1 : 0;
    // Loai lop (LT, BT, TT, ...)
    classType = input.at(12);
    //
    isNil = false;

    for (int i{ 0 }; i < 7; i++) time_data[i] = 0b000000000000;
    if (buoi_so == 1) time_data[thu - 2] = convertTime(thoi_gian);
}

Subject::Subject(bool input) {
    isNil = input;
}

void Subject::insert(Subject subject) {
    // Them vao buoi sau
    buoi_sau.push_back(subject);
    time_data[subject.thu - 2] = convertTime(subject.thoi_gian);
}

string Subject::oneLineData() {
    // Dua toan bo du lieu cua mon hoc ra thanh 1 string
    string output{ "" };
    output += to_string(ma_lop) + ',';
    output += ma_hp + ',';
    output += ten_hp + ',';
    output += to_string(khoi_luong) + ',';
    output += phong + ',';
    output += to_string(can_tn) + ',';
    output += classType + ',';
    output += to_string(buoi_so) + ',';
    output += thoi_gian + ',';
    output += to_string(thu);
    return output;
}

bool Subject::hasMoreThanOneClass() {
    // Lop hoc co nhieu hon 1 buoi
    return !buoi_sau.empty();
}

int Subject::get_ma_lop() {
    return ma_lop;
}

string Subject::get_ma_hp() {
    return ma_hp;
}

string Subject::get_name() {
    return ten_hp;
}

int Subject::get_so_tin() {
    return khoi_luong;
}

string Subject::get_phong() {
    return classType;
}

bool Subject::get_TN() {
    return can_tn;
}

string Subject::get_lop() {
    return phong;
}

int Subject::get_buoi_so() {
    return buoi_so;
}

string Subject::get_thoi_gian() {
    return thoi_gian;
}

int Subject::get_thu() {
    return thu;
}

customTime_t Subject::get_time_data() {
    return time_data;
}


vector<Subject> Subject::get_buoi_sau() {
    return buoi_sau;
}

#ifndef CSV_H
#define CSV_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "CustomDataTypes.h"

#include <QFile>
#include <QStringList>

full_data read_csv(string filename);
void write_csv(Timetable timetable);

#endif // CSV_H

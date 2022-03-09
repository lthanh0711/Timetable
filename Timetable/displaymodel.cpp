#include "displaymodel.h"

DisplayModel::DisplayModel(Timetable timetable, QObject *parent)
    : QAbstractTableModel(parent),
      displayData(timetable)
{
}

int DisplayModel::rowCount(const QModelIndex & /*parent*/) const
{
    return displayData.getList().size();
}

int DisplayModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 10;
}

QVariant DisplayModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        Subject sub = displayData.getList().at(index.row());
        switch (index.column()) {
        case 0:
            return QString::number(sub.get_ma_lop());
        case 1:
            return QString::fromStdString(sub.get_ma_hp());
        case 2:
            return QString::fromStdString(sub.get_name());
        case 3:
            return QString::number(sub.get_so_tin());
        case 4:
            return QString::fromStdString(sub.get_lop());
        case 5:
            return QString::number(sub.get_TN());
        case 6:
            return QString::fromStdString(sub.get_phong());
        case 7:
            return QString::number(sub.get_buoi_so());
        case 8:
            return QString::fromStdString(sub.get_thoi_gian());
        case 9:
            return QString::number(sub.get_thu());
        }
    }
    if (role == Qt::TextAlignmentRole) {
        if (index.column() != 2) return Qt::AlignCenter;
    }
    return QVariant();
}

QVariant DisplayModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Ma lop");
        case 1:
            return QString("Ma HP");
        case 2:
            return QString("Ten HP");
        case 3:
            return QString("So tin");
        case 4:
            return QString("Phong");
        case 5:
            return QString("Can TN");
        case 6:
            return QString("Lop");
        case 7:
            return QString("Buoi so");
        case 8:
            return QString("Thoi gian");
        case 9:
            return QString("Thu");
        }
    }
    return QVariant();
}

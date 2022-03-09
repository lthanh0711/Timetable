#ifndef DISPLAYMODEL_H
#define DISPLAYMODEL_H

#include <QAbstractTableModel>
#include "CustomDataTypes.h"

class DisplayModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    DisplayModel(Timetable timetable, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    Timetable displayData;
};

#endif // DISPLAYMODEL_H

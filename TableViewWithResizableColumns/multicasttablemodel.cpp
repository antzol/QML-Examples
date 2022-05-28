#include "multicasttablemodel.h"

//---------------------------------------------------------------------------------------
MulticastTableModel::MulticastTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    m_columnNames << tr("Name") << tr("IP Address") << tr("Port");
}

//---------------------------------------------------------------------------------------
int MulticastTableModel::rowCount(const QModelIndex &) const
{
    return 20;
}

//---------------------------------------------------------------------------------------
int MulticastTableModel::columnCount(const QModelIndex &) const
{
    return CountOfColumns;
}

//---------------------------------------------------------------------------------------
QVariant MulticastTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int col = index.column();

    if (row >= rowCount() || col >= columnCount() || role !=  Qt::DisplayRole)
        return QVariant();

    switch (col)
    {
    case ColumnMulticastName:
        return QString("Multicast %1").arg(row + 1 /*, 2, QChar('0')*/);
    case ColumnIpAddress:
        return QString("235.0.0.%1").arg(row + 1);
    case ColumnPort:
        return 1001 + row;
    }

    return QVariant();
}

//---------------------------------------------------------------------------------------
QVariant MulticastTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole || section >= columnCount())
        return QVariant();

    return m_columnNames.at(section);
}

//---------------------------------------------------------------------------------------
QHash<int, QByteArray> MulticastTableModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}

//---------------------------------------------------------------------------------------

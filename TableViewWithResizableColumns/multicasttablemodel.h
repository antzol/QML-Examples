#ifndef MULTICASTTABLEMODEL_H
#define MULTICASTTABLEMODEL_H

#include <qqml.h>
#include <QAbstractTableModel>

class MulticastTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)

public:
    enum {
        ColumnMulticastName = 0,
        ColumnIpAddress,
        ColumnPort,
        CountOfColumns
    };

    MulticastTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    QStringList m_columnNames;

};
#endif // MULTICASTTABLEMODEL_H

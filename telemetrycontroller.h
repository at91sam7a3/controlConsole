#ifndef TELEMETRYCONTROLLER_H
#define TELEMETRYCONTROLLER_H

#include <QObject>
#include <QAbstractListModel>
#include <QThread>


class TelemetryController : public QAbstractListModel
{
    Q_OBJECT
public:
    struct ListElement{
        QString name;
        QString value;
        enum Type{
            stype = 0,
            btype,
            ftype
        } paramType;
        QString units;
    };

public:
    enum Roles {
        ColorRole = Qt::UserRole + 1,
        NameRole,
        ValueRole,
        UnitsRole

    };

    TelemetryController(QObject *parent = 0);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

    void addOrModify(ListElement& e);

private:
    QVector<ListElement> m_data;
};

#endif // TELEMETRYCONTROLLER_H

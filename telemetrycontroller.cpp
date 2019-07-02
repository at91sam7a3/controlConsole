#include "telemetrycontroller.h"

TelemetryController::TelemetryController(QObject *parent) : QAbstractListModel(parent)
{
    ListElement test1{"Battery","7.40",ListElement::stype,"V"};
    ListElement test2{"BodyHeight","80",ListElement::stype,"mm"};
    ListElement test3{"X Coord","0",ListElement::stype,"mm"};
    ListElement test4{"Y Coord","0",ListElement::stype,"mm"};
    ListElement test5{"Direction","0",ListElement::stype,"deg"};
    ListElement test6{"Leg Power","OFF",ListElement::stype,""};
    m_data.push_back(test1);
    m_data.push_back(test2);
    m_data.push_back(test3);
    m_data.push_back(test4);
    m_data.push_back(test5);
    m_data.push_back(test6);
}

int TelemetryController::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

QVariant TelemetryController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
           return QVariant();
       }
       const ListElement *el = &m_data.at(index.row());
       switch (role) {
       case ColorRole:
       {
           if(el->value == "OFF")
               return "red";
           if(el->value == "ON")
               return "green";
             return QString("yellow");
       }
           return QVariant("lightblue");
       case NameRole:
           return m_data.at(index.row()).name;
       case ValueRole:
           return m_data.at(index.row()).value;
       case UnitsRole:
           return m_data.at(index.row()).units;

        default:
           return QString("-?-");
       }
}

QHash<int, QByteArray> TelemetryController::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
      roles[ColorRole] = "color";
      roles[NameRole] = "name";
      roles[ValueRole] = "value";
      roles[UnitsRole] = "units";
      return roles;
}

void TelemetryController::addOrModify(TelemetryController::ListElement& e)
{
    int idx=-1;
    for(int i=0;i<m_data.size();++i){
        if(m_data[i].name == e.name)
        {
            idx=i;
            break;
        }
    }
    if(idx==-1){
        beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
           m_data.append(e);
           endInsertRows();
    }
    else {
        m_data[idx].value = e.value;
        QModelIndex index = createIndex(idx, 2, static_cast<void *>(0));
        emit dataChanged(index, index);
    }


}

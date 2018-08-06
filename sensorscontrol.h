#ifndef SENSORSCONTROL_H
#define SENSORSCONTROL_H

#include <QObject>

class sensorsControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString parameter READ parameter WRITE setParameter NOTIFY parameterChanged)
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
    QString m_value;

    QString m_parameter;

public:
    explicit sensorsControl(QObject *parent = nullptr);

QString value() const
{
    return m_value;
}

QString parameter() const
{
    return m_parameter;
}

signals:

void valueChanged(QString value);

void parameterChanged(QString parameter);

public slots:
void setValue(QString value)
{
    if (m_value == value)
        return;

    m_value = value;
    emit valueChanged(m_value);
}
void setParameter(QString parameter)
{
    if (m_parameter == parameter)
        return;

    m_parameter = parameter;
    emit parameterChanged(m_parameter);
}
};

#endif // SENSORSCONTROL_H

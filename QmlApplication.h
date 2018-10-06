#ifndef QMLAPPLICATION_H
#define QMLAPPLICATION_H

#include <QObject>

class QmlApplication : public QObject
{
    Q_OBJECT
public:
    QmlApplication(QObject *parent = nullptr);
};

#endif // QMLAPPLICATION_H

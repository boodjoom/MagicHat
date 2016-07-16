#ifndef LOADFROMXMLTASK_H
#define LOADFROMXMLTASK_H

#include <QObject>
#include <QRunnable>
#include <QMap>
#include <QString>
#include <hat.h>

class loadFromXMLTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    loadFromXMLTask(const QString& fileName, QObject* parent = 0);
    hat::hatStorage loadFromXML();
public slots:
    void run() {
        emit ready( loadFromXML() );
    }
signals:
    void ready( const hat::hatStorage& storage );
private:
    QString _fileName;
};

#endif // LOADFROMXMLTASK_H

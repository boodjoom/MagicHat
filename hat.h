#ifndef HAT_H
#define HAT_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QSharedPointer>
#include "frase.h"

class hat : public QObject
{
    Q_OBJECT
public:
    friend class MagicHatTest;
    explicit hat(QObject *parent = 0);
    void loadFromXML(const QString& filePath);
    typedef QMap< QString,QSharedPointer<frase> > hatStorage;
    QSharedPointer<frase> findFrase(const QString &key);
signals:
    void prigressChanged(int progress);

public slots:
    void onXmlLoaderReady( const hatStorage& storage );
public:
    hatStorage _storage;
private:
    bool startsWith(const QString& source, const QString& fragment);
};

#endif // HAT_H

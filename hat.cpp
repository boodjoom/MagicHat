#include "hat.h"
#include <QThread>
#include "loadfromxmltask.h"
#include <QDebug>

//Q_DECLARE_METATYPE(hat)
Q_DECLARE_METATYPE(hat::hatStorage)

hat::hat(QObject *parent) : QObject(parent)
{
    //qRegisterMetaType<hat>("hat");
    qRegisterMetaType<hat::hatStorage>("hatStorage");
}

void hat::loadFromXML(const QString &filePath)
{
    loadFromXMLTask * task = new loadFromXMLTask(filePath);
    QThread* thread = new QThread;
    connect( thread, SIGNAL( finished() ), task, SLOT( deleteLater() ) );
    connect( thread, SIGNAL( finished() ), thread, SLOT( deleteLater() ) );
    connect( task, SIGNAL( ready( hatStorage ) ), SLOT( onXmlLoaderReady( hatStorage ) ) );
    connect( task, SIGNAL( ready( hatStorage ) ), thread, SLOT( quit() ) );
    connect( thread, SIGNAL( started() ), task, SLOT( run() ) );

    task->moveToThread( thread );
    thread->start();
}

QSharedPointer<frase> hat::findFrase(const QString& key)
{
    for(hatStorage::const_iterator it=_storage.constBegin();
        it!=_storage.constEnd();
        ++it)
    {
        if(startsWith(it.key(),key))
            return it.value();
    }
    return frase::sptr();
}

void hat::onXmlLoaderReady(const hatStorage &storage)
{
    _storage=storage;
    for(hatStorage::const_iterator it=_storage.constBegin();
        it!=_storage.constEnd();
        ++it)
    qDebug()<<it.key()<<" "<<it.value()->text();
}

bool hat::startsWith(const QString &source, const QString &fragment)
{
    bool res = true;
    if(source.isNull() || source.isEmpty() || fragment.isEmpty() || fragment.isNull())
        return false;

    for(int i=0;i<fragment.length();++i)
    {
        if(i==source.length() || fragment.at(i)!=source.at(i))
        {
            res=false;
            break;
        }
    }
    return res;
}

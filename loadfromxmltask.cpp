#include "loadfromxmltask.h"
#include "frase.h"
#include <QXmlStreamReader>
#include <QFile>
#include <QSharedPointer>
#include <QDebug>

loadFromXMLTask::loadFromXMLTask(const QString &fileName, QObject *parent):
    QObject(parent),
    _fileName(fileName)
{

}

hat::hatStorage loadFromXMLTask::loadFromXML()
{
    qDebug()<<"load from xml: "<<_fileName;
    hat::hatStorage storage;
    QFile file(_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"file not found at path: "<< _fileName;
       return storage;
    }
    QXmlStreamReader xml(&file);
    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement)
        {
            if (xml.name() == "items")
                continue;
            if (xml.name() == "item")
            {
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("key"))
                {
                    storage[attributes.value("key").toString()]=QSharedPointer<frase>::create(xml.readElementText());
                }
            }
        }
    }
    return storage;
}

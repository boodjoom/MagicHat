#ifndef FRASE_H
#define FRASE_H

#include <QObject>
#include <QString>
#include <QByteArray>

class frase
{
public:
    typedef QSharedPointer<frase> sptr;
    frase(const QString& text = QString());
    const QString& text();
    void setText(const QString& text);
    void setSound(const QByteArray& sound);
    const QByteArray& sound();
    bool hasSound();
private:
    QString _text;
    QByteArray _sound;
    bool _hasSound;
};

#endif // FRASE_H

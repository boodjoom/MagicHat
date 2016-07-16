#include "frase.h"

frase::frase(const QString &text):
    _text(text)
  ,_hasSound(false)
{

}

const QString &frase::text(){return _text;}

void frase::setText(const QString &text){_text=text;}

void frase::setSound(const QByteArray &sound){if(!sound.isEmpty()){_sound=sound;}else{_sound.clear();}_hasSound=_sound.isEmpty();}

const QByteArray &frase::sound(){return _sound;}

bool frase::hasSound(){return _hasSound;}

#include "frase.h"

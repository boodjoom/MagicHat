#include "maindialog.h"
#include "ui_maindialog.h"
#include <QApplication>
#include "QtSpeech.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

using namespace QtSpeech_v1;

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    QtSpeech::VoiceNames vs = QtSpeech::voices();
    if(vs.isEmpty())
    {
        ui->cbVoice->setEditable(false);
        ui->btnSay->setEnabled(false);
        ui->sdrRate->setEnabled(false);
    }
    foreach(QtSpeech::VoiceName vn,vs)
        ui->cbVoice->addItem(vn.name,QVariant::fromValue(vn.id));
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_btnOpebFile_clicked()
{
    QString file="";
    file = QFileDialog::getOpenFileName(this, tr("Открыть xml"), "", tr("Xml Files (*.xml)"));
    if(!file.isEmpty())
    {
        _hat.loadFromXML(file);
         ui->lbFileName->setText(file);
    }
}

void MainDialog::on_btnSay_clicked()
{
    frase::sptr fr = _hat.findFrase(ui->editKey->text());
    if(!fr.isNull())
    {
        QtSpeech::VoiceName name;
        name.name=ui->cbVoice->currentText();
        name.id=ui->cbVoice->currentData().value<QString>();
        QtSpeech speech(name, this);
        speech.setRate(ui->sdrRate->value());
        qDebug()<<"say:"<<fr->text();
        speech.say(fr->text());
    }
    else qDebug()<<"Key not found";
}

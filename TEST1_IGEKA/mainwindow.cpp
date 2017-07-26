#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QString>
#include <QWidget>
#include <QMimeDatabase>
#include <QMimeType>
#include <QDirIterator>
#include <QRegExp>
QString mask_pdf = "*.pdf";
QString mask_doc = "*.docx";
QString equal = "=";
QString different = "<>";
QString none = "żadne";
QStringList RegList = (QStringList() << equal << different);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox_Mask->addItem(mask_pdf);
    ui->comboBox_Mask->addItem(mask_doc);
    ui->checkBox_FullName ->setChecked(false);
    ui->checkBox_Name1 -> setChecked(true);
    ui->checkBox_Name2 -> setChecked(true);
    ui->checkBox_Name3 -> setChecked(true);
    ui->checkBox_Name4 -> setChecked(true);
    ui->checkBox_Name5 -> setChecked(true);

    ui->comboBox_Reg1->addItems(RegList);
    ui->comboBox_Reg2->addItems(RegList);
    ui->comboBox_Reg3->addItems(RegList);
    ui->comboBox_Reg4->addItems(RegList);
    ui->comboBox_Reg5->addItems(RegList);

    ui->label_Sep1->setEnabled(true);
    ui->label_Sep2->setEnabled(true);
    ui->label_Sep3->setEnabled(true);
    ui->label_Sep4->setEnabled(true);

//    connect(ui->comboBox_Modul4->lineEdit(), &QLineEdit::returnPressed,
//           this, &MainWindow::animateFindingClick);
   // connect(ui->pushButton_Analyse, &QAbstractButton::clicked, this, &MainWindow::find);
    connect(ui->pushButton_Analyse, &QAbstractButton::clicked, this, &MainWindow::Find_by);
    connect(ui->pushButton_Browse, &QAbstractButton::windowTitleChanged, this, &MainWindow::on_pushButton_Browse_clicked);
//    connect(ui->comboBox_Browse, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
//            this, &MainWindow::on_pushButton_Analyse_clicked);
//    QObject::connect(ui->comboBox_Mask, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
//            this, &MainWindow::on_pushButton_Analyse_clicked);
    //ustawienie blokad

    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name1, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg1, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name1, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name1, SIGNAL(toggled(bool)), ui->lineEdit_Name1, SLOT(setEnabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name2, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg2, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name2, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name2, SIGNAL(toggled(bool)), ui->lineEdit_Name2, SLOT(setEnabled(bool)));
     connect(ui->checkBox_Name2, SIGNAL(toggled(bool)), ui->label_Sep1, SLOT(setEnabled(bool)));     //sep1
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name3, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg3, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name3, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name3, SIGNAL(toggled(bool)), ui->lineEdit_Name3, SLOT(setEnabled(bool)));
     connect(ui->checkBox_Name3, SIGNAL(toggled(bool)), ui->label_Sep2, SLOT(setEnabled(bool)));     //sep2
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name4, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg4, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name4, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name4, SIGNAL(toggled(bool)), ui->lineEdit_Name4, SLOT(setEnabled(bool)));
     connect(ui->checkBox_Name4, SIGNAL(toggled(bool)), ui->label_Sep3, SLOT(setEnabled(bool)));     //sep3
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name5, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg5, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name5, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name5, SIGNAL(toggled(bool)), ui->lineEdit_Name5, SLOT(setEnabled(bool)));
     connect(ui->checkBox_Name5, SIGNAL(toggled(bool)), ui->label_Sep4, SLOT(setEnabled(bool)));     //sep4
    connect(ui->lineEdit_Name1, SIGNAL(textChanged(const QString &)), this, SLOT(text()));

//    Keep a pointer to the QLineEdit "l" in your class, e.g. as QLineEdit* m_lineEdit.
//    connect b, SIGNAL(clicked()) to a slot buttonClicked().
//    Implement buttonClicked like this:
//    void MyWidget::buttonClicked() {
//        const QString text = m_lineEdit->text();
//     filesFoundLabel = new QLabel;
//     createFilesTable();

}

MainWindow::~MainWindow()
{
    delete ui;
}

static void updateComboBox(QComboBox *comboBox)
{
    if (comboBox->findText(comboBox->currentText()) == -1)
        comboBox->addItem(comboBox->currentText());
}
void MainWindow::on_pushButton_Browse_clicked()
{
    QString directory =
    QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, "Choose directory", QDir::currentPath()));

    if (!directory.isEmpty()) {
        if (ui->comboBox_Browse->findText(directory) == -1) // wartosc -1 oznacza ze w combobox nie ma nic na liscie, czyli
            ui->comboBox_Browse->addItem(directory);       // jesli nc nie ma to dodaje sie "sie directory do comboBox"
        ui->comboBox_Browse->setCurrentIndex(ui->comboBox_Browse->findText(directory));
    }
}

void MainWindow::on_pushButton_Analyse_clicked()
{
    QString sep1 = ui->label_Sep1 ->text();
    QString sep2 = ui->label_Sep2 ->text();
    QString sep3 = ui->label_Sep3 ->text();
    QString sep4 = ui->label_Sep4 ->text();
    QString string1 = ui->lineEdit_Name1 ->text();
    QString string2 = ui->lineEdit_Name2 ->text();
    QString string3 = ui->lineEdit_Name3 ->text();
    QString string4 = ui->lineEdit_Name4 ->text();
    QString string5 = ui->lineEdit_Name5 ->text();

    all_string = string1 + sep1 + string2 + sep2 + string3 + sep3 + string4 + sep4 + string5;
    ui->label_Test ->setText("Szukany string: "+ all_string + ui->comboBox_Mask->currentText());

}

void  MainWindow::animateFindingClick()
{
    ui->pushButton_Analyse->animateClick();
}

void MainWindow::on_lineEdit_Sep_textChanged(const QString &arg1)
{
    ui->label_Sep1->setText(arg1);
    ui->label_Sep2->setText(arg1);
    ui->label_Sep3->setText(arg1);
    ui->label_Sep4->setText(arg1);
}

void MainWindow::on_lineEditFilter_textChanged(const QString &arg1)
{
    /*string2 = ui->lineEdit_Name2 ->text();
    QDir myPath= ui->comboBox_Browse->currentText();
    QRegExp reg_exp(myPath, QRegExp::Wildcard | Qt::CaseInsensitive);
    reg_exp.setPatternSyntax(QRegExp::Wildcard);
    if(reg_exp.exactMatch(string2)){
    ui->listWidget_Errors->addItem()
    }*/
/*
    QDir myPath= ui->comboBox_Browse->currentText();
    myPath.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    myList = myPath.entryList();
    ui->listWidget_Errors->addItems(myList);
    ui->label_Total->setText(QString("%1").arg(ui->listWidget_Errors->count()));

    QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    ui->listWidget_Errors->clear();
    ui->listWidget_Errors->addItems(myList.filter(regExp));
    ui->label_Total->setText(QString("%1").arg(ui->listWidget_Errors->count()));*/
}

void MainWindow::showFiles2(const QStringList &files)
{
    ui->listWidget_Results->addItems(files);
}
void MainWindow::Find_by()
{
    ui->listWidget_Results->clear();
    QString filter = ui->comboBox_Mask->currentText();

    QString sep = ui->lineEdit_Sep -> text();
    QString string1 = ui->lineEdit_Name1 ->text();
    QString string2 = ui->lineEdit_Name2 ->text();
    QString string3 = ui->lineEdit_Name3 ->text();
    QString string4 = ui->lineEdit_Name4 ->text();
    QString string5 = ui->lineEdit_Name5 ->text();

    QString targetStr = ui->lineEdit_Name2 ->text(); // What we search for

    QStringList listFiles; // list for matches targets
    QString directory = ui->comboBox_Browse->currentText(); // Where to search
    QDirIterator iterator(directory, QStringList() << filter, QDir::Files, QDirIterator::Subdirectories);
    while (iterator.hasNext()) {//zwraca false jesli nie napotka direct lub zwraca true jesli napotka,
        QString filename = iterator.next(); //przejscie iteratora do kolejnego wejscia
        QFileInfo file(filename);

        if (file.isDir()) { // Check if it's a dir
            continue;
        }


//       if (ismatch(filename, string1, string2, string3, string4, string5, sep, filter))
//       {
//           listFiles << filename;
//       }


       //  If the filename contains target string - put it in the hitlist
        if (file.fileName().contains(targetStr, Qt::CaseInsensitive)) {
            listFiles << filename;
             ui->label_Test2 ->setText(file.fileName());
        }


    }
 showFiles2(listFiles);

//    rozszerzenie - suffix
//    QFileInfo fi("/tmp/archive.tar.gz");
//    QString file_suffix = fi.suffix();  // ext = "gz"*/

//    //nazwa pliku - fileName
//    QFileInfo fi("/tmp/archive.tar.gz");
//    QString name = fi.fileName();
}

bool MainWindow::ismatch(const QString &next_file_name, const QString &string1, const QString &string2, const QString &string3,
                         const QString &string4, const QString &string5, const QString &separator, const QString &filter)
{
    QString filter_correct = filter;
    filter_correct = filter_correct.remove(0, 1);
    QString user_file_name = string1 + separator + string2 + separator + string3 + separator + string4 + separator + string5;

    QString correct_next_file_name = next_file_name;

    int pos = correct_next_file_name.indexOf(filter_correct); //5
    correct_next_file_name = correct_next_file_name.remove(pos, 5);

    //ui->listWidget_Errors ->addItems("File name: " + file.fileName());
    QString * Tab_QStrFile = tab_File_Qstring(correct_next_file_name, 5, separator);
    QString * Tab_QStrUser = tab_File_Qstring(user_file_name, 5, separator);
    QStringList lists;
    lists << Tab_QStrFile[0]<< Tab_QStrFile[1]<< Tab_QStrFile[2]<< Tab_QStrFile[3]<< Tab_QStrFile[4]<< Tab_QStrUser[0]<< Tab_QStrUser[1]<< Tab_QStrUser[2]<< Tab_QStrUser[3]<< Tab_QStrUser[4];
    ui->listWidget_Errors->addItems(lists);
}

QString *MainWindow::tab_File_Qstring(const QString &FileQString, int size, const QString &separator)
{
    QString *newQTab = new QString[size];
    QString tempQStMAIN = FileQString;
   // tempQStMAIN = tempQStMAIN.append(separator);
    QString TempQstab = tempQStMAIN;
    QString TempQS_less_and_less = tempQStMAIN;
    int pos;

    for(int i = 0; i < 5; i++)
    {
       pos = TempQS_less_and_less.indexOf(separator); //5
       TempQstab = TempQstab.remove(pos, 50);
       newQTab[i] = TempQstab;
       TempQS_less_and_less = TempQS_less_and_less.remove(0, pos+1);
       TempQstab = TempQS_less_and_less;
    }
    return newQTab;
    //ABCDE-12345-FGHIH-56789-HOPFD
}


void MainWindow::on_pushButton_Test_clicked()
{
    QString *Tab_QStrFile = tab_File_Qstring("ABCDE-12345-FGHIH-56789-HOPFD.*pdf", 5, ui->comboBox_Mask->currentText());
    QStringList lists;
    lists << Tab_QStrFile[0]<< Tab_QStrFile[1]<< Tab_QStrFile[2]<< Tab_QStrFile[3]<< Tab_QStrFile[4];
    ui->listWidget_Errors->addItems(lists);
    ui->label_Test2->setText(Tab_QStrFile[0]);
}

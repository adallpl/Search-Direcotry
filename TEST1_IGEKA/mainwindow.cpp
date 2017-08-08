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
#include <QDesktopServices>
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

    QStringList tableHeader;
    ui -> tableWidget -> setColumnCount(3);
    tableHeader << tr("Lp.") <<  tr("Nazwa pliku") <<  tr("Ścieżka");
    ui -> tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui -> tableWidget -> setHorizontalHeaderLabels(tableHeader);
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
     connect(ui->checkBox_Name1, SIGNAL(toggled(bool)), ui->label_Sep1, SLOT(setEnabled(bool)));     //sep1
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name2, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg2, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name2, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name2, SIGNAL(toggled(bool)), ui->lineEdit_Name2, SLOT(setEnabled(bool)));
     connect(ui->checkBox_Name2, SIGNAL(toggled(bool)), ui->label_Sep2, SLOT(setEnabled(bool)));     //sep1
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name3, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg3, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name3, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name3, SIGNAL(toggled(bool)), ui->lineEdit_Name3, SLOT(setEnabled(bool)));
     connect(ui->checkBox_Name3, SIGNAL(toggled(bool)), ui->label_Sep3, SLOT(setEnabled(bool)));     //sep2
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name4, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg4, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name4, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name4, SIGNAL(toggled(bool)), ui->lineEdit_Name4, SLOT(setEnabled(bool)));
     connect(ui->checkBox_Name4, SIGNAL(toggled(bool)), ui->label_Sep4, SLOT(setEnabled(bool)));     //sep3
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name5, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg5, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name5, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name5, SIGNAL(toggled(bool)), ui->lineEdit_Name5, SLOT(setEnabled(bool)));
   //  connect(ui->checkBox_Name5, SIGNAL(toggled(bool)), ui->label_Sep4, SLOT(setEnabled(bool)));     //sep4


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

void MainWindow::showFiles(const QStringList &files)
{
    ui -> listWidget_Results->clear();
    ui->listWidget_Results->addItems(files);
}
void MainWindow::Find_by()
{
    ui->listWidget_Results->clear();
    QString mask = ui->comboBox_Mask->currentText();
    QString sep = ui->lineEdit_Sep -> text();
    //  odczytanie lineEdit
    QString string1 = ui->lineEdit_Name1 ->text();
    QString string2 = ui->lineEdit_Name2 ->text();
    QString string3 = ui->lineEdit_Name3 ->text();
    QString string4 = ui->lineEdit_Name4 ->text();
    QString string5 = ui->lineEdit_Name5 ->text();

    QStringList listFiles; // list for matches targets
    QString directory = ui->comboBox_Browse->currentText(); // Where to search
    QDirIterator iterator(directory, QStringList() << mask, QDir::Files, QDirIterator::Subdirectories);


    int iter_dubl = 0;
    while (iterator.hasNext())
    {
        //zwraca false jesli nie napotka direct lub zwraca true jesli napotka,
        QString filename = iterator.next(); //przejscie iteratora do kolejnego wejscia

        QFileInfo file(filename);

        if (file.isDir()) { // Check if it's a dir
            continue;
        }
       QString filename_next = file.fileName();
       bool gen_Check = ismatch(filename_next, string1, string2, string3, string4, string5, sep, mask);
       if (gen_Check == true)
       {
           ui -> tableWidget -> horizontalHeader() -> setSectionResizeMode(0, QHeaderView::Stretch);
           ui->tableWidget->insertRow(ui->tableWidget->rowCount());
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::number(iter_dubl+1)));
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(file.fileName()));
           ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(file.canonicalPath()));
           listFiles << QString::number(iter_dubl+1) + ". " + file.fileName() + "   " + file.canonicalPath();
           iter_dubl++;
           QDesktopServices::openUrl(QUrl(filename, QUrl::TolerantMode));
       }
       //  If the filename contains target string - put it in the hitlist
//        if (file.fileName().contains(string1, Qt::CaseInsensitive))
//        {
//            listFiles << filename;
//        }
    }

}

bool MainWindow::ismatch(const QString &next_file_name, const QString string1, const QString string2, const QString string3,
                         const QString string4, const QString string5, const QString &separator, const QString &mask)
{

    //  sprawdzenie comboReg czy rowne, lub rozne ("=" lub "<>")
    QString *comboReg_check = new QString[5];
    comboReg_check[0] = ui->comboBox_Reg1 -> currentText(); // tu moze byc tylko "=" lub "<>"
    comboReg_check[1] = ui->comboBox_Reg2 -> currentText();
    comboReg_check[2] = ui->comboBox_Reg3 -> currentText();
    comboReg_check[3] = ui->comboBox_Reg4 -> currentText();
    comboReg_check[4] = ui->comboBox_Reg5 -> currentText();
    //sprawdzenie checkBox_name

    bool *checkBoxName_is_checked = new bool[5];
    checkBoxName_is_checked[0] = ui->checkBox_Name1->isChecked();
    checkBoxName_is_checked[1] = ui->checkBox_Name2->isChecked();
    checkBoxName_is_checked[2] = ui->checkBox_Name3->isChecked();
    checkBoxName_is_checked[3] = ui->checkBox_Name4->isChecked();
    checkBoxName_is_checked[4] = ui->checkBox_Name5->isChecked();
    QString mask_correct = mask;
    mask_correct = mask_correct.remove(0, 1); // *.pdf -> .pdf

    QString user_file_name = string1+separator+string2+separator+string3+separator+string4+separator+string5+mask_correct;

    QString *QStrFile = QString_to_Tab(next_file_name, 5, separator, mask);
    QString *QStrUser = QString_to_Tab(user_file_name, 5, separator, mask);

    bool *match = new bool[5];

    //  pierwsza petla iteruje po kolejncych tresciach comboBoxów
    for(int i = 0; i < 5; ++i)
    {
        if(comboReg_check[i] == "=") // opcja z dopasowanie rownym("=") w jednej z reguł
        {
            if(checkBoxName_is_checked[i] == true)
            {
                if(QStrFile[i] == QStrUser[i] || QStrFile[i] == QStrUser[5])
                {
                    match[i] = true;
                }
                else{
                    match[i] = false;
                }
            }else{
                match[i] = true;
            }
        }
        else if(comboReg_check[i] == "<>") // opcja z dopasowanie roznym ("<>") w jednej z reguł
        {

            if(checkBoxName_is_checked[i] == true)
            {
                if(QStrFile[i] == QStrUser[i])
                {
                    match[i] = false;
                }
                else{
                    match[i] = true;
                }
            }else{
                match[i] = false;
            }
        }
    }
    if((match[0] == true) && (match[1] == true) && (match[2] == true) && (match[3] == true) && (match[4] == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString *MainWindow::QString_to_Tab(const QString &nextFileQString, int size, const QString &separator, const QString &mask)

{
    QString *newQTab_Return = new QString[size+1];
    QString mask_correct = mask;
    mask_correct = mask_correct.remove(0, 1); //    *.pdf -> .pdf
    QString correct_nextFileQString = nextFileQString;

    int position = correct_nextFileQString.indexOf(mask_correct);
    correct_nextFileQString = correct_nextFileQString.remove(position, 5);
    correct_nextFileQString = correct_nextFileQString.append(separator);
   // tempQStMAIN.indexOf(separator) ? tempQStMAIN = tempQStMAIN.append(separator) : tempQStMAIN = tempQStMAIN;

    QString TempQstab = correct_nextFileQString;
    QString TempQS_less_and_less = correct_nextFileQString;



    for(int i = 0; i < 5; i++)
    {
       int pos = TempQS_less_and_less.indexOf(separator); //5
       TempQstab = TempQstab.remove(pos, 50); //usuwamy reszte stringa
       newQTab_Return[i] = TempQstab;
       TempQS_less_and_less = TempQS_less_and_less.remove(0, pos+1); // usuwamy stringa juz przeslanego, do tablicy
       TempQstab = TempQS_less_and_less;
    }

    QString part_5 = newQTab_Return[4];
    QString year_in_string = newQTab_Return[4];
    int pos_year_present = part_5.lastIndexOf(".") + 1; //10

    const QString year_present = year_in_string.remove(0, pos_year_present); // 2016 or 16
    const int year_present_size = year_present.size(); // 2 or 4
    QString year_present1 = year_present;
    QString year_present2 = year_present;

    QString year_long = year_present_size == 4 ? year_present1 = year_present1 : year_present1 = year_present1.prepend("20"); //2016
    QString year_short = year_present_size == 2 ? year_present2 = year_present2 : year_present2 = year_present2.remove(0, 2); //16
    int year_long_size = year_long.size(); //4
    int year_short_size = year_short.size(); //2



   /* QString x = "Say yes!";
    QString y = "no";
    x.replace(4, 3, y);
    // x == "Say no!"
    fileName.isEmpty() ? QStringLiteral("*") : fileName, &files);*/

    newQTab_Return[5] = part_5.replace(pos_year_present,
                                       year_present_size == year_long_size ? year_long_size : year_short_size,
                                       year_present == year_long ? year_short : year_long);

    return newQTab_Return;
}

void MainWindow::on_pushButton_Test_clicked()
{
    ui->listWidget_Errors -> clear();
    QString mask = ui->comboBox_Mask->currentText();
    QString sep = ui->lineEdit_Sep->text();

    QString mask_correct = mask;
    mask_correct = mask_correct.remove(0, 1); //.pdf
    QString *Tab_QStrFile2 = QString_to_Tab("PK-120616_10.0001-R2016-Z0020-WET.P.332.2016" + mask_correct, 5, sep, mask); //
    QStringList lists;
    lists << Tab_QStrFile2[0] << Tab_QStrFile2[1] << Tab_QStrFile2[2] << Tab_QStrFile2[3] << Tab_QStrFile2[4];
    ui->listWidget_Errors -> addItems(lists);
}

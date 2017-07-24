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
QString maska_pdf = "pdf";
QString maska_doc = "doc";
QString rowne = "=";
QString rozne = "<>";
QString wcale = "żadne";
QStringList ListReg = (QStringList() << rowne << rozne);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox_Maska->addItem(maska_pdf);
    ui->comboBox_Maska->addItem(maska_doc);
    ui->checkBox_CalaNazwa ->setChecked(false);
    ui->checkBox_Nazwa1 -> setChecked(true);
    ui->checkBox_Nazwa2 -> setChecked(true);
    ui->checkBox_Nazwa3 -> setChecked(true);
    ui->checkBox_Nazwa4 -> setChecked(true);
    ui->checkBox_Nazwa5 -> setChecked(true);

    ui->comboBox_Reg1->addItems(ListReg);
    ui->comboBox_Reg2->addItems(ListReg);
    ui->comboBox_Reg3->addItems(ListReg);
    ui->comboBox_Reg4->addItems(ListReg);
    ui->comboBox_Reg5->addItems(ListReg);
//    connect(ui->comboBox_Modul4->lineEdit(), &QLineEdit::returnPressed,
//           this, &MainWindow::animateFindingClick);
    connect(ui->pushButton_Browse, &QAbstractButton::windowTitleChanged, this, &MainWindow::on_pushButton_Browse_clicked);
    connect(ui->comboBox_Browse, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_pushButton_Analyse_clicked);
    QObject::connect(ui->comboBox_Maska, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_pushButton_Analyse_clicked);
    //ustawienie blokad
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa1, SLOT(setChecked(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->comboBox_Reg1, SLOT(setDisabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa1, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Nazwa1, SIGNAL(toggled(bool)), ui->lineEdit_Cz1, SLOT(setEnabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa2, SLOT(setChecked(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->comboBox_Reg2, SLOT(setDisabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa2, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Nazwa2, SIGNAL(toggled(bool)), ui->lineEdit_Cz2, SLOT(setEnabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa3, SLOT(setChecked(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->comboBox_Reg3, SLOT(setDisabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa3, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Nazwa3, SIGNAL(toggled(bool)), ui->lineEdit_Cz3, SLOT(setEnabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa4, SLOT(setChecked(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->comboBox_Reg4, SLOT(setDisabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa4, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Nazwa4, SIGNAL(toggled(bool)), ui->lineEdit_Cz4, SLOT(setEnabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa5, SLOT(setChecked(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->comboBox_Reg5, SLOT(setDisabled(bool)));
    connect(ui->checkBox_CalaNazwa, SIGNAL(toggled(bool)), ui->checkBox_Nazwa5, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Nazwa5, SIGNAL(toggled(bool)), ui->lineEdit_Cz5, SLOT(setEnabled(bool)));
    connect(ui->lineEdit_Cz1, SIGNAL(textChanged(const QString &)), this, SLOT(text()));

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
    QString string1;
    QString string2;
    QString string3;
    QString string4;
    QString string5;
    string1 = ui->lineEdit_Cz1 ->text();
    string2 = ui->lineEdit_Cz2 ->text();
    string3 = ui->lineEdit_Cz3 ->text();
    string4 = ui->lineEdit_Cz4 ->text();
    string5 = ui->lineEdit_Cz5 ->text();
    all_string = string1 + string2 + string3 + string4 + string5;
    ui->label_Test ->setText("Szukany string: "+ all_string + "." + ui->comboBox_Maska->currentText());

    QDir myPath = ui->comboBox_Browse->currentText();
    myPath.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    myList = myPath.entryList();

    ui->listWidget_Zdubl->addItems(myList);
    ui->label_Total->setText(QString("%1").arg(ui->listWidget_Zdubl->count()));
    QString targetString = all_string; // What we search for
    QFileInfoList hitList; // Container for matches
    QString directory = ui->comboBox_Browse->currentText(); // Where to search
    QDirIterator iterator(directory, QDirIterator::Subdirectories);

    // Iterate through the directory using the QDirIterator

    while (iterator.hasNext())
    {
        //zwraca false jesli nie napotka direct lub true,

        QString filename = iterator.next(); //przejscie iteraotra do kolejnego wejscia
        QFileInfo file(filename);
        QStringList QString_hit_List;
        if (file.isDir()) { // Check if it's a dir
            continue;
        }

        // If the filename contains target string - put it in the hitlist
        if (file.fileName().contains(targetString, Qt::CaseInsensitive)) {
            QListWidgetItem *item = new QListWidgetItem(filename);
            ui->listWidget_Zdubl->addItem(item);
            hitList.append(file);
        }
    }
    foreach (QFileInfo hit, hitList) { //drugi argument czyli kontener, którego typ wartości odpowiada typowi zmiennej.
  //  QString_hit_List << hit.absoluteFilePath();
}
}

void MainWindow::on_pushButton_MIME_clicked()
{
    QString path("/home/my_user/my_file");
    #if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        QMimeDatabase db;
        QMimeType type = db.mimeTypeForFile(path);
      // std::cout << "Mime type:" << type.name();
    #endif
    QMessageBox::about(this, "Title", "Mime type: " + type.name());
}

void  MainWindow::animateFindingClick()
{
    ui->pushButton_Analyse->animateClick();
}


void MainWindow::on_lineEditFilter_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    ui->listWidget_Zdubl->clear();
    ui->listWidget_Zdubl->addItems(myList.filter(regExp));
    ui->label_Total->setText(QString("%1").arg(ui->listWidget_Zdubl->count()));
}

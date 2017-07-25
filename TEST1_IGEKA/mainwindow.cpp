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

QString mask_pdf = "pdf";
QString mask_doc = "doc";
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
//    connect(ui->comboBox_Modul4->lineEdit(), &QLineEdit::returnPressed,
//           this, &MainWindow::animateFindingClick);
    connect(ui->pushButton_Analyse, &QAbstractButton::clicked, this, &MainWindow::find);
    connect(ui->pushButton_Browse, &QAbstractButton::windowTitleChanged, this, &MainWindow::on_pushButton_Browse_clicked);
    connect(ui->comboBox_Browse, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_pushButton_Analyse_clicked);
    QObject::connect(ui->comboBox_Mask, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_pushButton_Analyse_clicked);
    //ustawienie blokad
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name1, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg1, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name1, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name1, SIGNAL(toggled(bool)), ui->lineEdit_Name1, SLOT(setEnabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name2, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg2, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name2, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name2, SIGNAL(toggled(bool)), ui->lineEdit_Name2, SLOT(setEnabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name3, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg3, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name3, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name3, SIGNAL(toggled(bool)), ui->lineEdit_Name3, SLOT(setEnabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name4, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg4, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name4, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name4, SIGNAL(toggled(bool)), ui->lineEdit_Name4, SLOT(setEnabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name5, SLOT(setChecked(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->comboBox_Reg5, SLOT(setDisabled(bool)));
    connect(ui->checkBox_FullName, SIGNAL(toggled(bool)), ui->checkBox_Name5, SLOT(setDisabled(bool)));
    connect(ui->checkBox_Name5, SIGNAL(toggled(bool)), ui->lineEdit_Name5, SLOT(setEnabled(bool)));
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
    QString string1;
    QString string2;
    QString string3;
    QString string4;
    QString string5;

    QString sep1 = ui->label_Sep1 ->text();
    QString sep2 = ui->label_Sep2 ->text();
    QString sep3 = ui->label_Sep3 ->text();
    QString sep4 = ui->label_Sep4 ->text();
    string1 = ui->lineEdit_Name1 ->text();
    string2 = ui->lineEdit_Name2 ->text();
    string3 = ui->lineEdit_Name3 ->text();
    string4 = ui->lineEdit_Name4 ->text();
    string5 = ui->lineEdit_Name5 ->text();
    all_string = string1 + sep1 + string2 + sep2 + string3 + sep3 + string4 + sep4 + string5;
    ui->label_Test ->setText("Szukany string: "+ all_string + "." + ui->comboBox_Mask->currentText());
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

void MainWindow::on_lineEdit_Sep_textChanged(const QString &arg1)
{
    ui->label_Sep1->setText(arg1);
    ui->label_Sep2->setText(arg1);
    ui->label_Sep3->setText(arg1);
    ui->label_Sep4->setText(arg1);
}

void MainWindow::on_lineEditFilter_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    ui->listWidget_Errors->clear();
    ui->listWidget_Errors->addItems(myList.filter(regExp));
    ui->label_Total->setText(QString("%1").arg(ui->listWidget_Errors->count()));
}


static void findRecursion(const QString &path, const QString &pattern, QStringList *result)
{

    QDir currentDir(path);
    const QString prefix = path + QLatin1Char('/');
    foreach (const QString &match, currentDir.entryList(QStringList(pattern), QDir::Files | QDir::NoSymLinks))
        result->append(prefix + match);
    foreach (const QString &dir, currentDir.entryList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot))
        findRecursion(prefix + dir, pattern, result);
}

void MainWindow::find()
{
    ui->listWidget_Results->clear();

    QString string1;
    QString string2;
    QString string3;
    QString string4;
    QString string5;
    QString sep1 = ui->label_Sep1 ->text();
    QString sep2 = ui->label_Sep2 ->text();
    QString sep3 = ui->label_Sep3 ->text();
    QString sep4 = ui->label_Sep4 ->text();
    string1 = ui->lineEdit_Name1 ->text();
    string2 = ui->lineEdit_Name2 ->text();
    string3 = ui->lineEdit_Name3 ->text();
    string4 = ui->lineEdit_Name4 ->text();
    string5 = ui->lineEdit_Name5 ->text();
    all_string = string1 + sep1 + string2 + sep2 + string3 + sep3 + string4 + sep4 + string5;
    QString fileName = all_string;
 //   QString text = ui ->textComboBox->currentText();
    QString path = QDir::cleanPath(ui->comboBox_Browse->currentText());
    updateComboBox(ui->comboBox_Browse);

    currentDir = QDir(path);
    QStringList files;
    findRecursion(path, fileName.isEmpty() ? QStringLiteral("*") : fileName, &files);
    //if (!text.isEmpty())
    //files = findFiles(files, text);     ///!!!
    showFiles2(files);                     ///!!!
}
/*QStringList MainWindow::findFiles(const QStringList &files, const QString &text)
{
    QProgressDialog progressDialog(this);
    progressDialog.setCancelButtonText(tr("&Cancel"));
    progressDialog.setRange(0, files.size());
    progressDialog.setWindowTitle(tr("Find Files"));

    QMimeDatabase mimeDatabase;
    QStringList foundFiles;

    for (int i = 0; i < files.size(); ++i) {
        progressDialog.setValue(i);
        progressDialog.setLabelText(tr("Searching file number %1 of %n...", 0, files.size()).arg(i));
        QCoreApplication::processEvents();


        if (progressDialog.wasCanceled())
            break;

        const QString fileName = files.at(i);
        const QMimeType mimeType = mimeDatabase.mimeTypeForFile(fileName);
        if (mimeType.isValid() && !mimeType.inherits(QStringLiteral("text/plain"))) {
            qWarning() << "Not searching binary file " << QDir::toNativeSeparators(fileName);
            continue;
        }
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            QString line;
            QTextStream in(&file);
            while (!in.atEnd()) {
                if (progressDialog.wasCanceled())
                    break;
                line = in.readLine();
                if (line.contains(text, Qt::CaseInsensitive)) {
                    foundFiles << files[i];
                    break;
                }
            }
        }
    }
    return foundFiles;
}*/

/*void MainWindow::showFiles(const QStringList &files)
{
    for (int i = 0; i < files.size(); ++i) {
        const QString &fileName = files.at(i);
        const QString toolTip = QDir::toNativeSeparators(fileName);
        const QString relativePath = QDir::toNativeSeparators(currentDir.relativeFilePath(fileName));
        const qint64 size = QFileInfo(fileName).size();
        QTableWidgetItem *fileNameItem = new QTableWidgetItem(relativePath);
        fileNameItem->setData(absoluteFileNameRole, QVariant(fileName));
        fileNameItem->setToolTip(toolTip);
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *sizeItem = new QTableWidgetItem(tr("%1 KB")
                                             .arg(int((size + 1023) / 1024)));
        sizeItem->setData(absoluteFileNameRole, QVariant(fileName));
        sizeItem->setToolTip(toolTip);
        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);

        int row = filesTable->rowCount();
        filesTable->insertRow(row);
        filesTable->setItem(row, 0, fileNameItem);
        filesTable->setItem(row, 1, sizeItem);
    }
    filesFoundLabel->setText(tr("%n file(s) found (Double click on a file to open it)", 0, files.size()));
    filesFoundLabel->setWordWrap(true);
}*/
void MainWindow::showFiles2(const QStringList &files)
{
    ui->listWidget_Results->addItems(files);
}


void MainWindow::on_pushButton_Find_clicked()
{
    find();
}

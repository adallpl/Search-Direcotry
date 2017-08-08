#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString all_string;

private slots:
    void on_pushButton_Browse_clicked();
    void on_pushButton_Analyse_clicked();
    void animateFindingClick();
    void Find_by();
    void on_lineEdit_Sep_textChanged(const QString &arg1);
    void on_pushButton_Test_clicked();

private:
    Ui::MainWindow *ui;
    QStringList myList;
    void showFiles(const QStringList &files);
    bool ismatch(const QString &next_file_name, const QString string1, const QString string2, const QString string3,
                 const QString string4, const QString string5, const QString &separator, const QString &filter);
    QString *QString_to_Tab(const QString &FileQString, int size, const QString &separator, const QString &mask);
    QDir currentDir;
};

#endif // MAINWINDOW_H

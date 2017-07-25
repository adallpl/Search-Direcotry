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
    void on_pushButton_MIME_clicked();
    void on_lineEditFilter_textChanged(const QString &arg1);
    void find();
    void on_lineEdit_Sep_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStringList myList;
    void showFiles(const QStringList &files);
    void showFiles2(const QStringList &files);
   // QStringList findFiles(const QStringList &files, const QString &text);
    QDir currentDir;
};

#endif // MAINWINDOW_H

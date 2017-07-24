/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_Kat;
    QPushButton *pushButton_Browse;
    QComboBox *comboBox_Browse;
    QGroupBox *groupBox_Maska;
    QLabel *label_Maska;
    QComboBox *comboBox_Maska;
    QGroupBox *groupBox_NazwPlik;
    QLabel *label_Sep1;
    QLabel *label_Sep2;
    QLabel *label_Sep3;
    QLabel *label_Sep4;
    QCheckBox *checkBox_Nazwa5;
    QCheckBox *checkBox_Nazwa2;
    QCheckBox *checkBox_Nazwa1;
    QCheckBox *checkBox_Nazwa3;
    QCheckBox *checkBox_Nazwa4;
    QComboBox *comboBox_Reg1;
    QComboBox *comboBox_Reg2;
    QComboBox *comboBox_Reg3;
    QComboBox *comboBox_Reg4;
    QComboBox *comboBox_Reg5;
    QLabel *label_3;
    QCheckBox *checkBox_CalaNazwa;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_Cz4;
    QLineEdit *lineEdit_Cz2;
    QLineEdit *lineEdit_Cz1;
    QLineEdit *lineEdit_Cz5;
    QLineEdit *lineEdit_Cz3;
    QPushButton *pushButton_Analyse;
    QPushButton *pushButton_MIME;
    QListWidget *listWidget_Zdubl;
    QListWidget *listWidget_Bledy;
    QLabel *label_Test;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_9;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Filter;
    QLineEdit *lineEditFilter;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_Total;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(867, 699);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_Kat = new QGroupBox(centralWidget);
        groupBox_Kat->setObjectName(QStringLiteral("groupBox_Kat"));
        groupBox_Kat->setGeometry(QRect(20, 10, 651, 91));
        pushButton_Browse = new QPushButton(groupBox_Kat);
        pushButton_Browse->setObjectName(QStringLiteral("pushButton_Browse"));
        pushButton_Browse->setGeometry(QRect(12, 38, 85, 23));
        comboBox_Browse = new QComboBox(groupBox_Kat);
        comboBox_Browse->setObjectName(QStringLiteral("comboBox_Browse"));
        comboBox_Browse->setGeometry(QRect(11, 11, 581, 20));
        groupBox_Maska = new QGroupBox(centralWidget);
        groupBox_Maska->setObjectName(QStringLiteral("groupBox_Maska"));
        groupBox_Maska->setGeometry(QRect(670, 10, 141, 81));
        label_Maska = new QLabel(groupBox_Maska);
        label_Maska->setObjectName(QStringLiteral("label_Maska"));
        label_Maska->setGeometry(QRect(11, 45, 65, 16));
        comboBox_Maska = new QComboBox(groupBox_Maska);
        comboBox_Maska->setObjectName(QStringLiteral("comboBox_Maska"));
        comboBox_Maska->setGeometry(QRect(11, 11, 69, 20));
        groupBox_NazwPlik = new QGroupBox(centralWidget);
        groupBox_NazwPlik->setObjectName(QStringLiteral("groupBox_NazwPlik"));
        groupBox_NazwPlik->setGeometry(QRect(20, 110, 821, 121));
        label_Sep1 = new QLabel(groupBox_NazwPlik);
        label_Sep1->setObjectName(QStringLiteral("label_Sep1"));
        label_Sep1->setGeometry(QRect(122, 23, 16, 16));
        label_Sep2 = new QLabel(groupBox_NazwPlik);
        label_Sep2->setObjectName(QStringLiteral("label_Sep2"));
        label_Sep2->setGeometry(QRect(254, 23, 16, 16));
        label_Sep3 = new QLabel(groupBox_NazwPlik);
        label_Sep3->setObjectName(QStringLiteral("label_Sep3"));
        label_Sep3->setGeometry(QRect(385, 23, 16, 16));
        label_Sep4 = new QLabel(groupBox_NazwPlik);
        label_Sep4->setObjectName(QStringLiteral("label_Sep4"));
        label_Sep4->setGeometry(QRect(517, 23, 16, 16));
        checkBox_Nazwa5 = new QCheckBox(groupBox_NazwPlik);
        checkBox_Nazwa5->setObjectName(QStringLiteral("checkBox_Nazwa5"));
        checkBox_Nazwa5->setGeometry(QRect(79, 53, 16, 16));
        checkBox_Nazwa2 = new QCheckBox(groupBox_NazwPlik);
        checkBox_Nazwa2->setObjectName(QStringLiteral("checkBox_Nazwa2"));
        checkBox_Nazwa2->setGeometry(QRect(22, 53, 16, 16));
        checkBox_Nazwa1 = new QCheckBox(groupBox_NazwPlik);
        checkBox_Nazwa1->setObjectName(QStringLiteral("checkBox_Nazwa1"));
        checkBox_Nazwa1->setGeometry(QRect(3, 53, 16, 16));
        checkBox_Nazwa3 = new QCheckBox(groupBox_NazwPlik);
        checkBox_Nazwa3->setObjectName(QStringLiteral("checkBox_Nazwa3"));
        checkBox_Nazwa3->setGeometry(QRect(41, 53, 16, 16));
        checkBox_Nazwa4 = new QCheckBox(groupBox_NazwPlik);
        checkBox_Nazwa4->setObjectName(QStringLiteral("checkBox_Nazwa4"));
        checkBox_Nazwa4->setGeometry(QRect(60, 53, 16, 16));
        comboBox_Reg1 = new QComboBox(groupBox_NazwPlik);
        comboBox_Reg1->setObjectName(QStringLiteral("comboBox_Reg1"));
        comboBox_Reg1->setGeometry(QRect(2, 92, 69, 20));
        comboBox_Reg2 = new QComboBox(groupBox_NazwPlik);
        comboBox_Reg2->setObjectName(QStringLiteral("comboBox_Reg2"));
        comboBox_Reg2->setGeometry(QRect(123, 92, 69, 20));
        comboBox_Reg3 = new QComboBox(groupBox_NazwPlik);
        comboBox_Reg3->setObjectName(QStringLiteral("comboBox_Reg3"));
        comboBox_Reg3->setGeometry(QRect(244, 92, 69, 20));
        comboBox_Reg4 = new QComboBox(groupBox_NazwPlik);
        comboBox_Reg4->setObjectName(QStringLiteral("comboBox_Reg4"));
        comboBox_Reg4->setGeometry(QRect(365, 92, 69, 20));
        comboBox_Reg5 = new QComboBox(groupBox_NazwPlik);
        comboBox_Reg5->setObjectName(QStringLiteral("comboBox_Reg5"));
        comboBox_Reg5->setGeometry(QRect(486, 92, 69, 20));
        label_3 = new QLabel(groupBox_NazwPlik);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(660, 60, 125, 16));
        checkBox_CalaNazwa = new QCheckBox(groupBox_NazwPlik);
        checkBox_CalaNazwa->setObjectName(QStringLiteral("checkBox_CalaNazwa"));
        checkBox_CalaNazwa->setGeometry(QRect(661, 21, 16, 16));
        label_2 = new QLabel(groupBox_NazwPlik);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(680, 21, 74, 16));
        label = new QLabel(groupBox_NazwPlik);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 90, 88, 22));
        lineEdit_Cz4 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Cz4->setObjectName(QStringLiteral("lineEdit_Cz4"));
        lineEdit_Cz4->setGeometry(QRect(398, 24, 112, 20));
        lineEdit_Cz2 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Cz2->setObjectName(QStringLiteral("lineEdit_Cz2"));
        lineEdit_Cz2->setGeometry(QRect(135, 24, 112, 20));
        lineEdit_Cz1 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Cz1->setObjectName(QStringLiteral("lineEdit_Cz1"));
        lineEdit_Cz1->setGeometry(QRect(4, 24, 111, 20));
        lineEdit_Cz5 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Cz5->setObjectName(QStringLiteral("lineEdit_Cz5"));
        lineEdit_Cz5->setGeometry(QRect(530, 24, 111, 20));
        lineEdit_Cz3 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Cz3->setObjectName(QStringLiteral("lineEdit_Cz3"));
        lineEdit_Cz3->setGeometry(QRect(267, 24, 111, 20));
        lineEdit_Cz4->raise();
        lineEdit_Cz2->raise();
        lineEdit_Cz1->raise();
        lineEdit_Cz5->raise();
        lineEdit_Cz3->raise();
        label_Sep1->raise();
        label_Sep2->raise();
        label_Sep3->raise();
        label_Sep4->raise();
        checkBox_Nazwa5->raise();
        checkBox_Nazwa2->raise();
        checkBox_Nazwa1->raise();
        checkBox_Nazwa3->raise();
        checkBox_Nazwa4->raise();
        comboBox_Reg1->raise();
        comboBox_Reg2->raise();
        comboBox_Reg3->raise();
        comboBox_Reg4->raise();
        comboBox_Reg5->raise();
        label_3->raise();
        checkBox_CalaNazwa->raise();
        label_2->raise();
        label->raise();
        pushButton_Analyse = new QPushButton(centralWidget);
        pushButton_Analyse->setObjectName(QStringLiteral("pushButton_Analyse"));
        pushButton_Analyse->setGeometry(QRect(30, 230, 75, 23));
        pushButton_MIME = new QPushButton(centralWidget);
        pushButton_MIME->setObjectName(QStringLiteral("pushButton_MIME"));
        pushButton_MIME->setGeometry(QRect(130, 230, 111, 23));
        listWidget_Zdubl = new QListWidget(centralWidget);
        listWidget_Zdubl->setObjectName(QStringLiteral("listWidget_Zdubl"));
        listWidget_Zdubl->setGeometry(QRect(10, 260, 491, 241));
        listWidget_Bledy = new QListWidget(centralWidget);
        listWidget_Bledy->setObjectName(QStringLiteral("listWidget_Bledy"));
        listWidget_Bledy->setGeometry(QRect(530, 260, 191, 241));
        label_Test = new QLabel(centralWidget);
        label_Test->setObjectName(QStringLiteral("label_Test"));
        label_Test->setGeometry(QRect(270, 230, 521, 16));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 510, 165, 73));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_Filter = new QLabel(widget);
        label_Filter->setObjectName(QStringLiteral("label_Filter"));

        horizontalLayout->addWidget(label_Filter);

        lineEditFilter = new QLineEdit(widget);
        lineEditFilter->setObjectName(QStringLiteral("lineEditFilter"));

        horizontalLayout->addWidget(lineEditFilter);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 590, 171, 16));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_Total = new QLabel(widget1);
        label_Total->setObjectName(QStringLiteral("label_Total"));

        horizontalLayout_2->addWidget(label_Total);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox_Kat->raise();
        groupBox_Maska->raise();
        groupBox_NazwPlik->raise();
        pushButton_Analyse->raise();
        pushButton_MIME->raise();
        listWidget_Zdubl->raise();
        listWidget_Bledy->raise();
        label_Test->raise();
        label_Filter->raise();
        lineEditFilter->raise();
        label_4->raise();
        label_Total->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 867, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_Kat->setTitle(QString());
        pushButton_Browse->setText(QApplication::translate("MainWindow", "Wybierz katalog", Q_NULLPTR));
        groupBox_Maska->setTitle(QString());
        label_Maska->setText(QApplication::translate("MainWindow", "Maska og\303\263lna", Q_NULLPTR));
        groupBox_NazwPlik->setTitle(QApplication::translate("MainWindow", "Definicja cz\304\231\305\233ci nazw pliku", Q_NULLPTR));
        label_Sep1->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        label_Sep2->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        label_Sep3->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        label_Sep4->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        checkBox_Nazwa5->setText(QString());
        checkBox_Nazwa2->setText(QString());
        checkBox_Nazwa1->setText(QString());
        checkBox_Nazwa3->setText(QString());
        checkBox_Nazwa4->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Pomi\305\204 cz\304\231\305\233\304\207 przy szukaniu", Q_NULLPTR));
        checkBox_CalaNazwa->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Po ca\305\202ej nazwie", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Regu\305\202y zdublowa\305\204", Q_NULLPTR));
        pushButton_Analyse->setText(QApplication::translate("MainWindow", "Analyse", Q_NULLPTR));
        pushButton_MIME->setText(QApplication::translate("MainWindow", "Check MIME Type", Q_NULLPTR));
        label_Test->setText(QString());
        label_Filter->setText(QApplication::translate("MainWindow", "Filter", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Total:", Q_NULLPTR));
        label_Total->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

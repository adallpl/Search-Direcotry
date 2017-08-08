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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
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
    QComboBox *comboBox_Mask;
    QGroupBox *groupBox_NazwPlik;
    QLabel *label_Sep1;
    QLabel *label_Sep2;
    QLabel *label_Sep3;
    QLabel *label_Sep4;
    QLabel *label_3;
    QCheckBox *checkBox_FullName;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_Name4;
    QLineEdit *lineEdit_Name2;
    QLineEdit *lineEdit_Name1;
    QLineEdit *lineEdit_Name5;
    QLineEdit *lineEdit_Name3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_Name1;
    QCheckBox *checkBox_Name2;
    QCheckBox *checkBox_Name3;
    QCheckBox *checkBox_Name4;
    QCheckBox *checkBox_Name5;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_Reg1;
    QComboBox *comboBox_Reg2;
    QComboBox *comboBox_Reg3;
    QComboBox *comboBox_Reg4;
    QComboBox *comboBox_Reg5;
    QPushButton *pushButton_Analyse;
    QListWidget *listWidget_Results;
    QListWidget *listWidget_Errors;
    QLabel *label_Test;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_9;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Sep;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Sep;
    QPushButton *pushButton_Test;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(867, 690);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_Kat = new QGroupBox(centralWidget);
        groupBox_Kat->setObjectName(QStringLiteral("groupBox_Kat"));
        groupBox_Kat->setGeometry(QRect(20, 10, 651, 61));
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
        comboBox_Mask = new QComboBox(groupBox_Maska);
        comboBox_Mask->setObjectName(QStringLiteral("comboBox_Mask"));
        comboBox_Mask->setGeometry(QRect(11, 11, 69, 20));
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
        label_3 = new QLabel(groupBox_NazwPlik);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(660, 60, 125, 16));
        checkBox_FullName = new QCheckBox(groupBox_NazwPlik);
        checkBox_FullName->setObjectName(QStringLiteral("checkBox_FullName"));
        checkBox_FullName->setGeometry(QRect(661, 21, 16, 16));
        label_2 = new QLabel(groupBox_NazwPlik);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(680, 21, 74, 16));
        label = new QLabel(groupBox_NazwPlik);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 90, 88, 22));
        lineEdit_Name4 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Name4->setObjectName(QStringLiteral("lineEdit_Name4"));
        lineEdit_Name4->setGeometry(QRect(398, 24, 112, 20));
        lineEdit_Name2 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Name2->setObjectName(QStringLiteral("lineEdit_Name2"));
        lineEdit_Name2->setGeometry(QRect(135, 24, 112, 20));
        lineEdit_Name1 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Name1->setObjectName(QStringLiteral("lineEdit_Name1"));
        lineEdit_Name1->setGeometry(QRect(4, 24, 111, 20));
        lineEdit_Name5 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Name5->setObjectName(QStringLiteral("lineEdit_Name5"));
        lineEdit_Name5->setGeometry(QRect(530, 24, 111, 20));
        lineEdit_Name3 = new QLineEdit(groupBox_NazwPlik);
        lineEdit_Name3->setObjectName(QStringLiteral("lineEdit_Name3"));
        lineEdit_Name3->setGeometry(QRect(267, 24, 111, 20));
        layoutWidget = new QWidget(groupBox_NazwPlik);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(3, 53, 661, 16));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBox_Name1 = new QCheckBox(layoutWidget);
        checkBox_Name1->setObjectName(QStringLiteral("checkBox_Name1"));

        horizontalLayout_4->addWidget(checkBox_Name1);

        checkBox_Name2 = new QCheckBox(layoutWidget);
        checkBox_Name2->setObjectName(QStringLiteral("checkBox_Name2"));

        horizontalLayout_4->addWidget(checkBox_Name2);

        checkBox_Name3 = new QCheckBox(layoutWidget);
        checkBox_Name3->setObjectName(QStringLiteral("checkBox_Name3"));

        horizontalLayout_4->addWidget(checkBox_Name3);

        checkBox_Name4 = new QCheckBox(layoutWidget);
        checkBox_Name4->setObjectName(QStringLiteral("checkBox_Name4"));

        horizontalLayout_4->addWidget(checkBox_Name4);

        checkBox_Name5 = new QCheckBox(layoutWidget);
        checkBox_Name5->setObjectName(QStringLiteral("checkBox_Name5"));

        horizontalLayout_4->addWidget(checkBox_Name5);

        layoutWidget1 = new QWidget(groupBox_NazwPlik);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(2, 92, 651, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox_Reg1 = new QComboBox(layoutWidget1);
        comboBox_Reg1->setObjectName(QStringLiteral("comboBox_Reg1"));

        horizontalLayout_5->addWidget(comboBox_Reg1);

        comboBox_Reg2 = new QComboBox(layoutWidget1);
        comboBox_Reg2->setObjectName(QStringLiteral("comboBox_Reg2"));

        horizontalLayout_5->addWidget(comboBox_Reg2);

        comboBox_Reg3 = new QComboBox(layoutWidget1);
        comboBox_Reg3->setObjectName(QStringLiteral("comboBox_Reg3"));

        horizontalLayout_5->addWidget(comboBox_Reg3);

        comboBox_Reg4 = new QComboBox(layoutWidget1);
        comboBox_Reg4->setObjectName(QStringLiteral("comboBox_Reg4"));

        horizontalLayout_5->addWidget(comboBox_Reg4);

        comboBox_Reg5 = new QComboBox(layoutWidget1);
        comboBox_Reg5->setObjectName(QStringLiteral("comboBox_Reg5"));

        horizontalLayout_5->addWidget(comboBox_Reg5);

        layoutWidget->raise();
        layoutWidget->raise();
        lineEdit_Name4->raise();
        lineEdit_Name2->raise();
        lineEdit_Name1->raise();
        lineEdit_Name5->raise();
        lineEdit_Name3->raise();
        label_Sep1->raise();
        label_Sep2->raise();
        label_Sep3->raise();
        label_Sep4->raise();
        label_3->raise();
        checkBox_FullName->raise();
        label_2->raise();
        label->raise();
        pushButton_Analyse = new QPushButton(centralWidget);
        pushButton_Analyse->setObjectName(QStringLiteral("pushButton_Analyse"));
        pushButton_Analyse->setGeometry(QRect(20, 230, 75, 23));
        listWidget_Results = new QListWidget(centralWidget);
        listWidget_Results->setObjectName(QStringLiteral("listWidget_Results"));
        listWidget_Results->setGeometry(QRect(10, 260, 551, 151));
        listWidget_Errors = new QListWidget(centralWidget);
        listWidget_Errors->setObjectName(QStringLiteral("listWidget_Errors"));
        listWidget_Errors->setGeometry(QRect(570, 260, 271, 241));
        label_Test = new QLabel(centralWidget);
        label_Test->setObjectName(QStringLiteral("label_Test"));
        label_Test->setGeometry(QRect(100, 230, 481, 21));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(40, 80, 211, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Sep = new QLabel(layoutWidget4);
        label_Sep->setObjectName(QStringLiteral("label_Sep"));

        horizontalLayout_3->addWidget(label_Sep);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        lineEdit_Sep = new QLineEdit(layoutWidget4);
        lineEdit_Sep->setObjectName(QStringLiteral("lineEdit_Sep"));

        horizontalLayout_3->addWidget(lineEdit_Sep);

        pushButton_Test = new QPushButton(centralWidget);
        pushButton_Test->setObjectName(QStringLiteral("pushButton_Test"));
        pushButton_Test->setGeometry(QRect(570, 500, 75, 23));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 430, 551, 192));
        tableWidget->setShowGrid(false);
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox_Kat->raise();
        groupBox_Maska->raise();
        groupBox_NazwPlik->raise();
        pushButton_Analyse->raise();
        listWidget_Results->raise();
        listWidget_Errors->raise();
        label_Test->raise();
        pushButton_Test->raise();
        tableWidget->raise();
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
        QWidget::setTabOrder(comboBox_Browse, pushButton_Browse);
        QWidget::setTabOrder(pushButton_Browse, comboBox_Mask);
        QWidget::setTabOrder(comboBox_Mask, lineEdit_Sep);
        QWidget::setTabOrder(lineEdit_Sep, lineEdit_Name1);
        QWidget::setTabOrder(lineEdit_Name1, lineEdit_Name2);
        QWidget::setTabOrder(lineEdit_Name2, lineEdit_Name3);
        QWidget::setTabOrder(lineEdit_Name3, lineEdit_Name4);
        QWidget::setTabOrder(lineEdit_Name4, lineEdit_Name5);
        QWidget::setTabOrder(lineEdit_Name5, checkBox_FullName);
        QWidget::setTabOrder(checkBox_FullName, checkBox_Name1);
        QWidget::setTabOrder(checkBox_Name1, checkBox_Name2);
        QWidget::setTabOrder(checkBox_Name2, checkBox_Name3);
        QWidget::setTabOrder(checkBox_Name3, checkBox_Name4);
        QWidget::setTabOrder(checkBox_Name4, checkBox_Name5);
        QWidget::setTabOrder(checkBox_Name5, comboBox_Reg1);
        QWidget::setTabOrder(comboBox_Reg1, comboBox_Reg2);
        QWidget::setTabOrder(comboBox_Reg2, comboBox_Reg3);
        QWidget::setTabOrder(comboBox_Reg3, comboBox_Reg4);
        QWidget::setTabOrder(comboBox_Reg4, comboBox_Reg5);
        QWidget::setTabOrder(comboBox_Reg5, pushButton_Analyse);
        QWidget::setTabOrder(pushButton_Analyse, listWidget_Results);
        QWidget::setTabOrder(listWidget_Results, listWidget_Errors);
        QWidget::setTabOrder(listWidget_Errors, pushButton_Test);

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
        label_Sep1->setText(QString());
        label_Sep2->setText(QString());
        label_Sep3->setText(QString());
        label_Sep4->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Pomi\305\204 cz\304\231\305\233\304\207 przy szukaniu", Q_NULLPTR));
        checkBox_FullName->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Po ca\305\202ej nazwie", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Regu\305\202y zdublowa\305\204", Q_NULLPTR));
        checkBox_Name1->setText(QString());
        checkBox_Name2->setText(QString());
        checkBox_Name3->setText(QString());
        checkBox_Name4->setText(QString());
        checkBox_Name5->setText(QString());
        pushButton_Analyse->setText(QApplication::translate("MainWindow", "Analyse", Q_NULLPTR));
        label_Test->setText(QString());
        label_Sep->setText(QApplication::translate("MainWindow", "Podaj separator", Q_NULLPTR));
        pushButton_Test->setText(QApplication::translate("MainWindow", "Test Button", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

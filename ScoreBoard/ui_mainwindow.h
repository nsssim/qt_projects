/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QPushButton *team_one_btn;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QToolButton *score_reset_btn;
    QToolButton *admin_btn;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QPushButton *team_two_btn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(743, 348);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Seven Segment"));
        font.setPointSize(20);
        font.setBold(false);
        groupBox->setFont(font);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        team_one_btn = new QPushButton(groupBox);
        team_one_btn->setObjectName(QString::fromUtf8("team_one_btn"));
        team_one_btn->setEnabled(true);
        team_one_btn->setGeometry(QRect(40, 50, 251, 251));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(team_one_btn->sizePolicy().hasHeightForWidth());
        team_one_btn->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Seven Segment"));
        font1.setPointSize(40);
        font1.setBold(false);
        team_one_btn->setFont(font1);

        horizontalLayout->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        score_reset_btn = new QToolButton(centralwidget);
        score_reset_btn->setObjectName(QString::fromUtf8("score_reset_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(score_reset_btn->sizePolicy().hasHeightForWidth());
        score_reset_btn->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Seven Segment"));
        font2.setPointSize(13);
        score_reset_btn->setFont(font2);

        verticalLayout->addWidget(score_reset_btn);

        admin_btn = new QToolButton(centralwidget);
        admin_btn->setObjectName(QString::fromUtf8("admin_btn"));
        sizePolicy2.setHeightForWidth(admin_btn->sizePolicy().hasHeightForWidth());
        admin_btn->setSizePolicy(sizePolicy2);
        admin_btn->setFont(font2);

        verticalLayout->addWidget(admin_btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignCenter);
        team_two_btn = new QPushButton(groupBox_2);
        team_two_btn->setObjectName(QString::fromUtf8("team_two_btn"));
        team_two_btn->setGeometry(QRect(40, 50, 251, 251));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(team_two_btn->sizePolicy().hasHeightForWidth());
        team_two_btn->setSizePolicy(sizePolicy3);
        team_two_btn->setFont(font1);

        horizontalLayout->addWidget(groupBox_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Team 1", nullptr));
        team_one_btn->setText(QString());
        score_reset_btn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        admin_btn->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Team 2", nullptr));
        team_two_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

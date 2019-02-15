#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test.h"



class QAction;
class QLabel;
class FindDialog;
class SpreadSheet;



class test : public QMainWindow
{
	Q_OBJECT

public:
	test(QWidget *parent = Q_NULLPTR);

private:
	Ui::testClass ui;
};

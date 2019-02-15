#include "test.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include "finddialog.h"

test::test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QWidget *window = new QWidget;
	window->setWindowTitle("Enter Your Age");
	QSpinBox *spinBox = new QSpinBox;
	QSlider *slider = new QSlider(Qt::Horizontal);
	spinBox->setRange(0, 130);
	slider->setRange(0, 130);

	connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

	spinBox->setValue(35);
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	window->setLayout(layout);
	//window->show();

	finddialog *fd = new finddialog;
	//fd->show();
}

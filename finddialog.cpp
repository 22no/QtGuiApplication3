#include "finddialog.h"
#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>

finddialog::finddialog(QWidget *parent)
	: QDialog(parent)
{
	label = new QLabel(tr("Find &whiat :"));
	linEdit = new QLineEdit;
	label->setBuddy(linEdit);

	caseCheckBox = new QCheckBox(tr("Match &case"));
	backwardCheckBox = new QCheckBox(tr("Search &backward"));

	findBtn = new QPushButton(tr("&Find"));
	findBtn->setDefault(true);
	findBtn->setEnabled(false);

	closeBtn = new QPushButton(tr("Close"));

	connect(linEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindBtn(const QString &)));
	connect(findBtn, SIGNAL(clicked()), this, SLOT(findClicked()));
	connect(closeBtn, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(linEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findBtn);
	rightLayout->addWidget(closeBtn);
	rightLayout->addStretch();

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("TestDlg"));
	setFixedHeight(sizeHint().height());



}


finddialog::~finddialog()
{
}



void finddialog::findClicked() {
	QString text = linEdit->text();
	Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;


	if (backwardCheckBox->isChecked()) {
		emit findPrevious(text, cs);
	}
	else {
		emit findNext(text, cs);
	}

}

void finddialog::enableFindBtn(const QString &text) {
	findBtn->setEnabled(!text.isEmpty());
}
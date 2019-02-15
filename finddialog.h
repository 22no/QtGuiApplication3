#pragma once
#include "qobject.h"
#include <QDialog>


class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class finddialog :
	public QDialog
{
	Q_OBJECT
public:
	finddialog(QWidget *parent = 0);
	~finddialog();

signals:
	void findNext(const QString &str, Qt::CaseSensitivity cs);
	void findPrevious(const QString &str, Qt::CaseSensitivity cs);

	private slots:
	void findClicked();
	void enableFindBtn(const QString &text);


private:
	QLabel *label;
	QLineEdit *linEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox;
	QPushButton *findBtn;
	QPushButton *closeBtn;


};


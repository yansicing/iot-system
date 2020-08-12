/****************************************************************************
** Form interface generated from reading ui file 'yang.ui'
**
** Created: Thu Jul 6 22:05:07 2017
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef FORM_H
#define FORM_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QLabel;
class QPushButton;

class Form : public QWidget
{ 
    Q_OBJECT

public:
    Form( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Form();

    QPushButton* Name;
    QPushButton* Id;
    QPushButton* Class;
    QLabel* Label;

public slots:
    virtual void ClassSlot();
    virtual void IdSlot();
    virtual void NameSlot();

};

#endif // FORM_H

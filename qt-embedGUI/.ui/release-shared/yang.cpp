/****************************************************************************
** Form implementation generated from reading ui file 'yang.ui'
**
** Created: Thu Jul 6 22:05:07 2017
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "yang.h"

#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a Form which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
Form::Form( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Form" );
    resize( 584, 480 ); 
    setCaption( tr( "YangQingForm" ) );

    Name = new QPushButton( this, "Name" );
    Name->setGeometry( QRect( 400, 60, 97, 30 ) ); 
    Name->setText( tr( "NAME" ) );

    Id = new QPushButton( this, "Id" );
    Id->setGeometry( QRect( 400, 120, 97, 30 ) ); 
    Id->setText( tr( "ID" ) );

    Class = new QPushButton( this, "Class" );
    Class->setGeometry( QRect( 400, 180, 97, 30 ) ); 
    Class->setText( tr( "CLASS" ) );

    Label = new QLabel( this, "Label" );
    Label->setGeometry( QRect( 390, 240, 120, 20 ) ); 
    Label->setText( tr( "LABEL" ) );

    // signals and slots connections
    connect( Name, SIGNAL( clicked() ), this, SLOT( NameSlot() ) );
    connect( Id, SIGNAL( clicked() ), this, SLOT( IdSlot() ) );
    connect( Class, SIGNAL( clicked() ), this, SLOT( ClassSlot() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
Form::~Form()
{
    // no need to delete child widgets, Qt does it all for us
}

void Form::ClassSlot()
{
    qWarning( "Form::ClassSlot(): Not implemented yet!" );
}

void Form::IdSlot()
{
    qWarning( "Form::IdSlot(): Not implemented yet!" );
}

void Form::NameSlot()
{
    qWarning( "Form::NameSlot(): Not implemented yet!" );
}


/****************************************************************************
** Form meta object code from reading C++ file 'yang.h'
**
** Created: Thu Jul 6 22:05:09 2017
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/yang.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *Form::className() const
{
    return "Form";
}

QMetaObject *Form::metaObj = 0;

#ifdef QWS
static class Form_metaObj_Unloader {
public:
    ~Form_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "Form" );
    }
} Form_metaObj_unloader;
#endif

void Form::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("Form","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Form::tr(const char* s)
{
    return qApp->translate( "Form", s, 0 );
}

QString Form::tr(const char* s, const char * c)
{
    return qApp->translate( "Form", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Form::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (Form::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (Form::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (Form::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    m1_t0 v1_0 = &Form::ClassSlot;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &Form::IdSlot;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &Form::NameSlot;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    QMetaData *slot_tbl = QMetaObject::new_metadata(3);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(3);
    slot_tbl[0].name = "ClassSlot()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "IdSlot()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "NameSlot()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"Form", "QWidget",
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

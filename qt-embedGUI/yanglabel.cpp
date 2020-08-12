#include "yanglabel.h"
#include <qlabel.h>

yanglabelForm::yanglabelForm( QWidget* parent, const char* name, WFlags fl):
Form(parent, name, fl)
{
}
yanglabelForm::~yanglabelForm()
{
}

void yanglabelForm::NameSlot()
{
	Label->setText("YangQing!");
}
void yanglabelForm::IdSlot()
{
	Label->setText("201416070220!");
}
void yanglabelForm::ClassSlot()
{
	Label->setText("IoT1402!");
}

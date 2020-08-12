#ifndef YANGLABEL_H
#define YANGLABEL_H
#include "yang.h"

class yanglabelForm: public Form
{ 
public:
    yanglabelForm( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    virtual ~yanglabelForm();
protected:
    virtual void NameSlot();
    virtual void IdSlot();
    virtual void ClassSlot();
};

#endif // YANGLABEL_H

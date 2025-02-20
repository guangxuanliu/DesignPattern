#ifndef FONTDIALOGDIRECTOR_H_
#define FONTDIALOGDIRECTOR_H_

#include "DialogDirector.h"

class ListBox;
class Button;
class EntryField;

class FontDialogDirector : public DialogDirector
{
public:
    FontDialogDirector();
    virtual ~FontDialogDirector();

    virtual void ShowDialog();
    virtual void WidgetChanged(Widget *);

protected:

    virtual void CreateWidgets();

private:    
    ListBox *_fontList;
    EntryField *_fontName;
    Button *_ok;
    Button *_cancel;
};


#endif // FONTDIALOGDIRECTOR_H_
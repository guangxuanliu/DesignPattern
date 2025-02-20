#include "FontDialogDirector.h"

#include "Button.h"
#include "ListBox.h"
#include "EntryField.h"

FontDialogDirector::FontDialogDirector()
{
}

FontDialogDirector::~FontDialogDirector()
{
}

void FontDialogDirector::ShowDialog()
{
}

void FontDialogDirector::WidgetChanged(Widget *theChangedWidget)
{
    if (theChangedWidget == _fontList)
    {
        _fontName->SetText(_fontList->GetSelection());
    }
    else if (theChangedWidget == _ok)
    {
        // apply the font change and dismiss the dialog
    }
    else if (theChangedWidget == _cancel)
    {
        // dismiss the dialog
    }
}

void FontDialogDirector::CreateWidgets()
{
    _ok = new Button(this);
    _cancel = new Button(this);
    _fontList = new ListBox(this);
    _fontName = new EntryField(this);

    // fill the listBox with the available font names

    // assemble the widgets in the dialog
}

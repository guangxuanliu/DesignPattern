#include "EntryField.h"

EntryField::EntryField(DialogDirector *d)   
    : Widget(d)
{
}

void EntryField::SetText(const char *text)
{
}

const char *EntryField::GetText()
{
    return nullptr;
}

void EntryField::HandleMouse(MouseEvent &event)
{
    Changed();
}

// other methods
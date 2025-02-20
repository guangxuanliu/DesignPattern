#include "ListBox.h"

ListBox::ListBox(DialogDirector *d)
    : Widget(d)
{
}

const char *ListBox::GetSelection()
{
    return nullptr;
}

void ListBox::SetList(std::list<char *> *list)
{
}

void ListBox::HandleMouse(MouseEvent &event)
{
    Changed();
}
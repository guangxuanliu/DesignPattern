#ifndef LISTBOX_H_
#define LISTBOX_H_

#include "Widget.h"

#include <list>

class ListBox : public Widget
{
public:
    ListBox(DialogDirector *);
    virtual const char *GetSelection();
    virtual void SetList(std::list<char *> *);
    virtual void HandleMouse(MouseEvent &);

    // other methods
};

#endif // LISTBOX_H_
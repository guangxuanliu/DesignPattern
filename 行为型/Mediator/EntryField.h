#ifndef ENTRYFIELD_H_
#define ENTRYFIELD_H_

#include "Widget.h"

class EntryField : public Widget
{
public:
    EntryField(DialogDirector *);
    virtual void SetText(const char *);
    virtual const char *GetText();
    virtual void HandleMouse(MouseEvent &);

    // other methods
};

#endif // ENTRYFIELD_H_
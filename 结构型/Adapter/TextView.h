#ifndef TEXTVIEW_H_
#define TEXTVIEW_H_

#include "Common.h"

class TextView
{
public:
    TextView();
    void GetOrigin(Coord &x, Coord &y) const;
    void GetExtent(Coord &width, Coord &height) const;
    virtual bool IsEmpty() const;
};

#endif // TEXTVIEW_H_
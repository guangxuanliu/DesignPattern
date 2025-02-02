#ifndef IMAGE_H_
#define IMAGE_H_

#include "Graphic.h"
#include "Common.h"
#include <string>

class Image : public Graphic
{
public:
    Image(std::string imageName);
    virtual ~Image();

    virtual void Draw(const Point &at);
    virtual void HandleMouse(Event &event);

    virtual const Point &GetExtent();
    virtual void Load(std::istream &from);
    virtual void Save(std::ostream &to);

private:
    // ...
};

#endif // IMAGE_H_
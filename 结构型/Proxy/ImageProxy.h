#ifndef IMAGEPROXY_H_
#define IMAGEPROXY_H_

#include "Graphic.h"
#include "Common.h"

#include <string>

class Image;

class ImageProxy : public Graphic
{
public:
    ImageProxy(std::string imageName);
    virtual ~ImageProxy();

    virtual void Draw(const Point& at);
    virtual void HandleMouse(Event& event);

    virtual const Point& GetExtent();
    virtual void Load(std::istream& from);
    virtual void Save(std::ostream& to);

protected:
    Image *GetImage();

private:
    Image *_image;
    Point _extent;
    std::string _fileName;
};

#endif // IMAGEPROXY_H_
#include "ImageProxy.h"
#include "Image.h"
#include "Common.h"

ImageProxy::ImageProxy(std::string imageName)
{
    _fileName = imageName;
    _extent = Point(0.0, 0.0);
    _image = nullptr;
}

ImageProxy::~ImageProxy()
{
}

void ImageProxy::Draw(const Point &at)
{
    GetImage()->Draw(at);
}

void ImageProxy::HandleMouse(Event &event)
{
    GetImage()->HandleMouse(event);
}

const Point &ImageProxy::GetExtent()
{
    if (_extent._x == 0 && _extent._y == 0)
    {
        _extent = GetImage()->GetExtent();
    }
    return _extent;
}

void ImageProxy::Load(std::istream &from)
{
    from >> _extent._x >> _extent._y >> _fileName;
}

void ImageProxy::Save(std::ostream &to)
{
    to << _extent._x << " " << _extent._y << _fileName << std::endl;
}

Image *ImageProxy::GetImage()
{
    if (_image == nullptr)
    {
        _image = new Image(_fileName);
    }
    return _image;
}

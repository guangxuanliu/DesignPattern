#ifndef COMPOSITION_H_
#define COMPOSITION_H_

class Compositor;
class Component;

class Composition
{
public:
    Composition(Compositor *);
    void Repair();

private:
    Compositor *_compositor;
    Component *_components;
    int _componentCount;
    int _lineWidth;
    int *_lineBreaks;
    
    int _lineCount;
};

#endif // COMPOSITION_H_
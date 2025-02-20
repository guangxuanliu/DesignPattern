#ifndef DIALOGDIRECTOR_H_
#define DIALOGDIRECTOR_H_

class Widget;

class DialogDirector
{
public:
    virtual ~DialogDirector();
    virtual void ShowDialog() = 0;
    virtual void WidgetChanged(Widget *) = 0;

protected:
    DialogDirector();
    virtual void CreateWidgets() = 0;
};

#endif // DIALOGDIRECTOR_H_
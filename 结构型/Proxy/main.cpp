#include <iostream>

#include "TextDocument.h"
#include "ImageProxy.h"

int main(int argc, char const *argv[])
{
    TextDocument *text = new TextDocument();
    // ...
    text->Insert(new ImageProxy("anImageFileName"));

    return 0;
}
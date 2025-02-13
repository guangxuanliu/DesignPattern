#include <iostream>

#include "HelpHandler.h"
#include "Application.h"
#include "Dialog.h"
#include "Button.h"

int main()
{

    const Topic PRINT_TOPIC = 1;
    const Topic PAPER_ORIENTATION_TOPIC = 2;
    const Topic APPLICATION_TOPIC = 3;

    Application *app = new Application(APPLICATION_TOPIC);
    Dialog *dialog = new Dialog(app, PRINT_TOPIC);
    Button *button = new Button(dialog, PAPER_ORIENTATION_TOPIC);

    button->HandleHelp();

    return 0;
}
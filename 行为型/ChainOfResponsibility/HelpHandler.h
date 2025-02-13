#ifndef HELPHANDLER_H_
#define HELPHANDLER_H_

typedef int Topic;
const Topic NO_HELP_TOPIC = -1;

class HelpHandler
{
public:
    HelpHandler(HelpHandler * = 0, Topic = NO_HELP_TOPIC);
    virtual bool HasHelp();
    virtual void SetHandler(HelpHandler *, Topic);
    virtual void HandleHelp();

private:
    HelpHandler *_successor;
    int _topic;
};

#endif // HELPHANDLER_H_
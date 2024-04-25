#ifndef HEADER_H_COMMAND
#define HEADER_H_COMMAND

class Command {

public:

    //TODO: why a virtual deconstructor?
    virtual ~Command() {}
    virtual void execute() = 0;


};

#endif
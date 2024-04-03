
class Command {

public:

    //TODO: why a virtual deconstructor?
    virtual ~Command() {}
    virtual void execute() = 0;


}
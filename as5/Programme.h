#include "Module.h"
#include <string>

class Programme
{
private:
    std::string _name;
    unsigned int _year;

private:
    // not mentioned directly in UML

    Module **modules;
    unsigned int capacity;
    unsigned int currentSize;

public:
    //////////////////////////////////////////////////
    //                  METHODS                     //
    //////////////////////////////////////////////////

    // constructor
    Programme(std::string name = "", unsigned int year = 0, unsigned int cap = 10);

    // copy constructor
    Programme(const Programme &other);

    // desctructor
    ~Programme();

public:
    // getter setter
    std::string getName() const;
    unsigned int getYear() const;
    unsigned int getCapacity() const;
    unsigned int getCurrentSize() const;

    void setName(std::string name);
    void setYear(unsigned int year);

public:
    // add module through pointer
    void addModule(Module *module);

public:
    // the tostring method
    std::string toStr() const;

public:
    // comparer
    Programme &operator=(const Programme &other);
};
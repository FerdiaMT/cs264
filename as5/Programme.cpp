#include "Programme.h"
#include <iostream>

// main constructor
Programme::Programme(std::string name, unsigned int year, unsigned int capacity)
    : _name(name), _year(year), capacity(capacity), currentSize(0)
{

    // check were not being asked to fill an empty program
    if (capacity == 0)
    {
        modules = nullptr;
        return;
    }

    // create our array of modules, with the limit being set by capacity input
    modules = new Module *[capacity];

    // initialize every module in the capacity to a nullptr
    for (unsigned int i = 0; i < capacity; i++)
    {
        modules[i] = nullptr;
    }
}

// copy constructor
// i know this isnt required but just incase it ends up being worth something
// as i know we had to make a copy constructor in all the other ones
// so here it is
Programme::Programme(const Programme &other)
    : _name(other._name), _year(other._year), capacity(other.capacity), currentSize(other.currentSize)
{

    // check were not being asked to fill an empty program
    if (capacity == 0 || other.modules == nullptr)
    {
        modules = nullptr;
        return;
    }

    // create our array of modules, with the limit being set by capacity input
    modules = new Module *[capacity];

    // copy in each pointer
    for (unsigned int i = 0; i < capacity; i++)
    {
        modules[i] = other.modules[i];
    }
}

// Destructor
Programme::~Programme()
{
    delete[] modules;
    modules = nullptr;
}

/////// Getters

std::string Programme::getName() const
{
    return _name;
}

unsigned int Programme::getYear() const
{
    return _year;
}

unsigned int Programme::getCapacity() const
{
    return capacity;
}

unsigned int Programme::getCurrentSize() const
{
    return currentSize;
}

/////// Setters /////////////////////

void Programme::setName(std::string name)
{
    _name = name;
}

void Programme::setYear(unsigned int year)
{
    _year = year;
}

// add module, this attatches the pointer of the module inside the array
void Programme::addModule(Module *module)
{
    // being really defensive here because i heard other people getting
    //  docked marks in assingment 3 due to something similair to this
    if (module == nullptr)
    {
        std::cout << "module being added is null, cannot add" << std::endl;
        return;
    }

    if (modules == nullptr)
    {
        std::cout << "module cannot be added as space to add is null" << std::endl;
        return;
    }

    // if we have remaining room in our array
    if (currentSize < capacity)
    {
        // set the array to point to inputed pointer
        modules[currentSize] = module;

        // increase current size pointer
        currentSize++;
    }
    else
    {
        // print incase its full
        std::cout << "cant add module as the array is full.  size: (" << capacity << ")" << std::endl;
    }
}

// to string
std::string Programme::toStr() const
{
    std::string res = "Programme name: " + _name + " (Year " + std::to_string(_year) + ")\n";
    res += "Module space remaning: " + std::to_string(currentSize) + "/" + std::to_string(capacity) + "\n";
    res += "==================== \n";
    res += "LIST OF MODULES:\n";

    for (unsigned int i = 0; i < currentSize; i++)
    {
        if (modules[i] != nullptr)
        {
            res += modules[i]->getName();
            res += " ( CREDITS:  " + std::to_string(modules[i]->getCredits()) + " , ";
            res += " ( STUDENTS: " + std::to_string(modules[i]->getStudents()) + " )\n";
        }
    }

    return res;
}

//  operator overloading
Programme &Programme::operator=(const Programme &other)
{
    if (this != &other)
    {
        delete[] modules;

        _name = other._name;
        _year = other._year;
        capacity = other.capacity;
        currentSize = other.currentSize;

        modules = new Module *[capacity];
        for (unsigned int i = 0; i < capacity; i++)
        {
            modules[i] = other.modules[i];
        }
    }
    return *this;
}
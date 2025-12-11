#include "Programme.h"
#include <iostream>

// main constructor
Programme::Programme(std::string name, unsigned int year, unsigned int capacity)
    : _name(name), _year(year), capacity(capacity), currentSize(0)
{
    // create our array of modules, with the limit being set by capacity input
    modules = new Module *[capacity];

    // initialize every module in the capacity to a nullptr
    for (unsigned int i = 0; i < capacity; i++)
    {
        modules[i] = nullptr;
    }
}

// copy constructor
Programme::Programme(const Programme &other)
    : _name(other._name), _year(other._year), capacity(other.capacity), currentSize(other.currentSize)
{
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
        std::cout << "Cannot add module as the array is full. Capacity size: (" << capacity << ")" << std::endl;
    }
}

// to string
std::string Programme::toStr() const
{
    std::string result = "Programme: " + _name + " (Year " + std::to_string(_year) + ")\n";
    result += "Capacity: " + std::to_string(currentSize) + "/" + std::to_string(capacity) + " modules\n";
    result += "Modules:\n";

    for (unsigned int i = 0; i < currentSize; i++)
    {
        if (modules[i] != nullptr)
        {
            result += "  - " + modules[i]->getName() +
                      " (" + std::to_string(modules[i]->getCredits()) + " credits, " +
                      std::to_string(modules[i]->getStudents()) + " students)\n";
        }
    }

    return result;
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
#include "Module.h"
#include <string>
#include <stdio.h>
#include <iostream>

Module::Module(std::string name, unsigned int students, unsigned int credits)
    : _name(name), _students(students), _credits(credits) {}

Module::~Module() {}

////////////////////////////////////////////
//             Getter, Setter             //
////////////////////////////////////////////

std::string Module::getName() const
{
    return _name;
}

unsigned int Module::getStudents() const
{
    return _students;
}

unsigned int Module::getCredits() const
{
    return _credits;
}

void Module::setName(std::string name)
{
    _name = name;
}

void Module::setStudents(unsigned int students)
{
    _students = students;
}

void Module::setCredits(unsigned int credits)
{
    _credits = credits;
}

// overloader
bool Module::operator==(const Module &other) const
{
    return (_name == other._name && _credits == other._credits);
}
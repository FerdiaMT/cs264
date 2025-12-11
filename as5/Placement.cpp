#include "Placement.h"
#include <string>

// in constructor we can create the Module manually as its inherited, this is how we set it to 15 credits
Placement::Placement(std::string name, unsigned int students, std::string description)
    : Module(name, students, 15), _description(description) {}

std::string Placement::getDescription() const
{
    return _description;
}

void Placement::setDescription(std::string description)
{
    _description = description;
}
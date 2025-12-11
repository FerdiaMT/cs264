#include "Module.h"
#include <string>

// placement class inherits from the module class
class Placement : public Module
{
private:
    // new field not in module, description
    std::string _description;

public:
    // this will always be 15 credits ,so in constructor we will do that manually
    Placement(std::string name = "", unsigned int students = 0, std::string description = "");

    std::string getDescription() const;
    void setDescription(std::string description);
};
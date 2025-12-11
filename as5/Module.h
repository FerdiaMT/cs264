#include <string>

#ifndef MODULE_H
#define MODULE_H

class Module
{
private:
    std::string _name;
    unsigned int _students;
    unsigned int _credits;

public:
    // Module defaults if nothing put in , to empty name, no student, 2 credit
    Module(std::string name = "", unsigned int students = 0, unsigned int credits = 2);

public:
    ////////////////////////////////////////////
    //             Getter, Setter             //
    ////////////////////////////////////////////

    // getters
    // setting all getters to const as its good practice
    std::string getName() const;
    unsigned int getStudents() const;
    unsigned int getCredits() const;

    // setters
    void setName(std::string name);
    void setStudents(unsigned int students);
    void setCredits(unsigned int credits);

public:
    // the operator overloaders
    bool operator==(const Module &other) const;

public:
    // destructor
    virtual ~Module();
};

#endif
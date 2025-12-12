#include <iostream>
#include "Module.h"
#include "Placement.h"
#include "Programme.h"

int main()
{
    std::cout << "=== SYSTEM TEST ====" << std::endl;

    // our two modules made for testing
    Module cs264("CS264", 181, 5);
    Module cs357("CS357", 155, 5);

    // a second cs264, but with dif amount of students
    Module cs264CompareTest("CS264", 100, 5);

    // test that the == just needs same name and credit
    if (cs264 == cs264CompareTest)
    {
        std::cout << "TEST SUCESS: CS264 and testModule1 are identical (same name and credits)" << std::endl;
    }
    else
    {
        std::cout << "TEST FAIL: CS264 and testModule1 are not identical (not same name and credits)" << std::endl;
    }

    // proof that == NEEDS same credits
    Module cs264CompareTestFail("CS264", 200, 2);
    if (!(cs264 == cs264CompareTestFail))
    {
        std::cout << "TEST SUCESS: CS264 and testModule2 are Different" << std::endl;
    }
    else
    {
        std::cout << "TEST FAIL: CS264 and testModule2 are same" << std::endl;
    }

    if (!(cs264 == cs357))
    {
        std::cout << "TEST SUCESS: CS264 and cs357 are Different " << std::endl;
    }
    else
    {
        std::cout << "TEST FAIL: CS264 and cs357 are same " << std::endl;
    }

    std::cout << " ========================== " << std::endl;

    // now we can create our program
    Programme csse("CSSE (3rd Year)", 3, 6);

    // add our 2 modules
    csse.addModule(&cs264);
    csse.addModule(&cs357);

    // create our placement class
    Placement placement("Work Placement", 160, "6 to 8 month internship that you hopefully get C: ");
    csse.addModule(&placement);

    std::cout << std::endl;

    // to string method test
    std::cout << csse.toStr() << std::endl;

    // testing the limit ability of our program
    std::cout << " =========== limit test ==========" << std::endl;
    Module extra1("CS310", 50, 5);
    Module extra2("CS320", 50, 5);
    Module extra3("CS353", 50, 5);
    Module extra4("CS370", 50, 5);

    // this should be the one that puts it over the limit
    Module extra5("CS380", 50, 5);

    csse.addModule(&extra1);
    csse.addModule(&extra2);
    csse.addModule(&extra3);
    csse.addModule(&extra4);

    // V should print out that its full
    csse.addModule(&extra5);

    std::cout << std::endl;
    std::cout << "---= final programme print =---" << std::endl;
    std::cout << csse.toStr();

    return 0;
}
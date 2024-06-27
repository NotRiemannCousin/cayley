#include <string>
#include <vector>

using std::string;
using std::vector;

struct UnitTest
{
    bool result;
    string name;
};

struct MajorTest
{
    vector<UnitTest> (*majorTest)();
    string name;
};
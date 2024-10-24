#include <functional>
#include <string>
#include <vector>

using std::function;
using std::string;
using std::vector;


struct UnitTest
{
    bool result;
    string name;
};

struct MainTest
{
    function<vector<UnitTest>()> runMainTest;
    string name;
};
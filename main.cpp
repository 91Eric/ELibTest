#include <iostream>
#include "staticlist.h"

using namespace ELibTest;
using namespace std;

class a
{


};

int main(void)
{
    StaticList<a,5> t,t2;
    a n;
    t.insert(n);
    t.insert(n);
    t2 = t;
    return 0;
}

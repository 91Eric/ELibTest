#include <iostream>
#include "linklist.h"

using namespace ELibTest;
using namespace std;

class a
{

public:
    a()
    {
        throw 0;
    }

};

int main(void)
{
   LinkList<int> l;
   l.insert(0,1);
   l.insert(3);
   l.insert(33);
    cout<<l.find(3)<<endl;
    return 0;
}

#include <iostream>

using namespace std;

#include "point.h"

int main()
{
    PPOINT point = PtCreate(1, 2);
    int x, y;
    PtGetValue(point, &x, &y);
    PtPrint(point);
    PtSetValue(point, 12, 12);
    PtPrint(point);

    return 0;
}

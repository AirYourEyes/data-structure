#include <iostream>

using namespace std;

#include "point.h"
#include "single_list.h"

int main()
{
    PPOINT point;
    PLIST list = LiCreate();
    point = PtCreate(1, 2);
    LiAppend(list, point);
    point = PtCreate(11, 3);
    LiAppend(list, point);
    point = PtCreate(3, 5);
    LiAppend(list, point);
    point = PtCreate(2, 3);
    LiAppend(list, point);
    point = PtCreate(7, 8);
    LiAppend(list, point);
    cout << "before delete node: " << endl;
    LiTraverse(list, DoPrintPoint, NULL);
    cout << "after delete node: " << endl;
    LiDelete(list, 1, DoDestoryPoint);
    LiTraverse(list, DoPrintPoint, NULL);
    cout << "after insert: " << endl;
    point = PtCreate(3, 3);
    LiInsert(list, (ADT)point, 1);
    point = PtCreate(4, 4);
    LiInsert(list, (ADT)point, 1);
    point = PtCreate(5, 5);
    LiInsert(list, (ADT)point, 1);
    LiTraverse(list, DoPrintPoint, NULL);
    point = PtCreate(1, 2);
    cout << "search point(1, 2): " << LiSearch(list, (ADT)point, DoComparePoint) << endl;
    point = PtCreate(9, 9);
    cout << "search point(9, 9): " << LiSearch(list, (ADT)point, DoComparePoint) << endl;
    cout << "get count: " << LiGetCount(list) << endl;
    return 0;
}

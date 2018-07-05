#include <iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
#include "point.h"

static char * DuplicateString(const char* s);

struct POINT {
    int x;
    int y;
};

// 创建点
PPOINT PtCreate(int x, int y)
{
    PPOINT point = new POINT;
    point->x = x;
    point->y = y;
    return point;
}

// 销毁点
void PtDestory(PPOINT point)
{
    if (point)
    {
        delete point;
    }
}

// 获取点的坐标
void PtGetValue(PPOINT point, int *x, int *y)
{
    if (point)
    {
        if (x)
        {
            *x = point->x;
        }

        if (y)
        {
            *y = point->y;
        }
    }
}

// 设置点的坐标
void PtSetValue(PPOINT point, int x, int y)
{
    if (point)
    {
        point->x = x;
        point->y = y;
    }
}

// 比较点
bool PtCompare(PPOINT point1, PPOINT point2)
{
    if (!point1 || !point2)
    {
        cout << "PtCompare: Parameter(s) illegal." << endl;
    }
    return (point1->x == point2->x) && (point1->y == point2->y);
}

// 将点的坐标转换成字符串输出
char * PtTransformIntoString(PPOINT point)
{
    char buf[BUFSIZ];
    if (point)
    {
        sprintf (buf, "(%d, %d)", point->x, point->y);
        return DuplicateString(buf);
    }

    return (char *)"NULL";
}

// 打印点
void PtPrint(PPOINT point)
{
    if (point)
    {
        cout << "(" << point->x << ", " << point->y << ")" << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }
}

char * DuplicateString(const char* s)
{
    int n = strlen(s);
    char *t = new char[n+1];
    for (int i = 0; i < n; i++)
    {
        t[i] = s[i];
    }
    t[n] = '\0';
    return t;
}

// 回调函数实现-比较大小
int DoComparePoint(CADT e1, CADT e2)
{
    return PtCompare((PPOINT)e1, (PPOINT)e2);
}

// 回调函数实现-销毁对象
void DoDestoryPoint(ADT e)
{
    PtDestory((PPOINT)e);
}

// 函调函数实现-遍历操作，tag是附加信息
void DoPrintPoint(ADT e, ADT tag)
{
    PtPrint((PPOINT)e);
}


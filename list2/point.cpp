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

// ������
PPOINT PtCreate(int x, int y)
{
    PPOINT point = new POINT;
    point->x = x;
    point->y = y;
    return point;
}

// ���ٵ�
void PtDestory(PPOINT point)
{
    if (point)
    {
        delete point;
    }
}

// ��ȡ�������
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

// ���õ������
void PtSetValue(PPOINT point, int x, int y)
{
    if (point)
    {
        point->x = x;
        point->y = y;
    }
}

// �Ƚϵ�
bool PtCompare(PPOINT point1, PPOINT point2)
{
    if (!point1 || !point2)
    {
        cout << "PtCompare: Parameter(s) illegal." << endl;
    }
    return (point1->x == point2->x) && (point1->y == point2->y);
}

// ���������ת�����ַ������
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

// ��ӡ��
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

// �ص�����ʵ��-�Ƚϴ�С
int DoComparePoint(CADT e1, CADT e2)
{
    return PtCompare((PPOINT)e1, (PPOINT)e2);
}

// �ص�����ʵ��-���ٶ���
void DoDestoryPoint(ADT e)
{
    PtDestory((PPOINT)e);
}

// ��������ʵ��-����������tag�Ǹ�����Ϣ
void DoPrintPoint(ADT e, ADT tag)
{
    PtPrint((PPOINT)e);
}


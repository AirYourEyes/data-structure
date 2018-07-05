#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED


// 抽象数据类型
typedef void * ADT;
typedef const void * CADT;

// 信息隐藏
struct POINT;
typedef struct POINT *PPOINT;

// 数据结构上的操作集
// 创建点
PPOINT PtCreate(int x, int y);
// 销毁点
void PtDestory(PPOINT point);
// 获取点的坐标
void PtGetValue(PPOINT point, int *x, int *y);
// 设置点的坐标
void PtSetValue(PPOINT point, int x, int y);
// 比较点
bool PtCompare(PPOINT point1, PPOINT point2);
// 将点的坐标转换成字符串输出
char * PtTransformIntoString(PPOINT point);
// 打印点
void PtPrint(PPOINT point);

// 回调函数实现-比较大小
int DoComparePoint(CADT e1, CADT e2);
// 回调函数实现-销毁对象
void DoDestoryPoint(ADT e);
// 函调函数实现-遍历操作，tag是附加信息
void DoPrintPoint(ADT e, ADT tag);

#endif // POINT_H_INCLUDED

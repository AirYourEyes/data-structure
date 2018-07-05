#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

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

#endif // POINT_H_INCLUDED

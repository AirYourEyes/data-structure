#ifndef SINGLE_LIST_H_INCLUDED
#define SINGLE_LIST_H_INCLUDED

#include <stdbool.h>

// 抽象数据类型
typedef void * ADT;
typedef const void * CADT;

// 函数指针类型
// 回调函数-比较大小
typedef int (* COMPARE_OBJECT)(CADT e1, CADT e2);
// 回调函数-销毁对象
typedef void (* DESTORY_OBJECT)(ADT e);
// 函调函数-遍历操作，tag是附加信息
typedef void (* MANIPULATE_OBJECT)(ADT e, ADT tag);

// 封装节点信息
struct NODE;
typedef struct NODE * PNODE;

// 封装链表信息
struct LIST;
typedef struct LIST * PLIST;

// 链表的操作集
// 创建链表
PLIST LiCreate();
// 销毁链表
void LiDestroy(PLIST list, DESTORY_OBJECT destory);
// 在链表末尾添加节点
void LiAppend(PLIST list, ADT obj);
// 在链表的指定位置插入节点
void LiInsert(PLIST list, ADT obj, unsigned int pos);
// 删除链表指定位置的节点
void LiDelete(PLIST list, unsigned int pos, DESTORY_OBJECT destory);
// 清空链表
void LiClear(PLIST list, DESTORY_OBJECT destory);
// 遍历链表
void LiTraverse(PLIST list, MANIPULATE_OBJECT manipulate, ADT tag);
// 在链表中查找指定节点
bool LiSearch(PLIST list, ADT obj, COMPARE_OBJECT compare);
// 获取链表节点的数量
int LiGetCount(PLIST list);
// 判断链表是否为空
bool LiIsEmpty(PLIST list);

#endif // SINGLE_LIST_H_INCLUDED

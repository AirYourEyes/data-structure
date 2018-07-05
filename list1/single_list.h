#ifndef SINGLE_LIST_H_INCLUDED
#define SINGLE_LIST_H_INCLUDED

#include <stdbool.h>

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
void LiDestroy(PLIST list);
// 在链表末尾添加节点
void LiAppend(PLIST list, PPOINT point);
// 在链表的指定位置插入节点
void LiInsert(PLIST list, PPOINT point, unsigned int pos);
// 删除链表指定位置的节点
void LiDelete(PLIST list, unsigned int pos);
// 清空链表
void LiClear(PLIST list);
// 遍历链表
void LiTraverse(PLIST list);
// 在链表中查找指定节点
bool LiSearch(PLIST list, PPOINT point);
// 获取链表节点的数量
int LiGetCount(PLIST list);
// 判断链表是否为空
bool LiIsEmpty(PLIST list);

#endif // SINGLE_LIST_H_INCLUDED

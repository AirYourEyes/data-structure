#ifndef SINGLE_LIST_H_INCLUDED
#define SINGLE_LIST_H_INCLUDED

#include <stdbool.h>

// ������������
typedef void * ADT;
typedef const void * CADT;

// ����ָ������
// �ص�����-�Ƚϴ�С
typedef int (* COMPARE_OBJECT)(CADT e1, CADT e2);
// �ص�����-���ٶ���
typedef void (* DESTORY_OBJECT)(ADT e);
// ��������-����������tag�Ǹ�����Ϣ
typedef void (* MANIPULATE_OBJECT)(ADT e, ADT tag);

// ��װ�ڵ���Ϣ
struct NODE;
typedef struct NODE * PNODE;

// ��װ������Ϣ
struct LIST;
typedef struct LIST * PLIST;

// ����Ĳ�����
// ��������
PLIST LiCreate();
// ��������
void LiDestroy(PLIST list, DESTORY_OBJECT destory);
// ������ĩβ��ӽڵ�
void LiAppend(PLIST list, ADT obj);
// �������ָ��λ�ò���ڵ�
void LiInsert(PLIST list, ADT obj, unsigned int pos);
// ɾ������ָ��λ�õĽڵ�
void LiDelete(PLIST list, unsigned int pos, DESTORY_OBJECT destory);
// �������
void LiClear(PLIST list, DESTORY_OBJECT destory);
// ��������
void LiTraverse(PLIST list, MANIPULATE_OBJECT manipulate, ADT tag);
// �������в���ָ���ڵ�
bool LiSearch(PLIST list, ADT obj, COMPARE_OBJECT compare);
// ��ȡ����ڵ������
int LiGetCount(PLIST list);
// �ж������Ƿ�Ϊ��
bool LiIsEmpty(PLIST list);

#endif // SINGLE_LIST_H_INCLUDED

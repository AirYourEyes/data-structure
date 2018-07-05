#ifndef SINGLE_LIST_H_INCLUDED
#define SINGLE_LIST_H_INCLUDED

#include <stdbool.h>

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
void LiDestroy(PLIST list);
// ������ĩβ��ӽڵ�
void LiAppend(PLIST list, PPOINT point);
// �������ָ��λ�ò���ڵ�
void LiInsert(PLIST list, PPOINT point, unsigned int pos);
// ɾ������ָ��λ�õĽڵ�
void LiDelete(PLIST list, unsigned int pos);
// �������
void LiClear(PLIST list);
// ��������
void LiTraverse(PLIST list);
// �������в���ָ���ڵ�
bool LiSearch(PLIST list, PPOINT point);
// ��ȡ����ڵ������
int LiGetCount(PLIST list);
// �ж������Ƿ�Ϊ��
bool LiIsEmpty(PLIST list);

#endif // SINGLE_LIST_H_INCLUDED

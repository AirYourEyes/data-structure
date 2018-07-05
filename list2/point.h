#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED


// ������������
typedef void * ADT;
typedef const void * CADT;

// ��Ϣ����
struct POINT;
typedef struct POINT *PPOINT;

// ���ݽṹ�ϵĲ�����
// ������
PPOINT PtCreate(int x, int y);
// ���ٵ�
void PtDestory(PPOINT point);
// ��ȡ�������
void PtGetValue(PPOINT point, int *x, int *y);
// ���õ������
void PtSetValue(PPOINT point, int x, int y);
// �Ƚϵ�
bool PtCompare(PPOINT point1, PPOINT point2);
// ���������ת�����ַ������
char * PtTransformIntoString(PPOINT point);
// ��ӡ��
void PtPrint(PPOINT point);

// �ص�����ʵ��-�Ƚϴ�С
int DoComparePoint(CADT e1, CADT e2);
// �ص�����ʵ��-���ٶ���
void DoDestoryPoint(ADT e);
// ��������ʵ��-����������tag�Ǹ�����Ϣ
void DoPrintPoint(ADT e, ADT tag);

#endif // POINT_H_INCLUDED

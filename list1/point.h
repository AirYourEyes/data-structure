#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

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

#endif // POINT_H_INCLUDED

#ifndef CORE1_H
#define CORE1_H

/*���ͷ�ļ���洢����ϵͳһ��صĺ��Ĳ���*/
struct menu1 //�����ϵͳһ������
{
    char name[52];  //����
    char sn  [52];  //ѧ�� student number
    char chat[52] ; //��ϵ��ʽ
    char dor [52] ; //�����
    int height;     //ƽ�����ĸ߶�
    struct menu1 *left;
    struct menu1 *right;
};
//extern int flag;
static int maxx(int x,int y);    //�������ֵ

static int high(struct menu1 *p);//���ظ߶�

struct menu1* singleft(struct menu1 *k2);//����

struct menu1* singright(struct menu1 *k2);//�ҵ���

struct menu1* doubleleft(struct menu1 *k3);//LR

struct menu1* doubleright(struct menu1 *k3);//RL

struct menu1* Record_1 (struct menu1 *ph,char a[],char b[],char c[],char d[]);//��¼ϵͳһ���û����ݣ��洢���ļ���

struct menu1* Seeit_1 (struct menu1 *head);//�鿴�������ݺ���

struct menul* Read1 (struct menu1 *head);   //���ļ��ж�ȡ����

struct menu1* Delete_1 (struct menu1 *p,char x[]);//ɾ��ʵ��

struct menu1* Find_1 (struct menu1 *head,char sp);//��ѯ����

struct menu1* Change_1 (struct menu1 *head);//�޸�����

struct menu1* EnterDelete_1 (struct menu1 *head);//����ɾ����һ���ӿ�

void FreeAll_1(struct menu1 *head);//�ͷ��ڴ溯��
#endif // CORE1_H
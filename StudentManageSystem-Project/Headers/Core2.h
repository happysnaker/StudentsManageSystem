#ifndef CORE2_H
#define CORE2_H
/*���ͷ�ļ���洢����ϵͳ����صĺ��Ĳ���*/
struct menu2
{
    char sn2  [52];    //ѧ��
    char name2[52];    //����
    float grade1;       //����
    float grade2;       //Ӣ��
    float grade3;       //C����
    float TotalGrade;   //�ܳɼ���ƽ����
    struct menu2 *Next; //������һ�ڵ�
    struct menu2 *Previous; //��һ�ڵ�
};

void FreeAll_2(struct menu2 *h);    //�ͷ��ڴ棬�˳�ʱ�õ�

struct menu2* Record_2 (struct menu2 *head,char *a,char *b,float c,float d,float e,int change); //д���ļ�,abcde����ķֱ���ṹ����Ϣ��ʾ,change������ܽ���ֻ��¼һ�ųɼ�����ʱ��������������Ч

struct menu2* Seeit_2  (struct menu2 *head); //�鿴��Ϣ

void SeeThesingle_2  (struct menu2 *head,int choice);   //�鿴���Ƴɼ�

struct menu2* Delete_2 (struct menu2 *head,char s[]);   //ɾ��

struct menu2* Find_2 (struct menu2 *head,int change,char c[]);  //����

void EnterSee2(struct menu2 *mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3); //�鿴�ӿں���

struct menu2* Change_2 (struct menu2 *head , int choice ,char sn[],char s[] , float grade);//�޸����ݺ���

void CordReport_2(struct menu2 *mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3);  //�ɼ���������
#endif // CORE2_H

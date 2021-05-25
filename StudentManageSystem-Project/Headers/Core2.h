#ifndef CORE2_H
#define CORE2_H
/*这个头文件里存储着与系统二相关的核心操作*/
struct menu2
{
    char sn2  [52];    //学号
    char name2[52];    //姓名
    float grade1;       //高数
    float grade2;       //英语
    float grade3;       //C语言
    float TotalGrade;   //总成绩的平均数
    struct menu2 *Next; //链表下一节点
    struct menu2 *Previous; //上一节点
};

void FreeAll_2(struct menu2 *h);    //释放内存，退出时用到

struct menu2* Record_2 (struct menu2 *head,char *a,char *b,float c,float d,float e,int change); //写入文件,abcde代表的分别如结构体信息所示,change代表可能仅仅只记录一颗成绩，此时另外两个参数无效

struct menu2* Seeit_2  (struct menu2 *head); //查看信息

void SeeThesingle_2  (struct menu2 *head,int choice);   //查看单科成绩

struct menu2* Delete_2 (struct menu2 *head,char s[]);   //删除

struct menu2* Find_2 (struct menu2 *head,int change,char c[]);  //查找

void EnterSee2(struct menu2 *mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3); //查看接口函数

struct menu2* Change_2 (struct menu2 *head , int choice ,char sn[],char s[] , float grade);//修改数据函数

void CordReport_2(struct menu2 *mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3);  //成绩分析报告
#endif // CORE2_H

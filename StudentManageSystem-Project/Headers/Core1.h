#ifndef CORE1_H
#define CORE1_H

/*这个头文件里存储着与系统一相关的核心操作*/
struct menu1 //这个是系统一的数据
{
    char name[52];  //姓名
    char sn  [52];  //学号 student number
    char chat[52] ; //联系方式
    char dor [52] ; //宿舍号
    int height;     //平衡树的高度
    struct menu1 *left;
    struct menu1 *right;
};
//extern int flag;
static int maxx(int x,int y);    //返回最大值

static int high(struct menu1 *p);//返回高度

struct menu1* singleft(struct menu1 *k2);//左单旋

struct menu1* singright(struct menu1 *k2);//右单旋

struct menu1* doubleleft(struct menu1 *k3);//LR

struct menu1* doubleright(struct menu1 *k3);//RL

struct menu1* Record_1 (struct menu1 *ph,char a[],char b[],char c[],char d[]);//记录系统一的用户数据，存储到文件中

struct menu1* Seeit_1 (struct menu1 *head);//查看所有数据函数

struct menul* Read1 (struct menu1 *head);   //从文件中读取数据

struct menu1* Delete_1 (struct menu1 *p,char x[]);//删除实现

struct menu1* Find_1 (struct menu1 *head,char sp);//查询函数

struct menu1* Change_1 (struct menu1 *head);//修改数据

struct menu1* EnterDelete_1 (struct menu1 *head);//进入删除，一个接口

void FreeAll_1(struct menu1 *head);//释放内存函数
#endif // CORE1_H

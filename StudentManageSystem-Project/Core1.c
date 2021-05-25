#include "../Headers/Everything.h"
/*这里绝大多数是有关平衡树的操作，其中需要你具备扎实的二叉树操作能力*/
/*LR与RL的写法貌似是反的，个人习惯这么叫*/

static int maxx(int x,int y)
{
    return x>y?x:y;
}

/*用以计算高度的函数*/
static int high(struct menu1 *p)
{
    if (p == NULL)
        return -1;
    else
        return p->height;
}

/*LL型旋转*/
struct menu1* singleft(struct menu1 *k2)  //左单旋  LL
{
    struct menu1 *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k1->height = maxx(high(k1->left),high(k1->right))+1;
    k2->height = maxx(high(k2->left),high(k2->right))+1;
    return k1;
}

/*RR型旋转*/
struct menu1* singright(struct menu1 *k2)  //右单旋 RR
{
    struct menu1 *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k1->height = maxx(high(k1->left),high(k1->right))+1;
    k2->height = maxx(high(k2->left),high(k2->right))+1;
    return k1;
}

struct menu1* doubleleft(struct menu1 *k3)   //左双旋 LR 核心操作 LRL(左孩子右单旋，本身左单旋)
{
    k3->left = singright(k3->left);
    return singleft(k3);
}

struct menu1* doubleright(struct menu1 *k3)  //右双旋 RL 核心操作 RLR
{
    k3->right = singleft(k3->right);
    return singright(k3);
}

/*用以记录系统一数据的函数，并未保存至文件中，采用递归实现(学号是有序的)*/
/*主要的思想就是平衡树的插入操作*/
/*a,b,c,d即结构体中的信息，都是按顺序来的*/
struct menu1* Record_1 (struct menu1 *ph,char a[],char b[],char c[],char d[])
{
    if (ph == NULL)
    {
        ph = (struct menu1*)malloc(sizeof(struct menu1));
        if (ph == NULL)
        {
            MessageBox(NULL,TEXT("程序异常崩溃"),TEXT("sorry!"),0);
            exit(0);
        }
        strcpy(ph->sn,a);
        strcpy(ph->name,b);
        strcpy(ph->chat,c);
        strcpy(ph->dor,d);
        ph->height = 0;
        ph->left=NULL;
        ph->right=NULL;
    }
    else if (strcmp(a,ph->sn)<0)
    {
        ph->left = Record_1(ph->left,a,b,c,d);
        if (high(ph->left)-high(ph->right) == 2)
        {
            if (strcmp(a,ph->left->sn)<0)
                ph = singleft(ph);
            else
                ph = doubleleft(ph);
        }
    }
    else if (strcmp(a,ph->sn)>0)
    {
        ph->right = Record_1(ph->right,a,b,c,d);
        if (high(ph->right)-high(ph->left) == 2)
        {
            if (strcmp(a,ph->right->sn)>0)
                ph = singright(ph);
            else
                ph = doubleright(ph);
        }
    }
    else if(strcmp(a,ph->sn) == 0)//检索学号重复
    {
        printf ("您输入的学号有重复!请您检查并重新操作 ");
        return ph;
    }
    ph->height = maxx(high(ph->left),high(ph->right)) + 1;
    return ph;
}

/*查看信息，中序遍历递归*/
struct menu1* Seeit_1 (struct menu1 *head)
{
    struct menu1 *p = head;
    if (p)
    {
        Seeit_1(p->left);
        printf ("\t\t     %-19s%-22s%-27s%-16s",p->sn,p->name,p->chat,p->dor);
        printf ("\n");
        Seeit_1(p->right);
    }
    return head;
}

/*删除节点函数，递归实现*/
/*主要的思想为平衡树删除节点的操作*/
struct menu1* Delete_1 (struct menu1 *p,char x[])
{
    if (!p)
        printf ("该学生不存在!\n");
    else
    {
        if (strcmp(x,p->sn)<0)
        {
            p->left = Delete_1(p->left,x);
            if (abs(high(p->left)-high(p->right))==2)
            {
                if (high(p->left->left)>high(p->left->right))
                    p = singleft(p);
                else
                    p = doubleleft(p);
            }
        }
        else if (strcmp(x,p->sn)>0)
        {
            p->right = Delete_1(p->right,x);
            if (abs(high(p->left)-high(p->right))==2)
            {
                if (high(p->right->left)<high(p->right->right))
                    p = singright(p);
                else
                    p = doubleright(p);
            }
        }
        else
        {
            struct menu1 *ph;
            if (p->left&&p->right)/*可以找到较高的子树中符合的节点替代，这样可以减少旋转的开销*/
            {
                if (high(p->left)>=high(p->right))
                {
                    ph = p->left;
                    while (ph->right)//左子树中最大节点替代
                        ph = ph->right;
                    strcpy(p->sn, ph->sn);
                    strcpy(p->name, ph->name);
                    strcpy(p->dor, ph->dor);
                    strcpy(p->chat, ph->chat);
                    p->left = Delete_1(p->left,ph->sn);
                }
                else
                {
                    ph = p->right;
                    while (ph->left)//右子树中最下节点替代
                        ph = ph->left;
                    strcpy(p->sn, ph->sn);
                    strcpy(p->name, ph->name);
                    strcpy(p->dor, ph->dor);
                    strcpy(p->chat, ph->chat);
                    p->right = Delete_1(p->right,ph->sn);
                }
            }
            else
            {
                struct menu1 *ph = p;
                if (p->left == NULL)
                    p = p->right;
                else if (p->right == NULL)
                    p = p->left;
                free(ph);
                ph = NULL;
            }
        }
    }
    return p;
}

/*查询函数*/
struct menu1* Find_1 (struct menu1 *head,char sp)//sp用以表示选择，即以何种方式查询
{
    char s[52];
    struct menu1 *p=head,*queue[1000];
    int hea = 0, tail = 0;
    queue[tail++] = head;
    if (p==NULL)
    {
        printf ("暂无数据\n");
        return p;
    }
    switch(sp)
    {
    case '4':
        printf ("请输入该生的学号  ");
        strcpy(s,inputString(s,52));
        HideConsoleCursor();
        system("cls");
        while (strcmp(p->sn,s)!=0)
        {
            if (strcmp(s,p->sn)<0)
                p=p->left;
            else if (strcmp(s,p->sn)>0)
                p=p->right;
            if (p==NULL)
            {
                printf ("对不起，该生不存在\n");
                return p;
            }
        }
        printf ("\t----------------------******************学生信息查看*********************--------------------\n");
        printf ("\t-------------学号---------------姓名------------------联系方式-------------------宿舍号-----\n\n");
        printf ("\t\t     %-19s%-22s%-27s%-16s\n",p->sn,p->name,p->chat,p->dor);
        return p;
    case '6':
        printf ("请输入该生的姓名  ");
        strcpy(s,inputString(s,52));
        HideConsoleCursor();
        system("cls");
        while (hea < tail && strcmp(queue[hea]->name,s) != 0)
        {
            if (queue[hea]->left)
                queue[tail++] = queue[hea]->left;
            if (queue[hea]->right)
                queue[tail++] = queue[hea]->right;
            hea++;
        }
        if (hea == tail)
        {

            printf ("对不起，该生不存在\n");
            return NULL;

        }
        else p = queue[hea];
        printf ("\t----------------------******************学生信息查看*********************--------------------\n");
        printf ("\t-------------学号---------------姓名------------------联系方式-------------------宿舍号-----\n");
        printf ("\t\t     %-19s%-22s%-27s%-16s\n",p->sn,p->name,p->chat,p->dor);
        return p;
    }
}

/*修改数据函数*/
struct menu1* Change_1 (struct menu1 *head)
{
    char sn1[52],ck;
    struct menu1 *p,*h = head;
    printf ("您需要输入您想要修改的学生的学号\n");
    p = Find_1(head,'4');
    if (p == NULL)
    {
        printf ("请按任意键返回");
        getch();
        return head;
    }
    while (1)
    {
        printf ("您可以输入 1 以修改学号，输入 2 以修改姓名，输入 3 以修改联系方式，输入 4 以修改宿舍号，输入 0 以退出本次操作\n");
        ck = getch();
        switch (ck)
        {
        case '0':
            return head;
        case '1':
            printf ("请输入新学号 ");
            strcpy(p->sn,inputString(sn1,52));
            printf ("操作成功，请继续操作\n");
            break;
        case '2':
            printf ("请输入新姓名 ");
            strcpy(p->sn,inputString(sn1,52));
            printf ("操作成功，请继续操作\n");
            break;
        case '3':
            printf ("请输入新联系方式 ");
            strcpy(p->sn,inputString(sn1,52));
            printf ("操作成功，请继续操作\n");
            break;
        case '4':
            printf ("请输入新宿舍号 ");
            strcpy(p->sn,inputString(sn1,52));
            printf ("操作成功，请继续操作\n");
            break;
        default:
            printf ("输入的数字有误，请重新输入\n");
            break;
        }
    }

}

/*删除函数的接口，进入删除菜单*/
struct menu1* EnterDelete_1(struct menu1 *head)
{
    char sn1[52],c;
    while (1)
    {
        ShowSeeit_1();
        Seeit_1(head);
        printf ("您可以输入 1 以继续删除，2 以全部删除，0 以返回菜单\n");
        c = getch();
        switch (c)
        {
        case '1':
            printf ("请输入您想要删除学生的学号 ");
            strcpy(sn1,inputString(sn1,52));
            head = Delete_1 (head,sn1);
            printf ("本次操作结束，请输入任意键继续... ");
            getch();
            break;
        case '2':
            FreeAll_1(head);
            head = NULL;
            break;
        case '0':
            return head;
        default:
            printf ("输入有误，请重新输入\n");
            break;
        }
    }
    return head;
}

/*Free*/
void FreeAll_1(struct menu1 *head)
{
    if (head && head->left)
        FreeAll_1(head->left);
    if (head)
    {
        free(head);
        head = NULL;
    }
    if (head && head->right)
        FreeAll_1(head->right);
    return;
}

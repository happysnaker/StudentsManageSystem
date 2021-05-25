#include "../Headers/Everything.h"
extern int flag;//申明全局变量的使用

/*用于记录数据，change用以表示选择，1个函数分别处理多个表头*/
struct menu2* Record_2 (struct menu2 *head,char *a,char *b,float c,float d,float e,int change)
{
    struct menu2 *p = head,*pr,*ph;//双向链表
    float f = (c+d+e)/3.0;
    while (p)
    {
        if (strcmp(p->sn2,a) == 0)
        {
            MessageBox(NULL,TEXT("学号存在重复，请检查输入..."),TEXT("!"),0);
            flag = 1;
            return head;
        }
        p = p->Next;
    }//检索学号重复
    p = head;
    ph = (struct menu2*)malloc(sizeof(struct menu2));
    if (ph==NULL)
    {
        MessageBox(NULL,TEXT("程序异常崩"),TEXT ("Sorry!"),0);
        exit (0);
    }
    if (p == NULL)
    {
        head = ph;
        ph->Previous = NULL;
        ph->Next = NULL;
    }
    else
    {
        switch (change)
        {
        case 0:
            if (f>p->TotalGrade || (f == p->TotalGrade && strcmp(a,p->sn2) <= 0))
            {
                head = ph;
                ph->Previous = NULL;
                ph->Next = p;
                p->Previous = ph;
            }
            else
            {
                while (p && f<p->TotalGrade)
                {
                    pr = p;
                    p = p->Next;
                }
                while (p && f == p->TotalGrade && strcmp(a,p->sn2) > 0)//成绩相同则按姓名排序
                {
                    pr = p;
                    p = p->Next;
                }
                if (p==NULL)
                {
                    pr->Next = ph;
                    ph->Previous = pr;
                    ph->Next = NULL;
                }
                else
                {
                    ph->Next = p;
                    ph->Previous = pr;
                    pr->Next = ph;
                    p->Previous = ph;
                }
            }
            break;
        case 1:
            if (c>p->grade1|| (c == p->grade1 && strcmp(a,p->sn2) <= 0))
            {
                head = ph;
                ph->Previous = NULL;
                ph->Next = p;
                p->Previous = ph;
            }
            else
            {
                while (p && c<p->grade1)
                {
                    pr = p;
                    p = p->Next;
                }
                while (p && c == p->grade1 && strcmp(a,p->sn2) > 0)
                {
                    pr = p;
                    p = p->Next;
                }
                if (p==NULL)
                {
                    pr->Next = ph;
                    ph->Previous = pr;
                    ph->Next = NULL;
                }
                else
                {
                    ph->Next = p;
                    ph->Previous = pr;
                    pr->Next = ph;
                    p->Previous = ph;
                }
            }
            break;
        case 2:
            if (d>p->grade2 || (d == p->grade2 && strcmp(a,p->sn2) <= 0))
            {
                head = ph;
                ph->Previous = NULL;
                ph->Next = p;
                p->Previous = ph;
            }
            else
            {
                while (p && d<p->grade2)
                {
                    pr = p;
                    p = p->Next;
                }
                while (p && d == p->grade2 && strcmp(a,p->sn2) > 0)
                {
                    pr = p;
                    p = p->Next;
                }
                if (p==NULL)
                {
                    pr->Next = ph;
                    ph->Previous = pr;
                    ph->Next = NULL;
                }
                else
                {
                    ph->Next = p;
                    ph->Previous = pr;
                    pr->Next = ph;
                    p->Previous = ph;
                }
            }
            break;
        case 3:
            if (e>p->grade3 || (e == p->grade3 && strcmp(a,p->sn2) <= 0))
            {
                head = ph;
                ph->Previous = NULL;
                ph->Next = p;
                p->Previous = ph;
            }
            else
            {
                while (p && e<p->grade3)
                {
                    pr = p;
                    p = p->Next;
                }
                while (p && e == p->grade3 && strcmp(a,p->sn2) > 0)
                {
                    pr = p;
                    p = p->Next;
                }
                if (p==NULL)
                {
                    pr->Next = ph;
                    ph->Previous = pr;
                    ph->Next = NULL;
                }
                else
                {
                    ph->Next = p;
                    ph->Previous = pr;
                    pr->Next = ph;
                    p->Previous = ph;
                }
            }
            break;
        }
    }
    strcpy(ph->sn2,a);
    strcpy(ph->name2,b);
    ph->grade1 = c;
    ph->grade2 = d;
    ph->grade3 = e;
    ph->TotalGrade = f;
    return head;
}

/*查看所有数据函数*/
struct menu2* Seeit_2  (struct menu2 *head)
{
    system ("cls");
    struct menu2 *p = head;
    printf ("\n\n\n\n\t----------------------******************学生成绩查看*********************--------------------\n\n\n");
    printf ("\t学号----------姓名----------高数成绩--------英语成绩--------C语言程序设计成绩--------总成绩(平均成绩)\n\n");
    while (p)
    {
        printf ("\t%-14s%-15s%-15.1f%-18.1f%-23.1f%-15.1f",p->sn2,p->name2,p->grade1,p->grade2,p->grade3,p->TotalGrade);
        printf ("\n");
        p=p->Next;
    }
    return head;
}

/*删除节点函数*/
//flag用以标记删除失败情况，避免多次删除
//主要要考虑前节点与后节点的存在情况
struct menu2* Delete_2 (struct menu2 *head,char s[])
{
    struct menu2 *p = head;
    if (!p)
    {
        flag = 1;//没有这个学生
        printf ("暂无数据!\n");
        return NULL;
    }
    while (strcmp(p->sn2,s)!=0)
    {
        p = p->Next;
        if (!p)
        {
            flag = 1;
            printf ("该生数据不存在，请重试！\n");
            return head;
        }
    }
    if (p->Previous  == NULL && p->Next == NULL)
    {
        free(p);
        p = NULL;
        return NULL;
    }
    else if (!p->Previous)
    {
        head = p->Next;
        p->Next->Previous = NULL;
    }
    else if (!p->Next)
        p->Previous->Next = NULL;
    else
    {
        p->Previous->Next = p->Next;
        p->Next->Previous = p->Previous;
    }
    free(p);
    p = NULL;
    return head;
}

/*遍历查询*/
struct menu2* Find_2 (struct menu2 *head,int change, char c[])//C用以表示姓名或者学号，取决于change是否为6还是4
{
    HideConsoleCursor();
    system("cls");
    struct menu2 *p = head;
    switch (change)
    {
    case 4:
        while (p)
        {
            if (strcmp(p->sn2,c)==0)
            {
                printf ("\n\n\n\n\t----------------------******************学生成绩查看*********************--------------------\n\n\n");
                printf ("\t学号----------姓名----------高数成绩--------英语成绩--------C语言程序设计成绩--------总成绩(平均成绩)\n\n");
                printf ("\t%-14s%-15s%-15.1f%-18.1f%-23.1f%-15.1f",p->sn2,p->name2,p->grade1,p->grade2,p->grade3,p->TotalGrade);
                printf ("\n");
                return p;
            }
            else
                //return Find_2(p->Next,4,c);
                p=p->Next;
        }
        printf ("该学生不存在\n");
        break;
    case 6:
        while (p)
        {
            if (strcmp(p->name2,c)==0)
            {
                printf ("\n\n\n\n\t----------------------******************学生成绩查看*********************--------------------\n\n\n");
                printf ("\t学号----------姓名----------高数成绩--------英语成绩--------C语言程序设计成绩--------总成绩(平均成绩)\n\n");
                printf ("\t%-14s%-15s%-15.1f%-18.1f%-23.1f%-15.1f",p->sn2,p->name2,p->grade1,p->grade2,p->grade3,p->TotalGrade);
                printf ("\n");
                return p;
            }
            else
                p=p->Next;//return Find_2(p->Next,6,c);
        }
        printf ("该学生不存在\n");
        break;
    }
    return NULL;
}

/*查看单科成绩*/
void SeeThesingle_2  (struct menu2 *headofit,int choice)
{
    struct menu2 *head = headofit;
    switch(choice)
    {
    case 1:
        printf ("\n\n\n\n\t----------------------******************学生高数成绩查看*********************--------------------\n\n\n");
        printf ("\t\t\t\t\t学号----------姓名----------高数成绩\n\n");
        while (head)
        {
            printf ("\t\t\t\t\t%-14s%-15s%-15.1f",head->sn2,head->name2,head->grade1);
            printf ("\n");
            head = head->Next;
        }
        break;
    case 2:
        printf ("\n\n\n\n\t----------------------******************学生英语成绩查看*********************--------------------\n\n\n");
        printf ("\t\t\t\t\t学号----------姓名----------英语成绩\n\n");
        while (head)
        {
            printf ("\t\t\t\t\t%-14s%-15s%-15.1f",head->sn2,head->name2,head->grade2);
            printf ("\n");
            head = head->Next;
        }
        break;
    case 3:
        printf ("\n\n\n\n\t----------------------******************学生C语言成绩查看*********************--------------------\n\n\n");
        printf ("\t\t\t\t\t学号----------姓名----------C语言成绩\n\n");
        while (head)
        {
            printf ("\t\t\t\t\t%-14s%-15s%-15.1f",head->sn2,head->name2,head->grade3);
            printf ("\n");
            head = head->Next;
        }
        break;
    }
    printf("\n\n");
    return ;
}

/*进入查看单科成绩接口*/
void EnterSee2(struct menu2 *Mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3)
{
    char c;
STA:
    HideConsoleCursor();
    system("cls");
    printf ("您可以输入数字 1 以查看学生高数成绩，2 以查看学生的英语成绩，3 以查看C语言成绩，5 以返回菜单,0以刷新当前页面\n");
    ShowConsoleCursor();
    while (1)
    {
        fflush(stdin);
        c = getch();
        switch(c)
        {
        case '1':
            SeeThesingle_2(head1,1);
            printf ("操作成功，您可以继续操作！\n");
            break;
        case '2':
            SeeThesingle_2(head2,2);
            printf ("操作成功，您可以继续操作！\n");
            break;
        case '3':
            SeeThesingle_2(head3,3);
            printf ("操作成功，您可以继续操作！\n");
            break;
        case '0':
            goto STA;
            break;
        case '5':
            return ;
        default:
            printf ("输入有误，请重新输入\n");
            break;
        }
    }
    return ;
}

/*修改数据，sn学号，s姓名，grade取决于choice分别表示不同的需要修改的成绩*/
struct menu2* Change_2 (struct menu2 *head, int choice,char sn[],char s[], float grade)
{
    struct menu2 *p = head;
    float f;
    while (p && strcmp(sn,p->sn2) != 0)//找到对应的学生
        p = p->Next;
    if (!p) return NULL;//没有什么也不做
    switch (choice)
    {
    case 1:
        strcpy(p->sn2,s);
        return head;
    case 2:
        strcpy(p->name2,s);
        return head;
    case 3:
        f = (grade + p->grade2 + p->grade3)/3.0;
        p->grade1 = grade;
        p->TotalGrade = f;
        return head;
    case 4:
        f = (grade + p->grade1 + p->grade3)/3.0;
        p->grade2 = grade;
        p->TotalGrade = f;
        return head;
    case 5:
        f = (grade + p->grade2 + p->grade1)/3.0;
        p->grade3 = grade;
        p->TotalGrade = f;
        return head;
    }
    return head;
}

/*成绩报告函数*/
void CordReport_2(struct menu2 *mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3)
{
Sta:
    HideConsoleCursor();
    system("cls");
    struct menu2 *p,*p1,*p2,*p3;
    float num1 = 0,num2 = 0,num3 = 0;//满绩、及格、挂科占比
    char ch;
    printf ("----------------------******************输入5以返回菜单，输入0以刷新页面*********************--------------------\n");
    printf ("----------------------******************输入5以返回菜单，输入0以刷新页面*********************--------------------\n");
    printf ("\t*您可以输入 1 以查看平均成绩报告，2 以查看高数成绩报告，3 以查看英语成绩报告，4 以查看C语言成绩报告* \n");
    while (1)
    {
        p = mainhead;
        p1 = head1;
        p2 = head2;
        p3 = head3;
        ShowConsoleCursor();
        fflush(stdin);
        ch = getch();
        num1 = 0,num2 = 0,num3 = 0;
        switch(ch)
        {
        case '0':
            goto Sta;
            break;
        case '1':
            printf ("\t\t\t\t*平均成绩报告*\n\n\t\t\t\t平均成绩在90分及以上的人分别是（满绩点人士）:\n");
            printf ("\t\t\t\t学号----------姓名-----------成绩\n");
            while (p && p->TotalGrade >= 90)
            {
                printf ("\n\t\t\t\t%-15s%-15s%.1f",p->sn2,p->name2,p->TotalGrade);
                num1++;
                num2++;
                p = p->Next;
            }
            if (num1 == 0)  printf("\t\t\t\t您的班没有满绩人士！");
            printf ("\n\n\t\t\t\t平均成绩在60分以下的人分别是（挂科人士）:\n");
            printf ("\t\t\t\t学号----------姓名-----------成绩\n");
            while (p)
            {
                if (p->TotalGrade < 60)
                {
                    printf ("\n\t\t\t\t%-15s%-15s%.1f",p->sn2,p->name2,p->TotalGrade);
                    num3++;
                }
                else num2++;
                p = p->Next;
            }
            if (num3 == 0)printf("\t\t\t\t您的班没有挂科人士！");
            if (num2+num3 != 0)
                printf ("\n\n\t\t\t\t总体分布:\n\t\t\t\t60分以下共有%.0f人，占比%.1f%%。\n\n\t\t\t\t60分以上共有%.0f人，占比%.1f%%。\n\n\t\t\t\t其中90分以上共有%.0f人,占比%.1f%%。\n\n",num3,(float)num3/(num2+num3)*100.0,num2,(float)num2/(num2+num3)*100.0,num1,(float)num1/(num2+num3)*100.0);
            else
                printf ("\n\n\t\t\t暂无数据！");
            break;
        case '2':
            printf ("\t\t\t\t*高数成绩报告*\n\n\t\t\t\t高数成绩在90分及以上的人分别是（满绩点人士）:\n");
            printf ("\t\t\t\t学号---------姓名----------成绩\n");
            while (p1 && p1->grade1 >= 90)
            {
                printf ("\n\t\t\t\t%-15s%-15s%.1f",p1->sn2,p1->name2,p1->grade1);
                num1++;
                num2++;
                p1 = p1->Next;
            }
            if (num1 == 0)  printf("\t\t\t\t您的班没有满绩人士！");
            printf ("\n\n\t\t\t\t高数成绩在60分以下的人分别是（挂科人士）:\n");
            printf ("\t\t\t\t学号---------姓名----------成绩\n");
            while (p1)
            {
                if (p1->grade1 < 60)
                {
                    printf ("\n\t\t\t\t%-15s%-15s%.1f",p1->sn2,p1->name2,p1->grade1);
                    num3++;
                }
                else num2++;
                p1 = p1->Next;
            }
            if (num3 == 0) printf("\t\t\t\t您的班没有挂科人士！");
            if (num2+num3 != 0)
                printf ("\n\n\t\t\t\t总体分布:\n\t\t\t\t60分以下共有%.0f人，占比%.1f%%。\n\n\t\t\t\t60分以上共有%.0f人，占比%.1f%%。\n\n\t\t\t\t其中90分以上共有%.0f人,占比%.1f%%。\n\n",num3,(float)num3/(num2+num3)*100.0,num2,(float)num2/(num2+num3)*100.0,num1,(float)num1/(num2+num3)*100.0);
            else
                printf ("\n\n\t\t\t\t暂无数据！");
            break;
        case '3':
            printf ("\t\t\t\t*英语成绩报告*\n\n\t\t\t\t英语成绩在90分及以上的人分别是（满绩点人士）:\n");
            printf ("\t\t\t\t学号---------姓名----------成绩\n");
            while (p2 && p2->grade2 >= 90)
            {
                printf ("\n\t\t\t\t%-15s%-15s%.1f",p2->sn2,p2->name2,p2->grade2);
                num1++;
                num2++;
                p2 = p2->Next;
            }
            if (num1 == 0)  printf("\t\t\t\t您的班没有满绩人士！");
            printf ("\n\n\t\t\t\t英语成绩在60分以下的人分别是（挂科人士）:\n");
            printf ("\t\t\t\t学号---------姓名----------成绩\n");
            while (p2)
            {
                if (p2->grade2 < 60)
                {
                    printf ("\n\t\t\t\t%-15s%-15s%.1f",p2->sn2,p2->name2,p2->grade2);
                    num3++;
                }
                else num2++;
                p2 = p2->Next;
            }
            if (num3 == 0) printf("\t\t\t\t您的班没有挂科人士！");
            if (num2 + num3 != 0)
                printf ("\n\n\t\t\t\t总体分布：\n\t\t\t\t60分以下共有%.0f人，占比%.1f%%。\n\n\t\t\t\t60分以上共有%.0f人，占比%.1f%%。\n\n\t\t\t\t其中90分以上共有%.0f人,占比%.1f%%。\n\n",num3,(float)num3/(num2+num3)*100.0,num2,(float)num2/(num2+num3)*100.0,num1,(float)num1/(num2+num3)*100.0);
            else
                printf ("\n\n\t\t\t暂无数据！");
            break;
        case '4':
            printf ("\t\t\t\t*C成绩报告*\n\n\t\t\t\tC成绩在90分及以上的人分别是（满绩点人士）:\n");
            printf ("\t\t\t\t学号---------姓名----------成绩\n");
            while (p3 && p3->grade3 >= 90)
            {
                printf ("\n\t\t\t\t%-15s%-15s%.1f",p3->sn2,p3->name2,p3->grade3);
                num1++;
                num2++;
                p3 = p3->Next;
            }
            if (num1 == 0)  printf("\t\t\t\t您的班没有满绩人士！");
            printf ("\n\n\t\t\t\tC成绩在60分以下的人分别是（挂科人士）:\n");
            printf ("\t\t\t\t学号---------姓名----------成绩\n");
            while (p3)
            {
                if (p3->grade3 < 60)
                {
                    printf ("\n\t\t\t\t%-15s%-15s%.1f",p3->sn2,p3->name2,p3->grade3);
                    num3++;
                }
                else num2++;
                p3 = p3->Next;
            }
            if (num3 == 0) printf("\t\t\t\t您的班没有挂科人士！");
            if (num2 + num3 != 0)
                printf ("\n\n\t\t\t\t总体分布：\n\t\t\t\t60分以下共有%.0f人，占比%.1f%%。\n\n\t\t\t\t60分以上共有%.0f人，占比%.1f%%。\n\n\t\t\t\t其中90分以上共有%.0f人,占比%.1f%%。\n\n",num3,(float)num3/(num2+num3)*100.0,num2,(float)num2/(num2+num3)*100.0,num1,(float)num1/(num2+num3)*100.0);
            else
                printf ("\n\n\t\t\t暂无数据！");
            break;
        case '5':
            return ;
        default:
            printf ("您的输入有误，请重新输入！\n");
        }
    }
    return ;
}
void FreeAll_2(struct menu2 *h)
{
    struct menu2 *p;
    while (h)
    {
        p = h;
        h = h->Next;
        free(p);
        p = NULL;
    }
    return ;
}

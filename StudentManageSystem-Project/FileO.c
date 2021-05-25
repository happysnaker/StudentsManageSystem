#include "../Headers/Everything.h"


/*存储基本信息函数接口*/
struct menu1* Store1 (struct menu1 *head)
{
    if (!head)
        return NULL;
    FILE *file1;
    file1 = fopen (filebuffer1,"wb+");
    struct menu1 *queue[1000];
    int first = 0,tail = 0;
    queue[tail++] = head;//数结构队列
    if (file1==NULL)
        return head;
    while(first < tail)//BFS遍历树存储每个节点
    {
        if (queue[first]->left)  queue[tail++] = queue[first]->left;
        if (queue[first]->right) queue[tail++] = queue[first]->right;
        fprintf(file1,"%s %s %s %s\n",queue[first]->sn,queue[first]->name,queue[first]->chat,queue[first]->dor);
        first++;
    }
    fclose(file1);
    return head;
}

/*从文件中读取信息数据函数接口*/
struct menul* Read1 (struct menu1 *head)
{
    char a [520];
    char b [52];
    char c [20];
    char d [520];//顺序表示学号姓名联系宿舍
    FILE* file1;
    file1=fopen (filebuffer1,"rb+");
    if (file1==NULL)
    {
        return head;
    }
    /*和主函数开头分析的一样*/
    char cp = fgetc(file1);
    if (cp == EOF)
        return head;
    ungetc(cp,file1);
    while (!feof(file1))
    {
        int f = fscanf (file1,"%s%s%s%s",a,b,c,d);
        if (f!=EOF)
            head=Record_1 (head,a,b,c,d);
    }
    fclose (file1);
    return head;
}


/*存储成绩信息函数接口*/
struct menu2* Store2 (struct menu2 *head)
{
    if (!head)
        return NULL;
    FILE *file2 = fopen(filebuffer2,"wb+");
    struct menu2 *p = head;
    if (file2==NULL)
    {
        return head;
    }
    while (p)
    {
        fprintf (file2,"%s %s %.1f %.1f %.1f\n",p->sn2,p->name2,p->grade1,p->grade2,p->grade3);
        p = p->Next;
    }
    fclose(file2);
    return head;
}

/*注册函数接口菜单*/
struct Users * Register(struct Users *user)
{
    struct Users *u = user,*ur = user,*uh;
    char act[19];
    char pass[19];
    char p1[19];
    char ch;
TOP_:

    HideConsoleCursor();
    system("cls");
    printf ("        --------------------******************注册账号*********************--------------------------\n");
    printf ("        --------------------******************注册账号*********************--------------------------\n");
    printf ("        --------------------******************注册账号*********************--------------------------\n\n\n");
    printf ("                             您可以输入 1 以进入注册，输入其他任意数以返回...\n\n");
    fflush(stdin);
    ch = getch();
    if (ch == '1')
    {
        printf ("请输入您的账号 ");
        enterspring(act,1);
        while(u)//检查账号是否已经存在
        {
            if (strcmp(u->accounts,act) == 0)
            {
                MessageBox(NULL,TEXT("账号已经存在..."),TEXT("!"),0);
                return user;
            }
            ur = u;
            u = u->next;
        }
        uh = (struct Users*)malloc(sizeof(struct Users));//新账号信息
        if (uh == NULL) return user;//异常错误
        printf ("请输入您的密码 ");
        enterspring(pass,2);
        printf ("请再次输入您的密码 ");
        if(strcmp(pass,enterspring(p1,2)) != 0)
        {
            printf ("两次输入密码不一致，请重新输入.\n按任意键继续...");
            getch();
            goto TOP_;
        }
        strcpy(uh->accounts,act);
        strcpy(uh->password,pass);
        uh->next = NULL;
        if (user == NULL)   user = uh;
        else    ur->next = uh;
    }
    else
        return user;
    printf ("注册成功，即将返回登陆页面！...");
    Sleep(200);
    return user;
}

/*登陆函数接口菜单*/
int Enter(struct Users *user)
{

    char act[19],pass[19];
    char ch,gh;
    //extern char;
TOP_:
    HideConsoleCursor();
    system("cls");
    printf ("    ------------------------******************登陆系统*********************------------------------\n");
    printf ("    ------------------------******************登陆系统*********************------------------------\n");
    printf ("    ------------------------******************登陆系统*********************------------------------\n\n\n");
    printf ("                             您可以输入 1 以进入登陆，其他任意键以返回...\n\n");
    fflush(stdin);
    ch = getch();
    if (ch == '1')
    {
        printf ("\n请输入您的账号 ");
        enterspring(act,1);
        if (user == NULL)
        {
            MessageBox(NULL,TEXT("账号信息不存在..."),TEXT("!"),0);
            return 0;
        }
        struct Users *p = user;
        while (p && strcmp(p->accounts,act) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
        {
            MessageBox(NULL,TEXT("账号信息不存在..."),TEXT("!"),0);
            return 0;
        }
        printf ("\n请输入您的密码 ");
        while(strcmp(p->password,enterspring(pass,2)) != 0)
        {
            printf ("密码错误,您可以输入 1 以继续输入密码，0 以刷新页面重新登陆 \n");
            fflush(stdin);
            gh = getch();
            if (gh == '1')
            {
                printf ("\n请输入您的密码 ");
                continue;
            }
            else if (gh == '0')
                goto TOP_;
        }
    }
    else
        return 0;
    /*用以创建存放用户数据两个文件夹的名称*/
    strcpy(filebuffer1,act);
    strcpy(filebuffer2,act);
    strcat(filebuffer1,"_IF.txt");//添加指定后缀
    strcat(filebuffer2,"_GD.txt");
    return 1;
}

/*读取用户账户信息*/
struct Users* Readuser(struct Users *user)
{
    struct Users *ph, *pc = user;
    FILE *p = fopen("Users.txt","rb+");
    if (p == NULL)
        return NULL;
    char act[19],pass[19];
    while (!feof(p))
    {
        int f = fscanf(p,"%s %s",act,pass);
        if (f != EOF)
        {
            ph = (struct Users*)malloc(sizeof(struct Users));
            strcpy(ph->accounts,act);
            strcpy(ph->password,pass);
            ph->next = NULL;
            if (user == NULL)
            {
                user = ph;
                pc = user;
            }
            else
            {
                pc->next = ph;
                pc = pc->next;
            }
        }
    }
    fclose(p);
    return user;
}

/*存储用户账户信息函数实现*/
void  StoreUser (struct Users *user)
{
    struct Users *p1;

    FILE *p = fopen("Users.txt","wb+");
    if (!p)
    {
        printf ("保存用户信息失败...");
        return ;
    }
    //printf ("%s %s",user->accounts,user->password);
    while (user)
    {
        p1= user;
        fprintf (p,"%s %s\n",user->accounts,user->password);
        user = user -> next;
        free(p1);
    }
    fclose(p);
    return ;
}

/*修改用户账号密码函数*/
struct Users* ChangePass(struct Users *user)
{
    char act[19],ch,pass[19],pass1[19],pass2[19];
    int len = strlen(filebuffer1),i;
    struct Users *p = user;
    /*检索当前账户名，通过创建的文件名，他们是右练习的，去掉后缀就好了*/
    for (i=0; i<len; i++)
    {
        if (filebuffer1[i] == '_')
            break;
        act[i] = filebuffer1[i];
    }
    act[i] = '\0';//防御性编程
    while (p && strcmp(p->accounts,act) != 0)//账户一定是存在的
    {
        p = p->next;
    }
TOP_:
    HideConsoleCursor();
    system("cls");
    printf ("   --------------------******************修改密码*********************------------------------\n");
    printf ("   --------------------******************修改密码*********************------------------------\n");
    printf ("   --------------------******************修改密码*********************------------------------\n\n\n");
    printf ("                        您可以输入 1 以开始修改操作，0 以返回...\n");
    fflush(stdin);
    ch = getch();
    if (ch == '1')
    {

        printf ("\n请输入原密码  ");
        while(p && strcmp(p->password,enterspring(pass,2)) != 0)
        {
            char gh;
            printf ("密码错误,您可以输入 1 以继续输入密码，0 以刷新页面 ");
            fflush(stdin);
            gh = getch();
            if (gh == '1')
            {
                printf ("\n请输入您的原密码 ");
                continue;
            }
            else if (gh == '0')
                goto TOP_;
        }
        printf ("请输入您的新密码 ");
        enterspring(pass1,2);
        printf ("请再次输入您的密码 ");
        if(strcmp(pass1,enterspring(pass2,2)) != 0)
        {
            printf ("两次输入密码不一致，请重新输入.\n按任意键继续...");
            getch();
            goto TOP_;
        }
        strcpy(p->password,pass1);
    }
    if (ch == '0')
        return user;
    printf ("修改密码成功！请按任意键返回...");
    getch();
    return user;
}

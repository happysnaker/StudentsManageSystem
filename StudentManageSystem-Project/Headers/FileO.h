#ifndef FILEO_H
#define FILEO_H
/*这个头文件里保存着大部分与文件读写有关的函数*/

//全局变量，用以记录用户存放数据的文件名
char filebuffer1[30],filebuffer2[30];

/*账号-密码结构体*/
struct Users
{
    char accounts[13];
    char password[13];
    struct Users *next;
};

int Enter(struct Users *user);//登陆函数

struct Users* Readuser(struct Users *user);//读取账户信息函数

struct Users* ChangePass(struct Users *user);//修改密码函数

struct Users * Register(struct Users *user);//注册函数

void  StoreUser (struct Users *user);//存储用户账户函数

struct menu1* Store1 (struct menu1 *head);//存储系统一的数据

struct menu2* Store2 (struct menu2 *head);//存储系统二的数据
#endif // FILEO_H

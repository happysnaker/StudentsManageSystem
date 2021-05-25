#include "../Headers/Everything.h"

/*隐藏光标和显示光标函数*/
VOID HideConsoleCursor(VOID)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
VOID ShowConsoleCursor(VOID)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 1};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void ShowMap0 (void)
{
    HideConsoleCursor();
    system("cls");
    system ("color 74");
    printf ("\t     -------------------******************学生管理系统*********************--------------------\n");
    printf ("\t     -------------------******************学生管理系统*********************--------------------\n\n");
    printf (" --------------------******************账号只允许由1-18位英文与数字组成*********************------------------------\n");
    printf ("\n --------------------******************密码只允许由6-18位英文与数字组成*********************------------------------\n");
    printf ("\n\t\t\t\t\t欢迎使用学生管理系统，请先登录！\n");
    printf("\n");
    printf("\n");
    printf("\t\t                   ╭ ⺌ % ╮                             ╭ ```╮  \n");
    printf("\t\t                   (@^o^@) 欢迎使用学生信息管理系统   (⌒:⌒)\n");
    printf("\t\t                   (~):(~)                            (~)v(~) \n");
    printf("\t\t                   *****************************************\n");
    printf("\t\t  *           *    *                                       *  *           *    \n");
    printf("\t\t  * *       * *    *                                       *  * *       * *    \n");
    printf("\t\t  *   *   *   *    *                菜   单                *  *   *   *   *    \n");
    printf("\t\t  *     *     *    *                                       *  *     *     *    \n");
    printf("\t\t  *     *     *    *                1：登录                *  *     *     *    \n");
    printf("\t\t  *     *     *    *                                       *     *     *    \n");
    printf("\t\t  *     *     *    *                2：注册                *  *     *     *    \n");
    printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
    printf("\t\t   *    *    *     *                0：退出                *   *    *    *     \n");
    printf("\t\t    *   *   *      *                                       *    *   *   *      \n");
    printf("\t\t      * * *        *****************************************      * * *        \n");
    printf("\n\t\t                                请输入您的操作！");
}
void ShowMap1 (void)
{
    HideConsoleCursor();
    system ("cls");
    system ("color 06");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf ("\t\t\t\t欢迎使用学生管理系统，初次使用前请务必阅读帮助服务\n");
    printf ("\t\t\t\t欢迎使用学生管理系统，初次使用前请务必阅读帮助服务\n");
    printf ("\t\t\t\t     您可以从键盘上输入 0 以进入帮助页面\n\n\n\n\n\n");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf ("\t  -------------------******************学生管理系统*********************--------------------\n\n");
    printf ("\n\t\t\t\t\t    * [1] 学生信息管理\n");
    printf ("\n\t\t\t\t\t    * [2] 学生成绩管理\n");
    printf ("\n\t\t\t\t\t    * [3]     修改密码\n");
    printf ("\n\t\t\t\t\t    * [4]     退出登陆\n");
    printf ("\n\t\t\t\t\t    * [5]     退出程序\n");
    printf ("\n\t\t\t\t\t    * [6]     关于\n");
    printf ("\n\t\t\t\t\t    * [0]     帮助\n\n\n");
    printf ("\t  -------------------*******************欢迎使用************************--------------------\n");
    ShowConsoleCursor();
    printf ("请您输入菜单上的按键--\n");
}
void ShowMap2 (void)
{
    HideConsoleCursor();
    system ("cls");
    system ("color 0E");
    printf ("\t******************这里是学生信息管理页面,您应该回到上一级阅读帮助以获取您可能想知道的信息*******************\n");
    printf ("\n\t\t*******************——————输入 0 以刷新页面——————*******************");
    printf ("\n\n\n\n\n");
    printf ("\t  -------------------******************学生信息管理*********************--------------------\n\n\n");
    printf ("\t\t\t     * [1] 添加学生信息             * [2] 删除学生信息\n\n");
    printf ("\t\t\t     * [3] 查看学生信息             * [4] 以学号查询学生信息\n\n");
    printf ("\t\t\t     * [5] 修改学生信息             * [6] 以姓名查询学生信息\n\n");
    printf ("\t\t\t     * [7] 保存学生信息             * [8] 回到上一级\n\n");
    printf ("\t\t\t     * [9] 退出程序                 * [0] 刷新页面\n\n\n\n");
    printf ("\t  -------------------*******************欢迎使用************************--------------------\n");
    ShowConsoleCursor();
    printf ("请您输入菜单上的按键--\n");
}
void ShowMap3 (void)
{
    HideConsoleCursor();
    system ("cls");
    system ("color 0E");
    printf ("\t******************这里是学生成绩管理页面,您应该回到上一级阅读帮助以获取您可能想知道的信息*******************\n");
    printf ("\n\t\t*******************——————输入 0 以刷新页面——————*******************");
    printf ("\n\n\n");
    printf ("\t  -------------------******************学生成绩管理*********************--------------------\n\n\n");
    printf ("\t\t\t     * [1]  录入学生成绩             * [2] 删除学生成绩\n\n");
    printf ("\t\t\t     * [3]  查看学生成绩             * [4] 以学号查询学生成绩\n\n");
    printf ("\t\t\t     * [5]  修改学生成绩             * [6] 以姓名查询学生成绩\n\n");
    printf ("\t\t\t     * [7]  保存学生成绩             * [8] 学生成绩报告\n\n");
    printf ("\t\t\t     * [9]  单科成绩排名             * [A/a] 返回上一级\n\n");
    printf ("\t\t\t     * [B/b]  退出程序               * [0]   刷新页面\n\n\n\n");
    printf ("\t  -------------------*******************欢迎使用************************--------------------\n");
    ShowConsoleCursor();
    printf ("请您输入菜单上的按键--\n");
}
void ShowHelp (void)
{
    HideConsoleCursor();
    system ("cls");
    system ("color 0E");
    printf ("\t*******************这里是学生成绩管理帮助页面，您可以从中获取你想要直到的消息*******************\n");
    printf ("\n\n\n\t基本介绍：本程序为学生管理系统，分为学生信息管理和学生成绩管理，您可以可以根据需求进入相应的管理页面");
    printf ("\n\n\n\n\t操作说明：您可以输入菜单中对应的数字或字母以进入对应的页面，对于字母而言，您既可以输入大写字母也可以输入小写字母，这将产生一致的结果");
    printf ("\n\n\n\n\t保存说明：第一次进入相应子系统时，您应该输入待读取的文件名，系统将会将自动读取文件中的内容，您应该将两个子系统的数据保存到两个不同的文件中，请确保您"
            "打开的是与之对应的文件，如果您选择读取文件而不是创建文件，请确保该文件存在，，文件默认保存在当前目录下，您可以输入../name.txt以保存在上一级目录中或者cur/name.txt以保存在cur下一级目录,请不要移动，退出程序时，务必保存学生数据，系统将保存至读入的文件夹");
    printf ("\n\n\n\n\t文件读写的一些问题:\n\t1:读取文件默认应在当在当前目录\n\t2:如果文件读取出现中文乱码，那么很可能是您的.txt文件格式不对，解决方法  打开.txt文件--> "
            "左上角文件-->另存为-->编码E选择ANSI方式-->覆盖当前文件\n\n\n\n\t一些额外说明:请您不要再输入的数据中加入空格，程序将空格前后视为两个输入");
    printf ("\n\n\t感谢您阅读帮助服务，您可以输入任意键以返回上一级 ———请输入任意键 ");
    ShowConsoleCursor();
    getch();
    return ;
}
void ShowRegard (void)
{
    HideConsoleCursor();
    system ("cls");
    system ("color 06");
    for (int i=1; i<=3; i++)
        printf ("******************************************************************************************************************\n");
    printf ("\n\n\n\t\t\t欢迎您来到本系统，本系统由一个NCU的不知名的菜鸡所研制，没有什么协议与规定，自己愉快的玩耍吧!\n\n\t\t\t版本号  4.0\n\n\t\t\t研发商 ：无敌啵啵啵\n\n\t\t\t如果您有什么好的想法，您可以发送到1637318597@qq.com"
            "\n\n\t\t\t知识产权：捏嘿嘿(知识产权是个什么东东？)\n\n\t\t\t如果你不会用的话，去看帮助吧，如果看了还不会，那可能是我的问题(你智商不够好使),sorry\n\n\t\t\t感谢支持，如有您不喜欢的地方，还望海涵\n");
    printf ("\n\n\n\t\t\t感谢您阅读关于服务，您可以输入任意键以返回上一级 ———请输入任意键 \n\n\n\n\n");
    for (int i=1; i<3; i++)
        printf ("******************************************************************************************************************\n");
    ShowConsoleCursor();
    getch();
    return ;
}
void ShowSeeit_1 (void)
{
    HideConsoleCursor();
    system("cls");
    printf ("\n\n\n\n\t----------------------******************学生信息查看*********************--------------------\n\n\n");
    printf ("\t-------------学号---------------姓名------------------联系方式-------------------宿舍号-----\n\n");
}
void heart()
{
    HideConsoleCursor();
    system("color 74");
    for (float y = 1.5f; y > -1.5f; y -= 0.1f)
    {
        printf("\t\t\t");
        for (float x = -1.5f; x < 1.5f; x += 0.05f)
        {
            float a = x * x + y * y - 1;
            putchar(a*a*a - x * x*y*y*y <= 0.0f ? '*' : ' ');
        }
        putchar('\n');
    }
    printf("\t\t\t       ");
    printf("欢");
    Sleep(200);
    printf(" 迎");
    Sleep(200);
    printf(" 使");
    Sleep(200);
    printf(" 用");
    Sleep(200);
    printf(" 学");
    Sleep(200);
    printf(" 生");
    Sleep(200);
    printf(" 管");
    Sleep(200);
    printf(" 理");
    Sleep(200);
    printf(" 系");
    Sleep(200);
    printf(" 统！");
    Sleep(200);
    printf (" (请按任意键进入...)");
    ShowConsoleCursor();
    getch();
    system("cls");
}

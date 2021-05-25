#include "../Headers/Everything.h"
float Calculate (char *s, int m) //计算函数
{
    int i, len = strlen (s);
    float sum = 0, sum1 = 0;
    static bool flag = false;

    for (i = 0; i < m; i++)
    {
        if (s[i] == '-')
        {
            flag = true;
            continue;
        }
        sum = sum*10 + (int)s[i] - '0';
    }

    for (i = len-1; i > m; i--)
    {
        sum1 = (float)sum1/10.0 +  (int)s[i] - '0';
    }

    if (flag)
        return (float) -(sum + sum1/10.0);

    else
        return (float)  (sum + sum1/10.0);
}

float inputlnt (float min,float max)
{
    char ch, ret[1024];
    int len, k = 0, book = 0, m = -1;
    float rax;

Start_Top:
    while (ch = getch(), ch != '\r') //只允许输入'-','.'或者数字
    {
        if (ch == '-' && k == 0)
        {
            putchar (ch);
            ret[k++] = ch;
            ret[k] = '\0';
        }

        else if (ch == '\b')
        {
            if (k == 0)
                continue;
            printf ("\b \b");
            k--;
            ret[k] = '\0';
        }

        else if (ch == '.' && book != 1)
        {
            book = 1;
            putchar (ch);
            ret[k++] = ch;
            ret[k] = '\0';
        }

        else if (ch >= '0' && ch <= '9')
        {
            putchar (ch);
            ret[k++] = ch;
            ret[k] = '\0';
        }

        else
            MessageBox(NULL,TEXT("不规范的输入"),TEXT("输入错误"),0);
    }
    m = strlen(ret);
    for (int i=0; i<strlen(ret); i++)
    {
        if (ret[i] == '.')
            m = i;
    }
    //如果没有小数点，把m置为len，保证计算函数的正确性
    rax = Calculate(ret,m);
    if (rax < min || rax > max)
    {
        MessageBox(NULL,TEXT("您输入的数字范围有误，请重新输入"),TEXT("输入错误"),0);
        goto Start_Top;//回退
    }
    printf ("\n");
    fflush(stdin);
    return rax;
}


char* inputString(char *buffer, unsigned int bufferLen)
{
    char ch;
    int k = 0;
TOP_:
    while (ch = getch(), ch != '\r')
    {
        if (k >= bufferLen-1 && ch != '\b')
        {
            MessageBox (NULL,TEXT("您输入字符串字数已达上限，无法继续输入。。。"),TEXT("overbuffer!"),0);
            fflush(stdin);
            continue;
        }
        if (ch < 0 || ch > 127)
        {
            if (k == bufferLen - 2)
            {
                MessageBox (NULL,TEXT("您输入字符串字数已达上限，无法继续输入。。。"),TEXT("overbuffer!"),0);
                fflush(stdin);
                continue;
            }
            char gh = getch();
            printf ("%c%c",ch,gh);
            fflush(stdin);
            buffer[k++] = ch;
            buffer[k++] = gh;
            buffer[k] = '\0';
        }
        else if (ch == '\b')
        {
            if (k >= 2 && (buffer[k-1] < 0 || buffer[k-1] > 127) )
            {
                k -= 2;
                printf ("\b\b  \b\b");
                buffer[k] = '\0';
            }
            else if (k>0)
            {
                k--;
                printf ("\b \b");
                buffer[k] = '\0';
            }
        }
        else if (ch != '\t')
        {
            buffer[k++] = ch;
            putchar(ch);
            buffer[k] = '\0';
        }
    }
    if (k == 0)
    {
        MessageBox (NULL,TEXT("您还未输入！"),TEXT("!"),0);
        goto TOP_;
    }
    printf ("\n");
    fflush(stdin);
    return buffer;
}
char* enterspring (char *buf , int c)//c是一则视为账号输入，二视为密码输入，输出用*
{
    char ch;
    int k = 0;
    START_:
    while (ch = getch(),ch != '\r')
    {
        if (k>17)
        {
            MessageBox (NULL,TEXT("您输入字符串字数已达上限，无法继续输入。。。"),TEXT("overbuffer!"),0);
            fflush(stdin);
            continue;
        }
        if (ch == '\b' && k > 0)
        {
            k--;
            printf ("\b \b");
            buf[k] = '\0';
        }
        else if ((ch >='a' && ch <= 'z')||(ch >= 'A' && ch <='Z')||(ch >= '0' && ch <='9'))
        {
            buf[k++] = ch;
            if (c != 1)
                putchar('*');
            else
                putchar(ch);
            buf[k] = '\0';
        }
    }
    if (c == 1)
    {
        if (k == 0)
        {
            MessageBox (NULL,TEXT("您还未输入..."),TEXT("!"),0);
            goto START_;
        }
    }
    else
    {
        if (k<6)
        {
            MessageBox (NULL,TEXT("您的密码太短了..."),TEXT("!"),0);
            goto START_;
        }
    }
    putchar('\n');
    return buf;
}














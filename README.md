# -
# -
学生管理系统

大一上所作，c语言，实现了登陆，文件读写，以及两个子系统，这分别包括学生成绩管理和学生信息管理，具体功能可以看看功能图。
亮点：

1.作为大一单人的课设，代码量大，一个系统中有着两个子系统，代码超2000多行(虽然现在的我看这个代码觉得写了很多废话)

2.有着较为完善的人机交互功能，基本上每个操作我都设置了返回和继续操作这个功能，给予用户较好的体验

3.采用了登陆模式，允许修改密码，单账号数据存储在文件中

4.数据结构强大，其中学生信息管理系统采用一颗AVL二叉树，学生成绩系统采用双向多重链表维护，较好的体现自己的水平

5.功能完善，创新设计

6.代码模块化，分类定义了头文件与源文件，几乎未使用全局变量，虽然这样做可能传参比较复杂，但使项目模块化，可读性更高


头文件与函数定义：

1.FileO,h&&FileO.c，这个模块设计到了登陆与许多文件操作(File Operate)

2.Core1.h&&Core1.c,这个模块设计到了与学生信息管理系统有关的核心操作

3.Core2.h&&Core2.c,这个模块设计到了与学生成绩管理系统有关的核心操作

4.Input.h&&Input.c，这个模块自定义了输入，使得所有的输入均使用getch(在vs下并不支持，需要换成_gettch_)，使得在输入时便可以判定是否输入有效

5.ShowMap.h&&ShowMap.c，这个模块设计了与界面有关的函数



ps:大一的时候可真美好啊，当时为了实现一个项目熬夜写一个星期都觉得累，反而单人完成项目之后还异常兴奋，有种难言的喜悦感，也挺佩服当时的自己的，一个人捣鼓了2000多行代码，不过还好当初做了亿点点注释，不然现在都看不懂了哈哈，代码部分繁琐，但我还是没改，毕竟也是当年的心血啊。


/The freshman made, C language, to achieve the landing, document reading and writing, as well as two subsystems, which respectively include student achievement management and student information management, specific functions can see the function diagram.

Window:



1. As a single-person course set in freshman year, the code is large. There are two subsystems in one system, and the code is more than 2000 lines (although I think I wrote a lot of nonsense when I look at this code now).



2. It has a relatively perfect human-computer interaction function. Basically, I set the function of return and continue operation for every operation, which gives users a better experience



3. Login mode is adopted, allowing password modification, and single account data is stored in the file



4. Powerful data structure. Among them, the student information management system adopts an AVL binary tree, and the student achievement system adopts two-way multi-linked list maintenance, which better reflects their own level



5. Perfect function and innovative design



6. Modular code, classifying the header file and the source file, almost no use of global variables, although this may be more complex to pass arguments, but make the project modular, more readable





Header files and function definitions:



1. Fileo,h&&FileO.c, This module is designed to log in and Operate many files.



2. Core1.H && Core1.C, this module is designed to the core operation related to the student information management system



3. Core2.H && Core2.C, this module is designed to the core operation related to the student achievement management system



4.Input.h&&Input.c. This module has a custom Input so that all inputs use getch(not supported under VS, instead of _gettch_), so that it is possible to check if the Input is valid at the time of Input



5.ShowMap.h&&ShowMap.c. This module designs functions related to the interface/

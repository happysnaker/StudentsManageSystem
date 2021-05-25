#ifndef INPUT_H
#define INPUT_H
float Calculate (char *s, int m);//这个函数计算字符串中的数字总和

float inputlnt (float min,float max); //这个函数是我们输入数字的函数，参数即为数字的范围，利用chao类型输入可以防止输入者输入非法数字，我们可以检测出来

char *inputString(char *buffer, unsigned int bufferLen); //这个函数就是输入字符串，同样我们可以检测是否溢出

char* enterspring (char *buf , int c); //接口，c是选择，可以实现输入密码的时候以****形式输入
#endif // INPUT_H

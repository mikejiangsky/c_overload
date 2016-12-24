#include <stdarg.h>
#include <stdio.h>

//可变参数( ... )的前面，必须需要一个有名字的变量
void my_print(const char *s, ...)
{
    const char *arg = s;
    va_list ap; //可变参数列表
	
	//获得不定参数的首地址
    va_start(ap, s);

    while(arg)
    {
		// 获得每一个可变参数
		// 每次调用va_arg都会改变ap值，使得后续的参数值能被依次添加
		// 第一个参数为可变参数列表变量
		// 第二个参数为类型
        printf("%s\n", arg);
        arg = va_arg(ap, const char*);
    }

	//参数获取完毕
    va_end(ap);
}

int main()
{
	//最后一个参数为NULL，作为可变参数的结束符
	my_print("hello", "mike", "jiang", NULL);
	
	return 0;
}
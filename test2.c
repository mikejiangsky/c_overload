#include <stdarg.h>
#include <stdio.h>

//可变参数( ... )的前面，必须需要一个有名字的变量，通常值为可变参数的个数
int sum(int n, ...)
{
	int i = 0;
	int all = 0;
    va_list ap; //可变参数列表
	
    //获得不定参数的首地址
	//第一个参数为可变参数列表变量
	//第二个参数必须为可变参数前面的最后一个参数值，如这里的n
    va_start(ap, n);

    for(i = 0; i < n; ++i)
    {
        // 获得每一个可变参数
		// 每次调用va_arg都会改变ap值，使得后续的参数值能被依次添加
		//第一个参数为可变参数列表变量
		//第二个参数为类型
        int num = va_arg(ap, int);
		all += num; //累加
    }
	
    //参数获取完毕
    va_end(ap);
	
	return all;
}

int main()
{
	//第一个参数为可变参数个数
	int num = sum(5, 1, 2, 3, 4, 5);
	printf("num = %d\n", num);
	
	return 0;
}
#include <stdarg.h>
#include <stdio.h>

//可变参数( ... )的前面，必须需要一个有名字的变量，通常值为可变参数的个数
void func(int a, int n, ...)
{
	int i = 0;
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
		printf("num = %d\n", num);
    }
	
    //参数获取完毕
    va_end(ap);
}

int main()
{
	func(1, 3, 10, 20, 30);
	
	return 0;
}
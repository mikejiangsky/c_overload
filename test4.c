#include <stdarg.h>
#include <stdio.h>

//C99规范支持了可变参数的宏
//'...'指可变参数, 这类宏在被调用时，它(这里指'...')被表示成零个或多个符号，包括里面的逗号，一直到到右括弧结束为止
//当被调用时，在宏体(macro body)中，那些符号序列集合将代替里面的__VA_ARGS__标识符
#define debug1(fmt, ...) printf(fmt, __VA_ARGS__)

#define debug2(format, arg...) printf("[%s: %d] " format, __FILE__, __LINE__, ##arg)

#define debug3(fmt, ...) my_print(__FILE__, __LINE__, fmt, __VA_ARGS__)
void my_print(const char* filename, int line, const char* fmt, ...)
{
    printf("[%s: %d] ", filename, line);
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}

int main()
{
	debug1("hello %s, a = %d\n", "mike", 250);
	debug2("hello %s, a = %d\n", "mike", 250);
	debug3("hello %s, a = %d\n", "mike", 250);
	
	return 0;
}
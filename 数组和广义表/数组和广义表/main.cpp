#include <stdarg.h> //标准头文件，提供宏va_start,va_ard,va_end
					//用于存取变长参数表

#define MAX_ARRAY_DIM 8
typedef struct
{
	int *base; //数组元素基址，由InitArray分配
	int dim; //数组维数
	int *bounds; //数组维界基址，由InitArray分配 
	int *constants; //数组映像函数常量基址，由InitArray分配
}Array;

bool InitArray(Array &A, int dim)
{

}

#include <stdarg.h> //��׼ͷ�ļ����ṩ��va_start,va_ard,va_end
					//���ڴ�ȡ�䳤������

#define MAX_ARRAY_DIM 8
typedef struct
{
	int *base; //����Ԫ�ػ�ַ����InitArray����
	int dim; //����ά��
	int *bounds; //����ά���ַ����InitArray���� 
	int *constants; //����ӳ����������ַ����InitArray����
}Array;

bool InitArray(Array &A, int dim)
{

}

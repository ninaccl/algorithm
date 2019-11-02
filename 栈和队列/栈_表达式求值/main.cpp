#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <string.h>

using namespace std;

char Precede(char a, char b) { //�ж���������ȼ�
	int i, j;
	char Table[8][8] = {
		{ ' ','+','-','*','/','(',')','=' },
		{ '+','>','>','<','<','<','>','>' },
		{ '-','>','>','<','<','<','>','>' },
		{ '*','>','>','>','>','<','>','>' },
		{ '/','>','>','>','>','<','>','>' },
		{ '(','<','<','<','<','<','=',' ' },
		{ ')','>','>','>','>',' ','>','>' },
		{ '=','<','<','<','<','<',' ','=' }
	};  //���ȼ����
	for (i = 0; i<8; i++)
		if (Table[0][i] == a)  //Ѱ�������a
			break;
	for (j = 0; j<8; j++) //Ѱ�������b
		if (Table[j][0] == b)
			break;
	return Table[j][i];
	
}


bool Calcu_temp(double a, char theta, double b, double &r) { //�����Ԫ���ʽ��ֵ
	if (theta == '+')
		r = a + b;
	else if (theta == '-')
		r = a - b;
	else if (theta == '*')
		r = a * b;
	else {
		if (fabs(b - 0.0)<1e-8)  //�������Ϊ0�����ش�����Ϣ
			return false;
		else
			r = a / b;
	}
	return true;
}



bool IsOper(char ch) { //�ж��ַ�ch�Ƿ�Ϊ�����
	char ptr[10] = { '+', '-', '*', '/', '(', ')', '=' };
	int i;
	for (i = 0; i<7; i++) {
		if (ch == ptr[i])
			return true;
	}
	return false;
}


bool Calculate(char s[], double &result) { //������ʽ�Ľ��
	char theta;
	int i = 0, j, point = 0;
	double a, b, r, num = 0;
	stack<double> num_stack;  //����ջ
	stack<char> oper_stack;  //�����ջ
	oper_stack.push('=');
	while (s[i] != '=' || oper_stack.top() != '=') { //�Ա��ʽa���м���
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.') { //�ַ������ֻ���С����
			num = 0;  //��ʼ������Ϊ0
			point = 0;  //point��������Ƿ����С�����Լ���ǰ����С������xλ��point==10^x
			if (s[i] == '.')
				point = 10;
			else
				num = s[i] - 48;
			j = i + 1;
			while (!IsOper(s[j])) { //����������Ҳ���¼�����֣�ֱ�������ֽ������������Ϊֹ
				if (s[j] == '.') {
					point = 10;
					j++;
					continue;
				}
				if (!point)  //��������
					num = num * 10 + (s[j] - 48);
				else {
					num = num + 1.0 * (s[j] - 48) / point;  //С������
					point *= 10;  //С��λ������һλ
				}
				j++;
			}
			i = j;
			num_stack.push(num);  //��������ѹ��ջ��
		}
		else if (IsOper(s[i])) { //�ַ��������
			switch (Precede(s[i], oper_stack.top())) { //���������ջ��������������ȼ��Ƚϲ�����ش���
			case '<':
				oper_stack.push(s[i++]);
				break;
			case '=':
				oper_stack.pop();
				i++;
				break;
			case '>':
				theta = oper_stack.top();  //��ջ�е���һ����������м���
				oper_stack.pop();
				b = num_stack.top();  //�����������֣�ע��˳���ȵ��������ǵڶ���������
				num_stack.pop();
				a = num_stack.top();
				num_stack.pop();
				if (Calcu_temp(a, theta, b, r))  //���㲢�ж��Ƿ��г�������0�����
					num_stack.push(r);  //���������򽫽��ѹ��ջ��
				else
					return false;  //���ֳ���Ϊ0����������ش�����Ϣ
				break;
			}
		}
	}
	result = num_stack.top();  //�������ջ�е�����Ϊ���ʽ�����ս��
	return true;
}



bool Check(char s[]) { //�����ʽ�����Ƿ�ƥ��
	int flag = 0, i;
	for (i = 0; s[i] != 0; i++) {
		if (s[i] == '(')
			flag++;
		if (s[i] == ')')
			flag--;
	}
	if (flag)
		return false;
	else
		return true;
}



int main() {

	//    freopen("in.txt", "r", stdin);
	int i, j;
	char s1[210], s2[210];
	double result;
	printf("\t\t���ʽ��ֵ��ջ��\n");
	printf("******************************************************************\n");
	printf("��������ʽ���ȺŲ������룺\n");
	while (gets_s(s1) != NULL) { //������ʽ
		if (strlen(s1) == 1 && s1[0] == '0')
			break;
		for (i = 0, j = 0; s1[i] != 0; i++) { //�����ʽת��Ϊ��񻯵ı��ʽ������ĩβ���ϡ�=����������s2��
			if (s1[i] == ' ')
				continue;
			s2[j++] = s1[i];
		}
		s2[j++] = '=';
		s2[j] = '\0';
		if (Check(s2)) { //��������Ƿ�ƥ��
			if (Calculate(s2, result))  //���㲢�����ʽ���Ƿ���ֳ���Ϊ0�����
				printf("%lf\n", result);
			else
				printf("��������Ϊ0\n");
		}
		else
			printf("���Ų�ƥ��\n");
	}
	return 0;
}
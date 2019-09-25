#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct stack {
    ElementType *S;
    int Left;
    int Right;
    int MaxSize;
}LinkStack ;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isLeft(char c)
{
	int ret = 0;
	 switch(c)
	 {
	    case '<':
		case '(':
		case '[':
		case '{':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
			break;

	  }
	  return ret;
}
int isRight(char c)
{
	int ret = 0;
	 switch(c)
	 {
	    case '>':
		case ')':
		case ']':
		case '}':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
			break;

	  }
	  return ret;
}
int match(char left, char right)
{
	int ret = 0;

	switch(left)
	{
	    case '<':
			ret = (right == '>');
			break;
		case '(':
			ret = (right == ')');
			break;
		case '[':
			ret = (right == ']');
			break;
		case '{':
			ret = (right == '}');
			break;
		case '\'':
			ret = (right == '\'');
			break;
		case '\"':
		    ret = (right == '\"');
			break;
		default:
			ret = 0;
			break;
	}
}
int scanner(const char* code)
{
	LinkStack* stack = LinkStack_Create();//����ջS;
	int ret = 0;
	int i = 0;

	while( code[i] != '\0')
	{
	    if(isLeft(code[i]))	   //code[i]Ϊ������
	    {
		    LinkStack_Push(stack,(void*)(code + i));  //��code[i]��ջ
		}

		if(isRight(code[i]))    //code[i]Ϊ������
		{
		   char* c = (char*)LinkStack_Pop(stack);      //��code[i]��ջ

		   if((c == NULL) || !match(*c,code[i]))    //���c��code[i]��ƥ��
		   {
		        printf("%c does not match!\n",code[i]);     //��ʱ����
				break;		                                //ֹͣѭ��
		   }
		}
		i++;
	}

	if((LinkStack_Size(stack)==0)&&(code[i]=='\0'))
	{
	       printf("Succeed!\n");                //�������if�����������ƥ��ɹ�
		   ret = 1;
	}
	else
	{
	       printf("Invalid code!\n");         //�����������Щ������ƥ��ʧ�ܣ�����
		   ret = 0;
	}
	LinkStack_Destroy(stack);                   //����ջ���ͷ��ڴ�
    return ret;
}
int main(int argc, char *argv[])
{
	const char* code = "void fint a[]) {int (*p)[5]; p = NULL;}";

	scanner(code);
	return 0;
}

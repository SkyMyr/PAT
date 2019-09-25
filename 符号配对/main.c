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
	LinkStack* stack = LinkStack_Create();//创建栈S;
	int ret = 0;
	int i = 0;

	while( code[i] != '\0')
	{
	    if(isLeft(code[i]))	   //code[i]为左括号
	    {
		    LinkStack_Push(stack,(void*)(code + i));  //将code[i]出栈
		}

		if(isRight(code[i]))    //code[i]为右括号
		{
		   char* c = (char*)LinkStack_Pop(stack);      //将code[i]入栈

		   if((c == NULL) || !match(*c,code[i]))    //如果c与code[i]不匹配
		   {
		        printf("%c does not match!\n",code[i]);     //此时报错
				break;		                                //停止循环
		   }
		}
		i++;
	}

	if((LinkStack_Size(stack)==0)&&(code[i]=='\0'))
	{
	       printf("Succeed!\n");                //如果满足if里面的条件则匹配成功
		   ret = 1;
	}
	else
	{
	       printf("Invalid code!\n");         //如果不满足那些条件则匹配失败，报错
		   ret = 0;
	}
	LinkStack_Destroy(stack);                   //销毁栈，释放内存
    return ret;
}
int main(int argc, char *argv[])
{
	const char* code = "void fint a[]) {int (*p)[5]; p = NULL;}";

	scanner(code);
	return 0;
}

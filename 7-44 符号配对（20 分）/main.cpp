#include<bits/stdc++.h>
using namespace std;

stack<char> sc;
int flag=1;
void check(char ch)
{
    if(!sc.empty())
    {
        char uh=sc.top();
        if(uh=='('&&ch==')')sc.pop();
        else if(uh=='['&&ch==']')sc.pop();
        else if(uh=='{'&&ch=='}')sc.pop();
        else if(uh=='*'&&ch=='*')sc.pop();
        else
        {
            printf("NO\n");
            if(uh=='(')printf("(");
            if(uh=='[')printf("[");
            if(uh=='{')printf("{");
            if(uh=='*')printf("/*");
            printf("-?\n");//少右
            flag=0;
        }
    }
    else
    {
        printf("NO\n");
        printf("?-");//少左
        if(ch==')')printf(")");
        if(ch==']')printf("]");
        if(ch=='}')printf("}");
        if(ch=='*')printf("*/");
        flag=0;
    }
}
int main()
{
    char a[1000];
    while(true)
    {
        gets(a+1);
        if(a[1]=='.')break;
        if(flag==0)continue;
        for(int i=1;a[i];i++)
        {
            char ch=a[i],nh=a[i+1];//ch当前，nh下一个
            if(ch=='('||ch=='['||ch=='{')//左
                sc.push(ch);
            else if(ch=='/'&&nh=='*')//这里特判下/*的情况
                sc.push('*'),i++;
            else if(ch==')'||ch==']'||ch=='}'||(ch=='*'&&nh=='/'))//右
            {
                if(ch=='*'&&nh=='/')i++;//这里特判下*/的情况
                check(ch);
            }
            if(flag==0)break;//如果不行直接跳出
        }
    }
    if(!sc.empty()&&flag)check(' ');//判断只有1个符号的情况
    if(flag)printf("YES\n");
    return 0;
}

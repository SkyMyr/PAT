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
            printf("-?\n");//����
            flag=0;
        }
    }
    else
    {
        printf("NO\n");
        printf("?-");//����
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
            char ch=a[i],nh=a[i+1];//ch��ǰ��nh��һ��
            if(ch=='('||ch=='['||ch=='{')//��
                sc.push(ch);
            else if(ch=='/'&&nh=='*')//����������/*�����
                sc.push('*'),i++;
            else if(ch==')'||ch==']'||ch=='}'||(ch=='*'&&nh=='/'))//��
            {
                if(ch=='*'&&nh=='/')i++;//����������*/�����
                check(ch);
            }
            if(flag==0)break;//�������ֱ������
        }
    }
    if(!sc.empty()&&flag)check(' ');//�ж�ֻ��1�����ŵ����
    if(flag)printf("YES\n");
    return 0;
}

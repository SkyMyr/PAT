#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/***********************************************************/
// 程序目的：列置换密码
// 日期：    2018-10-1
// 作者：    myr
// 邮箱：    244642897@qq.com
/***********************************************************/
#define col 6
int row;
int* key;
//明文
char plaintext[100]={32};
char *ptemp=plaintext;
//密文
char cipher[100][col]={32};
char c[100]={32};
//操作函数
int* getkey(char*k);
void encrypt(char*p,int* k);
char* printCipher(char cipher[100][col]);
int main ()
{
//加密
	char* plain;
	char k[100];
	char p[100]={32};
	char* ciphertext;
	int i,j;
	//输入密钥k
	//gets(k);
	//输入明文p
	gets(p);
	key=getkey(k);

	encrypt(p,key);
	ciphertext=printCipher(cipher);
	return 0;
}
int* getkey(char* pointerK){
	int temp[100];
	int* ktemp=temp;
	int i;
	int t=0;

	temp[0]=0;
	for(i=1;i<7;i++)
    {
        scanf("%d",&temp[i]);
    }
	/*for(i=0;i<100;i++)
		temp[i]=i;

    //分析密钥，得到矩阵ktemp
	do{
		if(*pointerK=='(')
			continue;
		else{
			t=*pointerK-'0';
			while(*(pointerK+1)!=')'){
			ktemp[*pointerK-'0']=*(pointerK+1)-'0';
			pointerK++;
			}
			ktemp[*pointerK-'0']=t;
			pointerK++;
		}
	}	while(*(++pointerK)!='\0');
	for(i=0;i<=10;i++)
        printf("%d",temp[i]);*/
	//puts(ktemp);
	return ktemp;
}
void encrypt(char * p,int* k){
	int totalLength=0;
	int i,j;

	while(*p!='\0'){
		if(*p!=32){
		*(ptemp+totalLength)=*p;
		totalLength++;
		}
		p++;

	}
	row=totalLength/col+1;

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			 cipher[i][*(k+j+1)-1]=*(ptemp+i*col+j);
		}
	}
}
char* printCipher(char cipher[][col]){
	int i,j;
	for(i=0;i<col;i++){
		for(j=0;j<row;j++){
                if(cipher[j][i]==NULL)
                {
                    printf("$");
                    c[i*row+j]=cipher[j][i];
                }
                else
                {
                    printf("%c",cipher[j][i]);
                    c[i*row+j]=cipher[j][i];
                }
		}
		//printf("\n");
	}
	return c;
}

#include <iostream>
using namespace std;
int main() {
    string a, b;
    getline(cin, a);//Ϊ�˷�ֹ��һ���ǿյģ�������cin >> a,��getline(cin, a)
    getline(cin, b);
    if (a.length() == 0) {
        cout << b;
        return 0;
    }
    int flag = 0;
    int lena = a.length();
    int lenb = b.length();
    //�����Ƿ��д�д
    for (int i = 0; i < lena; i++) {
        if (a[i] == '+') {
            flag = 1;
            a[i] = '#';
        }
    }
    //ȥ����д��ĸ
    if(flag) {
        for (int i = 0; i < lenb; i++) {
            if (b[i] >= 'A' && b[i] <= 'Z') {
                b[i] = '#';
            }
        }
    }
    //ȥ��������ĸ
    for (int i = 0; i < lenb; i++) {
        for (int j = 0; j < lena; j++) {
            if (a[j] == b[i]) {
                b[i] = '#';
            }
            if (a[j] >= 'A' && a[j] <= 'Z' && b[i] == a[j] + 32) {
                b[i] = '#';
            }
        }
    }
    int flag1 = 0;
    //print
    for (int i = 0; i < lenb; i++) {
        if (b[i] != '#') {
            cout << b[i];
            flag1 = 1;
        }
    }
    if (flag1 == 0)
        cout << endl;
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
/**********************************************************************
Copyright(c) 2022.09.21 11.35 MRLIU
All rigth reserved
vs2019
Դ��:https://gitee.com/loveMiaoW/vs_project.git
//***********************************************************************/
#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
#define MAXLEN 100

void LCSLength(char* x, char* y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;
    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 1; j <= n; j++)
        c[0][j] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;//Ϊ�˺�����ݣ���Ϊ���������е��ж�
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;//Ϊ�˺������ϻ��ݣ�����Ѱ�������е��ж�
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = -1;//Ϊ�˺���������ݣ�����Ѱ�������е��ж�
            }
        }
    }
}

void LCS(int b[][MAXLEN], char* x, int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 0)//�ҵ��˹����ַ�
    {
        LCS(b, x, i - 1, j - 1);
        printf("%c ", x[i - 1]);
    }
    else if (b[i][j] == 1)//���ϻ��ݵĹ���
        LCS(b, x, i - 1, j);
    else//������ݵĹ���
        LCS(b, x, i, j - 1);
}

int main(int argc, char** argv)
{
    char x[MAXLEN] = { "ABCBDABCA" };
    char y[MAXLEN] = { "BDCABABA" };
    int b[MAXLEN][MAXLEN] = { 0 };
    int c[MAXLEN][MAXLEN] = { 0 };
    int m, n;

    m = strlen(x);
    n = strlen(y);
    //for_each(b[0],b[m],myFun);
   
    LCSLength(x, y, m, n, c, b);//��д��̬�滮���
    cout <<"b������:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "c������:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "�����������:" << endl;
    LCS(b, x, m, n);//������������������

    return 0;
}

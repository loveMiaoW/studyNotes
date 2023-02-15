#define _CRT_SECURN_WARNINGS
/**********************************************************************
Copyright(c) 2022.10.01 09.30 MRLIU
All rigth reserved
vs2019
Դ��:https://gitee.com/loveMiaoW/vs_project.git
***********************************************************************/
#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream ifs("1.txt");
/*
7 9
1 2 6
1 6 1
2 3 4
2 7 3
3 4 2
4 5 6
4 7 5
5 6 8
5 7 7

*/
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int p[N];
struct Edge {//��ȻΪ����ͼ�����Ǵ�һ���߾���
    int a, b, w;//a��bȨΪw�ı�
    bool operator < (const Edge& W)const//���������<
    {
        return w < W.w;
    }
}edges[M];

int find(int x)//���鼯
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int Kruskal()
{
    sort(edges, edges + m);//��n���߰��ձ�Ȩ��С��������
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0, cnt = 0;//res��¼��С�������еı�Ȩ֮��,cnt��¼��С�������еı���
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;//��¼��Ȩ��ֵ
        a = find(a);//��¼a���ϵĶ���
        b = find(b);//��¼b���ϵĶ���
        if (a != b)//���a,b����һ��������
        {
            p[a] = b;//�ϲ�a,b��������
            res += w;//���ϱ�Ȩ
            cnt++;//���ϱ�
        }
    }
    if (cnt < n - 1)//����ߵĸ���С��n-1���Ͳ�����С������
        return INF;
    return res;
}
int main()
{
    ifs >> n >> m;
    for (int i = 0; i < m; i++) {
        ifs >> edges[i].a >> edges[i].b >> edges[i].w;
        cout << edges[i].a<<" " << edges[i].b<< " " << edges[i].w << endl;
    }
    int t = Kruskal();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << "���·����" << t << endl;
    return 0;
}
/**********************************************************************
Copyright(c) 2022.09.30 15.18 MRLIU
All rigth reserved
vs2019
Դ��:https://gitee.com/loveMiaoW/vs_project.git
***********************************************************************/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
using namespace std;

ifstream ifs("1.txt");
/*
0 6 0 0 0 1 0
6 0 4 0 0 0 3
0 4 0 2 0 0 0
0 0 2 0 6 0 5
0 0 0 6 0 8 7
1 0 0 8 0 0 0
0 1 0 5 7 0 0
*/
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
const int N = 510;
const int INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];//��ĵ㵽���ϵ���̾���
bool st[N];//���±�ĵ��Ƿ��ڼ�����,1�����ڼ����У�0�����ڼ�����

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;//����С�������ıߵĺ�
    for (int i = 0; i < n; i++)//�������еĵ�
    {
        int t = -1;//�Ǵ浱ǰ������ĵ����Ͼ�����̵ĵ�,-1��û�ҵ�
        for (int j = 1; j <= n; j++)//��i�������ĵ��ĸ���t�����·
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))//��j������С�������У���t��û�ҵ����·���±� ���� ��ǰi j����С��i t����
                t = j;//�������·���±�
        }
        if (i && dist[t] == INF)//��i���ǵ�һ���㣬�����·��������ʱ��֤��ͼ�д��ڲ���ͨ�ĵ㣬�Ͳ���������С������
            return INF;
        if (i)//���ҵ����·ʱ���Ҳ��ǵ�һ����
            res += dist[t];
        st[t] = true;//t����뼯��
        for (int j = 1; j <= n; j++)//���¼��뼯�ϵĵ�t����t�������ߵľ��������������㵽���ϵľ���
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{

    ifs >> n >> m;
    for (int i = 1; i <= n; i++)//�տ�ʼ�����еı߶���ʼ��Ϊ������
    {
        for (int j = 1; j <= n; j++)
        {
            /*if(i==j)
                g[i][j]=0;
            else*/
            g[i][j] = INF;
            //ifs >> g[i][j];
        }
    }
    while (m--)
    {
        int a, b, c;
        ifs >> a >> b >> c;
        cout << a <<" " << b <<" " << c << endl;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout <<"���·��:" << t << endl;
    return 0;
}
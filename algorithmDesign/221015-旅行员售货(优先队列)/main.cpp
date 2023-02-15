#include<iostream>
#include <fstream>
#include<cstring>
#include<queue>
#define INF 1e7
using namespace std;

ifstream ifs("1.txt");
//��ͼ�ڵ��� 1 - 2 - 3 -4
/*
4
0 20 10 4
20 0 5 6
10 5 0 30
4 6 30 0
*/

int m[100][100];//�洢·������1��ʼ
int bestx[100];//���Ž�·��
int bestl;//���Žⳤ��
int n;//������Ŀ

//�������Ľڵ㶨��
struct node
{
    int cl;//��ǰ�߹���·������
    int id;//����ĵڼ�������
    int x[100];//��¼��ǰ·�����±��1��ʼ

    node() {}
    node(int cl_, int id_)
    {
        cl = cl_;
        id = id_;
        memset(x, 0, sizeof(x));
    }
};



//���ڹ�����С��
struct cl_cmp {
    //��ǰ·�����ȶ̵����ȼ���
    bool operator()(node n1, node n2)
    {
        return n1.cl > n2.cl;
    }
};

void bfs()
{
    //ѡ����С��
    priority_queue<node, vector<node>, cl_cmp> q;
    //����һ���ڵ㣬�Ӹýڵ㿪ʼ����Ϊ1�ǹ̶�λ����ʵ�Ǵ�1��ʼ̽��
    node temp(0, 2);
    //��ʼ��������
    for (int i = 1; i <= n; ++i)
        temp.x[i] = i;
    q.push(temp);
    node cur;//��ǰ�ڵ㣬Ҳ���ǻ�ڵ�
    int t;
    while (!q.empty())
    {
        cur = q.top();
        q.pop();
        t = cur.id;
        //���������ڶ�������
        if (t == n)
        {
            //����Լ����������·��
            //���ͼG�Ƿ����һ���Ӷ���x[n-1]������x[n]�ıߺ�һ���Ӷ���x[n]������1�ı�
            //�����ǰ������۲��ֲ�ͬ����Ϊ�����Ǵ�1��ʼ��������0��ʼ
            if (m[cur.x[t - 1]][cur.x[t]] != INF && m[cur.x[t]][1] != INF)
            {
                if (cur.cl + m[cur.x[t - 1]][cur.x[t]] + m[cur.x[t]][1] < bestl)
                {
                    //�������Ž������·��
                    bestl = cur.cl + m[cur.x[t - 1]][cur.x[t]] + m[cur.x[t]][1];
                    for (int i = 1; i <= n; ++i)
                        bestx[i] = cur.x[i];
                }
            }continue;
        }
        //���ڵ�������·����û��Ҫ����̽���ˣ�����һ���ڵ㿪ʼ
        if (cur.cl >= bestl)
            continue;
        //�ӵ�ǰ�ڵ㿪ʼ̽��t-1 -> t,t+1,t+2...
        for (int j = t; j <= n; ++j)
        {
            //����Լ���������޽�����
            if (m[cur.x[t - 1]][cur.x[j]] != INF && cur.cl + m[cur.x[t - 1]][cur.x[j]] < bestl)
            {
                temp = node(cur.cl + m[cur.x[t - 1]][cur.x[j]], t + 1);
                //����ҵ���һ���¼��ڵ㣬��ô�ýڵ㵽����Ϊֹ��ͬ���Ľڵ�·����ͬ�����˵�ǰ��һ���Ĳ�ͬ
                for (int k = 1; k <= n; ++k)
                    temp.x[k] = cur.x[k];
                swap(temp.x[t], temp.x[j]);
                q.push(temp);
            }
        }
    }
}
int main()
{
    ifs >> n;
    cout << "�ڵ����: " << n << endl;
    //�Ƚ��г�ʼ��
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            m[i][j] = INF;
    memset(bestx, 0, n);
    bestl = INF;
    cout << "ͼ���ڽӾ���: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ifs >> m[i][j];
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    //����̽��
    bfs();
    cout << "����ֵΪ��" << bestl << endl;
    cout << "���Ž�Ϊ��";
    for (int i = 1; i <= n; ++i)
        cout << bestx[i] << " ";
    cout << bestx[1] << endl;
    return 0;
}

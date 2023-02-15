#define _CRT_SECURE_WARNINGS
/**********************************************************************
Copyright(c) 2022.09.29 17.08 MRLIU
All rigth reserved
vs2019
Դ��:https://gitee.com/loveMiaoW/vs_project.git
***********************************************************************/
#include <iostream> 
#include <fstream>  
#include <string> 
using namespace std;

const int N = 7;			//�����������������ͼ�������N�Ĵ�С
const int MAXINT = 9999;	//����Ȩֵ����9999�ı��뽫MAXINT ���µ�����
/*
9999 4	  6		6	9999 9999 9999
9999 9999 1	   9999 7	 9999 9999
9999 9999 9999 9999 6	 4	  9999
9999 9999 2	   9999 9999 5	  9999
9999 9999 9999 9999 9999 9999 4
9999 9999 9999 9999 1	 9999 8
9999 9999 9999 9999 9999 9999 9999
*/
ifstream fin("1.txt");

template<class Type>
void Dijkstra(int n, int v, Type dist[], int prev[], Type c[][N + 1])
{
	bool s[N + 1];
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];//dist[i]��ʾ��ǰ��Դ������i���������·������
		s[i] = false;

		if (dist[i] == MAXINT)
		{
			prev[i] = 0;//��¼��Դ������i�����·��i��ǰһ������
		}
		else
		{
			prev[i] = v;
		}
		//cout << "dist:" << dist[i] << " ";
	}
	//cout << endl;
	dist[v] = 0;
	s[v] = true;

	for (int i = 1; i < n; i++)
	{
		int temp = MAXINT;
		int u = v;//��һ����

		//ȡ��V-S�о����������·�����ȵĶ���u
		for (int j = 1; j <= n; j++)
		{
			if ((!s[j]) && (dist[j] < temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;

		//����������̰��ѡ�����Distֵ
		for (int j = 1; j <= n; j++)
		{
			if ((!s[j]) && (c[u][j] < MAXINT))
			{
				Type newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
		
	}
}
//������·�� vԴ�㣬i�յ�
void Traceback(int v, int i, int prev[])
{
	if (v == i)
	{
		cout << i;
		return;
	}
	Traceback(v, prev[i], prev);
	cout << "->" << i;
}
int main()
{
	
	int v = 1;//Դ��Ϊ1
	int dist[N + 1], prev[N + 1], c[N + 1][N + 1];

	cout << "(maxint = 9999) ����ͼȨ�ľ���Ϊ:" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			fin >> c[i][j];
			cout << c[i][j] << "\t";
		}
		cout << endl;
	}

	Dijkstra(N, v, dist, prev, c);

	for (int i = 2; i <= N; i++)
	{
		cout << "Դ��1����" << i << "�����·������Ϊ:" << dist[i] << "����·��Ϊ";
		Traceback(1, i, prev);
		cout << endl;
	}

	return 0;
}





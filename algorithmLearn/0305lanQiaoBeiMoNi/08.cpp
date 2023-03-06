#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;


int arr[110][110];

int main()
{
	int n,m,t;
	cin >> n >> m;
	cin >> t;
	for(int i = 1; i <= t;++i)
	{
		for(int j = 1;j < 4;++j)
		{
			cin >> arr[i][j]; 
		}
	}
	cout << m << n << t << endl;
	
//	for(int i = 0; i < t;++i)
//	{
//		for(int j = 0;j < 4;++j)
//		{
//			cout << a[i][j]; 
//		}
//		cout << endl;
//	}
	
	//统计一下清理的个数
	/*
		2 3
		2
		1 1 1 3
		1 2 2 2
	*/
	int sSum = 0;
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1;j <= m;++j)
		{
			for(int k = 1;k <= t;++k)
			{
				if(i >= arr[k][0] && i <= arr[k][2])
				{
					if((i >= arr[k][0]) && (i <= arr[k][2]) && (j >= arr[k][1]) && (j <= arr[k][3]))
					{
						sSum += 1;
						cout << sSum << endl;
					}
				}
			}
		}
	 } 
	cout << n * m  - sSum << endl; 
	return 0;
 } 

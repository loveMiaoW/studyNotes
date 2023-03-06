#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;

int ans = 0;
int a[110];
int b[110];

int main()
{
	int w,h,n,r;
	cin >> w >> h >> n >> r;
	for(int i = 0;i < n;++i)
	{
		cin >> a[i];
	}
	for(int i = 0;i < n;++i)
	{
		cin >> b[i];
	}
//	for(int i = 0;i < n;++i)
//	{
////		cin >> b[i];
//		cout << a[i] <<" ";
//	}
//	for(int i = 0;i < n;++i)
//	{
////		cin >> b[i];
//		cout << b[i] <<" ";
//	}
	for(int i = 0;i <= w;++i)
	{
		for(int j = 0;j <= h;++j)
		{
			for(int k = 0;k < n;++k)
			{
				if(sqrt(pow(i - a[k],2) + pow(j - b[k],2)) <= r)
				{
					ans++;
					break;
				 } 
			}
		}
	}
	cout << ans << endl;
	
	return 0;
 } 

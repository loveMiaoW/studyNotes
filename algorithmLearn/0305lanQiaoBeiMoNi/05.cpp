#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;

char arr[10][10];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int tmp = 0;
//int ans = 0;
void dfs(int x,int y)
{
	if(x < 0 || y < 0 || x > 3 || y > 3 || arr[x][y] == 0)
	{
		return;
	}
//	tmp++;
	arr[x][y] = 0;
	for(int i = 0;i < 4;++i)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		dfs(xx,yy);
	}
	
}

int main()
{
//	freopen("./1.txt","r",stdin);
	
	for(int i = 0;i < 4;++i)
	{
		for(int j = 0;j < 4;++j)
		{
			cin >> arr[i][j];	
		}	
	} 
	int ans = 0;
	for(int i = 0;i < 4;++i)
	{
		for(int j = 0;j < 4;++j)
		{
//			cin >> arr[i][j];	
			if(arr[i][j] == 1)
			{
				//tmp = 0;
				dfs(i,j);
				ans += 1;
			}
		}	
	} 	
	cout << ans << endl;
	return 0;
 } 

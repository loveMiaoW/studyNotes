#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;

int dp[110][110];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int s[110][110];
int ans = 0;
int n,m;

int dfs(int x,int y)
{
	if(s[x][y] == 1) return s[x][y];
	s[x][y] = 1;
	for(int i = 0;i < 4;++i)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx > 0 && yy > 0 && xx <= n && yy <= m && dp[x][y] > dp[xx][yy])
		{
			dfs(xx,yy);
			s[x][y] = max(s[x][y],s[xx][yy] + 1);
		}
	}
	return s[x][y];
}


int main()
{
	
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1;j <= m;++j)
		{
			cin >> dp[i][j];
		}
	}
//	for(int i = 1;i <= n;++i)
//	{
//		for(int j = 1;j <= m;++j)
//		{
////			cin >> dp[i][j];
//			cout << dp[i][j] <<" ";
//		}
//		cout << endl;
//	}
		for(int i = 1;i <= n;++i)
		{
			for(int j = 1;j <= m;++j)
			{
				ans = max(ans,dfs(i,j));
			}
		}
		cout << ans << endl;
	return 0;
 } 

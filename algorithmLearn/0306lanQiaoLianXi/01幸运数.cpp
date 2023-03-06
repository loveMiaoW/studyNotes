#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;

const int N = 1e6 + 10;

int arr[N];
int m,n;
int ans = 0;

void dfs(int luck)
{
	if(luck > n)
	{
		return;
	} 
	int index = luck;
	for(int i = luck;i <= n;++i)
	{
		if(i % arr[luck])
		{
			arr[index++] = arr[i];
		}
	 } 
	 dfs(luck+1);
}

int main()
{
	cin >> m >> n;
	
	for(int i = 1;i <= n;++i)
	{
		arr[i] = 2 * i - 1;
	}
	
	dfs(2);
	
	for(int i = 1; arr[i] < n;++i)
	{
		if(arr[i] > m)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
 } 

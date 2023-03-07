#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;

typedef long long yy;
const int modNum = 998244353;
const int N = 1e5 + 10;
int n,m;
int x[N],y[N];
 


int main()
{
	cin >> n;
	for(int i = 0;i < n;++i)
	{
		cin >> x[i] >> y[i];
		int d = __gcd(x[i],y[i]);
		x[i] /= d;
		y[i] /= d;
	}
	ll aa = 0;
	ll bb = 0;
	for(int i = n - 1;i >= 0;--i)
	{
		ll tmp = 
	}
	
	return 0;
 } 

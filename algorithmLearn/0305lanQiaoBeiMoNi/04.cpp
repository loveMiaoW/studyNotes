#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;
int arr[31] = {99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77};


int main()
{
	int ans = 0;
	for(int i = 0;i < 29;++i)
	{
		for(int j = i + 1;j < 30;++j)
		{
			if(arr[i] * arr[j] >= 2022)
			{
				ans++;
			}
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
 } 

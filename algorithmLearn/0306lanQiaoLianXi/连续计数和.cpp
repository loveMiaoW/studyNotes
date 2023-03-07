#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;


/*

*/

int main()
{
	//cout << 111 * 111 * 111; 
	int ans;
	for(int i = 1;;i += 2)
	{
		int tmp = 0;
		for(int j = i;j <= 100000;j += 2)
		{
			if((tmp += j) == (111 * 111 * 111))
			{
				cout << i << endl;
			}
		}
	}
	
	
	return 0;
 } 

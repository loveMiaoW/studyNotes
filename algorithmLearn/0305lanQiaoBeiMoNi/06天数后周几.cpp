#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;

int w[7] = {7,1,2,3,4,5,6};
int we;
int n;

int main()
{
	cin >> we >> n;
//	cout << w << n;
	int tmp = 0;
	
	tmp = n  % 7;
	//cout << tmp << endl;
	int t = (we + tmp) % 7;
	
	cout << w[t] << endl;
	return 0;
 } 

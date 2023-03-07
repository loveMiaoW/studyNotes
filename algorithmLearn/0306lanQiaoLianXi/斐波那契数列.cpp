#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
//#include <mui>
using namespace std;

typedef long long ll;
vector<ll> vec;

const long long n = 202202011200; 
long long arr[100010];


int main()
{
//	for(int i = 0;i < 3;++i)
//	{
//		//vec[i] = 1;
//		arr[i] = 1;
//	}
//
//	for(int i = 3;i <= 200;++i)
//	{
////		vec[i] = vec[i - 1] + vec[i - 2];
//		arr[i] = arr[i-1] + arr[i-2];
//	}
////	cout << vec.size() << endl;
//	//cout << sizeof(arr) / sizeof(int) ; 
//	
//	for(int i = 1;i < 500;++i)
//	{
//		cout << arr[i] << endl;;
//	}
//	arr[0] = 0;
//	arr[1] = 1;
//	arr[2] = 1;
//	int index = 0;
//	for(ll i = 3;i <= 800;++i)
//	{
//		arr[i] = (arr[i-1] + arr[i-2]) % 10;
//		if(arr[i] == 7)
//		{
//			cout <<"第" << index++ <<"个数"<<"  "<<"i是：" <<   i <<"  arr[i]"<<arr[i] << endl;
//			index++;
//		}
//		
//	}
//	cout << index << endl;
	long long i,a=1,b=1,tem,n=202202011200,total=0;
   for(i=3;i<=n;i++)
   {
     tem=b;
     b+=a;
     a=tem;
     if(b%10==7) total++;
   }
   cout<<total;

	return 0;
 } 

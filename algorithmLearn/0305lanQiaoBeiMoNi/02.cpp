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
	1900 1 1 - 9999 12 31
	
*/

int ans = 0;
int yearBitNum[4];
int mouBitNum[2];
int dayBitNum[2];
int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isRun(int year)
{
	if((year % 4 == 0 && year % 100) || (year % 400 == 0))
	{
		return true;
	}
	return false;
 } 

int main()
{
	
	for(int i = 0;i < 2;++i)
	{
		mouBitNum[i] = 0;
		dayBitNum[i] = 0;
	}
	for(int i = 1900;i <= 9999;++i)		//Äê·Ý 
	{
		for(int i = 0;i < 4;++i)
		{
			yearBitNum[i] = 0;
		}
		if(isRun(i) == true)
		{
			days[2] = 29;	
		}	
		else{
			days[2] = 28;
		}
		int ySum = 0;
		int mSum = 0;
		int dSum = 0;
		int yearIndex = 0;
		int tmpYear = i;
		while(tmpYear != 0 )
		{
			yearBitNum[yearIndex++] = tmpYear % 10;
			tmpYear /= 10;
		}
//		printf("%d %d %d %d\n",yearBitNum[0],yearBitNum[1],yearBitNum[2],yearBitNum[3]);
		//system("puase");
		ySum = yearBitNum[0]+yearBitNum[1]+yearBitNum[2]+yearBitNum[3];
		for(int j = 1;j <= 12;++j)
		{
			for(int i = 0;i < 2;++i)
			{
				mouBitNum[i] = 0;
//		dayBitNum[i] = 0;
			}
			int mouIndex = 0;
			int tmpMou = j;
			while(tmpMou != 0)
			{
				mouBitNum[mouIndex++] = tmpMou % 10;
				tmpMou /= 10;
			}
			
			mSum = mouBitNum[0] + mouBitNum[1];
			
			for(int k = 1;k <= days[j];++k)
			{
				for(int i = 0;i < 2;++i)
				{
//		mouBitNum[i] = 0;
					dayBitNum[i] = 0;
				}
				int dayIndex = 0;
				int tmpDay = k;
				while(tmpDay != 0)
				{
					dayBitNum[dayIndex++] = tmpDay % 10;
					tmpDay /= 10;
				}
				dSum = dayBitNum[0] + dayBitNum[1];
				
				if(ySum == (dSum + mSum))
				{
//					printf("%d %d %d\n",i,j,k);
//					printf("mouBitNum->%d %d\n",mouBitNum[0],mouBitNum[1]);
//					printf("dayBitNum->%d %d\n",dayBitNum[0],dayBitNum[1]);
//					printf("%d %d %d %d\n",yearBitNum[0],yearBitNum[1],yearBitNum[2],yearBitNum[3]);
					ans++;
				}
				
			}
			
			
			
			
		}
		
		
		
	}
	
	printf("%d\n",ans);
	return 0;
 } 

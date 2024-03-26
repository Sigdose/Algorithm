//1669_멍멍이쓰다듬기 
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	long long fibo[200001] = {0};
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int X,Y;
	cin >> X >> Y;
	
	int diff = Y-X;
	fibo[0] = 0;
	//fibo[1] = 1; // 1 ;  
	//fibo[2] = 2; // 1 + 1; 
	//fibo[3] = 4; //1 + 2 + 1; 
	//fibo[4] = 6; //1 + 2 + 2 + 1;
	//fibo[5] = 9; //1 + 2 + 3 + 2 + 1;
	if(diff == 0)
	{
		cout<<"0"<<"\n";
		return 0;
	}
	int plus = 1;
	int count = 0;
	for(int i=1;i<200000;i++)
	{
		fibo[i] = fibo[i-1] + plus;
		count++;
		if(count == 2) //2번의주기마다 plus하는 수를 1증가 
		{
			count = 0;
			plus ++;
		}
		if(diff >= fibo[i-1] && diff <= fibo[i])
		{
			cout << i << "\n";
			return 0;
		}
	}
	
	/*
	for(int i=0;i<100000;i++) //예제출력 
	{
		cout<<i<<" "<<fibo[i]<<"\n";
	}
	*/
	
	return 0; 
}

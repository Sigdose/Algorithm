//2805_나무자르기 
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long N,M;
	
	
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+N);
	long long sol = 0;
	long long left = 0;
	long long right = 1111111111;
	long long sum=0;
	while(left<=right)
	{
		long long middle = (left+right)/2;
		//cout<<middle<<endl;
		sum = 0LL;
		for(int i=0;i<N;i++)
		{	
			if(middle < arr[i])
			sum += (arr[i]-middle);
		}	
		if(sum<M)
		{
			right = middle - 1;
		}
		else if(sum>=M) 
		{
			if(sol<middle) sol = middle;
			left = middle + 1;
		}
	}
	cout << sol;
}

//16206_������ũ 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool Comp(int a,int b)
{
	if(a%10==0 && b%10==0) //�Ѵ� 10�ǹ���϶� �������� 
	{
		if(a<b) return true;
		else return false;
	}
	//10�ǹ���� ������ 
	else if(a%10==0 && b%10!=0)
		return true;
	else if(a%10!=0 && b%10==0)
		return false; 
	else  //�������� 
	{
		if(a<b) return true;
		return false;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,M;
	int count = 0;
	int answer = 0;
	vector<int> v;
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),Comp);
	
	for(int i=0;i<v.size();i++)
	{	 
		//cout<<"v[i]:"<<v[i]<<"  v.size: "<<v.size()<<" answer : "<<answer<<endl;
		while(v[i] > 10)
		{
			if(count==M) break;
			v[i] -= 10;
			answer++;
			count++;
		}
		if(v[i]==10)
		{
			answer++;
		}
		if(count==M)
		{
			break;
		}
	}
	cout << answer << endl;
	return 0; 
}

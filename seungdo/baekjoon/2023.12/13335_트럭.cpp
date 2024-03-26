//13335_트럭 
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	queue<pair<int,int> > q; //first = time , second = weight;
	vector<int> truck;
	int n,w,l,count=0;
	int time=1;
	int bridge_weight=0;
	
	bool flag;
	
	cin>>n>>w>>l;
	
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		truck.push_back(temp);
	}
	int i = 0;

	while(true)
	{
		if(q.empty()==false)
		{
			if(time == q.front().first + w) //다리길이만큼 지나오면 나가게해주기 
			{
				bridge_weight -= q.front().second;
				q.pop(); //다리를 지나감
				count++; 	//몇대의 트럭이 나갔는지 
				if(count == n) break; //트럭이 다 지나가면
			}
		}
		if(i< n && bridge_weight+truck[i] <= l) //벡터 범위내에서 , 다리가 다음트럭의 하중을 견딜수있다면 
		{
			bridge_weight += truck[i];
			q.push(make_pair(time,truck[i])); //진입시각 , 해당트럭무게 저장 
			i++;
		}
		time++;
	}
	cout<<time<<"\n";
	return 0;
}

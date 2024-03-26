//2170 ¼±±ß±â 
#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    int x,y;
    long long ans = 0LL;
    cin >> N;
    vector<pair<int,int>> v(N,{0,0});
    
    
    for(int i=0;i<N;i++)
    {
    	cin>>x>>y;
    	if(x>y)
		{
    		int temp = x;
    		x = y;
    		y = temp;
		}
		v[i] = {x,y};
	}
    
    x = v[0].first;
    y = v[0].second;
    for(int i=1;i<N;i++)
    {
    	if(v[i].first < y)
    	{
    		if(y < v[i].second)
    		{
    			y = v[i].second;
			}
		}	
    	else
		{
    		ans += y-x;
    		x = v[i].first;
    		y = v[i].second;
		}
	}
	ans += y - x;
	cout << ans << "\n";
    
    
    return 0;
}

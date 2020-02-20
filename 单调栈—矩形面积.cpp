#include<iostream>
#include<stack> 
#include<vector>
using namespace std;
int main()
{
	vector<int> heights;
	int N,t,max=0,area;
	cin>>N; 
	while(N--)
	{
		cin>>t;
		heights.push_back(t);
	}
	heights.push_back(-1);
	stack<int> up;
	for(int i=0;i<heights.size();i++)
	{
		if(up.empty() || heights[up.top()]<=heights[i]) up.push(i);
		else
		{		
			while(!up.empty()&&heights[up.top()]>heights[i])
			{
				t=up.top();	
				area=(i-t)*heights[up.top()];
				max=area>max ? area : max;
				up.pop();
			}
			if((i+1-t)*heights[i]>max) max=(i+1-t)*heights[i];
			cout<<(i+1-t)*heights[i]<<endl;
            up.push(i);
			//up.push(t);
			//heights[t]=heights[i];//特殊情况，向左扩展 
		}
	}
	cout<<max;
	return 0;
}

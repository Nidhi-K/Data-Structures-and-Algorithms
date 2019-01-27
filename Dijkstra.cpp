#include<bits/stdc++.h>
using namespace std;

int n,m,a,b,source;
vector <pair<int,int> > graph[112345];
priority_queue<pair <int,int> >pq;
int d[112345];

int main()
{
	int i,u,v,w;
	
	cin>>n>>m;
	
	for(i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(w,v));
		graph[v].push_back(make_pair(w,u));
	}
	
	for(i=0;i<n;i++)
		d[i]=-1;
	
	source=0;
	
	pq.push(make_pair(0,source));
	
	pair<int,int> tp;
	
	int min_dist,node;
	
	while(!pq.empty())
	{
		tp=pq.top();
		pq.pop();
		min_dist=-tp.first;
		node=tp.second;
		if(d[node]==-1)
		{
			d[node]=min_dist;
			for(auto child:graph[node])
			{
				if(d[child.second]==-1)
					pq.push(make_pair(-(child.first+min_dist),child.second));
			}
		}		
	}
	
	for(int i=0;i<n;i++)
		cout<<"i:"<<i<<" "<<d[i]<<endl;
	
	return 0;
}
		

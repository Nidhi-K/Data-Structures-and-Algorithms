#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector <int> g[11];
int x;

void dfs(int node, int num)
{
   
    cout<<num<<" ";
   
    for(int i=0;i<g[node].size();i++)
    {
        int next_num = num*10 + g[node][i];
        
        if(next_num<=x) 
        {
           // cout<<"next_num:"<<next_num<<endl;
            dfs(g[node][i],next_num);
        }
    }
    
    //cout<<"after:"<<num<<endl;    
    if(num<9)
    {
        //cout<<num<<"less ";
        dfs(g[node][1],num+1);
    }
}

int main() 
{
	//code
	
	for(int i=0;i<9;i++)
	{
	    g[i].pb(i+1);
	    g[i+1].pb(i);
	}
	
/*	for(int i=0;i<10;i++)
	{
	    cout<<i<<": ";
	    for(int j=0;j<g[i].size();j++)
	        cout<<g[i][j]<<" ";
	    cout<<endl;
	}
*/	
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x;
        cout<<0<<" ";
        dfs(1,1);
        cout<<endl;
    }
    //cout<<"\nblah\n";
    return 0;
}

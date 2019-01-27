//second most common string
#include <bits/stdc++.h>
using namespace std;

unordered_map <string, int> um;
unordered_map <string, int>:: iterator it;


int main() 
{
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    um.clear();

	    int n;
	    cin>>n;
	    string s;
	    for(int i=0;i<n;i++)
	    {
	        cin>>s;
	        um[s]++;
	    }
	    
	    int max=0,sm=0;
	    
	    for(it=um.begin();it!=um.end();it++)
	    {
	      if (it->second>max) max=it->second;
	      
	    }
	    
	    string ans;
	    
	    for(it=um.begin();it!=um.end();it++)
	    {
	      if (it->second>sm && it->second<max) 
	      {
	          sm=it->second;
	          ans = it->first;
	      }
	    }
	    
	    cout<<ans<<endl;
	}
	
	return 0;
}

/*
2
6
aaa bbb ccc bbb aaa  aaa
6
geeks for geeks for geeks aaa
*/

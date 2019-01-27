#include <bits/stdc++.h>
using namespace std;

int main() 
{
	//code
    int t;
    cin>>t;
    while(t--)
    {
        string s[110];
        
        int n;
        cin>>n;
        int ml=INT_MAX;
        for(int i=0;i<n;i++) 
        {
            cin>>s[i];
            int l = s[i].length();
           	ml=min(ml,l);
        }
      
        int done=0;
        for(int p=0;p<ml && !done;p++)
        {
            for(int i=1;i<n;i++)
            {
               	if(s[i][p]!=s[0][p]) 
                {
                   done=1;
                   break;                               
                }                
            }
            
            if(!done) cout<<s[0][p];
            if(done || (p==ml-1))
            {
            	if(p==0 && done) cout<<-1<<endl;
            	else cout<<endl;
            	break;
            }
        }
        

     }
    
	return 0;
}

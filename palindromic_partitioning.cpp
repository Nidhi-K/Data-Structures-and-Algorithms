#include <bits/stdc++.h>
using namespace std;

int p[1123][1123];
int cut[1123];

int main() 
{
	//code
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        
        for(int l=1;l<=n;l++)
        {
            for(int i=0;(i+l-1)<n;i++)
            {
                if(l==1) { p[i][i]=1;continue; }
                if(l==2 && s[i]==s[i+l-1]) { p[i][i+l-1] =1; continue;}
                
                if(s[i]!=s[i+l-1])
                {
                    p[i][i+l-1] = 0;
                    continue;
                }
                
                else
                {
                    p[i][i+l-1] = p[i+1][i+l-2];
                }
            }
        }
        
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<p[i][j]<<" ";
            cout<<endl;
        }
        */
      
        for(int i=0;i<n;i++)
        {
            if(p[0][i]) { cut[i]=0; continue; }
            
            cut[i]=INT_MAX;
            
            for(int j=0;j<i;j++)
            {
                if(p[j+1][i])
                    cut[i] = min(cut[i], 1 + cut[j]);
            }
            
            //cout<<s[i]<<":"<<cut[i]<<endl;
        }
        
        
        cout<<cut[n-1]<<endl;
        
    }
    
	return 0;
}

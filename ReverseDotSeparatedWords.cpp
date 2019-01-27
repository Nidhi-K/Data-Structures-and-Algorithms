#include <bits/stdc++.h>
using namespace std;

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
        int wc=0;
        
        for(int i=0;i<n;i++)
        {
              if(s[i]!='.' && i!=(n-1))
              {
                  wc++;
                  continue;
              }
              
              if(s[i]=='.' || i==n-1)
              {
                  if(i==n-1) {i++; wc++;}
                 // cout<<wc<<" "<<i-wc<<" "<<wc/2 + i-wc<<endl;
                  for(int j=i-wc;j<wc/2 + i-wc;j++)
                  {
                      int temp=s[j];
                      s[j]=s[2*i-j-1-wc];
                      s[2*i-j-1-wc]=temp;
                  }
                  wc=0;
              }
        }
        
        cout<<s<<endl;
    }
    
	return 0;
}

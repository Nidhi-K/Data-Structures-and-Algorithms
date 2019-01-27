#include <bits/stdc++.h>

using namespace std;

int dp[11234][11234];

int main()
{
	
	string s1,s2;
	
	cin>>s1>>s2;
	
	int n1 = s1.length();
	int n2 = s2.length();
	
	for(int i=0;i<=n1;i++)
	{
		dp[i][0] = 1;
	}
	
	for(int j=0;j<=n2;j++)
	{
		dp[0][j] = 0;
	}	
	
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				//dp[i][j]=1+dp[i-1][j-1];
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]);
			}
			
			else
			{
				//dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	
	/*
	int n3=dp[n1][n2];
	//string s3;
	char s3[n3];
	s3[n3]='\0';
	
	int i=n1,j=n2,k=n3-1;
	
	while(i>0 || j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			s3[k--]=s1[i-1]; //cout<<s1[i-1]<<" "<<s3[k+1]<<" "<<k<<" "<<endl;
			i--;
			j--;
		}
		
		else
		{
			if(dp[i-1][j] > dp[i][j-1])
			{
				i--;
			}
			
			else
			{
				j--;
			}
		}		
	}
	
	cout<<n3<<" "<<s3<<endl;
	*/
	
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			//cout<<dp[i][j]<<" ";
		}	
		
		//cout<<endl;
	}
	
	cout<<dp[n1][n2]<<endl;
	
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int a[1123345];

int main()
{
	int n;
	cin>>n;
	
	int plus=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>=0) plus=1;
	}
	
	if(!plus)
	{
		int m=0,i=0;
		while(i<n)
		{
			if(a[i]>a[m]) m=i;
			i++;
		}
		
		cout<<m<<" "<<m<<" "<<a[m]<<endl;
		
		return 0;
	}	
	
	int s=0,e=0,true_s=0;
	int maxsum=-1,sum=0;
	for(int i=0;i<n;i++)
	{
		//cout<<"i:"<<i<<" a[i]:"<<a[i];
		sum+=a[i];
		if(sum>maxsum)
		{
			maxsum=sum;
			e=i;
			true_s=s;
		}
		
		if(sum<0)
		{
			sum=0;
			s=i+1;
		}
		
		//cout<<" sum:"<<sum<<" max_sum:"<<maxsum<<" true_s:"<<true_s<<" e:"<<e<<endl; 
	}	
	
	cout<<true_s<<" "<<e<<" "<<maxsum<<endl;
	
	return 0;
}

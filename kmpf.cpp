#include <bits/stdc++.h>

using namespace std;

int lps[112345];

int main()
{
	string text,pat;
	
	getline(cin,pat);
	getline(cin, text);	
	//cout<<text<<endl<<pat<<endl;
	int ltext=text.length();
	int lpat=pat.length();
	
	int i=1,s=0;
	while(i<lpat)
	{
		//cout<<"i: "<<i<<"  s: "<<s<<endl;
		if(pat[i]==pat[s])
		{
			s++;
			lps[i]=s;
			i++;
		}
		else
		{
			if(s==0)
			{
				lps[i]=s;
				i++;
			}
			else
			{
				s=lps[s-1];
			}			
		}
	}//end of while
	//cout<<"~~"<<text[50]<<"~~"<<endl;
	for(int i=0;i<lpat;i++)
		cout<<pat[i]<<": "<<lps[i]<<endl;
	int ti=0,pi=0;
	int f=0;
	while(ti<ltext)
	{
		//cout<<"Text: "<<text[ti]<<"  Pat: "<<pat[pi]<<endl;
		if(text[ti]==pat[pi])
		{
			ti++;pi++;
		}
		else
		{
			if(pi==0) ti++;
			else
			{
				pi=lps[pi-1];
			}
		}
		
		if(pi==lpat)
		{
			cout<<ti-pi+1<<endl;
			pi=lps[pi-1];
			f=1;
		}
	}
	
	if(!f) cout<<-1;
	
	return 0;
}

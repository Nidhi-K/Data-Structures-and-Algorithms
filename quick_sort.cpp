#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int n;

void swap( int &a, int &b)
{
	int temp = a;
	a=b;
	b=temp;
}
int partition(int ar[],int l, int r)
{
	cout<<l<<" "<<r<<endl;
	int p=ar[r];
	int i,j=l-1,temp;
	for(i=l;i<r;i++)
	{
		if(ar[i]<p)
		{
			j++;
			//temp=ar[i];
			//ar[i]=ar[j]; //swap a[i] and a[j]
			//ar[j]=temp;
			
			swap(ar[i],ar[j]);
		}
	}
	j++;
	//temp=ar[r];
	//ar[r]=ar[j]; //swap a[r] and a[j] 
	//ar[j]=temp;
	swap(ar[r],ar[j]);

	return j;

}

void quick_sort(int ar[], int l, int r,int n)
{
	if(l<r)
	{
		int p = partition(ar,l,r);	
		quick_sort(ar,l,p-1,n);
		quick_sort(ar,p+1,r,n);
	}



}

int main()
{
   cin>>n;
   int ar[n], i;
   for(i = 0; i < n; i++) 
   {
      scanf("%d", &ar[i]);
   }
long long a = LONG_MIN;
cout<<a<<endl;
   quick_sort(ar,0,n-1,n);
   
   for(int i=0;i<n;i++) cout<<ar[i]<<" ";
 
   return 0;
}

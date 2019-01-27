//min_heap

#include <bits/stdc++.h>

using namespace std;

int a[112345];

int lchild(int i)
{
	return 2*i;
}

int rchild(int i)
{
	return 2*i + 1;
}

int parent( int i)
{
	return i/2;
}

void min_heapify(int a[], int n, int pos)
{
	//cout<<"pos:"<<pos<<endl;
	//for(int i=0;i<n;i++)
	//	cout<<a[i]<<" ";
	//cout<<endl;
	
	int min_pos = pos;
	
	int l = lchild(pos);
	int r = rchild(pos);
	
	if(l < n && a[l] < a[min_pos])
		min_pos = l;
	
	if(r < n && a[r] < a[min_pos])
		min_pos = r;
	
	if(min_pos != pos)
	{
		int temp = a[pos];
		a[pos] = a[min_pos];
		a[min_pos] = temp;
		
		min_heapify(a,n,min_pos);
	}	
}

void build_min_heap(int a[], int n)
{
	for(int i=n/2;i>=0;i--)
	{
		//cout<<"i:"<<i<<endl;
		min_heapify(a,n,i);
	}
}

void heapsort(int a[], int n)
{
	build_min_heap(a,n);
	
	for(int i=n;i>0;i--)
	{
		int temp = a[i];
		a[i]=a[0];
		a[0]=temp;
		
		min_heapify(a,i,0);
	}
}

int heap_minimum(int a[],int n)
{
	if (n>0)
		return a[0];
}

int heap_extract_minimum(int a[], int n)
{
	int min = a[0];
	
	int temp = a[0];
	a[0] = a[n-1];
	a[n-1] = a[0];
	min_heapify(a,n-1,0);
	
	return min;
}

void heap_decrease_key(int a[], int pos, int val)
{
	if(a[pos] < val) return;
	
	a[pos] = val;
	
	while(a[parent(pos)] > a[pos])
	{
		int temp = a[parent(pos)];
		a[parent(pos)] = a[pos];
		a[pos] = temp;
		
		pos = parent(pos);
	}
	 
}

void min_heap_insert(int a[], int n, int val)
{
	n++;
	a[n-1] = INT_MAX;
	
	heap_decrease_key(a,n-1,val);
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
	build_min_heap(a,n);
	 //sorts in descending order. for ascending, use maxheap.
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
	int ch =5;
	
	while(ch!=0)
	{
		cout<<"1. heap_minimum\n2.heap_extract_minimum\n3.heap_decrease_key\n4.min_heap_insert\n0.exit: ";
		cin>>ch;
		
		switch (ch)
		{
			case 1: cout<<heap_minimum(a,n)<<endl; break;
			case 2: cout<<heap_extract_minimum(a,n)<<endl; n--;break;
			case 3:	int v,pos; cin>> v>>pos; heap_decrease_key(a,pos,v); break;
			case 4: int ins; cin>>ins; min_heap_insert(a, n, ins); n++; break;
			case 0: return 0; break;
						
			//heapsort(a,n);
		}
		
		
			for(int i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout<<endl;
	}

	
	return 0;
}	

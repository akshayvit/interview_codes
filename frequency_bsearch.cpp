#include <bits/stdc++.h>
using namespace std;

main()
{
	int arr[]={1,2,3,3,3,3,5};
	int n=7;
	int l=0,r=n-1,c=0,k=3;
	while(r-l>1)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]>=k)
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	int a=l;
	l=0,r=n-1;
	while(r-l>1)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]<=k)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	cout<<l-a;
}

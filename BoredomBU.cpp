#include<iostream>
using namespace std;
long long int tab[100002],a[100002];
int g,n,mx;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>g;
		a[g]++;
		if(mx<g) mx=g;
	}
	tab[0]=0;
	for(int i=1;i<=mx;i++)
		tab[i]=tab[i-1]>tab[i-2]+a[i]*i ? tab[i-1]:tab[i-2]+a[i]*i; 
	cout<<tab[mx];
}


#include<cstdio>
#include<list>
using namespace std;
bool _(int a,int b) {return a==b;}
int n,k,a,b,c,t;
list<int> mlist;
main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c);
		if(i==1) if(b>c) mlist.push_back(b);
		if(i>=2) if(b>c&&b>a) mlist.push_back(b);
		if(i==n-1&&c>b) mlist.push_back(c);
		a=b;b=c;
	}
	if(mlist.size()==0)
	{
		printf("-1");
		return 0;
	}
	mlist.sort();
	mlist.unique(_);
	if(mlist.size()<k) for(list<int>::iterator it=mlist.begin();it!=mlist.end();it++)
		printf("%d\n",*it);
	else for(list<int>::reverse_iterator it=mlist.rbegin();it!=mlist.rend()&&t!=k;it++,t++)
		printf("%d\n",*it);
}

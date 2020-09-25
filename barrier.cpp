#include<cstdio>
#include<queue>
using namespace std;
int s=2e9,m,n,k,a[6000002];
deque<pair<int,int> > Q;
pair<int,int> p;
main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
		p.first=a[i],p.second=i;
		while(!Q.empty()) {
			if(Q.back().first>=a[i]) Q.pop_back();
			else break;
		}
		Q.push_back(p);
		if(i-Q.front().second>k) Q.pop_front();
		if(m==a[i]-Q.front().first)
			s=s<i-Q.front().second?s:i-Q.front().second;
		if(m<a[i]-Q.front().first)
			m=a[i]-Q.front().first,s=i-Q.front().second;
	}
	printf("%d\n%d",m,s);
}

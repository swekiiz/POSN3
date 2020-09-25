#include<cstdio>
#include<algorithm>
int n,T,l=-1,cc;
struct ms{int s;int e;}t[1000];
bool c(ms a,ms b){return a.e<b.e;}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){scanf("%d %d",&t[i].s,&T);t[i].e=t[i].s+T-1;}
	std::sort(t,t+n,c);
	for(int i=0;i<n;i++){
		if(t[i].s>l){
			l=t[i].e;
			cc++;
			printf("%d %d\n",t[i].s,t[i].e);
		}
	}
	printf("%d",cc);
}

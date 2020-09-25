#include<bits/stdc++.h>
using namespace std;
struct h{int x,a;}p[1500000];
int m,k,q,a[700001],g,l,r,h;
main(){
	scanf("%d %d",&m,&k);
	for(int i=0;i<m;i++) scanf("%d",&a[i]);
	sort(a,a+m);
	for(int i=0;i<m;){
		int z=i,c=0;
		if(i!=m-1) for(int j=i;a[j]==a[j+1]-1;j++) z=j+1,c++;
		p[g].a=a[i]-1;
		p[g++].x=a[i]-q-1;
		p[g].a=a[z]+1;
		p[g++].x=a[z]-q-c;
		i+=c+1;
		q+=c+1;
	}
	for(int i=0;i<k;i++){
		scanf("%d",&q);
		l=0,r=g-1;
		while(1){
			h=(l+r)/2;
			if(p[h].x==q) break;
			if(q>p[h].x) l=h+1;
			else r=h-1;
			if(l>r){
				h=-1;
				break;
			}
		}
		if(h!=-1) printf("%d ",p[h].a);
		else printf("%d ",p[r].a-p[r].x+q);
	}
}

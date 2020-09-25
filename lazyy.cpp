#include<bits/stdc++.h>
using namespace std;
int n,q,t,m,a,b,l,r;
map<int,vector<int> > h;
int bs(int l,int r,int w,bool x){
	if(l>r) return x?r:l;
	int m=l+(r-l)/2;
	if(h[t][m]==w) return m;
	if(h[t][m]<w) return bs(m+1,r,w,x);
	return bs(l,m-1,w,x);
}
main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		h[t].push_back(i);
	}
	while(q--){
		scanf("%d %d %d",&a,&b,&t);
		if(h[t].empty()) printf("0\n");
		else printf("%d\n",bs(0,h[t].size()-1,b,1)-bs(0,h[t].size()-1,a,0)+1);
	}
}

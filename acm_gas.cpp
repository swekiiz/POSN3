#include<bits/stdc++.h>
using namespace std;
struct pr{int x,w;bool operator<(const pr &a)const{return a.w<w;};}tp;
pr mp(int a,int b){pr t;t.x=a,t.w=b;return t;}
int n,q,s,e,p,t1,t2,w,d[101];
vector<pr> v[101];
priority_queue<pr> Q;
main(){
	scanf("%d",&q);
	while(q-->0){
		for(int i=0;i<101;i++){
			v[i].clear();
			d[i]=INT_MAX;
		}
		while(!Q.empty()) Q.pop();
		scanf("%d %d %d %d",&n,&s,&e,&p);
		for(int i=0;i<p;i++){
			scanf("%d %d %d",&t1,&t2,&w);
			v[t1].push_back(mp(t2,w));
		}
		d[s]=0;
		for(Q.push(mp(s,0));!Q.empty();Q.pop()){
			tp=Q.top();
			if(tp.x==e) break;
			for(int i=0;i<v[tp.x].size();i++){
				if(d[v[tp.x][i].x]>d[tp.x]+v[tp.x][i].w){
					d[v[tp.x][i].x]=d[tp.x]+v[tp.x][i].w;
					Q.push(mp(v[tp.x][i].x,d[tp.x]+v[tp.x][i].w));
				}
			}
		}
		printf("%d\n",d[e]==INT_MAX?0:d[e]);
	}
	
}

#include<bits/stdc++.h>
using namespace std;
struct pa{int x,c;bool operator<(const pa &A)const{return c>A.c;}}nw,e[200001];
pa mp(int b,int a){pa T;T.c=a,T.x=b;return T;}
int w,n,q,m,p=2e9,su,s,ds[100001],dq[100001];
vector<pa> v[100000];
priority_queue<pa> Q;
bool ch[100001];
main(){
	scanf("%d %d %d %d",&n,&m,&s,&q);
	for(int i=0;i<100001;i++) ds[i]=INT_MAX,dq[i]=INT_MAX;
	ds[s]=0,dq[q]=0;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&e[i].x,&e[i].c,&w);
		v[e[i].x].push_back(mp(e[i].c,w));
		v[e[i].c].push_back(mp(e[i].x,w));
		su+=w;
	}
	for(Q.push(mp(s,0));!Q.empty();Q.pop()){
		nw=Q.top();
		if(!ch[nw.x]){
			ch[nw.x]=true;
			for(int i=0;i<v[nw.x].size();i++){
				if(ds[nw.x]+v[nw.x][i].c<ds[v[nw.x][i].x]){
					ds[v[nw.x][i].x]=ds[nw.x]+v[nw.x][i].c;
					Q.push(mp(v[nw.x][i].x,ds[nw.x]+v[nw.x][i].c));
				}
			}
		}
	}
	for(int i=0;i<100001;i++) ch[i]=false;
	for(Q.push(mp(q,0));!Q.empty();Q.pop()){
		nw=Q.top();
		if(!ch[nw.x]){
			ch[nw.x]=true;
			for(int i=0;i<v[nw.x].size();i++){
				if(dq[nw.x]+v[nw.x][i].c<dq[v[nw.x][i].x]){
					dq[v[nw.x][i].x]=dq[nw.x]+v[nw.x][i].c;
					Q.push(mp(v[nw.x][i].x,dq[nw.x]+v[nw.x][i].c));
				}
			}
		}
	}
	for(int i=0;i<m;i++) p=min(p,min(ds[e[i].x]+dq[e[i].c],ds[e[i].c]+dq[e[i].x]));
	printf("%d",su-p);
}


#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > a[100001];
class pl{public:bool operator()(pair<int,int> a,pair<int,int> b){return a.second<b.second;}};
priority_queue<pair<int,int>,vector<pair<int,int> >,pl> Q;
int n,m,b,c,d,s1,e1,s2,e2,f[100001];
vector<int> g[100001];
pair<int,int> p;
bool ch[100001],hc[100001];
void x(int s){
	if(hc[s]) return;
	hc[s]=true;
	for(int i=0;i<g[s].size();i++) x(g[s][i]);
}
void z(int s,int t){
	for(int i=0;i<100001;i++) g[i].clear(),f[i]=INT_MAX,ch[i]=false;
	hc[s]=true;
	p.first=s,p.second=0,f[s]=0;
	for(Q.push(p);!Q.empty();Q.pop()){
		p=Q.top();
		if(ch[p.first]) continue;
		ch[p.first]=true;
		printf("%d => %d\n",p.first,p.second);
		for(int i=0;i<a[p.first].size();i++){
			if(f[p.first]+a[p.first][i].second==f[a[p.first][i].first]){
				if(hc[a[p.first][i].first]){
					x(p.first);
				}
				else g[a[p.first][i].first].push_back(p.first);
			}
			else if(!ch[a[p.first][i].first]&&f[p.first]+a[p.first][i].second<f[a[p.first][i].first]){
				if(a[p.first][i].first==t) x(t);
				f[a[p.first][i].first]=f[p.first]+a[p.first][i].second;
				g[a[p.first][i].first].push_back(p.first);
				Q.push(make_pair(a[p.first][i].first,f[a[p.first][i].first]));
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d - ",f[i]);
	}puts("");
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d %d %d",&b,&c,&d);
		a[c].push_back(make_pair(b,d));
		a[b].push_back(make_pair(c,d));
	}
	scanf("%d %d %d %d",&s1,&e1,&s2,&e2);
	z(s1,e1);
	for(int i=0;i<200;i++) if(hc[i]) printf("%d ",i);
	printf("%d",f[e1]);
}

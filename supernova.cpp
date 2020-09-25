#include<bits/stdc++.h>
using namespace std;
struct eg{int s,e,i;}ed[2002],tp;
int n,t,k[2002],a[2002];
bool cc[2002],ch[2002];
vector<int> v[2002];
int dfs(int x,int p){
	ch[x]=true;
	for(int i=0;i<v[x].size();i++){
		if(ch[v[x][i]]&&v[x][i]!=p){
			cc[x]=true;
			return v[x][i];
		}
		if(!ch[v[x][i]]){
			int temp=dfs(v[x][i],x);
			if(temp==x){
				cc[x]=true;
				return -1;
			}
			if(temp!=-1){
				cc[x]=true;
				return temp; 
			}
		}
	}
	return -1;
}
int ds(int x){
	int s=1;
	ch[x]=true;
	for(int i=0;i<v[x].size();i++) if((!cc[v[x][i]])&&(!ch[v[x][i]])) s+=ds(v[x][i]);
	return k[x]=s;
}
main(){
	scanf("%d %d",&n,&t);
	for(int i=0;i<n;i++){
		ed[i].i=i;
		scanf("%d %d",&ed[i].s,&ed[i].e);
		v[ed[i].s].push_back(ed[i].e);
		v[ed[i].e].push_back(ed[i].s);
	}
	dfs(1,-1);
	for(int i=0;i<2002;i++) ch[i]=false;
	for(int i=1;i<=n;i++) 
		if(cc[i]){
			ds(i);
			k[i]=INT_MAX;
		}
	for(int i=0;i<n;i++)
		if(cc[ed[i].s]&&cc[ed[i].e]) printf("0 ");
		else printf("%d ",min(k[ed[i].s],k[ed[i].e])*(n-min(k[ed[i].s],k[ed[i].e])));
}

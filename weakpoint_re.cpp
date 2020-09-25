#include<bits/stdc++.h>
using namespace std;
vector<int> a[500001];
int n,m,t1,t2,mx=-1,y;
bool ch[500001],cy[500001];
int dp(int x){
	int s=0,t=0;
	bool b=false;
	if(a[x].size()==1&&x!=m) return 1;
	for(int i=0;i<a[x].size();++i){
		if(!ch[a[x][i]]){
			ch[a[x][i]]=true;
			t=dp(a[x][i]);
			s+=t;
			if(t==0) b=true;
		}
		else if(a[x][i]==m) b=true;
	}
	if(mx<s&&x!=m) mx=s,y=x;
	else if(mx==s&&x!=m&&x<y) y=x;
	if(b||cy[x]){ 
		cy[x]=true;
		return 0;
	}
	return s+1;
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&t1,&t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	ch[m]=true;
	dp(m);
	printf("%d\n%d",y,mx);
}

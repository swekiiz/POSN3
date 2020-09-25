#include<bits/stdc++.h>
using namespace std;
struct st{
	int no,k,te;
	bool operator<(const st &r)const{
		if(r.k==k){
			if(r.te==te) return no>r.no;
			else return te>r.te;
		}
		else return k>r.k;
	}
}nw;
priority_queue<st> Q;
queue<int> q;
bool h[100001];
st mp(int a,int b,int c){st t;t.te=c,t.k=b,t.no=a;return t;}
int b,d[100001],y,n,p,t,te[100001],mi[100001],t1,t2,t3,R[10001];
vector<int> v[100001],s,u;
vector<st> o;
int ds(int x){
	if(mi[x]!=INT_MAX) return mi[x];
	for(int i=0;i<v[x].size();i++) mi[x]=min(ds(v[x][i]),mi[x]);
	return mi[x]=min(mi[x],te[x]);
}
main(){
	scanf("%d %d %d",&n,&p,&t);
	for(int i=1;i<100001;i++) mi[i]=INT_MAX;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&t1,&t2);
		if(t2==0) s.push_back(i),q.push(i);
		d[i]=t2,te[i]=t1,R[t1]++;
		for(int j=0;j<t2;j++){
			scanf("%d",&t3);
			v[t3].push_back(i);
		}
	}
	o.push_back(mp(0,0,0));
	if(s.empty()){
		printf("-1");
		return 0;
	}
	for(;!q.empty();q.pop()){
		for(int i=0;i<v[q.front()].size();i++) if(--d[v[q.front()][i]]==0) q.push(v[q.front()][i]);
		b++;
	}
	if(b!=n){
		printf("-1");
		return 0;
	}
	for(int i=0;i<s.size();i++) ds(s[i]);
	for(int i=1;i<=n;i++) Q.push(mp(i,mi[i],te[i]));
	for(;!Q.empty();Q.pop()) o.push_back(Q.top());
	for(int i=1;i<=t+1;i++) if(o[i-1].k!=o[i].k) y=i-1;
	for(int i=1;i<=y;i++) u.push_back(o[i].te);
	sort(u.begin(),u.end());
	for(int i=1;i<=y;i++){
		R[o[i].te]--;
	}
//	
//	
//	puts("");for(int i=1;i<=n;i++) {for(int j=0;j<v[i].size();j++) printf("%d ",v[i][j]);puts("");}
//	for(int i=0;i<o.size();i++){
//		printf("sumkun = %d : radub = %d : node = %d \n",o[i].k,o[i].te,o[i].no);
//	}puts("");
//	for(int i=1;i<=p;i++) printf("%d ",R[i]);puts("");
//	
	for(int i=1;i<=p;i++){
		if(R[i]!=0) break;
		t1=i;
	}
	printf("%d",t1);
}

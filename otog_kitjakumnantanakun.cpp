#include<bits/stdc++.h>
using namespace std;
struct ee{
	int a;
	int b;
	int w;
	bool operator<(const ee &a)const{
		return a.w<w;
	}
}temp;
int n,e,head[100001],sum,t1,t2,w;
priority_queue<ee> Q;
int fi(int x){
	if(head[x]==x) return x;
	return head[x]=fi(head[x]);
}
void ui(int a,int b){
	int A=fi(a),B=fi(b);
	head[A]=head[B];
}
main(){
	scanf("%d %d",&n,&e);
	for(int i=0;i<n;i++) head[i]=i;
	for(int i=0;i<e;i++){
		scanf("%d %d %d",&t1,&t2,&w);
		temp.a=t1,temp.b=t2,temp.w=w;
		Q.push(temp);
	}
	for(;!Q.empty();Q.pop()){
		temp=Q.top();
		if(fi(temp.a)!=fi(temp.b)){
			ui(temp.a,temp.b);
			sum+=temp.w;
		}
	}
	printf("%d",sum);
}





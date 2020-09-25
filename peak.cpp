#include<bits/stdc++.h>
int n,k,a,b,c,r[5000001],p,u;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;a=b,b=c,i++){
		scanf("%d",&c);
		if(i!=0&&b>c&&b>a) r[p++]=b;
		if(n-1==i&&c>b) r[p++]=c;
	}
	std::sort(r,r+p,std::greater<int>());
	for(int i=0;i<p;i++) if(r[i]==r[i+1]) r[i]=0,u++;
	if(p-u==0) puts("-1");
	else if(k<=p-u){
		std::sort(r,r+p,std::greater<int>());
		for(int i=0;i-u<p&&k>0;i++,k--)  printf("%d\n",r[i]);
	}
	else{
		std::sort(r,r+p);
		for(int i=u;i<p&&k>0;i++,k--)  printf("%d\n",r[i]);
	}
}

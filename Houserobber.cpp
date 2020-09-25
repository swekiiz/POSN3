#include<bits/stdc++.h>
using namespace std;
int m[100001],n,a[100001];
int dp(int x){
	if(m[x]!=0) return m[x];
	if(x<0) return 0; 
	return m[x]=max(dp(x-2)+a[x],dp(x-1));
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("%d",dp(n));
}

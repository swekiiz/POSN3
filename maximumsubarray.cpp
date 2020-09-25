#include<bits/stdc++.h>
using namespace std;
int n,a[100000],mx;
int dp(int x){
	if(x<0) return 0;
	int t=max(a[x],dp(x-1)+a[x]);
	mx=max(mx,t);
	return t;
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	dp(n-1);
	printf("%d",mx);
}

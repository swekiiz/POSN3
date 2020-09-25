#include<bits/stdc++.h>
int n,e[200003];
long long mem[200002];
long long po(int x){
	if(!x) return 1;
	if(x%2){
		long long t=po(x>>1);
		return t*t;
	}
	return po(x-1)<<1;
}
main(){
	scanf("%d",&n);
	for(int i=n;i>=1;i--) scanf("%d",&e[i]);
	for(int i=0;i<=n;i++) for(int j=0;;j++){
		long long t=po(j);
		if(t+i>n) break;
		mem[t+i]=std::max(mem[t+i],mem[i]+t*e[t+i]);
	}
	printf("%lld",mem[n]);
}

#include<stdio.h>
int n,q,t;
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int lcm(int a,int b){
	return (a*b)/gcd(a,b);
}
long long p;
main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			p=i==0?t:lcm(p,t);
		}
		printf("%lld\n",p);
	}
}

#include<bits/stdc++.h>
int n,m,p[]={500,800,1500,3000},q[]={1,2,5,15},mem[1000001];
main(){
	std::cin>>n;
	for(int i=1;i<=n;i++){
		mem[i]=m=INT_MAX;
		for(int j=0;j<4;j++)
			mem[i]=std::min(mem[i],std::min(m,((i-q[j]>=0)?mem[i-q[j]]:0)+p[j]));
	}
	std::cout<<mem[n];
}

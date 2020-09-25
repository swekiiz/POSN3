#include<bits/stdc++.h>

int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

int lcm(int a,int b){
	return (a*b)/gcd(a,b);
}

int pw(int a,int b){
	if(b==0) return 1;
	if(b%2) return pw(a,b-1)*a;
	else{
		int t=pw(a,b/2);
		return t*t;
	}
}

std::vector<int> eratosthenes(int n){
	bool check[100000]={0};
	std::vector<int> prime;
	for(int i=2;i<=n;i++){
		if(!check[i]){
			prime.push_back(i);
			for(int j=i+i;j<=n;j+=i){
				check[j]=1;
			}
		}
	}
	return prime;
}

main(){
	std::vector<int> v=eratosthenes(100);
	for(int i=0;i<v.size();i++) printf("%d ",v[i]);
}














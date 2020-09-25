#include<iostream>
using namespace std;
long long int n;
int a[70],c;
main(){
	cin>>n;
	for(;n!=0;n/=2) a[c++]=n%2;
	for(int i=--c;i>=0;i--) cout<<a[i];
	for(int i=0;i<c;i++) a[i]=(a[i]+a[i+1])%2;
	for(cout<<endl;c>=0;c--) cout<<a[c];
}

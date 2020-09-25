#include<iostream>
#include<string>
using namespace std;
int n=1,a[102],p;
main(){
	for(a[0]=1;n<102;n++)
		a[n]=(a[n-1]*2)%5;
	cin>>n;
	string t;
	for(int k=0;k<n;p=0,++k){
		cin>>t;
		for(int i=t.size()-1,j=0;i>=0;i--,j++,p%=5)
			if(t[j]==49) p+=a[i];
		cout<<p<<endl;
	}
}

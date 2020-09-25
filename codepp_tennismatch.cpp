#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,a[6],b[6],w[6];
string t;
main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		a[i]=t.at(0)-'0',b[i]=t.at(2)-'0';
	}
	for(int i=0;i<n;i++){
		if(i!=2){
			if(a[i]==7&&b[i]==6) w[i]=1;
			if(b[i]==7&&a[i]==6) w[i]=2;
			if(a[i]-b[i]>=2&&(a[i]==6||b[i]==6)) w[i]=1;
			if(b[i]-a[i]>=2&&(a[i]==6||b[i]==6)) w[i]=2;
		}
		else{
			if(a[i]-b[i]==2&&a[i]>=6&&b[i]>=6) w[i]=1;
			if(b[i]-a[i]==2&&a[i]>=6&&b[i]>=6) w[i]=2;
		}
		
		if(w[i]==0||n==1){
			cout<<n<<" Sets"<<endl<<"Invalid";
			return 0;
		}
	}
	if(n==2){
		if(w[0]!=w[1]){
			cout<<n<<" Sets"<<endl<<"Invalid";
			return 0;
		}
	}
	cout<<n<<" Sets"<<endl<<"Valid";
}

#include<iostream>
#include<string>
using namespace std;
string c[8]={"11111111","01010101","00110011","00010001","00001111","00000101","00000011","00000001"};
int aa,bb;
main(){
	string a,b,p[8]={"O-","O+","A-","A+","B-","B+","AB-","AB+"};
	cin>>a>>b;
	for(int i=0;i<8;i++){
		if(a==p[i]) aa=i;
		if(b==p[i]) bb=i;
	}
	if(c[aa].at(bb)==48) cout<<a<<" and "<<b<<" are incompatible";
	else cout<<a<<" and "<<b<<" are compatible";
}

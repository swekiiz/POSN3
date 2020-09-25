#include<iostream>
#include<cmath>
using namespace std;
int determinant(int m[20][20],int n) {   
	int det=0;
	int sm[20][20];
	if(n==1) return m[0][0];
	if(n==2) return m[0][0]*m[1][1]-m[1][0]*m[0][1];
	for(int x=0;x<n;x++){
    	int subi=0; 
        for(int i=1;i<n;i++){
        	int subj=0;
        	for(int j=0;j<n;j++){
            	if(j==x) continue;
            	sm[subi][subj]=m[i][j];
            	subj++;
        	}
        	subi++;
    	}
    	det+=(x%2==0?1:-1)*m[0][x]*determinant(sm,n-1);
	}
	return det;
}
main() {
	int n;
	int matrix[20][20];   
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
	cout<<determinant(matrix, n);
}

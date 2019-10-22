#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePaths1(int m, int n) {
    if(m<1||m<1)
		return 0;
	int *grid = new int[m*n];
    int i=0;
    int j=0;
    for(i=0;i<m;i++)
    	grid[i*n]=1;
    for(j=0;j<n;j++)
    	grid[j]=1;
    for(i=1;i<m;i++){
    	for(j=1;j<n;j++){
    		grid[i*n+j]=grid[(i-1)*n+j] + grid[i*n+j-1];
    	}
    }
    return grid[m*n-1];
}

int Cmn(int m, int n){
	double temp = 1.0;
    if(m<n-m)
        return Cmn(n-m, n);
    for(int i=0;i<n-m;i++){
        temp*=m+i+1;
        temp/=i+1;
    }
    return (int)temp;
}

int uniquePaths(int m, int n) {
	if(m<1||m<1)
		return 0;
	return Cmn(m-1,m+n-2);
}

int main(){
	cout<<uniquePaths(7,3);
	return 0;
}
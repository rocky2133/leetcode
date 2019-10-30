#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int countPrimes(int n) {
	if(n<=2)
		return 0;
    bool *count = new bool[n+1];
    for(int i=0;i<=n;i++)
    	count[i]=0;
    int cnt = 0;
    for(int i=2;i<n;i++){
    	if(!count[i])
    		cnt++;
    	for(long long j=i*i;j<n;j+=i)
    		count[j]=true;
    }
    return cnt;
}

int main(){
	cout<<countPrimes(499979)<<endl;
	return 0;
}
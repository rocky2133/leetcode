#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

int trailingZeroes(int n) {
	if(n==0)
		return 0;
	int cnt=0;
	while(n!=0){
		n/=5;
		cnt+=n;
	}
	return cnt;
}

int main(){
	cout<<trailingZeroes(2)<<endl;
	return 0;
}
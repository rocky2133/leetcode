#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int integerBreak(int n) {
	if(n<=3)
		return n-1;
	int n3=n/3;
    if(n%3==1)
    	n3--;
    int n2 = (n-(n3*3))/2;
    int res = pow(3,n3);
    res = res<<n2;
    return res;
}

int main(){
	cout<<integerBreak(10)<<endl;
	return 0;
}
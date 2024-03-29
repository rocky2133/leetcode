#include <iostream>

using namespace std;

int mySqrt(int x) {
	if(x<=1)
		return x;
    int left = 0, right = x;
    while(left<right-1){
    	int mid = left+(right-left)/2;
    	if(x/mid == mid){
    		return mid;
    	}
    	else if(x/mid > mid)
    		left=mid;
    	else
    		right=mid;
    }
    return left;
}

int main(){
	cout<<mySqrt(3)<<endl;
	return 0;
}
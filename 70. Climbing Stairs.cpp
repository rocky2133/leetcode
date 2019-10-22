#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int *cnt;

int step(int n){
	if(n<=0)
		return 0;
	if(cnt[n]){
		return cnt[n];
	}
	else{
		if(n<=2){
			cnt[n] = n;
			return n;
		}
	}
	cnt[n] = step(n-1)+step(n-2);
	return cnt[n];
}

int climbStairs1(int n) {
    cnt = new int[n+1];
    for(int i=0;i<=n;i++)
    	cnt[i]=0;
    return step(n);
}

int climbStairs(int n) {
    if(n<=2)
    	return n;
    int pre2 = 1;
    int pre1 = 2;
    for(int i=2;i<n;i++){
    	int curr = pre1+pre2;
    	pre2 = pre1;
    	pre1 = curr;
    }
    return pre1;
}

int main(){
	cout<<climbStairs(4)<<endl;
	return 0;
}
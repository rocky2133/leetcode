#include <iostream>
#include <queue>

using namespace std;

bool ifSquare(int k){
	for(int i=1;i<=k;i++){
		if(i*i==k)
			return true;
	}
	return false;
}

int numSquares(int n) {
    queue<int> qe;
    qe.push(0);
    int len = 0;
    bool *isSQ = new bool[n+1];
    bool *flag = new bool[n+1];
    for(int i=1;i<=n;i++){
    	flag[i]=1;
    	isSQ[i] = ifSquare(i);
    }
    while(!qe.empty()){
    	int size = qe.size();
    	len++;
    	while(size-->0){
	    	int curr = qe.front();
	    	qe.pop();
	    	for(int i=curr+1;i<=n;i++){
	    		if(flag[i] && isSQ[i-curr]){
	    			if(i==n)
	    				return len;
	    			qe.push(i);
	    			flag[i] = 0;
	    		}
	    	}
	    }
    }
    return 0;
}

int main(){
	cout<<numSquares(12)<<endl;
	return 0;
}
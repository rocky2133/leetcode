#include <iostream>
#include <vector>

using namespace std;

bool *flag;

void countCircle(vector<vector<int> >& M, int x){
	flag[x] = 0;
	for(int i=0;i<M.size();i++){
		if(flag[i] && M[x][i]==1){
			countCircle(M, i);
		}
	}
}

int findCircleNum(vector<vector<int> >& M) {
    int ans = 0;
    int n = M.size();
    flag = new bool[n];
    for(int i=0;i<n;i++)
		flag[i] = 1;
    for(int i=0;i<n;i++){
    	if(flag[i]){
    		countCircle(M, i);
    		ans++;
    	}
    }
    return ans;
}

int main(){

	return 0;
}
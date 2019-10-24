#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void trans(vector<string> &strs){
	for(int i=0;i<strs.size();i++){
		int zeros=0;
		int ones=0;
		for(auto c:strs[i]){
			if(c=='0')
				zeros++;
			else
				ones++;
		}
		string tp = "";
		char c = '0'+zeros;
		tp+=c;
		c='0'+ones;
		tp+=c;
		strs[i]=tp;
	}
}

int findMaxForm(vector<string>& strs, int m, int n) {
    trans(strs);
    int **dp = new int*[m+1];
    for(int i=0;i<=m;i++){
    	dp[i]=new int[n+1];
    	for(int j=0;j<=n;j++)
    		dp[i][j]=0;
    }
    for(str: strs){
    	int vm = str[0]-'0';
    	int vn = str[1]-'0';
    	for(int i=m; i>=vm; i--){
    		for(int j=n; j>=vn; j--){
    			dp[i][j] = max(dp[i][j], dp[i-vm][j-vn]+1);
    		}
    	}
    }
    return dp[m][n];
}

int main(){
	vector<string> temp = {"10", "0", "1"};
	findMaxForm(temp, 1, 1);
	return 0;
}
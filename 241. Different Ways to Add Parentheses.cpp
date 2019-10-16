#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<int> diffWaysToCompute(string input) {
	vector<int> ans;
    for(int i=0;i<input.length();i++){
    	if(input[i]<'0'||input[i]>'9'){
    		vector<int> left = diffWaysToCompute(input.substr(0,i));
    		vector<int> right = diffWaysToCompute(input.substr(i+1));
    		for(int j=0;j<left.size();j++){
    			for(int k=0;k<right.size();k++){
					switch(input[i]){
						case '+':
							ans.push_back(left[j]+right[k]);
							break;
						case '-':
							ans.push_back(left[j]-right[k]);
							break;
						case '*':
							ans.push_back(left[j]*right[k]);
							break;
					}
				}
			}
    	}
    }
    if(ans.size()==0){
    	// cout<<input<<endl;
    	ans.push_back(stoi(input));
    }
    return ans;
}

int main(){
	diffWaysToCompute("2-1-1");
	return 0;
}
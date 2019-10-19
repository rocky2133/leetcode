#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, string> strMap = {
    {1,""},
    {2,"abc"},
    {3,"def"},
    {4,"ghi"},
    {5,"jkl"},
    {6,"mno"},
    {7,"pqrs"},
    {8,"tuv"},
    {9,"wxyz"}
};
string dig;

void addComb(vector<string> &curr, string str){
    if(str.length()==dig.length()){
        curr.push_back(str);
        return;
    }
    for(char c:strMap[(dig[str.length()]-'0')]){
        addComb(curr, str+c);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits=="")
        return ans;
    dig = digits;
    addComb(ans,"");
    return ans;
}

int main(){
    // vector<string> ans;
    // addComb(ans,"");
	vector<string> ans = letterCombinations("");
	for(auto i:ans)
		cout<<i<<endl;
	return 0;
}
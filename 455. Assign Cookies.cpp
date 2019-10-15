#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int ng = 0, ns = 0;
    while(ng<g.size() && ns<s.size()){
    	if(g[ng]<=s[ns])
    		ng++;
    	ns++;
    }
    return ng;
}

int main(){

	return 0;
}
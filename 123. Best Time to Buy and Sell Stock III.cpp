#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int maxProfit(vector<int>& prices) {
	int p1 = INT_MIN;
    int s1 = 0;
    int p2 = INT_MIN;
    int s2 = 0;
    for(auto prc:prices){
        if(p1 < -prc)
            p1 = -prc;
        if(s1 < p1 + prc)
            s1 = p1+prc;
        if(p2 < s1 - prc)
            p2 = s1-prc;
        if(s2 < p2 + prc)
            s2 = p2+prc;
    }
    return s2;
}

int main(){
	vector<int> temp = {1, 3, 2, 8, 4, 9};
	cout<<maxProfit(temp, 2)<<endl;
	return 0;
}
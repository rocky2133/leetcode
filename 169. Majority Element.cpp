#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums) {
    int maj = -1;
    int cnt = 0;
    for(int num: nums){
    	if(cnt==0){
    		maj = num;
    		cnt++;
    	}
    	else{
    		if(num == maj)
    			cnt++;
    		else
    			cnt--;
    	}
    }
    return maj;
}

int main(){
	vector<int> temp = {3,3,4};
	cout<<majorityElement(temp)<<endl;
	return 0;
}
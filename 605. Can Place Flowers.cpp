#include <iostream>
#include <vector>

using namespace std;



bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int left=0, right=0;
    int num = 0;
    if(flowerbed.size()==0)
    	return false;
    flowerbed.insert(flowerbed.begin(),0);
    flowerbed.insert(flowerbed.end(),0);
    while(right<flowerbed.size()){
    	while(left<flowerbed.size() && flowerbed[left]==1) left++;
    	right = left;
    	while(right<flowerbed.size() && flowerbed[right]==0) right++;
    	num+=(right-left-1)/2;
    	// cout<<left<<" "<<right<<" "<<num<<endl;
    	left = right;
    	if(num>=n)
    		return true;
    }
    return false;
}

int main(){
	int a[20] = {0,1,0,0};
	vector<int> fl(a, a+4);
	cout<<canPlaceFlowers(fl,1);
	return 0;
}
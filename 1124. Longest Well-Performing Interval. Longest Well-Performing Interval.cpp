#include<iostream>
#include<vector>

using namespace std;

int longestWPI(vector<int>& hours) {
	vector<int> wpi;
	wpi.push_back(0);
	hours.insert(hours.begin(), 0);
	for(int i=1;i<hours.size();i++){
		if(hours[i]>8)
			hours[i] = hours[i-1]+1;
		else
			hours[i] = hours[i-1]-1;
	}
	int ans = 0;
	for(int i=0;i<hours.size()-ans;i++){
		for(int j=hours.size()-1;j>i;j--){
			if(hours[j]-hours[i]>=1){
				if((j-i)>ans)
					ans = j-i;
				break;
			}
		}
	}
	return ans;
}

int main(){
	int a[7] = {};
	vector<int> hours(a, a+0);
	cout<<longestWPI(hours)<<endl;
	return 0;
}
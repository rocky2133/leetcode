#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class temp
{
public:
	int first;
	int second;
	temp(){};
	temp(int a, int b){first = a; second = b;};
};

bool operator <(const temp &t1, const temp &t2){return t1.second > t2.second;}

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> mp;
    map<int, int>::iterator iter;
    for(int i=0;i<nums.size();i++){
    	iter = mp.find(nums[i]);
    	if(iter!=mp.end())
    		iter->second++;
    	else
    		mp[nums[i]]=1;
    }
    priority_queue<temp> que;
    for(iter = mp.begin(); iter!=mp.end(); iter++){
    	temp tp(iter->first, iter->second);
    	que.push(tp);
    	
    	if(que.size()> k){
    		que.pop();
    	}
    }
    vector<int> ans;
    while(!que.empty()){
    	ans.push_back(que.top().first);
    	cout<<que.top().first<<" : "<<que.top().second<<endl;
    	que.pop();
    }
    return ans;
}

int main(){
	int a[20] = {1,1,1,2,2,3,3,3,3};
	vector<int> nums(a, a+9);
	vector<int> ans = topKFrequent(nums, 2);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}
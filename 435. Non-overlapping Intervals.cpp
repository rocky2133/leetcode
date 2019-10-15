#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool mysort(const vector<int> &t1, const vector<int> &t2){
	return t1[1]<t2[1];
}

int eraseOverlapIntervals(vector<vector<int> >& intervals) {
    sort(intervals.begin(), intervals.end(), mysort);
    int right = INT_MIN;
    int num = 0;
    for(int i=0;i<intervals.size();i++){
    	if(intervals[i][0]>=right){
    		num++;
    		right = intervals[i][1];
    		cout<<right<<endl;
    	}
    }
    return intervals.size()-num;
}

int main(){
	vector<vector<int> > intervals;
	int a1[2] = {1,2};
	intervals.push_back(vector<int>(a1,a1+2));
	int a2[2] = {2,3};
	intervals.push_back(vector<int>(a2,a2+2));
	int a3[2] = {3,4};
	intervals.push_back(vector<int>(a3,a3+2));
	int a4[2] = {-100,-2};
	intervals.push_back(vector<int>(a4,a4+2));
	int a5[2] = {5,7};
	intervals.push_back(vector<int>(a5,a5+2));
	eraseOverlapIntervals(intervals);
	// for(int i=0;i<intervals.size();i++){
	// 	cout<<intervals[i][0]<<", "<<intervals[i][1]<<endl;
	// }
	return 0;
}
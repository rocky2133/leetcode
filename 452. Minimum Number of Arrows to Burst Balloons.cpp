#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool mysort(const vector<int> &t1, const vector<int> &t2){
	return t1[0]<t2[0];
}

int findMinArrowShots(vector<vector<int> >& points) {
	if(points.size()==0)
		return 0;
    sort(points.begin(), points.end(), mysort);
    int num = 1;
    int end = points[0][1];
    for(int i=1;i<points.size();i++){
    	if(points[i][0]<=end)
    		continue;
    	num++;
    	end = points[i][1];
    }
    return num;
}

int main(){
	vector<vector<int> > intervals;
	int a1[2] = {10,16};
	intervals.push_back(vector<int>(a1,a1+2));
	int a2[2] = {2,8};
	intervals.push_back(vector<int>(a2,a2+2));
	int a3[2] = {1,6};
	intervals.push_back(vector<int>(a3,a3+2));
	int a4[2] = {7,12};
	intervals.push_back(vector<int>(a4,a4+2));
	// int a5[2] = {5,7};
	// intervals.push_back(vector<int>(a5,a5+2));
	cout<<findMinArrowShots(intervals)<<endl;
	return 0;
}
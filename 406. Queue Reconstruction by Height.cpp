#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool mysort(const vector<int> &t1, const vector<int> &t2){
	if(t1[0]==t2[0])
		return t1[1]<t2[1];
	return t1[0]>t2[0];
}

vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
    sort(people.begin(), people.end(), mysort);
    vector<vector<int> > rec;
    for(int i=0;i<people.size();i++){
    	rec.insert(rec.begin()+people[i][1], people[i]);
    }
    return rec;
}

int main(){

	return 0;
}
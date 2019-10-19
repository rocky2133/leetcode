#include <iostream>
#include <vector>

using namespace std;

int x;
int y;
int f1[4] = {-1,1,0,0};
int f2[4] = {0,0,-1,1};

void reach(vector<vector<int> >& matrix, bool *can, int i, int j, int comp){
	if(i<0 || i>=x || j<0 || j>= y || matrix[i][j]<comp || can[i*y+j]){
		return;
	}
	can[i*y+j] = true;
	for(int k=0;k<4;k++){
		reach(matrix, can, i+f1[k], j+f2[k], matrix[i][j]);
	}
}

vector<vector<int> > pacificAtlantic(vector<vector<int> >& matrix) {
	vector<vector<int> > ans;
	if(matrix.size()<1 || matrix[0].size()<1){
		return ans;
	}
	x = matrix.size();
	y = matrix[0].size();
    bool *can1 = new bool[x*y];
    bool *can2 = new bool[x*y];
    for(int i=0;i<x*y;i++){
    	can1[i] = false;
    	can2[i] = false;
    }
    for(int i=0;i<x;i++){
    	reach(matrix, can1, i, 0, INT_MIN);
    	reach(matrix, can2, i, y-1, INT_MIN);
    }
    for(int i=0;i<y;i++){
    	reach(matrix, can1, 0, i, INT_MIN);
    	reach(matrix, can2, x-1, i, INT_MIN);
    }
    for(int i=0;i<x;i++){
    	for (int j=0; j<y; j++){
    		if(can1[i*y+j] && can2[i*y+j]){
    			vector<int> temp;
    			temp.push_back(i);
    			temp.push_back(j);
    			ans.push_back(temp);
    		}
    	}
    }
    return ans;
}

int main(){
	int a1[20] = {1,2,2,3,5};
	int a2[20] = {3,2,3,4,4};
	int a3[20] = {2,4,5,3,1};
	int a4[20] = {6,7,1,4,5};
	int a5[20] = {5,1,1,2,4};
	vector<vector<int> > matrix;
	vector<int>temp1(a1,a1+1);
	matrix.push_back(temp1);
	// vector<int>temp2(a2,a2+5);
	// matrix.push_back(temp2);
	// vector<int>temp3(a3,a3+5);
	// matrix.push_back(temp3);
	// vector<int>temp4(a4,a4+5);
	// matrix.push_back(temp4);
	// vector<int>temp5(a5,a5+5);
	// matrix.push_back(temp5);

	vector<vector<int> > ans=pacificAtlantic(matrix);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
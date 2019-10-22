#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	if(matrix.size()<1||matrix[0].size()<1)
		return;
    int row=-1;
    int col=-1;
    for(int i=0;i<matrix.size();i++){
    	for(int j=0;j<matrix[0].size();j++){
    		if(matrix[i][j]==0){
    			row=i;
    			col=j;
    			break;
    		}
    	}
    	if(row!=-1)
    		break;
    }
    if(row<0||col<0)
    	return;
    for(int i=row+1;i<matrix.size();i++){
    	for(int j=0;j<matrix[0].size();j++){
    		if(j==col)
    			continue;
    		if(matrix[i][j]==0){
    			matrix[i][col]=0;
    			matrix[row][j]=0;
    		}
    	}
    }
    for(int i=0;i<matrix.size();i++){
    	if(matrix[i][col]==0){
    		if(i==row)
    			continue;
    		for(int j=0;j<matrix[0].size();j++){
    			matrix[i][j]=0;
    		}
    	}
    }
    for(int i=0;i<matrix[0].size();i++){
    	if(matrix[row][i]==0){
    		for(int j=0;j<matrix.size();j++){
    			matrix[j][i]=0;
    		}
    	}
    	matrix[row][i]=0;
    }
}

int main(){
	vector<vector<int> > matrix = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
	setZeroes(matrix);
	for(auto i:matrix){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
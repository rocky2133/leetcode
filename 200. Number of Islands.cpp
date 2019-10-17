#include <iostream>
#include <vector>

using namespace std;

int f1[4] = {1,0,-1,0};
int f2[4] = {0,1,0,-1};

bool countIsland(vector<vector<char> >& grid, int x, int y){
	if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y] == '0')
		return false;
	grid[x][y] = '0';
	for(int i=0;i<4;i++)
		countIsland(grid, x+f1[i], y+f2[i]);
	return true;
}

int numIslands(vector<vector<char> >& grid) {
	int ans=0;
    for(int i=0;i<grid.size();i++){
    	for(int j=0;j<grid[0].size();j++){
    		if(countIsland(grid, i, j)){
    			ans++;
    		}
    	}
    }
    return ans;
}

int main(){

	return 0;
}
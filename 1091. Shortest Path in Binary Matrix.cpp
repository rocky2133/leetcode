#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int shortestPathBinaryMatrix(vector<vector<int> >& grid) {
	if(grid[0][0] == 1)
		return -1;
	int N = grid.size();
	if(N==1)
		return 1;
	int f1[8] = {1,1,1,0,0,-1,-1,-1};
	int f2[8] = {1,0,-1,1,-1,1,0,-1};
	bool **flag = new bool*[N];
	for(int i=0;i<N;i++){
		flag[i] = new bool[N];
		for(int j=0;j<N;j++)
			flag[i][j] = 1;
	}
	queue<vector<int> > qe;
	qe.push(vector<int>(2,0));
	int x=0,y=0;
	int len = 0;
	while(!qe.empty()){
		int num = qe.size();
		len++;
		while(num-->0){
			x = qe.front()[0];
			y = qe.front()[1];
			qe.pop();
			for(int i=0;i<8;i++){
				int x1 = x+f1[i];
				int y1 = y+f2[i];
				if(x1>=0 && x1<N && y1>=0 && y1<N && flag[x1][y1] && grid[x1][y1]==0){
					if(x1==y1 && x1 == N-1)
						return len+1;
					vector<int> temp;
					temp.push_back(x1);
					temp.push_back(y1);
					flag[x1][y1]=0;
					qe.push(temp);
				}
			}
		}
	}
	return -1;
}

int main(){

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f1[4] = {1,1,-1,-1};
int f2[4] = {1,-1,1,-1};
int num;

bool canfill(vector<string>& board, int &i, int &j){
	for(auto t1:board){
		if(t1[j]=='Q')
			return false;
	}
	for(auto t1:board[i]){
		if(t1=='Q')
			return false;
	}
	for(int k=0;k<4;k++){
		int m=i+f1[k];
		int n=j+f2[k];
		while(m>=0 && m<num && n>=0 && n<num){
			if(board[m][n] == 'Q')
				return false;
			m+=f1[k];
			n+=f2[k];
		}
	}
	return true;
}

void queen(vector<vector<string> > &ans, vector<string>& board, int i, int j, int &que){
	if(que == num){
		ans.push_back(board);
		return;
	}
	if(j==num){
		j=0;
		i++;
	}
	while(i<num){
		if(canfill(board, i, j)){
			board[i][j]='Q';
			que++;
			queen(ans, board, i, j+1, que);
			que--;
			board[i][j]='.';
		}
		j++;
		if(j==num){
			j=0;
			i++;
		}
	}
	return;
}

vector<vector<string> > solveNQueens(int n) {
    num = n;
    vector<vector<string> > ans;
    vector<string> board;
    string s = "";
    for(int i=0;i<n;i++)
    	s+=".";
    for(int i=0;i<n;i++)
    	board.push_back(s);
    int que=0;
    queen(ans, board, 0, 0, que);
    return ans;
}

int main(){
	vector<vector<string> > ans = solveNQueens(0);
    for(auto i:ans){
		for(auto j:i){
			cout<<j<<endl;
		}
		cout<<endl;
	}
	return 0;
}
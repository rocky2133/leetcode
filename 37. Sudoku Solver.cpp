#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canfill(vector<vector<char> >& board, int &i, int &j, char &c){
	for(auto t1:board){
		if(t1[j]==c)
			return false;
	}
	for(auto t1:board[i]){
		if(t1==c)
			return false;
	}
	for(int k=i/3*3; k<3+i/3*3; k++){
		for(int l=j/3*3; l<3+j/3*3; l++){
			if(board[k][l]==c)
				return false;
		}
	}
	return true;
}

bool sodoku(vector<vector<char> >& board, int i, int j){
	if(j==9){
		j=0;
		i++;
	}
	if(i==9){
		return true;
	}
	if(board[i][j]!='.'){
		return sodoku(board, i, j+1);
	}
	for(char c='1';c<='9';c++){
		if(canfill(board, i, j, c)){
			board[i][j]=c;
			if(sodoku(board, i, j+1))
				return true;
			board[i][j]='.';
		}
	}
	return false;
}

// void canfill(vector<vector<char> >& board, vector<int> &fill, int i, int j, int type){
// 	for(char c='1';c<='9';c++){
// 		if(type == 0){
// 			for(auto t1:board){
// 				if(t1[j]==c)
// 					return false;
// 			}
// 		}
// 		for(auto t1:board[i]){
// 			if(t1==c)
// 				return false;
// 		}
// 		i = i/3*3;
// 		j = j/3*3;
// 		for(int k =0; k<3; k++){
// 			for(int l=0; l<3; l++){
// 				if(board[i+k][j+l]==c)
// 					return false;
// 			}
// 		}
// 	}
// 	return true;
// }

void solveSudoku(vector<vector<char> >& board) {
    sodoku(board, 0, 0);
    // canfill(board, 5, 5, '1');
}

int main(){
	vector<vector<char> > board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(board);
    for(auto i:board){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
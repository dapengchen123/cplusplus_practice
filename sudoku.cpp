#include<iostream>
#define V 9


void printsolution(int grid[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            std::cout<<grid[i][j]<<" ";
        std::cout<<"\n";
    }
}



bool next_position(int grid[V][V], int row, int col, int& new_row, int& new_col){
    for(int i=col; i<V; i++)
        if(grid[row][i]==0)
        {
            new_row = row;
            new_col = i;
            return true;
        }

    for(int i=row+1; i<V; i++){
        for(int j=0; j<V; j++){
            if(grid[i][j] ==0){
                new_row = i;
                new_col = j;
                return true;
            }
        }
    }

    return false;
}


bool isSafe(int grid[V][V], int row, int col, int num){

    // the row check
    for(int i=0;i<V;i++)
        if(grid[row][i]==num)
            return false;

    // the col check
    for(int i=0;i<V;i++)
        if(grid[i][col]==num)
            return false;

    // the sub 3x3 matrix check
    int startrow = row - row%3;
    int startcol = col - col%3;
    for(int i=startrow;i<startrow+3;i++){
        for(int j=startcol; j<startcol+3;j++){
            if(grid[i][j]==num)
                return false;
        }
    }

    return true;
}

bool solveSudoko(int grid[V][V], int row, int col){
    int new_row, new_col;
    if(next_position(grid, row, col, new_row, new_col)){
        for(int i=1; i<10; i++){
            if(isSafe(grid, new_row, new_col, i )) {
                grid[new_row][new_col] = i;
                if(solveSudoko(grid, new_row, new_col))
                    return true;
                grid[new_row][new_col] = 0;
            }
        }
        return false;
    }else{
        printsolution(grid);
        return true;
    }

}

int main(){

    int grid[V][V] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };


    if(solveSudoko(grid,0,0))
        std::cout<<"there is a solution\n";
    else
        std::cout<<"there is no solution\n";


    return 0;
}
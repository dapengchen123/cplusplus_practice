//
// Created by hp on 24/03/2021.
//

#include<cstdio>
#include<iostream>
#define N 4


int xMove[8] = {0, 1 };
int yMove[8] = {1, 0 };

bool isSafe(int x, int y, int maze[N][N]){

    if( x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
        return true;

    return false;
}

bool solveunit(int x , int y, int maze[N][N], int sol[N][N]){

    //termination condition
    if(x==N-1 && y==N-1 && maze[x][y]==1){
        sol[x][y] = 1;
        return true;
    }


    //
    if(isSafe(x, y, maze)){

        if (sol[x][y] == 1)
            return false;

        sol[x][y] = 1;
        int move_x, move_y;
        for(int k=0; k<2; k++){
            move_x = x + xMove[k];
            move_y = y + yMove[k];

            if (solveunit(move_x, move_y, maze, sol))
                return true;
        }
        sol[x][y] = 0;
        return false;
    }else{
        return false;
    }

}


void printSolution(int sol[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            std::cout<<" "<<sol[i][j];
        std::cout<<"\n";
    }
}

bool solveMaze(int maze[N][N]){
    int sol[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            sol[i][j]=0;

    if(solveunit(0,0, maze, sol)){
        printSolution(sol);
        return true;
    }else{
        std::cout<<"there is no solution"<<"\n";
        return false;
    }

}






int main() {

    int maze[N][N] ={
            {1,0,0,0},
            {1,1,0,1},
            {0,1,0,0},
            {1,1,1,1}
    };

    solveMaze(maze);

    return 0;
}

//https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

#include<cstdio>
#include<iostream>
#define N 4


int xMove[8] = {0, 1 };
int yMove[8] = {1, 0 };

int sum_num=0;

bool isSafe(int x, int y, int maze[N][N]){

    if( x>=0 && x<N && y>=0 && y<N && maze[x][y]==0)
        return true;

    return false;
}


void printSolution(int sol[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            std::cout<<" "<<sol[i][j];
        std::cout<<"\n";
    }
    std::cout<<"\n";
}


void solveMaze_util(int x , int y, int maze[N][N], int sol[N][N]){

    //termination condition
    if(x==N-1 && y==N-1 && maze[x][y]==0){
        sol[x][y] = 1;
        sum_num = sum_num+1;
        printSolution(sol);
        return;
    }


    //
    if(isSafe(x, y, maze)) {

        if (sol[x][y] == 1)
            return;

        sol[x][y] = 1;
        int move_x, move_y;
        for (int k = 0; k < 2; k++) {
            move_x = x + xMove[k];
            move_y = y + yMove[k];
            solveMaze_util(move_x, move_y, maze, sol);
        }
        sol[x][y] = 0;
    }

}



int solveMaze(int maze[N][N]){
    int sol[N][N];
    for(int x=0; x<N; x++) {
        for (int y = 0; y < N; y++)
            sol[x][y] = 0;
    }

    solveMaze_util(0,0, maze, sol);

    if(sum_num == 0){
        std::cout<<"there is no solution"<<"\n";
    }else{
        std::cout<<"the solution number is: "<<sum_num<<"\n";
    }
    return 0 ;
}



int main() {

    int maze[N][N] ={
            {0,0,0,0},
            {0,-1,0,0},
            {-1,0,0,0},
            {0,0,0,0}
    };

    solveMaze(maze);

    return 0;
}

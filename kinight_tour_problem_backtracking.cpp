#include<cstdio>
#include<iostream>
#define N 6


int xMove[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int yMove[8] = {1, -1, 2,-2, 1,-1,2, -2};


int isSafe(int x, int y, int sol[N][N]){

    return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}

int solveKTunit(int x, int y, int movei, int sol[N][N] ){
    std::cout<<" "<<movei<<"\n";
    if (movei == N*N)
        return 1;

    int k, next_x, next_y;
    for(k=0; k<8; k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)){
            sol[next_x][next_y] = movei;
            if (solveKTunit(next_x, next_y, movei + 1, sol)==1){
                return 1;
            }else{
                sol[next_x][next_y] = -1;
            }

        }

    }

    return 0;
}

void print_solution(int sol[N][N]){
    for(int x=0; x<N; x++) {
        for (int y = 0; y < N; y++) {
            std::cout << " " << sol[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

int solveKT(){

    int sol[N][N];
    /*initilization of the solution matrix*/
    for(int x=0; x<N; x++)
        for(int y=0; y<N; y++)
            sol[x][y] = -1;

    // start the solution
    sol[0][0]=0;
    if(solveKTunit(0,0,1, sol)==0){
        std::cout<<"solution is not found";
        return 0;
    }else{
        print_solution(sol);
        return 1;
    }


}

int main() {
    solveKT();

    return 0;
}

#include<iostream>
#define N 4

void printsolution(int color[]){
    for (int i=0;i<N;i++)
        std::cout<<color[i]<<" ";
    std::cout<<"\n";
}


bool checksafe(int row, int color[N], int graph[N][N]){
    for(int i=0; i<row&&graph[row][i]; i++)
        if (color[i]==color[row])
            return false;
    return true;
}

bool solvecolor_utils(int s, int color[N], int graph[N][N], const int m) {
    // termination condition

    if (checksafe(s, color, graph)) {
        if (s == N - 1) {
            printsolution(color);
            return true;
        } else {

            for(int c=0; c<m; c++) {
                color[s + 1] = c;
                bool flag = solvecolor_utils(s + 1, color, graph, m);
                color[s + 1] = -1;
                if(flag) return true;
            }
        }
    }
    return false;
}

void solvecolor(int graph[N][N], const int m){

    int* color=new int[N];
    for(int i=0; i<N; i++)
        color[i]=-1;

    color[0] = 0;
    if(solvecolor_utils(0, color, graph, m)){
        std::cout<<"solution found";
    }else{
        std::cout<<"there is no solution";
    }

    delete [] color;
}


int main(){
    int graph[N][N] = {
            {0,1,1,1},
            {1,0,1,0},
            {1,1,0,1},
            {1,0,1,0},};
    int m=3;
    solvecolor(graph,m);
    return 0;
}



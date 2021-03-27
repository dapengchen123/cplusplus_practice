#include<iostream>
#define V 5


void printsolution(int path[V]){
    for(int i=0;i<V;i++)
        std::cout<<path[i]<<" ";
    std::cout<<std::endl;
}

bool is_connected(int path[V], bool graph[V][V]){
    int end_node = path[V-1];
    int start_node = path[0];
    if (graph[end_node][start_node] == 1) {
        return true;
    }
    return false;
}

bool is_once(int s, int path[V]){
    for(int i=0; i<s; i++) {
        if (path[i]==path[s])
            return false;
    }
    return true;
}

bool hamilton_utils(int s, int path[V], bool graph[V][V]){
    // termination condition
    if(s==V-1){
        if(is_connected(path, graph)&&is_once(s,path)){
            printsolution(path);
            return true;}
        else
            return false;
    }

    if(is_once(s,path)){
        int cur_label = path[s];
        for(int i=0; i<V;i++)
            if(graph[cur_label][i]==1){
                path[s+1] = i;
                bool flag = hamilton_utils(s + 1, path, graph);
                path[s+1] =-1;
                if(flag) return true;
            }
    }

    return false;
}

void hamilton_cycle(bool graph[V][V]){
    // solution

    int path[V];
    // intilization
    for(int i=0; i<V; i++)
        path[i] = -1;

    path[0] = 0;
    if(hamilton_utils(0, path, graph))
        std::cout<<"there is a solution \n";
    else
        std::cout<<"no solution exists \n";

    path[0] = -1;
}


int main(){

    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 1},
                         {0, 1, 1, 1, 0}};

    hamilton_cycle(graph1);

    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};

    hamilton_cycle(graph2);

    return 0;

}
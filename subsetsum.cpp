#include<iostream>
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
#define mx 200

int total_nodes = 0;


void print_solution(int t[], int size_a){
    for(int i=0; i<size_a; i++)
        std::cout<<t[i]<<" ";
    std::cout<<"\n";
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum){
    total_nodes++;
    if (sum == target_sum) {
        print_solution(t, t_size);
        total_nodes--;
        std::cout<<total_nodes<<"  \n";
        return;
        // remove the previously added item and go ahead
    }

    if(sum>target_sum){
        total_nodes--;
        return;
    }else{
        for(int i=ite; i <s_size; i++){
            t[t_size] = s[i];
            subset_sum(s, t, s_size, t_size+1,
                       sum+s[i], i+1, target_sum);
        }

    }
    total_nodes--;
}

void solve_sum(int s[], int size, int target_sum){
    int* tuple_set = new int [mx];
    subset_sum(s, tuple_set, size, 0, 0, 0, target_sum);
    delete [] tuple_set;
}

int main(){

    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int size = ARRAYSIZE(weights);
    std::cout<<size<<"\n";
    solve_sum(weights, size, 53);
    std::cout << "Nodes generated " << total_nodes <<"\n";

    return 0;

}
//set-sum-backtracking-4/
#include<cstdio>
#include<cmath>
#include<iostream>


#define Max 20

int pos[Max+1];
int sum;

bool checkNQ(int col){
    for(int i=1; i<col; i++)
        if(pos[i]==pos[col] || abs(i-col) == abs(pos[i]-pos[col]))
            return false;
        return true;
}

void dfsNQ(int col, int n){
    if(col==n+1)
        sum++;
    for(int i=1; i<=n; i++){
        pos[col] = i;
        if (checkNQ(col))
            dfsNQ(col+1, n);
    }
}


int main() {
    int n;
    std::cout<<"请输入皇后的数量：";
    std::cin>>n;
    sum = 0;
    dfsNQ(1, n);
    std::cout<<"满足条件的所有摆放次数为："<<sum<<std::endl;


    return 0;
}

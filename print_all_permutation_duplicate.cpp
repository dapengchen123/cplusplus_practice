#include<iostream>
#include<string>
#include<vector>



void print_intarray(int a[], int n){
    for(int i=0; i<n; i++)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}

void print_chararray(char a[], int n){
    for(int i=0; i<n; i++)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}



void permutation_utils(const char alphabeta[], int alphanum[], int alphacount, char sol[], int solcount, int stringcount){

    if (solcount==stringcount)
        print_chararray(sol, stringcount);

    for(int i=0;i<alphacount;i++)
    {
        if(alphanum[i]>0){
            alphanum[i] = alphanum[i]-1;
            sol[solcount] = alphabeta[i];
            permutation_utils(alphabeta, alphanum, alphacount,sol,solcount+1, stringcount);
            sol[solcount] = 'a';
            alphanum[i] = alphanum[i]+1;
        }
    }

}

void dup_permutation(std::string& s){
    int count_number[26];

    for(int i=0;i<26;i++)
        count_number[i]=0;

    for(int i=0; i<s.length(); i++){
        ++count_number[s[i]-'A'];
    }

    int number=0;
    for(int i=0; i<26; i++)
        if(count_number[i]>0)
            number++;
    char alphabeta[number];
    int alphanum[number];
    char sol[s.length()];

    int j=0;
    for(int i=0; i<26; i++)
        if(count_number[i]>0){
            alphabeta[j]= i+'A';
            alphanum[j]= count_number[i];
            j=j+1;
        }

    for(int i=0;i<s.length();i++)
        sol[i] = 'a';

//    print_intarray(alphanum, number);
//    print_chararray(alphabeta, number);

    permutation_utils(alphabeta, alphanum, number, sol, 0, s.length());

}

int main(){
    std::string s = "ABC";
    dup_permutation(s);
    return 0;
}

//Print all distinct permutations of a given string with duplicates

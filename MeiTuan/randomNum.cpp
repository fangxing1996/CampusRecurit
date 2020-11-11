#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    for(int i = 0; i < 10; i++){
        vec.push_back(i);
    }
    srand((unsigned int)time(NULL));
    vector<int> ::iterator it;
    for(int i = 0; i < 10; i++){
        int temp = rand()%vec.size();
        cout << vec[temp];
        it = vec.begin();
        for(int j = 0; j < temp;j++)
            it++;
        vec.erase(it);
    }
    return 0;
}

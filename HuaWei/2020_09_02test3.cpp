#include<stdio.h>
#include<iostream>
using namespace std;
int backTracking(int curPos, int curSpace, int curValue, int &sp, int &va, int maxSpace, int w[], int v[], int n);
int space = 0;
int value = 0;
int backTracking(int curPos, int curSpace, int curValue, int &sp, int &va, int maxSpace, int w[], int v[], int n){
    if(curPos == n){
        if(curSpace <= maxSpace && curSpace > sp){
            sp = curSpace;
            va = curValue;
        }
        else if(curSpace <= maxSpace && curSpace == sp){
            if(curValue > va){
                va = curValue;
            }
        }
        return 0;
    }
    backTracking(curPos + 1, curSpace + w[curPos], curValue + v[curPos], sp, va, maxSpace, w, v, n);
    backTracking(curPos + 1, curSpace, curValue, sp, va, maxSpace, w, v, n);
    return 0;
}
int main(){
    int maxSpace;
    int num;
    cin >> maxSpace >> num;
    int w[num], v[num];
    for(int i = 0; i < num; i++){
        cin >> w[i];
    }
    for(int i = 0; i < num; i++){
        cin >> v[i];
    }
    int &sp_ = space;
    int &va_ = value;
    backTracking(0, 0, 0, sp_, va_, maxSpace, w, v, num);
    cout <<endl << space << endl;
    cout << value;
    return 0;
}

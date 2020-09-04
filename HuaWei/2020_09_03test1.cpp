#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int rp[3] = {0}, bp[3] = {0};
int sr = 0, sb = 0;
int rbubble(int in[], int n){
    int in_[n];
    memcpy(in_, in, n*sizeof(int));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(in_[i] > in_[j]){
                int temp;
                temp = in_[i];
                in_[i] = in_[j];
                in_[j] = temp;
            }
        }
    }
    if(in_[n - 1] != 0 && in_[n - 2] != 0 && in_[n - 3] != 0){
        sr = in_[n - 1] + in_[n - 2] + in_[n - 3];
        for(int i = 0; i < n; i++){
            if(in[i] == in_[n - 1]){
                rp[2] = i + 1;
            }
            else if(in[i] == in_[n -2]){
                rp[1] = i + 1;
            }
            else if(in[i] == in_[n -3]){
                rp[0] = i + 1;
            }
        }
    }
    else{
        return 0;
    }
    return 1;
}

int bbubble(int in[], int n){
    int in_[n];
    memcpy(in_, in, n*sizeof(int));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(in_[i] > in_[j]){
                int temp;
                temp = in_[i];
                in_[i] = in_[j];
                in_[j] = temp;
            }
        }
    }
    if(in_[n - 1] != 0 && in_[n - 2] != 0 && in_[n - 3] != 0){
        sb = in_[n - 1] + in_[n - 2] + in_[n - 3];
        for(int i = 0; i < n; i++){
            if(in[i] == in_[n - 1]){
                bp[2] = i + 1;
            }
            else if(in[i] == in_[n -2]){
                bp[1] = i + 1;
            }
            else if(in[i] == in_[n -3]){
                bp[0] = i + 1;
            }
        }
    }
    else{
        return 0;
    }
    return 1;
}
int main(){
    int num;
    cin >> num;
    if(num < 3){
        cout << "null";
        return 0;
    }
    int r[num] = {0}, b[num] = {0};
    int x, y;
    for(int i = 0; i < num; i++){
        cin >> x >> y;
        if(y == 1){
            r[i] = x;
        }
        else if(y == 2){
            b[i] = x;
        }
    }
    int f1;
    f1 = rbubble(r, num);
    int f2;
    f2 = bbubble(b, num);
    if(f1 > 0 && f2 > 0){
        if(sr > sb){
            cout << rp[0] << " " << rp[1] << " " << rp[2] << endl;
            cout << "1" << endl;
            cout << sr;
        }
        else if(sr < sb){
            cout << bp[0] << " " << bp[1] << " "<< bp[2] << endl;
            cout << "2" << endl;
            cout << sb;
        }
        else if(sr == sb){
            if(rp[0] < bp[0]){
                cout << rp[0] << " " << rp[1] << " "<< rp[2] << endl;
                cout << "1" << endl;
                cout << sr;
            }
            else{
                cout << bp[0] << " " << bp[1] << " " << bp[2] << endl;
                cout << "2" << endl;
                cout << sb;
            }
        }
    }
    else if(f1 > 0 && f2 == 0){
        cout << rp[0] << " " << rp[1] << " " << rp[2] << endl;
        cout << "1" << endl;
        cout << sr;
    }
    else if(f1 == 0 && f2 > 0){
        cout << bp[0] << " " << bp[1] << " " << bp[2] << endl;
        cout << "2" << endl;
        cout << sb;
    }
    else if(f1 == 0 && f2 == 0){
        cout << "null";
    }
    return 0;
}

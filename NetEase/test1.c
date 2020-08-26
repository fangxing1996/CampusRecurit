//Date, 2020.08.08
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int isHuiWen(char c[], int t);

int isHuiWen(char c[], int t){
    int i;
    int k = t/2;
    for(i = 0; i < k; i++){
        if(c[i] != c[t - i -1])
            return 0;
    }
    return 1;
}

int main(){
    char ch[2000];
    scanf("%s", ch);
    int len = strlen(ch);
    int i;
    int j;
    int l;
    for(i = 0; i < len; i++){
        l = len + i;

        for(j = 0; j < i; j++){
            ch[l - j -1] = ch[j]; 
        }
        ch[l] = '\0';
        if(isHuiWen(ch, l)){
            cout << ch;
            break;
        }
    }
    return 0;
}

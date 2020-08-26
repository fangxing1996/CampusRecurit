//Date, 2020.08.26
#include<stdio.h>
#include<math.h>
unsigned int in[1000];
int btod(int in[], int n);
int dtob(unsigned in, int e);
int moveRight2Bits(unsigned int in[], int num);

int btod(int in[], int n){  //Binary to decimal.
    int s = 0;
    int temp;
    for(int i = 0; i < n; i++){
        temp = pow(2, i);
        s = s + in[i]*temp;
    }
    return s;
}

int dtob(unsigned int in, int e){  //Decimal to binary, return the value of No.e bit.
    int i;
    int b[32];
    int temp;
    for(i = 0; i < 32; i++){
        temp = pow(2, i);
        if(in & temp){
            b[i] = 1;
        }
        else{
             b[i] = 0;
        }
    }
    for(i = 0; i < 16; i++){
        int t = b[2*i];
        b[2*i] = b[2*i + 1];
        b[2*i + 1] = t;
    }
    return b[e];
}

int moveRight2Bits(unsigned int in[], int num){  //Move right 2 bits.

    for(int k = 0; k < num; k++){

        int i;
        int b[32];
        int temp;
        for(i = 0; i < 32; i++){
            temp = pow(2, i);
            if(in[k] & temp){
                b[i] = 1;
            }
            else{
                b[i] = 0;
            }
        }

        for(i = 0; i < 16; i++){
            int t = b[2*i];
            b[2*i] = b[2*i + 1];
            b[2*i + 1] = t;
        }
        if(k == 0){
            for(int l = 0; l < 30; l++){
                b[l] = b[l + 2];
            }
            b[30] = dtob(in[num - 1], 0);
            b[31] = dtob(in[num - 1], 1);
        }
        else{
            for(int l = 0; i < 30; i++){
                b[l] = b[l + 2];
            }
            b[30] = dtob(in[k - 1], 0);
            b[31] = dtob(in[k - 1], 1);
        }
        printf("%u ", btod(b, 32));
    }
    return 0;
}


int main(){
    int count = 0;
    int a, i = 0, s = 0, len;
    char ch;
    while((ch = getchar())!= '\n'){
        if(ch == ' '){
            in[i++] = s;
            s = 0;
        }
        else{
            s = 10*s + ch - '0';
        }
    }
    in[i++] = s;
    len = i;
    moveRight2Bits(in, len);
    return 0;
}

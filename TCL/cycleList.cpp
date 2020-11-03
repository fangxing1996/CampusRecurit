#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node* next;
}node;
class cycleList {
    public:
        node* pHead;
    public:
        cycleList():pHead(NULL){

        }
        void addNode(int n){
            if(pHead == NULL){
                node* nNode = (node*)malloc(sizeof(node));
                nNode -> data  = n;
                pHead = nNode;   
                nNode -> next = pHead;
            }
            else{
                node* p = pHead;
                while(p -> next != pHead){
                    p = p -> next;
                }
                node* nNode = (node*)malloc(sizeof(node));
                nNode -> data  = n;
                nNode -> next = pHead;
                p -> next = nNode;
            }
        }
        void findNode(int k, int m){
            node * tail = pHead; //找到链表第一个结点的上一个结点，为删除操作做准备
            while (tail -> next != pHead){
                    tail = tail -> next;
            }
            node* p = pHead;
            //找到编号为k的人
            while (p -> data != k){
                tail = p;
                p = p -> next;
            }
            //从编号为k的人开始，只有符合p -> next == p时，说明链表中除了p结点，所有编号都出列了，
            while (p -> next != p){
                //找到从p报数1开始，报m的人，并且还要知道数m - 1的人的位置tail，方便做删除操作。
                for (int i = 1; i < m; i++){
                    tail = p;
                    p = p -> next;
                }
                tail -> next = p -> next;//从链表上将p结点摘下来
                printf("the No get out: %d\n", p -> data);
                free(p);
                p = tail -> next;//继续使用p指针指向出列编号的下一个编号，游戏继续
            }
            printf("the No get out: %d\n", p -> data);
            free(p);
        }
};
int main(){
    int n, k, m;
    cin >> n >> k >> m;
    cycleList cl;
    for(int i = 0; i < n; i++){
        cl.addNode(i + 1);
    }
    cl.findNode(k, m);
    return 0;
}

#include"Node.h"



int main(){
    string s = "abcdefg";
    Node* head = CreateList(s);
    PrintList(head);
    Reverse(head);
    PrintList(head);
}
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdlib.h>
using namespace std;
struct BiTNode
{
    /* data */
    char data;
    struct BiTNode* lchild, * rchild;
    BiTNode(char _data) : data(_data), lchild(NULL), rchild(NULL) {
        ;
    }
};
int Height(BiTNode* root);
int Size(BiTNode* root);
/*从广义表（如A(B(D,E(G,)),C(,F)这样）中得到二叉树，返回头结点*/
BiTNode* GetFromLists(std::string Lists);
/*从subTree结点开始搜索current结点的父结点，找到返回父结点，没找到返回空*/
BiTNode* Parent(BiTNode* subTree, BiTNode* current);

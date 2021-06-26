#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<stdlib.h>
#include<queue>
using namespace std;
struct BiTNode
{
    /* data */
    char data;
    struct BiTNode* lchild, * rchild;
    int ltag, rtag;
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

/*从先序、中序中获取二叉树*/
BiTNode* GetFromVisit(string pre_order, string in_order, int l_pre, int r_pre, int l_in, int r_in);

void InOrderVisit(BiTNode* root);
void PreOrderVisit(BiTNode* root);
void LevelOrderVisit(BiTNode* root);

/*创建中序遍历二叉树*/
void CreateInThread(BiTNode* root);
void InThread(BiTNode*& root, BiTNode*& pre);

void DeepCopy(BiTNode* root1, BiTNode*& root2);

int IsPerfect(BiTNode* root);

/*交换左右子树*/
void Swap(BiTNode*& root);

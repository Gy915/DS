#include"tree.h"
using namespace std;

int Height(BiTNode* root) {
    return 0;
}
int Size(BiTNode* root) {
    return 0;
}
BiTNode* GetNodePtr(char ch) {
    BiTNode* ptr = (BiTNode*)malloc(sizeof(BiTNode));
    ptr->data = ch;
    ptr->lchild = ptr->rchild = NULL;

    return ptr;

}
BiTNode* GetFromLists(string Lists) {
    // A(B(D,E(G,)),C(,F))#
    stack<BiTNode*> temp;
    BiTNode* root = NULL;
    BiTNode* parent = NULL;
    BiTNode* last_node = NULL;
    int type = 1;
    char ch;
    for (int i = 0; i < Lists.size(); i++) {
        ch = Lists[i];
        if (ch == '#')
            break;
        switch (ch)
        {
        case '('://左括号入栈,进入子树
            temp.push(last_node);
            type = 1;
            /* code */
            break;
        case ')':
            temp.pop();
            break;
        case ',':
            type = 2;
            break;
        default:
            last_node = GetNodePtr(ch);
            if (!root) {
                root = last_node;
            }
            else {
                parent = temp.top();
                if (type == 1) {
                    parent->lchild = last_node;
                }
                else if (type == 2) {
                    parent->rchild = last_node;
                }
            }
            break;
        }
    }
    return root;

}
BiTNode* Parent(BiTNode* subTree, BiTNode* current) {
    if (subTree == NULL)
        return NULL;
    else {
        if (subTree->lchild == current || subTree->rchild == current)
            return subTree;
        BiTNode* res;
        if ((res = Parent(subTree->lchild, current)) != NULL)
            return res;
        else
            return Parent(subTree->rchild, current);
    }
}



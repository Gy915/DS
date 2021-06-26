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
    ptr->ltag = 0;
    ptr->rtag = 0;
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

BiTNode* GetFromVisit(string pre_order, string in_order, int l_pre, int r_pre, int l_in, int r_in) {
    if (l_pre == r_pre) {
        BiTNode* node = GetNodePtr(pre_order[l_pre]);
        return node;
    }
    else {
        BiTNode* root = GetNodePtr(pre_order[l_pre]);
        char root_value = pre_order[l_pre];
        int in_pos = 0;
        for (int i = 0; i < in_order.size(); i++) {
            if (in_order[i] == root_value)
                in_pos = i;
        }
        int l_len = in_pos - l_in;
        int r_len = r_in - in_pos;
        if (l_len == 0)
            root->lchild = NULL;
        else
            root->lchild= GetFromVisit(pre_order, in_order, l_pre + 1, l_pre + l_len, l_in, in_pos - 1);
        if (r_len == 0)
            root->rchild = NULL;
        else
            root->rchild = GetFromVisit(pre_order, in_order, r_pre - r_len + 1, r_pre, in_pos + 1, r_in);
        return root;
    }
}
void InOrderVisit(BiTNode* root) {
    stack<BiTNode*> S;
    BiTNode* p = root;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            p = p->lchild;
        }
        else {
            p = S.top();
            S.pop();
            cout << p->data << endl;
            p = p->rchild;

        }
    }

}

void PreOrderVisit(BiTNode* root){
    stack<BiTNode*> S;
    BiTNode* p = root;
    while (p || !S.empty()) {
        if (p) {
            cout << p->data << endl;
            S.push(p);
            p = p->lchild;
        }
        else {
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }
}
void LevelOrderVisit(BiTNode* root) {
    queue<BiTNode*> Q;
    BiTNode* p = root;
    Q.push(root);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        cout << p->data << endl;
        if (p->lchild != NULL)
            Q.push(p->lchild);
        if (p->rchild != NULL)
            Q.push(p->rchild);
    }
    cout << endl;
}

void CreateInThread(BiTNode* root){
    BiTNode* pre = NULL;
    if (root) {
        InThread(root, pre);
        pre->rtag = NULL;
        pre->rtag = 1;
    }
}

void InThread(BiTNode*& root, BiTNode*& pre){
    if (root) {
        InThread(root->lchild, pre);
        if (root->lchild == NULL) {
            root->lchild = pre;
            root->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = root;
            pre->rtag = 1;
        }
        pre = root;
        InThread(root->rchild, pre);
    }
}

void DeepCopy(BiTNode* root1, BiTNode* &root2){
    if (!root1) {
        root2 = NULL;
    }
    else {
        char value = root1->data;
        root2 = GetNodePtr(value);
        DeepCopy(root1->lchild, root2->lchild);
        DeepCopy(root1->rchild, root2->rchild);
    }
}

int IsPerfect(BiTNode* root){

    BiTNode* Q[100];
    int rear  = 0;
    int front = 0;
    Q[rear++] = root;
    BiTNode* temp = NULL;
    while (front < rear) {
        temp = Q[front++];//取头结点
        if (temp) {
            Q[rear++] = temp->lchild;
            Q[rear++] = temp->rchild;
        }
        else {
            BiTNode* p = NULL;
            while (front < rear) {
                p = Q[front++];
                if (p)
                    return 0;

            }
        }
    }




    return 1;
}

void Swap(BiTNode*& root){
    if (!root)
        return;
    else {
        Swap(root->lchild);
        Swap(root->rchild);
        BiTNode* l = root->lchild;
        BiTNode* r = root->rchild;
        root->lchild = r;
        root->rchild = l;


    }


}


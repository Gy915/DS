#include"tree.h"

using namespace std;

int main() {

    string lists = "A(B(D,E(G,)),C(,F)#";
    BiTNode* root = GetFromLists(lists);
    BiTNode* res = Parent(root, root->lchild->rchild);
    cout << res->data << endl;
    system("pause");
}
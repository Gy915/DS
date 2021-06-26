#include"tree.h"
using namespace std;

int main() {





    string lists = "A(B(D,E(G,)),C(,F)#";
    BiTNode* root = GetFromLists(lists);
    
    string in_order = "24153";
    string pre_order = "12435";
    BiTNode* root2 = GetFromVisit(pre_order, in_order, 0, pre_order.size() - 1, 0, in_order.size() - 1);
   BiTNode* res = Parent(root2, root2->lchild->rchild);
   BiTNode* root3 = NULL;
   DeepCopy(root2, root3);
   LevelOrderVisit(root3);
   cout << IsPerfect(root3)<<endl;
   Swap(root3);
   LevelOrderVisit(root3);
}
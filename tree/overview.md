#! https://zhuanlan.zhihu.com/p/257291645

# **数据结构 树**

# 1.树的概念

## 1.1 树的定义

* 自由树：
  $T_{f} = (V, E)$ $(V=\{v_{21}, v_{2}, ...v_{n}\}$ $E=\{(v_{i}, v_{j})|v_{i},v_{j}\in V, 1 \leq i,j \leq n
  \})$，其中，集合$E$的元素个数为 $n-1$, $(v_{i}, v_{j})$称为边或分支, $T_{f}$为连通图
* 有根树:
  $T=\begin{cases}\phi,\qquad n=0\\
  \{r,T1, T2, T3,...,T_{m}\}, \qquad n>0
  \end{cases}$<br>$n=0$时称为空树，$T_{1},T_{2},...T_{m}$称为子树<br>根节点没有前驱，除此之外每个节点有且只有一个前驱；所有节点有零个或多个后继
* 目录结构、集合文氏图、凹入表表示、广义表表示

## 1.2 常见术语

* 结点：包含数据项和其他结点的分支
* 度：拥有子树的个数,树的度是结点的最大度
* 叶结点：度为0的点，终端结点
* 分支节点：除叶结点以外的点，非终端节点
* 子女节点：若结点$x$有子树，子树的根结点即$x$的子女
* 父结点：结点$x$为其子女结点的父结点
* 兄弟结点：同一父结点的子女护卫兄弟
* 祖先结点：对结点$x$，根结点到这个结点唯一路径上的任意结点
* 子孙结点：子女结点的子女
* 层次：根到该结点的子树个数，记根结点为层次为1，子结点层次为父结点加1
* 深度：最远结点的层次，空树为0，自顶向下
* 高度：叶结点高度为1，其父结点的高度为最高子女高度+1，树的高度为根结点高度，自底向上，数值上与深度相等。
* 有序树、无序树：各棵子树能够交换，例如有序树中$T_{1}, T_{2}...$被称为第一棵子树、第二棵子树...
* 森林：$m \geq0$棵互不相交的树，树$\to$森林：删去一棵非空树的根结点（空森林也是森林） 森林$\to$树：增加一个结点，让每一棵树的根结点都称为这个结点的子女结点

## 1.3 树的性质

* 结点数等于度数和加1
* 度为$m$的树第$i$层至多有$m^{i-1}个结点$
* 高度为$h$的$m$叉树（度为$m$)至多有 $\sum_{i=1}^hm^{i-1}=\frac{(m^{h}-1)}{(m-1)}$
* 设度为$m$的树（$m$叉树）结点个数为$n$,由上一个性质，我们推出：

$$
\begin{gathered}
    n \leq\,\frac{(m^{h}-1)}{m-1}\\
    \qquad h \geq \lceil\log_{m}(n(m-1)+1)\rceil
    \end{gathered}

$$

# 2.二叉树

## 2.1 二叉树定义

$$
T=
  \begin{cases}
    \phi \qquad n=0\\  
    \{r, \,T_{l}, \,T_{r} \} \qquad n \geq 1
  \end{cases}

$$

树的度至多为2（即最多两个子女结点），左右子树能交换（有序的）

## 2.2 二叉树的性质

* 第$i$层至多$2^{i-1}$个结点
* 高为$k$至多$2^{k}-1$个结点，至少$k$个结点（每层一个）
* 考虑两个等式:

  $$
  \begin{gathered}
    n = n_{0} + n_{1} + n_{2} \\
    e = n-1 = n_{1} + 2 * n_{2}   
  \end{gathered}

  $$


  故有:$n_{0} = n_{2} +1$
* 满二叉树：每一层都达到最大结点个数；完全二 叉树：每一个结点都与具有相同高度的满二叉 树对应（上面$k-1$层是满的，仅第$k$层从右向左却若干个)
* $n$个结点的完全二叉树最小深度为$\lceil \log(n+1)\rceil$
* 对于完全二叉树，编号为$1,2,3...n$,结点 $i$ 的父结点编号为 $\lfloor\frac{n}{2}\rfloor$ ,结点 $i$ 的左子女结点为 $2*i$,右子女结点为 $2*i+1$ ，(检查结点是否超过 $n$ ),深度 $\lfloor\log(i)\rfloor + 1$ <br/></br>

# 3.二叉树存储

## 3.1 二叉树数组表示

* 适用场景：二叉树大小和形态不发生剧烈动态变化
* 将二叉树存储在一组连续的存储单元（即数组内），要体现树的逻辑结构。
* 完全二叉树数组存储：自顶向下，自左向右顺序编号为 $1,2,3,4...,n$,按照这个序列把完全二叉树放入一维数组中（根结点在索引为$1$处）。**这种方式最简单、最省存储空间**
* 一般二叉树存储：仿照完全二叉树编号，遇到空子树时假定有子树编号。这样的做法会浪费存储空间（eg.只有右子树）

## 3.2 二叉树的链表表示

* 适用一般二叉树，变化剧烈
* 二叉树的每一个结点可以有两个分支，分别指向左、右子树，因此至少有三个域，分别存放结点的数据、左右子女结点指针。**很方便的找到子女结点，但找到父结点很困难**
* 为了找到父结点，可以再加一个父指针域，称为三叉链表
* 对于 $n$ 个结点的二叉链表中，共有 $2*n$ 个指针域，由于二叉树中共有 $n -1$ 条边，故**二叉链表中有 $n+1$ 个空指针域**，同理，三叉链表中有 $n+2$ 个空指针域（根结点的父结点域为空）
* 这两种链表形式都可以是静态链表结构，即把链表存放在一个一维数组中，每个一维数组元素是一个结点，包括三个域：数组域、左子女域、右子女域，还可以增加父指针域，指针域指向数组中的下标：
  ```
                     A
                    /  
                   B
                  / \
                 C   D
                    /
                   E
  ```


  | index | data | Parent | LeftChild | RightChild |
  | - | - | - | - | - |
  | 0 | A | -1(root) | 1(B) | -1(NULL) |
  | 1 | B | 0(A) | 2(C) | 3(D) |
  | 2 | C | 1(B) | -1(NULL) | -1(NULL) |
  | 3 | D | 1(B) | 4(E) | -1(NULL) |
  | 4 | E | 3(D) | -1(NULL) | -1(NULL) |
  | </br> |   |   |   |   |

# 4.二叉树的遍历及应用

## 概述

  二叉树遍历是指遵从某种次序，遍历二叉树中所有的结点，使得每个结点访问且只访问一次，且不破坏树的数据结构,产生的结构是一个线性队列。<br>  考虑自身、左右三个结点的顺序，总共的遍历方式有 $A_{3}^{3}= 6$ 种，规定先左后右，共有三种方式。常见的遍历方式有先序（NLR）、中序（LNR）、后序（LRN）三种。

## 三种遍历算法

* 递归访问
  ```cpp
  /*先序遍历*/
  void PreOrder(BiTNode* T){
    if(T!=NULL){
      visit(T);
      PreOrder(T->lchild);
      PreOrder(T->rchild);
    }
  }
  /*中序遍历*/
  void InOrder(BitNode* T){
    if(T!=NULL){
      InOrder(T->lchild);
      visit(T);
      InOrder(T->rchild);
    }
  }
  /*后序遍历*/
  void PostOrder(BitNode* T){
    if(T！=NULL){
      PostOrder(T->lchild);
      PostOrder(T->rchild);
      visit(T);
    }
  }
  ```
* 先序非递归遍历

1. 王道书(好记):沿着左子树走至空指针处，弹栈，将当前结点变更为弹出结点的右子树结点，递归访问

   ```cpp
   void PreOrder(BiTNode* T)
   {
     stack<BiTNode* T> S;
     S.Init();//初始化栈
     BiTNode p = T;//遍历指针
     while(p || !S.IsEmpty()){
       if(p){
         visit(p);//访问该结点
         S.push(p);//入栈
         p = p->lchild;//左孩子不空则一直向左走
       }
       else{
         S.pop(p);//栈顶元素出栈，访问
         p = p->rchild;//其右子树
       }
     }
   }
   ```

   ```
                       A
                     /   \
                    B     C
                    \     /
                     D   E
   栈变化：A->AB->A->AD->A->null->C->CE->C->finish
   ```
2. 殷书：每次访问一个节点后，访问其左子树，并将右子树入栈；当左子树为空时，从栈顶弹出一个元素

   ```cpp
     void PreOrder2(BiTNode* T){
       stack<BiTNode* >S;
       BiTNode* p =T;
       S.Init();
       S.push(NULL);
       while(p!=NULL){
         visit(p);
         if(p->rchild!=NULL)
           S.push(p->rchild);
         if(p->lchild!=NULL);
         p = p->lchild;
         else
           S.pop(p);
       }

     }
   ```

   ```
                       A
                     /   \
                    B     C
                    \     /
                     D   E
   栈变化：null->null C(访问A）->null CD（访问B）->NULL C（访问B后D退栈，访问D）->NULL（访问C）->NULL（访问E）->finish
   ```


   第二个方法是每次从栈顶弹出一个结点访问，每次访问结点时将左右结点入栈，**先右后左**<br/></br>

* 中序非递归遍历：与先序类似，沿着左子树链走，当遇到空指针时，递归遍历右子树，与先序的差别在于访问结点的顺序在出栈时

  ```cpp
    void InOrder2(BiTNode* T){
      stack<BiTNode*> S;
      BiTNode * p = T;
      while(p!=NULL||| !S.IsEmpty()){
        if(P){
          S.push(P);//结点进栈
          p = p->lchild;//访问左子树
        }
        else{
          S.Pop(p);//弹出一个结点并访问
          visit(P);
          p = p->rchild;//转而访问右子树
        }
      }

    }
  ```

  ```
                      A
                    /   \
                   B     C
                   \     /
                    D   E
  栈变化：
  A->AB->A->AD->A->null->C->CE->C->finish
  ```


  **与先序遍历的差别在于访问结点的位置,先序遍历在入栈时，中序遍历在弹栈时**<br/><br>
* 后续非递归遍历：每次需要判断访问结束的结点是来自左子树还是右子树，因此需要设立一个辅助指针，**记录上次访问过的结点**，每次返回时取得栈顶结点，将上次访问的结点与栈顶结点比较，如果栈顶的右节点等于上次访问的结点，表示这是遍历结束的，可以访问根结点。这里要注意，每次访问完一个结点后要将访问变量置空（否则会循环访问）

  ```cpp
  void PostOrder2(BiTNode* T){
    stack<BiTNode* T> S;
    BitNode* p = T;
    BitNode* r = NULL;
    while(p || !S.IsEmpty()){
      if(p){
        push(S, p);
        p = p->lchild;//访问左链
      }
      else{
        p = S.top();
        if(p->rchild && p->rchild!=r){
          p = p->rchild;//如果有右子树且不空
        }
        else{
          S.pop();
          visit(p->data);
          r=p;
          p=NULL;//这里需要将p置空
        }
      }
    }
  }
  ```
* 层次遍历
  BFS遍历，借助队列

  ```cpp
    void LevelOrder(BiTNode* T){
      Queue<BiTNode*> Q;
      BiTNode* p = root;
      Q.push(p);
      while(!Q.IsEmpty()){
        p = Q.pop();
        visit(p);
        if(p->lchild != NULL)
          Q.push(p->lchild);
        if(p->rchild!=NULL)
          Q.push(p->rchild);
      }
    }
  ```

# 5. 二叉树计数

  我们考虑有$n$个结点能组成的二叉树个数，这里，定义 $n=0$ 时有一棵树，则总的个数$b_n$为卡特兰数：

$$
\begin{cases}
  b_0 = 1   \quad n=0 \\\\  
  b_n = \sum_{i=0}^{h=n-1}b_i * b_{n-i-1},\quad n \geq1 
  
\end{cases}

$$

可以理解为在根为1的情况下，左子树 $i$ 个结点和右子树 $n-i-1$ 个结点进行随意组合

# 6.线索二叉树

## 6.2 线索

在二叉链表的存储结构中，利用空的左孩子结点存放前驱（规定遍历顺序）结点指针，空的右孩子结点存放后继结点。这种指针叫做**线索**，有了线索，无需遍历二叉树，就可以得到结点的前驱与后继。

## 6.3 中序线索二叉树建立

结构：

```
left  | ltag  | data  | rtag |  right
```

tag为0，表示存放孩子结点指针；为1表示存放后继或前驱

构造:将二叉链表中的空指针指向前驱或后继，在二叉数遍历时，设pre和p两个指针，pre指向前驱，p指向当前结点，在中序遍历时，检查p左指针是否为空，若为空则指向pre；检查pre右指针是否为空，若为空则指向p：

```cpp
struct  ThreadNode{
  int data;
  struct ThreadNode* lchild, *rchild;
  int ltag, rtag;
} 
void InThread(ThreadNode &p, ThreadNode &pre){
    if(p!= NULL){
      InThread(p->lchild, pre);

      if(p->lchild==NULL){
        p -> lchild = pre;
        p -> ltag = 1;
      }//左子树为空，则左指针域指向前驱
      if(pre!=NULL && pre ->rchild ==NULL){
        pre -> rchild = p;
        pre -> rtag = 1;
      }
      pre = p;
      InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTNode &root){
  ThreadNode pre = NULL;
  if(root != NULL){
    InThread(T, pre);
    pre -> rchild = NULL;
    pre -> rtag = 1;
  }
}
```

# 6.4 中序线索二叉树遍历

* 找后继结点：对于rtag为1的结点，后继结点即为右孩子结点；否则，后继结点为右子树最左结点，即latg为0一直找
  ```cpp
  ThreadNode *FirstNode(ThreadNode *p){
    while(p->ltag == 0) p = p->lchild;
    return p;
  }

  ThreadNdoe *NextNode(ThreadNode *p){
    if(p->rtag == 0)  return Firstnode(p->rchild);
    else  return p->rchild;
  }
  ```
* 找前驱结点：逻辑类似，左为1则为前驱，否则为左孩子的最右结点
  ```cpp
  ThreadNode *LastNode(ThreadNode *p){
    while(p->rtag == 0) p = p->rchild;
    return p;
  }

  ThreadNdoe *PriorNode(ThreadNode *p){
    if(p->ltag == 0)  return LastNode(p->lchild);
    else  return p->lchild;
  }
  ```

# 7 中序线索二叉树的先序遍历、后序遍历、找父结点

# 8 插入、删除

# 9 先序、后续线索二叉树

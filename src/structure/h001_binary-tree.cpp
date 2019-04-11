//
// Created by 王明海 on 2019-04-11.
//

#include <utils.h>

// 定义二叉树的节点结构体
template<class T>
struct BinaryTreeNode {
    T _data;
    BinaryTreeNode <T>* _left;
    BinaryTreeNode <T>* _right;
    // 二叉树节点的构造函数
    BinaryTreeNode(T &data):_data(data),_left(NULL),_right(NULL){}
};

template<class T>
class BinaryTree {
private:
    typedef BinaryTreeNode<T> Node;
    Node* _root;

public:

    // 无参构造函数
    BinaryTree():_root(NULL){};

    // 有参构造函数
    BinaryTree(T* a, size_t size, size_t index, const T& Invalid) {
        _root = _CreateBinaryTree(a,size,index,Invalid);
    }

    //创造二叉树
    Node* _CreateBinaryTree(T* a,size_t size,size_t &index,const T& Invalid) {
        Node* root = NULL;
        if (a[index]!= Invalid && index < size) {
            root= new Node(a[index]);
            root->_left=_CreateBinaryTree(a, size,++index, Invalid);
            root->_right=_CreateBinaryTree(a, size,++index, Invalid);
        }
        return root;
    }

    // 递归前序遍历
    void PrevOrder () {
        _PrevOrder(_root);
    };

    void _PrevOrder (Node* root) {
        if (root == NULL) {
            return;
        }
        cout<<root->_data<<" ";
        _PrevOrder(root->_left );
        _PrevOrder(root->_right);
    }

    //递归中序遍历二叉树
    void InOrder(){
        _InOrder(_root);
    }

    void _InOrder(Node* root) {
        if(root==NULL) {
            return;
        }
        _InOrder(root->_left );
        cout<<root->_data <<" ";
        _InOrder(root->_right );
    }

    size_t Size() {
        return _Size(_root);
    }

    size_t _Size(Node* root) {
        static size_t Ssize=0;
        if(root==NULL)
            return 0;
        ++Ssize;
        _Size(root->_left);
        _Size(root->_right);
        return Ssize;
    }
};

TEST(_h001, BinaryTree) {
    int arr[10]={1,2,3,'#','#',4,'#','#',5,6};
    BinaryTree<int> bt(arr,10,0,'#');

    cout<<"前序递归遍历：";
    bt.PrevOrder();
    cout<<endl;

    cout<<"前序递归遍历：";
    bt.InOrder();
    cout<<endl;

    cout<<"二叉树的大小："<<bt.Size()<<endl;


}
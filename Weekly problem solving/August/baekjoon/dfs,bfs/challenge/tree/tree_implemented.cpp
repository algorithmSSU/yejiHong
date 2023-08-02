#include <iostream>
#include <string>
using namespace std;


struct Node{
    Node *left, *right;
    int value;
};


class BinarySearchTree{
    public:
        BinarySearchTree() : root(nullptr){};
        ~BinarySearchTree(){};

        void addNode(int value);
        bool searchValue(int value);
        void removeNode(int value);
        void show();
    private:
        Node *root;
        Node *tail;
        // inorder : 중위순회 
        void inorder(Node *current){
            if(current!=nullptr){
                inorder(current->left);
                cout << current->value << endl;
                inorder(current->right);
            }
        };
        Node*searchMaxNode(Node*node){ // 오른쪽 맨 마지막 노드를 가리키는
            if(node==NULL){
                return NULL;
            }
            while(node->right!=NULL){
                node = node->right;
            }
            return node;
        };
        Node *removeSeqence(Node *node, int value);
};


/*모든 노드 출력*/
void BinarySearchTree::show(){
    if(root==nullptr){
        cout << "nothing" << endl;
        return;
    }else{
        Node *node = root;
        inorder(node);
    };
};

/*노드를 추가하는 함수*/
void BinarySearchTree::addNode(int value){
    Node *node = new Node();
    Node *tmpRoot = nullptr;

    node -> value = value;

    // 새로운 node를 만들어서 value 값을 넣어줌


    // root 가 nullptr 이면 root를 node로 설정
    if(root==nullptr){
        root = node;
    }else{
        // ptr에 root 노드 연결
        Node *ptr = root;
        // node가 nullptr아닌경우 계속 탐색
        while(ptr!=nullptr){
            tmpRoot = ptr;
            // 새로만든 노드의 새로 넣으려는 값 < 현재 노드의 값
            if(node->value < ptr->value){
                ptr = ptr->left;
            }else{
                ptr = ptr->right;
            }
        }

        // tmpRoot = ptr; 
        // nullptr 이기 전에 노드를 가리키는 tmpRoot
        if(node->value < tmpRoot ->value){
            tmpRoot->left = node;
        }else{
            tmpRoot->right = node;
        }
    }

}

/*노드를 제거하는 함수*/
Node* BinarySearchTree::removeSeqence(Node* node,int _value){
    if(node==nullptr){ 
        return node;
    }else if(node->value>_value){ 
        node->left = removeSeqence(node->left, _value);
    }else if(node->value <_value){ 
        node->right = removeSeqence(node->right, _value);
    }else{ 
        Node *ptr = node;
        if(node->right==nullptr && node->left == nullptr){ 
            delete node;
            node = nullptr; 
        }else if(node->right==nullptr){ 
            node = node->left;
            delete ptr; 
        }else{ 
            ptr = searchMaxNode(node->left); 
            node->value = ptr->value;
            node->left = removeSeqence(node->left, ptr->value);
        };
    };
    return node;
};


void BinarySearchTree::removeNode(int value){
    Node *ptr = root;
    removeSeqence(ptr, value); // root노드부터 value를 가진 노드를 탐색해서 삭제
};


/*값을 찾는 함수*/
bool BinarySearchTree::searchValue(int value){
    Node *ptr = root;
    Node *tmpRoot = nullptr;
    while(ptr!=nullptr){
        if(ptr->value==value){
            cout << value << "Found" << endl;
            return true;
        }else if(ptr->value>value){
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        };
    }
    cout << value << "Not Found" << endl;
    return false;
};




int main(){

    BinarySearchTree *BST = new BinarySearchTree();

    BST->addNode(1);
    BST->addNode(3);
    BST->addNode(6);
    BST->addNode(9);
    BST->addNode(13);
    BST->addNode(22);
    BST->addNode(17);
    BST->addNode(10);
    BST->addNode(2);

    BST->show();
};
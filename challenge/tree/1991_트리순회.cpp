#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using std::pair;

/*8/17 풀기*/


#define MAX 26
struct node{
    char left;
    char right;
};

vector<node> v(MAX);


void preorder(char node){
    if(node=='.'){
        return;
    };
    cout << node;
    preorder(v[node].left);
    preorder(v[node].right);
};


void inorder(char node){
    if(node=='.'){
        return;
    };
    inorder(v[node].left);
    cout << node;
    inorder(v[node].right);
};

void postorder(char node){
    if(node=='.'){
        return;
    };
    postorder(v[node].left);
    postorder(v[node].right);
    cout << node;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    char root, le, ri;



    for (int i = 0; i < n;i++){
        cin >> root >> le >> ri;
        v[root].left = le;
        v[root].right = ri;
    }

    preorder('A');
    cout << "\n";

    inorder('A');
    cout << "\n";

    postorder('A');

    return 0;
};
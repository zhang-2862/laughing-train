#include <iostream>
#include <string>

using namespace std;

struct TreeNode{
    TreeNode* lchild;
    TreeNode* rchild;
    char data;
    TreeNode(char c):data(c),lchild(NULL),rchild(NULL){}
};

//根据先序遍历构建二叉树
TreeNode* Build(int &position,string str){
    char c=str[position++];
    if(c == '#'){
        return NULL;
    }
    TreeNode * root =new TreeNode(c);
    //先序遍历，先构建左子树，后构建右子树
    root->lchild = Build(position,str);//构建左子树
    root->rchild = Build(position,str);//构建右子树
    return root;
}

//中序遍历
void InOrder(TreeNode* root){
    if(root ==NULL){
        return;
    }
    InOrder(root->lchild);
    cout<<root->data<<" ";
    InOrder(root->rchild);
}

int main(){
    string str;
    cin>>str;
    int position = 0;
    TreeNode* root = Build(position,str);
    InOrder(root);
    delete root;
    return 0;
}

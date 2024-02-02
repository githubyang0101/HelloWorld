#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include "string.h"
using namespace std;
#include<memory>
#include <functional>

struct TreeNode {
    int num;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n, TreeNode* l, TreeNode* r):num(n),left(l),right(r){}
};
template<class Function>
void preorderTraverse(TreeNode* root, Function func)
{
    if(!root) return;
    func(root);
    preorderTraverse(root->left, func);
    preorderTraverse(root->right, func);
}
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> vec;
    int num;
    std::function<void(TreeNode*)> recursive_lambda = [&](TreeNode* t)
    {
        if (t==nullptr)
        {
            return;
        }
        vec.push_back(t->num);
        recursive_lambda(t->left);
        recursive_lambda(t->right);
    }; 
    recursive_lambda(root);
    return vec;
}
auto add(auto a,auto b)
{
    return a+b;
}
int func1(vector<int>& arr) {
    if (arr.size() < 2) {
        return -1; 
    }
    int l = arr[0];
    int s = arr[1];
    if (l < s) {
        swap(l, s);
    }
    for (int i = 2; i < arr.size(); i++) {
        if (arr[i] > l) {
            s = l;
            l = arr[i];
        } else if (arr[i] > s && arr[i] != l) {
            s = arr[i];
        }
    }
    return s;
}

vector<int> func2(int num)
{
    vector<int> vec;
    while(num!=0)
    {
        vec.push_back(num%10);
        num=num/10;
    }
    return vec;
}
int main() 
{
    vector<int> vec2=func2(123);
    for(int i=vec2.size()-1;i>=0;i--)
    {
        cout<<vec2[i]<<endl;
    }
    auto x=add(1,2.5);
    cout<<x<<endl;
    unique_ptr<TreeNode> p1(new TreeNode(5,nullptr,nullptr));
    unique_ptr<TreeNode> p2(new TreeNode(6,nullptr,nullptr));
    TreeNode n1(2,nullptr,nullptr);
    TreeNode n2(1,nullptr,nullptr);
    TreeNode n3(6,&n1,&n2);
    vector<int> vec;
    vec= preorderTraversal(&n3);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<":"<<endl;
    }
}


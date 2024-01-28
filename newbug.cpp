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
/*def preorderTraversal(root) -> List[int]:
    myList=[]
    def helper(root):
        if(root==None):
            return
        myList.append(root.val)
        helper(root.left)
        helper(root.right)
    helper(root)
    return myList
*/

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> vec;
    int num;
     auto recursive_lambda = [vec,root,&num](TreeNode* t) mutable{
        if(t==nullptr)
        {
            return;
        }
        //vector<int> &it=vec.begin();
       // vec.push_back(5);
        num=5;
        vec.push_back(5);
    };
        //recursive_lambda();
    
}
int main() {
        unique_ptr<TreeNode> p1(new TreeNode(5,nullptr,nullptr));
        unique_ptr<TreeNode> p2(new TreeNode(6,nullptr,nullptr));
        cout<<p1->num<<endl;
        cout<<p2->num<<endl;
        constexpr char* networkDBusService = "xyz.openbmc_project.Network";
        //*networkDBusService = "z";
        auto recursive_lambda = [](int n) {
        if (n <= 0) {
            return 0;
        } else {
           // return n + recursive_lambda(n - 1); // 递归调用
        }
    };

}


// edit on the remote
// edit on the localagainagain
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include "string.h"

using namespace std;
class A
{
public:
    virtual void print() { cout << "This is A" << endl; }
};
class B : public A
{
public:
    virtual void print() { cout << "This is B" << endl; }
};
/*
     a
    b   c
  d  e f  g

*/
typedef struct treeNode
{
    char c;
    treeNode *left;
    treeNode *right;
    treeNode(char ch, treeNode *l = NULL, treeNode *r = NULL) : c(ch), left(l), right(r)
    {
    }
} Node;
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->c;
    preOrder(root->left);
    preOrder(root->right);
}

void breadthOrder(Node *root)
{
    queue<Node *> que;
    if (root != NULL)
    {
        que.push(root);
    }
    while (!que.empty())
    {
        Node *temp = que.front();
        if (temp->left != NULL)
        {
            que.push(temp->left);
        }
        if (temp->right != NULL)
        {
            que.push(temp->right);
        }
        cout << temp->c;
        que.pop();
    }
    cout << endl;
    return;
}

int numIslands(vector<vector<char>> &grid)
{
    int visited[300][300] = {0};
    int num = 0;
    queue<int> quem, quen;
    for (int m = 0; m < grid.size(); m++)
    {
        for (int n = 0; n < grid[m].size(); n++)
        {
            if (grid[m][n] == '0' || (visited[m][n] == 1))
            {
                visited[m][n] = 1;
                continue;
            }
            quem.push(m);
            quen.push(n);
            num++;
            while (!quem.empty())
            {
                if (quem.front() + 1 < grid.size() && (visited[quem.front() + 1][quen.front()] == 0))
                {
                    if ((grid[quem.front() + 1][quen.front()] == '1'))
                    {
                        quem.push(quem.front() + 1);
                        quen.push(quen.front());
                        visited[quem.front() + 1][quen.front()] = 1;
                    }
                }
                if (quen.front() + 1 < grid[quem.front()].size() && (visited[quem.front()][quen.front() + 1] == 0))
                {
                    if ((grid[quem.front()][quen.front() + 1] == '1'))
                    {
                        quem.push(quem.front());
                        quen.push(quen.front() + 1);
                        visited[quem.front()][quen.front() + 1] = 1;
                    }
                }
                if ((quem.front() - 1 >= 0) && (visited[quem.front() - 1][quen.front()] == 0))
                {
                    if ((grid[quem.front() - 1][quen.front()] == '1'))
                    {
                        quem.push(quem.front() - 1);
                        quen.push(quen.front());
                        visited[quem.front() - 1][quen.front()] = 1;
                    }
                }
                if (quen.front() - 1 >= 0 && (visited[quem.front()][quen.front() - 1] == 0))
                {
                    if ((grid[quem.front()][quen.front() - 1] == '1'))
                    {
                        quem.push(quem.front());
                        quen.push(quen.front() - 1);
                        visited[quem.front()][quen.front() - 1] = 1;
                    }
                }
                quem.pop();
                quen.pop();
            }
        }
    }
    return num;
}
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> st;
    st.insert(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (st.find(nums[i]) != st.end())
        {
            return true;
        }
        st.insert(nums[i]);
    }
    return false;
}
int findKthLargest(vector<int> &nums, int k)
{
    map<int, int> mp;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) == mp.end())
        {
            mp.insert(pair<int, int>(nums[i], 0));
        }
        else
        {
            mp[nums[i]]++;
        }
    }
    auto it = --mp.end();
    while (count < k - 1)
    {
        if (it->second > 0)
        {
            (it->second)--;
        }
        else
        {
            it--;
        }
        count++;
    }
    return it->first;
}
int findKthLargestl(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> que;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        que.push(nums[i]);
        if (que.size() > k)
        {
            que.pop();
        }
    }
    return que.top();
}
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *pre = nullptr;
    ListNode *current = head;
    while (current)
    {
        ListNode *temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }
    return pre;
}

ListNode *reverseLList1(ListNode *head)
{
    ListNode *mid = head->next;
    head->next = nullptr;
    ListNode *last = mid->next;
    mid->next = head;
    ListNode *num[5000] = {0};
    int count = {0};
    num[count++] = head;
    num[count++] = num[count - 1]->next;
    num[count - 2]->next = nullptr;
    /*while()
    {
        num[count++]=num[count-1]->next;
        num[count-1]->next=
    }*/

    return head;
}
/*Question: Given an array of integers,
write a function to move all zeroes to the end of the array
while maintaining the relative order of the non-zero elements.
Example: Input: [0, 1, 0, 3, 12]  Output: [1, 3, 12, 0, 0]*/

vector<int> func(vector<int> &nums)
{
    int index;
    int N = nums.size();
    vector<int> reNums(N, 0);
    for (index = 0; index < nums.size(); index++)
    {
        if (nums[index])
        {
            reNums.push_back(nums[index]);
        }
    }
    return reNums;
}

int *moveZeroes(int nums[], int size)
{
    int index;
    int count = 0;
    vector<int> vec(size, 0);
    for (index = 0; index < size; index++)
    {
        if (nums[index])
        {
            vec[count] = nums[index];
            count++;
        }
    }
    for (index = 0; index < size; index++)
    {
        nums[index] = vec[index];
    }
    return nums;
}
/*2. Question: Given a string,
determine if it is a valid palindrome,
considering only alphanumeric characters and ignoring cases.
   Example:
   Input: "A man, a plan, a canal: Panama"
   Output: true*/

bool isPalindrome(string str)
{
    string str1;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            str1 += str[i];
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str1 += str[i] + 32;
        }
    }
    for (int i = 0; i < str1.size() / 2; i++)
    {
        if (str1[i] != str1[str1.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}
/*Question: Implement stack using list.
 The stack class should have a push and a pop method.*/
struct ListNode1
{
    int val;
    ListNode1 *next;
    ListNode1() : val(0), next(nullptr) {}
    ListNode1(int x) : val(x), next(nullptr) {}
    ListNode1(int x, ListNode1 *next) : val(x), next(next) {}
};

class Stack
{
private:
    ListNode1 *top;

public:
    Stack() : top(nullptr) {}
    void push(int data);
    void pop();
    bool empty();
};
bool Stack::empty()
{
    return top == nullptr;
}
void Stack::push(int data)
{
    ListNode1 *temp = new ListNode1(data);
    if (!temp)
    {
        cout << "heap overflow" << endl;
        exit(1);
    }
    temp->next = top;
    top = temp;
}
class complex
{
private:
    float r, i;

public:
    complex(float rr, float ii)
    {
        r = rr;
        i = ii;
    }
    void displaydata()
    {
        cout << "the value of r:" << r << endl;
        cout << "the value of i:" << i << endl;
    }
};
void Stack::pop()
{
    if (Stack::empty())
    {
        cout << "Stack overflow" << endl;
        exit(1);
    }
    ListNode1 *temp;
    temp = top;
    top = top->next;
    free(temp);
}

int main()
{
    complex c(5, 10);
    c.displaydata();
    B obj;
    A *p = &obj;
    p->print();
    Node *root;
    int *ptr1 = nullptr;
    int *ptr2;
    int num = 123;
    int micro1[5] = {0, 1, 0, 3, 12};
    string s = "ab";
    cout << "sizeof(s): " << s[2] << endl;
    char arr[] = "str";
    char *ptr = arr;
    char *str = "morn";
    int *p2 = moveZeroes(micro1, 5);
    int a = 1;
    cout << "sizeof(arr):" << sizeof(arr) << endl;
    cout << "sizeof(ptr): " << sizeof(ptr) << endl;
    cout << "strlen(str): " << strlen(str) << endl;
    cout << "xx=" << (a++) * (++a) << endl;
    bool b = isPalindrome(s);
    cout << b << "isPalindrome" << endl;
    for (int i = 0; i < 5; i++)
    {
        // cout<<p2[i]<<",";
    }
    // cout<<&ptr1<<endl<<ptr2<<endl<<&num<<endl;
    Node BB('b');
    Node CC('c');
    Node AA('a', &BB, &CC);
    root = &AA;

    // breadthOrder(root);
    // preOrder(root);
}

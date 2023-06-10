#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include <algorithm>
#include<unordered_set>

using namespace std;

string deleteDupliLetter(string s)
{
    stack<char> sk;
    string sd,st;
    int count[26]={0},countStack[26]={0},countOutside[26]={0};
    for(int i=0;i<s.size();i++)
    {
        countOutside[s[i]-'a']++;
    }
    if(!s.empty())
    {
        sk.push(s[0]);
        countOutside[s[0]-'a']--;
        countStack[s[0]-'a']++;
    }

    for(int i=1;i<s.size();i++)
    {
        if(countStack[s[i]-'a']>=1)
        {
            countOutside[s[i]-'a']--;
            continue;
        }
        while(!sk.empty()&&s[i]<sk.top()&&countOutside[sk.top()-'a']>0) {
            countStack[sk.top()-'a']--;
            sk.pop();
        }
        sk.push(s[i]);
        countOutside[s[i]-'a']--;
        countStack[s[i]-'a']++;
    }
    while(!sk.empty())
    {
        sd.push_back(sk.top());
        sk.pop();
    }
    for(int i=sd.size()-1;i>=0;i--)
    {
        st+=sd[i];
    }
    return st;
}

int longestSubStr(string s)
{
    if(s.size()==0)
    {
        return 0;
    }
    int index,max=1,first=0,last=first+1;
    set<int> st;
    for(index=0;index<s.size();index++)
    {
        if(st.find(s[index])==st.end()) //集合里面没有这个符号
        {
            st.insert(s[index]);  //放进集合里面
        }
        else
        {
            if(max<st.size())
            {
                max=st.size();
            }
            st.erase(s[first]);
            first++;
            index--;
        }
    }
    if(max<st.size())
    {
        max=st.size();
    }
    return max;
}

int fn(int n)
{
    if(0==n ||1==n ||2==n)
    {
        return n;
    }
    return fn(n-1)+fn(n-2);
}

int fx(int n)
{
    int arr[n];
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            arr[i]=1;
        }else if(i==2)
        {
            arr[i]=2;
        }else{
            arr[i]=arr[i-1]+arr[i-2];
        }
    }
    return arr[n];
}
bool isValid(string s) {
    stack<char> sign;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==')'&&!sign.empty()&&sign.top()=='(') {
            sign.pop();
            
        }else if(s[i]=='}'&&!sign.empty()&&sign.top()=='{') {
            sign.pop();
        }
        else if(s[i]==']'&&!sign.empty()&&sign.top()=='['){
            sign.pop();  
        }else{
            sign.push(s[i]);
        }
    }
    if(sign.empty()){
       return true; 
    }
    return false;
}
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    vector<int> left(nums.size(),1);
    vector<int> right(nums.size(),1);

    for(int index=1;index<nums.size();index++)
    {
        left[index]=left[index-1]*nums[index-1];
        right[nums.size()-1-index]=right[nums.size()-index]*nums[nums.size()-index];
    }
    for(int index=0;index<nums.size();index++)
    {
        result.push_back(left[index]*right[index]);
    }
    return result;
}
/*输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
  输出：         [[7,4,1],[8,5,2],[9,6,3]]

输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：         [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

xy->y(N-1-x)
y(N-1-x)->(n-1-x)(n-1-y)
(n-1-x)(n-1-y)->(n-1-y)x
(n-1-y)x->xy
  */
void rotate(vector<vector<int>>& matrix) 
{
    int N=matrix.size();
    int temp,count=0;
    for(int i=0;i<N/2;i++)
    {
        for(int j=0+count;j<N-1-count;j++)
        {
            temp=matrix[i][j];
            matrix[i][j]=matrix[N-1-j][i];
            matrix[N-1-j][i]=matrix[N-1-i][N-1-j];
            matrix[N-1-i][N-1-j]=matrix[j][N-1-i];
            matrix[j][N-1-i]=temp;
        }
        count++;
    }
return;
}
/*
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6。
*/
int maxSubArray(vector<int>& nums) {
    int max=0,maxOut=nums[0];
    for(int i=0;i<nums.size();i++)
    { if(max+nums[i]<nums[i]) {
            max=nums[i];
        } else{
            max=nums[i]+max;
        }
        if(maxOut<max)
        {
            maxOut=max;
        }
    }
    return maxOut;
}
/*
输入：stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
输出：5
stones[0]=[0,0]
stones[1]=[0,1]
stones[2]=[1,0]
stones[3]=[1,2]
stones[4]=[2,1]
stones[5]=[2,2]
*/
int removeStones(vector<vector<int>>& stones) {
    int len=stones.size(),N=1000,j,x;
    vector<int> temp;
    unordered_set<int> st;
    vector<vector<int>> xy[1000];
    temp.push_back(stones[0][0]);
    temp.push_back(stones[0][1]);
    st.insert(0);
    xy[0].push_back(temp);
    temp.clear();
    for(j=0;j<N;j++) 
    {
        for(x=0;x<xy[j].size();x++)
        {
            for(int i=0;i<len;i++)
            {
                if(st.find(i)!=st.end())
                {
                    continue;
                }
                if((xy[j][x][0]==stones[i][0])||(xy[j][x][1]==stones[i][1]))
                {
                    st.insert(i);
                    temp.push_back(stones[i][0]);
                    temp.push_back(stones[i][1]);
                    xy[j].push_back(temp);
                    temp.clear();
                }
            }
        }
        if(st.size()>=stones.size())
        {
            break;
        }
        for(int index=0;index<stones.size();index++)
        {
            if(st.find(index)==st.end())
            {
                st.insert(index);
                temp.push_back(stones[index][0]);
                temp.push_back(stones[index][1]);
                xy[j+1].push_back(temp);
                temp.clear();
                break;
            }
        }
    }

return stones.size()-(j+1);
}
/*输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
*/
vector<int> findAnagrams(string s, string p) {
    vector<int> index;
    map<char,int> mp1,mp2;
    int i,j,sum=0,left,right;
    string x;
    int N=p.size();
    if(s.size()<p.size())
    {
        return index;
    }
    x=s.substr(0,N);
    for(i=0;i<N;i++)
    {
        if(mp1.find(p[i])==mp1.end()){
            mp1.insert(pair<char,int>(p[i],1));
        }else{
            mp1[p[i]]++;
        }
        if(mp2.find(x[i])==mp2.end()){
            mp2.insert(pair<char,int>(x[i],1));
        }else{
            mp2[x[i]]++;
        }
    }
    if(mp1==mp2)
    {
        index.push_back(0);
    }
    for(right=x.size();right<s.size();right++)//条件断点不能加分号
    {
        if(mp2[s[right-N]]>1)
        {
            mp2[s[right-N]]--;
        }else{
            mp2.erase(s[right-N]);
        }
        if(mp2.find(s[right])==mp2.end())
        {
            mp2.insert(pair<char,int>(s[right],1));
        }else{
            mp2[s[right]]++;
        }
        if(mp1==mp2)
        {
            index.push_back(right-N+1);
        }
    }
    return index;
}
class A
{
    public:
    void print(){cout<<"This is A"<<endl;}
};
class B : public A
{
    public:
    void print(){cout<<"This is B"<<endl;}
};
int main333()
{
    B obj;
    A *p=&obj;
    p->print();
 /*    string s="bcbb";//"cdafaghdijkl";//
    int maxLen=longestSubStr(s);
    vector<int> result;
    string x="]";
    bool b=isValid(x);
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    result=productExceptSelf(nums);
    for(int index=0;index<result.size();index++)
    {
        //cout<<result[index]<<";";
    }
    //cout<<b<<endl;
    int c=5; */
    /*"aaaaaaaaaa"
"aaaaaaaaaaaaa"
"cbaebabacd"
"ababababab"
"aab"*/
/*     string st="ababababab",p = "aab";
    vector<vector<int>> matrix;
    vector<int> nums;
    //[-2,1,-3,4,-1,2,1,-5,4]
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    vector<int> temp,index;
    temp.push_back(5);
    temp.push_back(1);
    temp.push_back(9);
    temp.push_back(11);
    matrix.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(8);
    temp.push_back(10);
    matrix.push_back(temp);
    temp.clear();
    temp.push_back(13);
    temp.push_back(3);
    temp.push_back(6);
    temp.push_back(7);
    matrix.push_back(temp);
    temp.clear();
    temp.push_back(15);
    temp.push_back(14);
    temp.push_back(12);
    temp.push_back(16);
    matrix.push_back(temp);
    temp.clear();
    rotate(matrix);
    index=findAnagrams(st,p);
    for(int i=0;i<index.size();i++)
    {
        cout<<index[i]<<"**";
    }
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            //cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    //cout<<maxSubArray(nums)<<endl;
    vector<vector<int>> stone;
// [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
//[[0,0],[0,2],[1,1],[2,0],[2,2]]
//[[2,6],[2,0],[4,2],[1,0],[5,2],[0,2],[6,5]]
    temp.push_back(2);
    temp.push_back(6);
    stone.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(0);
    stone.push_back(temp);
    temp.clear();    
    temp.push_back(4);
    temp.push_back(2);
    stone.push_back(temp);
    temp.clear();    
    temp.push_back(1);
    temp.push_back(0);
    stone.push_back(temp);
    temp.clear();
    temp.push_back(5);
    temp.push_back(2);
    stone.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(2);
    stone.push_back(temp);
    temp.clear();
    temp.push_back(6);
    temp.push_back(5);
    stone.push_back(temp);
    temp.clear();
    int num=removeStones(stone);
    //cout<<num<<"++++++"<<endl;
    string x="abcdefg";
    x=x+x[0];
    cout<<x<<"[]"<<endl; */
    //cout<<fx(36)<<endl;
    //cout<<maxLen<<endl;
    int x=0,i=0;
    void *pv=&x;
    pv;
    string  s="strkdh";
    cout<<s.size()<<";;;"<<s.length()<<endl;
    do {
        if(i%5==0)
        {
            cout<<x<<"xxx";
            x++;
        }
        i++;
    }while(i<10);
    cout<<x<<"xxx";
    return 0;
}
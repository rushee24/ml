//fib
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void printFibonacciNumbers(int n){
    if(n>=0)cout<<0<<" ";
    if(n>=1)cout<<1<<" ";
    int prev2=0,prev1=1;
    for(int i=2;i<n;i++){
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
        cout<<curr<<" ";
    }
    return;
}
int main(){
    int n;
    cout<<"Enter Number"<<endl;
    cin>>n;
    printFibonacciNumbers(n);
    return 0;

}
//fibo rec
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int func(int n,vector<int>&dp){
    if(dp[n]!=-1)return dp[n];
    if(n==0 || n==1)return n;
    int num=func(n-1,dp)+func(n-2,dp);
    return dp[n]=num;
}
int main(){
    int n;
    cout<<"Enter Number"<<endl;
    cin>>n;
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++){
        int num=func(i,dp);
        cout<<num<<" ";
    }
    return 0;
}
//huff
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
    public:
    char data;
    int freq;
    Node *left,*right;
    Node(char data,int freq){
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

class cmp{
    public:
    bool operator()(Node* a,Node* b){
        return a->freq>b->freq;
    }
};

void printTree(Node *head,string str=""){
    if(head==NULL)return;
    if(head->left==NULL && head->right==NULL){
        cout<<head->data<<" -> "<<str<<endl;
        return;
    }
    printTree(head->left,str+"0");
    printTree(head->right,str+"1");
}

Node* buildTree(vector<char>&arr,vector<int>&frequency){
    priority_queue<Node*,vector<Node*>,cmp>pq;
    for(int i=0;i<arr.size();i++){
        pq.push(new Node(arr[i],frequency[i]));
    }
    while(pq.size()>1){
        Node *a=pq.top();
        pq.pop();
        Node *b=pq.top();
        pq.pop();
        Node *c=new Node('$',a->freq+b->freq);
        c->left=a;
        c->right=b;
        pq.push(c);
    }
    return pq.top();
}

int main(){
    int n;
    cin>>n;
    vector<char>arr(n);
    vector<int>frequency(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>frequency[i];
    }
    Node *head=buildTree(arr,frequency);
    printTree(head);
    return 0;
}
 //knaspack
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Item{
    public:
    int value;
    int weight;
};

bool cmp(Item a,Item b){
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;
}

double fractionalKnapsack(vector<Item>items,int W){
    sort(items.begin(),items.end(),cmp);
    double mx=0;
    for(int i=0;i<items.size();i++){
        if(items[i].weight<=W){
            mx+=items[i].value;
            W-=items[i].weight;
        }
        else{
            mx+=(items[i].value/(double)items[i].weight)*(double)W;
            break;
        }
    }
    return mx;
}
int main(){
    int n,W;
    cin>>n>>W;
    vector<Item>items(n);
    for(int i=0;i<n;i++){
        cin>>items[i].value;
        cin>>items[i].weight;
    }
    double maxValue=fractionalKnapsack(items,W);
    cout<<maxValue<<endl;
    return 0;
}
//knapsack without
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int func(int i,int j,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp){
    if(i==0){
        if(wt[i]<=j)return val[i];
        else return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int notTake=func(i-1,j,val,wt,dp);
    int take=0;
    if(wt[i]<=j){
        take=val[i]+func(i-1,j-wt[i],val,wt,dp);
    }
    return dp[i][j]=max(take,notTake);
}
int knapsack(int n,vector<int>&val,vector<int>&wt,int W){
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    int ans=func(n-1,W,val,wt,dp);   
    
    return ans;
}

// int knapsack(int n,vector<int>&val,vector<int>&wt,int W){
// iterative approach
// can be space optimized
//     vector<vector<int>>dp(n,vector<int>(W+1,0));
//     for(int j=wt[0];j<=W;j++)dp[0][j]=val[0];
//     for(int i=1;i<n;i++){
//         for(int j=0;j<=W;j++){
//             int notTake=dp[i-1][j];
//             int take=0;
//             if(wt[i]<=j){
//                 take=val[i]+dp[i-1][j-wt[i]];
//             }
//             dp[i][j]=max(take,notTake);
//         }
//     }
//     return dp[n-1][W];
// }
int main(){
    int n,W;
    cin>>n>>W;
    vector<int>val(n),wt(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int maxValue=knapsack(n,val,wt,W);
    cout<<maxValue<<endl;
    return 0;
}
//n queen
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isValid(int row,int col,vector<vector<char>>&board,int n){
    
    int dup_row=row;
    int dup_col=col;
    while(col>=0 && row>=0){
        if(board[row][col]=='Q')return false;
        row--;
        col--;
    }
    row=dup_row;
    col=dup_col;
    while(col>=0){
        if(board[row][col]=='Q')return false;
        col--;
    }
    col=dup_col;
    while(row<n && col>=0){
        if(board[row][col]=='Q')return false;
        row++;
        col--;
    }
    return true;
}
bool placeQueen(int col,vector<vector<char>>&board,int n){
    if(col==n)return true;
    for(int i=0;i<n;i++){
        if(isValid(i,col,board,n)){
            board[i][col]='Q';
            bool check=placeQueen(col+1,board,n);
            if(check==true)return true;
            board[i][col]='.';
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>board(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='.';
        }
    }
    placeQueen(0,board,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

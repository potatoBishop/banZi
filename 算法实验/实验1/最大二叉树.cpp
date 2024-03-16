#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stdlib.h> 
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;

struct Tree
{
    int z;
    struct Tree* left;
    struct Tree* right;
};

int getmax(int left, int right, int *a  ){
    int p = a[left];
    int pid = 0;
    for( int i = left; i <= right; i++ ){
        if( a[i] >= p ){
            p = a[i];
            pid = i;
        }
    }
    return pid;
}

Tree* bigTree(int left, int right, int *a){
    if( left > right ){ return NULL; }
    int maxid = getmax(left, right, a);
    struct Tree* ptree = new Tree();
    ptree->z = a[maxid];
    ptree->left  = bigTree(   left, maxid-1, a);
    ptree->right = bigTree(maxid+1,   right, a);

    return ptree;
}

void cenxu(Tree *tree) //层序遍历_队列实现
{
    queue <Tree*> q;
    if (tree != NULL)
    {
        q.push(tree);   //根节点进队列
    }

    cout << q.front()->z << " "; 
    while (q.empty() == false)  //队列不为空判断
    {
        // cout << q.front()->z << "  "; 
        if(q.front()->left == NULL&&q.front()->right == NULL){
            q.pop();
            continue;
        }

        if (q.front()->left != NULL)   //如果有左孩子，leftChild入队列
        {
            q.push(q.front()->left);
            cout<<q.front()->left->z<<" ";   
        } else {
            cout<<"null ";
        }

        if (q.front()->right != NULL)   //如果有右孩子，rightChild入队列
        {
            q.push(q.front()->right);
            cout<<q.front()->right->z<<" "; 
        }else {
            cout<<"null ";
        }

        q.pop();  //已经遍历过的节点出队列
    }
}


void solve(){
    // cout<<" =================="<<endl;
    int n;
    cin>>n;
    int* a = new int[10086];
    for( int i = 1; i <= n; i++ ) cin >> a[i];
    struct Tree* head = bigTree(1, n, a);
    // cout<<head->z<<endl;
    cenxu(head);
    free(a);
    return ;
}

int main() 
{ 
    clock_t c1 = clock();
    freopen(   "E:\\VS_code\\C++\\in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "E:\\VS_code\\C++\\out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int T ;
    cin >> T;
    while( T-- ){
        solve();
        cout<<endl;
    }
   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}


#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stdlib.h> 
using namespace std;
const int maxn = 1e5 + 5;

int getRand(int a, int b  ){
    return (rand() % (b-a+1))+ a;
}

void qs( int left, int right, int *a ){
    if( left >= right ) return;

    int tt = getRand(left, right);
    swap( a[left], a[tt] );             //随机取数
    // cout<<left<<" "<<tt<<endl;
    int q = a[left];
    int i = left-1, j = right+1;
    while( i < j ){
        do{i++;}while( a[i] < q );
        do{j--;}while( a[j] > q );
        if( i < j ) swap( a[i], a[j] );
    }
    qs( left,  i-1, a );
    qs( i+1, right, a );
    return;
}

void solve(){
    // cout<<" =================="<<endl;
    int n;
    cin>>n;
    int* a = new int[10086];
    for( int i = 1; i <= n; i++ ) cin >> a[i];
    qs(1, n, a);
    for( int i = 1; i <= n; i++ ) cout << a[i]<<" ";
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


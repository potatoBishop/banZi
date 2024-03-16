#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;

void solve( ){
    int n;
    int a[222];
    int sum = 0;

    cin >> n;
    for( int i = 1; i <= 2*n; i++ ) {cin >> a[i];}
    sort( a+1, a+2*n+1 );
    int j = 2*n-1;
    int prex = a[1], prey = a[2*n];

    for( int i = 2; i <= n; i++, j-- ){
        sum = sum + ( prey - a[j]  ) + ( a[i] - prex );
        prey = a[j];
        prex = a[i];
    }
    cout<<sum<<endl;

    j = 2*n;
    for( int i = 1; i <= n; i++, j-- ){
        cout<<a[i]<<" "<<a[j]<<endl;
    }

    return;
}


int main() 
{ 
    clock_t c1 = clock();
    freopen(   "E:\\VS_code\\C++\\in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "E:\\VS_code\\C++\\out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int T;
    cin >> T;
    while( T-- ){
        solve();
    }
   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}


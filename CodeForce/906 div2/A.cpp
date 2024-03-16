#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;

int solve(){
    int a[110];
    int num = 0, can = 0;
    cin >> num;
    int flag1 = -1, flag2 = -1, knum1 = 0, knum2 = 0;

    for( int i = 1; i <= num; i++ ){ 
        cin>> a[i];
        if( i == 1 ){ flag1 = a[i]; can++;} 
        if( i != 1 && a[i] != flag1 && knum2 == 0){ flag2 = a[i]; can++; }
        if( a[i] == flag1 ) knum1++;
        if( a[i] == flag2 ) knum2++;
        // cout<<knum1<<" "<<knum2<<endl;
    }
    // cout<<can<<endl;
    if( num == 2 ) return 1;
    else if( can == 1 ) return 1;
    else if( can == 2 ){
        if( num == knum2 + knum1 && abs(knum2 - knum1) <= 1 ) return 1;
    }

    return 0;
}

int main() 
{ 
    clock_t c1 = clock();
    freopen(   "E:\\VS_code\\C++\\in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "E:\\VS_code\\C++\\out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    
    int T;
    cin >> T;
    while( T -- ){
        int res = solve();
        if( res == 1 ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}


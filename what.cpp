#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

string mp[100];

void solve(){
    cin>>r>>c;
    for( int i = 1; i <= r; i++ ){
        string p;
        cin>>p;
        p = " " + p;
        mp[i] = p;
    }

    for( int i = 1; i <= r; i++ ){
        for( int j = 1; j <= c; j++ ){
            if(  )
        }
    }
    

    return;
}

int main() 
{ 
    clock_t c1 = clock();
    freopen(   "E:\\VS_code\\C++\\in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "E:\\VS_code\\C++\\out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int T  = 1;
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


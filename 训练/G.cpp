#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
const int maxn = 1e5 + 5;

void solve(){

    string str;
    int ql = 0;
    int qr = 0;
    int flag = 0;
    int flag2 = 0;
    int flag3 = 0;
    cin >> str;

    for( int i = 0; i < str.length(); i++ ){
        if( str[i] == '(' ) {
            flag = 1;
            ql++;
        }else {
            flag3 = 1;
            qr++;
            if( flag == 0 ){
                
            } else {
                ql--;
            }
        }
        if( ql < 0 ) flag2 = 1; 
    }
    
    if( (ql > qr) || flag2 == 1) cout<<"impossible"<<endl;
    else cout<<str<<endl;
    return;
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
    }
   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}


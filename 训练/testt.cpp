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
    // cout<<"-========"<<endl;
    string str;
    string res = "";
    char p;
    int ql = 0;
    // int qr = 0;
    int flag = 0;
    p = getchar();

    while( p !='\n' ){
        // cout<<p;
        if( p == '(' ) { 
            if( flag == 0 ){
                res.append('(');
                ql++;
            } else {
                res.append(")(");
                flag--;
            }
            
            
        } else {
            if( ql >= qr ){
                continue;
            } else {
                res.append(')');
            }
            qr++;
     
        }
        p = getchar();
    }

    // cout<<"ans::"<<endl;
    
    if( q!=0 ) cout<<"impossible"<<endl;
    else cout<<res<<endl;
    return;
}

int main() 
{ 
    // clock_t c1 = clock();
    // freopen(   "E:\\VS_code\\C++\\in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    // freopen( "E:\\VS_code\\C++\\out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int T ;
    cin >> T;
    getchar();
    while( T-- ){
        solve();
    }
   
    
    return 0; 
    //=======================================================================================
    // cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    // fclose(stdin);//关闭文件
    // fclose(stdout);//关闭文件
}


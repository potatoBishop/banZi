#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 100;

int gerLength( int x ){
    int p = 0;
    if( x == 0 ) return 1;
    while( x > 0 ){
        p++;
        x = x >> 1;
    }
    return p;
}

void solve( int p[], int s[], int l[], int b[] ){
    s[0] = 0;
    for( int i = 1; i <= 7; i++ ){
        int bmax = gerLength( p[i] );       // 获取该点像素的位数
        b[i] = bmax;
        s[i] = s[i-1] + bmax;
        l[i] = 1;                           //设定刚加入的点自成一段？
        for( int j = 2; j <= i && j <= 256; j++ ){
            if( bmax < b[i-j+1] ) bmax = b[i-j+1];
            if( s[i] > s[i-j] + bmax*j ) { 
                s[i] = s[i-j] + bmax*j;
                l[i] = j; 
            }
        } 
        s[i] += 11;
    }

    // for( int i = 0; i <= 7; i++ ) cout<<i<<" ";
    // cout<<endl;
    // for( int i = 0; i <= 7; i++ ) cout<<s[i]<<" ";
    // cout<<endl;
    // for( int i = 0; i <= 7; i++ ) cout<<l[i]<<" ";
    // cout<<endl;
    // for( int i = 0; i <= 7; i++ ) cout<<b[i]<<" ";
    // cout<<endl;
}


int main() 
{ 
    clock_t c1 = clock();
    freopen(   "in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int p[maxn];
    int s[maxn];
    int l[maxn];
    int b[maxn];
    for( int i = 1; i <= 7; i++ ){
        cin >> p[i];
    }
    solve(p, s, l, b);
   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}


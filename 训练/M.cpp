#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int a[300010];
int b[300010];
void solve(){
    // cout<<"===  "<<endl;
    int n;
    cin >> n;
    
    vector<int> vp;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i] >> b[i];
        vp.push_back(a[i]);
        vp.push_back(b[i]);
    }
    sort( vp.begin(), vp.end() );
    int id = n-1+(n+1)/2;
    cout<<vp[id]<<endl;
    
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


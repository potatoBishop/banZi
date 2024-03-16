#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;


int pan( string a, int size ){
	for( int i = 1; i < size; i++ ){
		if( a[i] == a[i+1] ) {
			return 0;	
		}
	}
	return 1;
}

int solve(){
	int sn, tn;
	string s, t;
	cin >> sn >> tn;
	cin >> s >> t;
	s = " " + s;
	t = " " + t;

	if( sn <= 1 ) return 1;

	int flagt = pan( t, tn );
	int flags = pan( s, sn );

	int kind = -1;
	// cout<<t[1]<<" "<<t[tn]<<endl;
	if( t[1] == '0' && t[tn] == '0' ) kind = 0;
	if( t[1] == '1' && t[tn] == '1' ) kind = 1;
	// cout<<kind<<endl;
	
	if( flags == 1 ) return 1;
	if( flags == 0 ){
		if( flagt == 0 ) return 0;
		if( flagt == 1 && kind != -1 ){
			for( int i = 1; i < sn; i++ ){
				if( s[i] == s[i+1] ){
					char key = s[i];
					if( key == '1' && kind == 1 ) return 0;
					if( key == '0' && kind == 0 ) return 0;
				}
			}
			return 1;
		}
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
    	if( res == 1 ) cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;
    }
   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}


#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;

void solve(){
	int sn;
	string s, t;
	cin >> sn;
	cin >> s;
	s = " " + s;
	t = " 01";

	int num = 0;
	int a[310];
	if( sn == 1 || sn%2 == 1 ){ cout<<-1<<endl; return ; } ; //奇数

	for( int i = 1; i <= sn/2; i ++ ){
		int j = sn - i + 1;
		if( s[i] == s[j] && num < 300 ){
			// cout<<sn<<" "<<i<<" "<<j<<endl;
			num++;
			a[num] = j;
			string ps = s.substr(0, j+1) + "01" + s.substr(j+1, sn - j + 1);
			// cout<<ps<<endl;
			s = ps;
			sn+=2;
		} 
		if( num > 300 ) { cout<<-1<<endl; return ; }
	}
	cout<<num<<endl;
	for( int i = 1; i <= num; i++ ){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	return ;
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
    	solve();
    }
   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}


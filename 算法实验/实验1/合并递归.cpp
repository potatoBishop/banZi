#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;

void digui(int left, int right, int *a){
	if( left >= right ) return ;

	int mid = (left + right)/2;
	digui(  left,   mid, a );
	digui( mid+1, right, a );
	int b[10086];
	int k1 = left;
	int k2 = mid+1;
	int t = 0;

	while( k1 <= mid && k2 <= right ){
		if( a[k1] < a[k2] ){ 
			b[++t] = a[k1++];  
		}else {
			b[++t] = a[k2++];  
		}	
	}

	while( k1 <= mid ){ b[++t] = a[k1++]; }
	while( k2 <= right ){ b[++t] = a[k2++]; }
	for( int i = 0; i < t; i++ ){
		a[left+i] = b[i+1];
	}
	return;

}

void solve(){
	int n;
	cin>>n;
	int* a = new int[10086];
	for( int i = 1; i <= n; i++ ) cin >> a[i];
	digui(1, n, a);
	for( int i = 1; i <= n; i++ ) cout << a[i]<<" ";
	free(a);
	return ;
}
int main() 
{ 
    clock_t c1 = clock();
    freopen(   "E:\\VS_code\\C++\\in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "E:\\VS_code\\C++\\out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //==========================================================================
    int T;
    cin >> T;
    while( T -- ){
    	solve();
    	cout<<endl;
    }
    return 0; 
    //==========================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}




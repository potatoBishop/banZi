//优先队列

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct task{
    int si;
    int fi;
    // bool operator() (task a, task b) {
    //     if( a.fi == b.fi ) return a.si > b.si;
    //     else return a.fi > b.fi; //小顶堆
    // }
    bool operator<(const task& a) const
    {
        if( fi == a.fi ) return si < a.si;
        return fi < a.fi; //大顶堆
    }
    bool operator>(const task& a) const
    {
        if( fi == a.fi ) return si > a.si;
        return fi > a.fi; //大顶堆
    }
};

int main(){
    int n;
    cin >> n;
    priority_queue<task, vector<task>, greater<task> > pq;
    for( int i = 1; i <= n; i++ ){
        int si, fi;
        cin >> si >> fi;
        struct task ptask = {si, fi};
        pq.push(ptask);
    }
    int all = 0;
    int now = 0;
    while( !pq.empty() ){
        struct task p = pq.top();
        if( p.si >= now ){
            now = p.fi;
            all++;
        }
        pq.pop();
    }
    cout<<all;
    return 0;
}






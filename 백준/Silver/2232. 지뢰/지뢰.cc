#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <stack>
#include <cstring>
#include <deque>
#include <set>
#include <unordered_set>
#include <chrono>
#include <tuple>

using namespace std;
#define MAXX 2147483647


int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int N;
    cin>>N;
    vector<int>graph(N);
    
    for(int a=0; a<N; a++)
        cin>>graph[a];
        
        //개수가 1개인 경우
        if(N==1)
            cout<<1;
        else
        {
        	//맨 앞에서 터져야 할 경우
            if(graph[0]>=graph[1])
                cout<<1<<'\n';
            
            for(int a=1;a<N-1;a++)
                // 양쪽을 터뜨릴 수 있을 경우
                if(graph[a]>=graph[a-1] && graph[a]>=graph[a+1])
                    cout<<a+1<<'\n';
            
            //맨 뒤에서 터져야 할 경우
            if(graph[N-1]>=graph[N-2])
                cout<<N<<'\n';
            
        }

    
  

    return 0;
}
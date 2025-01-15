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

using namespace std;
#define MAXX 99999999




int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int n,m;

    cin>>n>>m;
   
    priority_queue<long long, vector<long long>, greater<>>pq;
    vector<long long>v;

      for (int a=0;a<n ;a++ )
        {
            int b;
            cin>>b;
            v.push_back(b);
        }
    sort(v.rbegin(),v.rend());

    
  
    for (int a=0;a<n ;a++ )
        {
            long long b=v[a];

            if(pq.size()<m)
                pq.push(b);
            else
            {
                long long tmp = pq.top();
                pq.pop();
                tmp+=b;
                pq.push(tmp);
            }
        }

       
        while(!(pq.size()==1))
            pq.pop();
    cout<<pq.top();
    

}

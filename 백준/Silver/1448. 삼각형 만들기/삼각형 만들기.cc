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


vector<int>w; // 가로 
vector<int>h; // 세로  
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
    cin>>n;
    vector<int>v(n);
    for (int a=0;a<n ; a++) 
        cin>>v[a];

    sort(v.begin(),v.end());

    for (int a = n-1;a>=2 ;a-- ) 
    {
         if(v[a]<v[a-1] + v[a-2])
         {     cout<<v[a]+v[a-1] + v[a-2];
             return 0;
         }
    }
    
	cout<<-1;


}


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


set<string> Set;
int arr[26];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        memset(arr,0,sizeof(arr));
        int len = s.length();
        vector<int> v(len,0);
        
        for(int a = 0; a < len; a++)
            arr[s[a]-'a']++; // 빈도
        

        int cur = 0;
        for(int a = 0; a < 26; a++)
        {
            if(arr[a] == 0) 
                continue;

            while(arr[a] > 0)
            {
                v[cur] = a;
                arr[a]--;
                cur++;
            }
        }


      
        do{
            string ret = "";
            for(int a = 0; a < len; a++)
                ret += v[a] + 'a';
            Set.insert(ret);
        }while(next_permutation(v.begin(),v.end())); // 백트래킹과 같이 모든 조합 출력

        for(auto i : Set)
            cout << i << '\n';
        

          Set.clear();
    }

    return 0;
   
}



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

vector<int> wm;
vector<int> wp;
vector<int> mm;
vector<int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;
    for (int a = 0; a < n; a++) 
    {
        int want_height;
        cin >> want_height;
        
        if (want_height < 0) 
            mm.push_back(want_height); // 남자이면서 음수            
        else 
            mp.push_back(want_height); // 남자이면서 양수
    }
    
    for (int i = 0; i < n; i++) 
    {
        int want_height;
        cin >> want_height;
        
        if (want_height < 0) 
            wm.push_back(want_height); // 여자이면서 음수
        else 
            wp.push_back(want_height); // 여자이면서 양수
        
    }
    
    sort(mm.begin(), mm.end());
    sort(wp.begin(), wp.end());
    sort(mp.begin(), mp.end());
    sort(wm.begin(), wm.end());

    int ct = 0;


    int l = 0;  // 큰 남자를 원하는 여자
    int r = mm.size()-1; // 작은 여자를 원하는 남자
    while(r>=0)
    {

        if (l >= wp.size() ) // 모두 돌아봤다면
            break;
        
        if (abs(mm[r]) > wp[l])
        {

            l++;
            ct++;
        }
        
         r--;
    }

    l = 0;  // 큰 여자를 원하는 남자
    r = wm.size()-1; // 작은 남자를 원하는 여자

    
    while(r>=0)
    {

        if (l>= mp.size()) 
            break;
        
       // 자기보다 키 작은 원하는 여자인 경우
        if (abs(wm[r]) > mp[l]) 
        {
            
            l++;
            ct++;
        }
        r--;
    }
    cout << ct;
}

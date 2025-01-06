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



vector<string>v;

bool compare(string s1, string s2)
{
   
 if (s1==s2) //문자가같다면
        return false;
 
    // 서로 결합케이스 생성
    string s1s2 = s1 + s2;
    string s2s1 = s2 + s1;
    
    if (s1s2 > s2s1)
        return true;
        
    else
        return false;

    
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int n;
    int flag = 0;
    cin>>n;
    for (int a=0;a<n ;a++ )
        {
            string s;
            cin>>s;
            v.push_back(s);
            
            if(s!="0")
                flag = 1;
        }

     if (flag == 0) // 전부 0이라면
         cout << 0;
         
    else
     {
        //정렬
        sort(v.begin(), v.end(), compare);
        for (int a = 0; a < n; a++) 
            cout << v[a]; 
    }
	return 0;

}

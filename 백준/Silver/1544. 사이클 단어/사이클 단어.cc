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

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    map<string, int> m;
    map<string, int>::iterator iter;

    int ans = 0; //서로 다른 단어가 몇 개인지

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        iter = m.find(str);
    

        if (iter == m.end())//map에 없는 경우
        { 
            ans++;

            //사이클 단어를 만드는 코드
            for (int j = 0; j < str.size(); j++) {
                string temp = "";
                for (int k = j; k < str.size(); k++) 
                    temp = temp + str[k];
                
                for (int q = 0; q < j; q++) 
                    temp = temp + str[q];
                

                m.insert({ temp,i });

            }

        }
        else 
            continue;
        



    }
    cout << ans;

}
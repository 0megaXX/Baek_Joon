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
#define MAXX 987654321
using namespace std;

string arr[1001];
string str[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 

    int cass, len;
    cin >> cass >> len;
    for (int a = 0; a < cass; a++) 
        cin >> arr[a];
    


    for (int a = 0; a < len; a++) 
    {
        set<string> s;
        set<string>::iterator iter;

        for (int b = 0; b < cass; b++) 
            str[a] += arr[b][a];
        

        s.insert(str[a]);
    }

    for (int a = 0; a < cass; a++) {
        set<string> s;
        set<string>::iterator iter;

        for (int b = 0; b < len; b++) 
        {
            if (str[b].size() != 0) {
                str[b].erase(str[b].begin());

                iter = s.find(str[b]);

                if (iter == s.end()) 
                    s.insert(str[b]);
                
                else 
                {
                    if (a == 0) {
                        cout << 0;
                        return 0;
                    }
                    cout << a;
                    return 0;
                }
            }

        }
    }
    cout << cass - 1;
}
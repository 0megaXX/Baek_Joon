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
   
	string s1, s2;
	int ct = 0;

    getline(cin, s1);
    getline(cin, s2);

    for (int a = 0; a < s1.length(); a++)
    {
        bool flag = true;
        for (int b = 0; b < s2.length(); b++)
        {
            if (s1[a + b] != s2[b])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ct++;
            a += s2.length() - 1;
        }
    }
    cout << ct;


}
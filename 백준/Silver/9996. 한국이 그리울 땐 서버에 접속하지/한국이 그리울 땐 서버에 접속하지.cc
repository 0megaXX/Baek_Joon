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
    #include <regex>

    using namespace std;
    #define MAXX 2147483647


 
    regex pattern("(100+1+|01)+");

 
    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);

        int N;
        cin >> N;

        string s;
        cin >> s;

        int pos = s.find('*');
        string first = s.substr(0, pos);
        string last = s.substr(pos + 1, s.length());

        for (int i = 0; i < N; i++) {
            string s2;
            cin >> s2;

            if (s2.length() < first.length() + last.length())
            {
                cout << "NE" << "\n";
                continue;
            }

            string compfirst = s2.substr(0, first.length());
            string complast = s2.substr(s2.length() - last.length(), s2.length());

            if (compfirst == first && complast == last)
                cout << "DA" << "\n";
            else
                cout << "NE" << "\n";
        }


        return 0;
    }

 
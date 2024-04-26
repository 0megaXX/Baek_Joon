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
   string x, y;
	cin >> x >> y;

    int minn = 987654321;
    for (int a = 0; a < y.size(); a++) 
    {
        if (a + x.size() > y.size())
            continue;
        int diff = 0;
        for (int b = 0; b < x.size(); b++)
            if (x[b] != y[a + b]) diff++;
        
        minn = min(diff, minn);
    }
    cout << minn;

}
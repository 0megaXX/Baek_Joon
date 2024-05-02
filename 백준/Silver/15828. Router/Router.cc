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

bool compare(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int sizz;
    cin >> sizz;
    int num;
    queue<int> q;

    while (1)
    {
        cin >> num;
        if (num == -1)
            break;
        if (num > 0)
        {
            if (q.size() < sizz)
                q.push(num);
        }
        if (num == 0)
            q.pop();
    }
    if (q.empty())
        cout << "empty\n" ;
    else
        while (!q.empty())
        {
            cout << q.front() << ' ';
            q.pop();
        }


}
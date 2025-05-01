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



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	int w, h, p, q, t;
	cin >> w >> h;
	cin >> p >> q;
	cin >> t;
	bool pb = true, qb = true;
	int pt = t % (2 * w);
	int qt = t % (2 * h);

	while (pt--) {
		if (p == w) 
			pb = false;
		
		else if (p == 0) 
			pb = true;
		
		if (pb)
			p++;
		else
			p--;
	}
	while (qt--) {
		if (q == h) 
			qb = false;
		
		else if (q == 0) 
			qb = true;
		
		if (qb)
			q++;
		else
			q--;
	}
	cout << p << " " << q;

}

 
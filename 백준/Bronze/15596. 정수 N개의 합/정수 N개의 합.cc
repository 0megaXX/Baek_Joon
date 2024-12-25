#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
        for (int b = 0; b < a.size(); b++) 
		ans += a[b];
	
	return ans;
}

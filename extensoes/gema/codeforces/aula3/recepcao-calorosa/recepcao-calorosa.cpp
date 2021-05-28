#include <bits/stdc++.h>
using namespace std;

bool solve (int l, int r)
{
    if(l > r)
		return false;
	int m = (l + r ) / 2;
    cout << m << endl;
    int n;
	cin >> n;

	if(n == 0 )          
		return solve (l, m - 1);  

	else if (n == 1)
		return solve (m + 1, r);
	
	else
		return true;   
	

}


int main()
{
	bool answer = solve(1, 10);
    return 0;
}
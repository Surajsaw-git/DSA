/*
You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.

A number which completely divides another number is called it's divisor.

Example 1:
Input: n = 6

Output = [1, 2, 3, 6]

Explanation: The divisors of 6 are 1, 2, 3, 6.

Example 2:
Input: n = 8

Output: [1, 2, 4, 8]

Explanation: The divisors of 8 are 1, 2, 4, 8.
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> ans;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    Solution D;
    D.divisors(n);
    return 0;
}
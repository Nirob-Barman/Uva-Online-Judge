#include <bits/stdc++.h>

using namespace std;

vector<int> calculateFactorial(int n)
{
    vector<int> result;
    result.push_back(1); // Initialize the result with 1 (0! = 1)

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < result.size(); j++)
        {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }

        while (carry)
        {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    return result;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;

        vector<int> factorial = calculateFactorial(n);

        cout << n << "! --" << endl;
        vector<int> digitCount(10, 0); // Initialize counts for digits 0-9

        for (int i = 0; i < factorial.size(); i++)
        {
            digitCount[factorial[i]]++;
        }

        for (int i = 0; i <= 9; ++i)
        {
            cout << setw(5) << "(" << i << ")"
                 << setw(5) << digitCount[i];
            if (i == 4 || i == 9)
                cout << endl;
        }
    }

    return 0;
}

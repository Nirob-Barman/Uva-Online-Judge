#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 1500;

    // vector<int> ugly(n);
    int ugly[n];
    ugly[0] = 1;
    // printf("%d %d\n", 0, ugly[0]);

    int i2 = 0, i3 = 0, i5 = 0; // Indexes for multiples of 2, 3, and 5

    for (int i = 1; i < n; i++)
    {
        // Find the next ugly number by choosing the smallest among the multiples
        ugly[i] = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));
        // printf("%d %d - ", i, ugly[i]);

        // Update the indexes for multiples of 2, 3, and 5
        if (ugly[i] == ugly[i2] * 2)
        {
            // printf("i: %d\n", i);
            i2++;
        }
        if (ugly[i] == ugly[i3] * 3)
        {
            // printf("i: %d\n", i);
            i3++;
        }
        if (ugly[i] == ugly[i5] * 5)
        {
            // printf("i: %d\n", i);
            i5++;
        }
    }

    cout << "The 1500'th ugly number is " << ugly[n - 1] << "." << endl;

    return 0;
}

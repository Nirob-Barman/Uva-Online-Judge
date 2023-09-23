/*
C(n, k) = n! / (n-k)! * k!
        = [n * (n-1) *....* 1]  / [ ( (n-k) * (n-k-1) * .... * 1) *
                                    ( k * (k-1) * .... * 1 ) ]
After simplifying, we get
C(n, k) = [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]

Also, C(n, k) = C(n, n-k)  // we can change k to n-r if k > n-k

// nCr = (n * (n - 1) * (n - 2) * ... * (n - r + 1)) / (1 * 2 * 3 * ... * r)
*/
#include <bits/stdc++.h>

using namespace std;

long long calculateNCR(long long n, long long r)
{
    if (r == 0 || r == n)
    {
        return 1;
    }

    if (n - r > r)
    {
        r = n - r;
    }

    long long result = calculateNCR(n - 1, r - 1);
    result = result * n / r;

    return result;
}

int main()
{
    long long n, m;
    while (scanf("%lld %lld", &n, &m) && (n || m))
    {
        printf("%lld things taken %lld at a time is %lld exactly.\n", n, m, calculateNCR(n, m));
    }
    return 0;
}
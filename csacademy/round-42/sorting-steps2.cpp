#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int A[100005];

int main()
{
    int N, ans = 0;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
    }
    int steps = 0;
    while (true)
    {
        ++steps;
        bool isSorted = true;
        for (int i = 1; i < N; ++i)
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                printf("%d %d\n", i, i+1);
                isSorted = false;
            }
        if (isSorted) break;
    }
    printf("%d\n", steps);
    return 0;
}


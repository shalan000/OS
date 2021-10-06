#include <stdio.h>
int main()
{
    // P0, P1, P2, P3, P4 are the Process names here
    int n=5, m=3, i, j, k, y,ind=0; 
    //n- Number of processes
    //m- Number of resources
    int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
 
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4
    int finish[n], safesequence[n],work[3],need[n][m];
    int avail[3]= { 3, 3, 2 }; // Available Resources
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    //calculating NEED matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    printf("NEED matrix is");
    for (i = 0; i < n; i++) 
    {
        printf("\n");
        for (j = 0; j < m; j++)
               printf(" %d  ",need[i][j]);
               
    }
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) 
        {
            if (finish[i] == 0) 
            {
                int flag = 0;
                for (j = 0; j < m; j++) 
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    safesequence[ind++] = i;
                    for (y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
    printf("\nFollowing is the SAFE Sequence\n");
    for (i = 0; i <= n - 1; i++)
        printf(" P%d ", safesequence[i]);
 }

#include "types.h"
#include "stat.h"
#include "user.h"
int main()
{
    setprio(0);
    if(fork()!=0)
    {
        // printf(1, "P(%d)[%d]\n", getpid(), getprio());
        int n = 10;
        int a[n][n];
        int b[n][n];
        int c[n][n];
        int x, i, j, k;
        sleep(1);
        printf(1, "P[%d]\n", getprio());
        for(x=0; x<n*1000; x++){
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    for(k=0; k<n; k++){
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
        }
        sleep(1);
        printf(1, "P[%d]\n", getprio());
        wait();
        exit();
    }
    else
    {
        sleep(1);
        printf(1, "C[%d]\n", getpid(), getprio());
        exit();
    }
}

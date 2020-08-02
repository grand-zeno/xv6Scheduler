#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int id1=fork();
    int init, fin;
    if(id1==0)
    {
        init = getprio();
        setprio(10);
        fin = getprio();
        sleep(1);
        printf(1, "C[%d->%d]\n", init, fin);

        exit();
    }
    else
    {
        init = getprio();
        setprio(0);
        fin = getprio();
        sleep(1);
        printf(1, "P[%d->%d]\n", init, fin);
        
        wait();
    }
    exit();
}


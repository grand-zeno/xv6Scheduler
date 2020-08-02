#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    setprio(0);
    if(fork()!=0)
    {
        printf(1,"Parent [%d]\n",getprio());
        wait();
        printf(1,"Parent [%d]\n",getprio());
        exit();
    }
    else
    {
        setprio(1);
        int tik = uptime();
        int tok = tik;
        while((tik-tok)<40)
        {
            tik = uptime();
        }
        exit();
    }
    
}

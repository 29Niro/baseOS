#include "io.h"
#include "fb.h"

    /* The C function */
    int sum_of_three(int arg1, int arg2, int arg3)
    {
        return arg1 + arg2 + arg3;
    }

    void run(){
        char c[] = "Welcome";
        write(c, 2);
    }
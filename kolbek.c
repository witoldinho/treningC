#include<stdio.h>
//#include"reg_callback.h"

/* reg_callback.h */
typedef void (*callback)(void);
void register_callback(callback ptr_reg_callback);

/* registration goes here */
void register_callback(callback ptr_reg_callback)
{
    printf("inside register_callback\n");
    /* calling our callback function my_callback */
    (*ptr_reg_callback)();
}

/* callback function definition goes here */
void my_callback(void)
{
    printf("inside my_callback\n");
}

int main(void)
{
    /* initialize function pointer to
    my_callback */
    callback ptr_my_callback=my_callback;
    printf("This is a program demonstrating function callback\n");
    /* register our callback function */
    register_callback(ptr_my_callback);
    printf("back inside main program\n");
    for (int i=0;i<10;i++){
    //my_callback();
    register_callback(ptr_my_callback);
    }

    return 0;

}

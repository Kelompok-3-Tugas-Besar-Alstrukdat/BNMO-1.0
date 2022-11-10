#include <time.h>
#include <stdio.h>

void countdown(){
    int check;
    time_t start_t, end_t;
    float diff_t;
    check = 0;
        time(&start_t);
        time(&end_t);
        
        diff_t = difftime(end_t, start_t);
        while (diff_t != 3){
            time(&end_t);
            diff_t = (float) difftime(end_t, start_t);
            
            if ((diff_t == 1 ) && (check != -1) && (check != -2) && (check != -99)) {
                printf(".");
                check = -1;
            }
            if ((diff_t == 2 ) && (check == -1)) {
                printf(".");
                check = -2;
            }
            if ((diff_t == 3 ) && (check == -2)) {
                printf(".");
                check = -99;
            }
        }
        printf("\n");
}
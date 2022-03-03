
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//-------------------------
void static_array(){
    static int array [1000];
}
void array_on_stack(){
    int array [1000];
}
void array_on_heap(){
    int *array = (int*) malloc(1000 * sizeof(int));
    free(array);
}
float calc_time(clock_t start, clock_t end){
    return (float)(end - start) / CLOCKS_PER_SEC;
}
//-------------------------
int main(){

    clock_t start_time = clock();
    for(int i=0; i<1000000; i++){
        static_array();
    }
    clock_t end_time = clock();
    printf("It took %f seconds for the static array.\n", calc_time(start_time, end_time));

    start_time = clock();
    for(int i=0; i<1000000; i++){
        array_on_stack();
    }
    end_time = clock();
    printf("It took %f seconds for the array on stack.\n", calc_time(start_time, end_time));

    start_time = clock();
    for(int i=0; i<1000000; i++){
        array_on_heap();
    }
    end_time = clock();
    printf("It took %f seconds for the array on heap.\n", calc_time(start_time, end_time));

}

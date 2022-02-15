#include <stdlib.h>

int main(){

    return 0;
}
//One function should have an integer variable that starts at 0. It should print ping: {value} then increment the value.
// It should write that value to a pipe and read the value back from the other pipe until the value is greater than or equal to 100.
// It should call exit() when complete.
void intPipe(){
    int value =0;
    printf("ping: ", value);
    value++;
    // write value to pipe
    

}
#include <stdio.h>

int main() {
    char input[] = "Encrypt this!"; //array
    int i = 0;
    int n = sizeof(input)/sizeof(char); //provides an endpoint where the code stops encrypting the message
    //char output[n];
    int k = 4; //k is the key value that will decide how many characters the rotation cipher will rotate
    
        for(i = 0; i < n; i++)  {
        
            if((input[i] > 97) && (input[i] < 122)) {
                input[i] = input[i] - 32;
            }
        
        input[i]+=k;
        printf("%c", input[i]);
    }

return 0;

}
#include <stdio.h>

int main() {
    char input[] = "abcdefghijklmnopqrstuvwxyz 123456789"; //array
    int i = 0;
    int n = sizeof(input)/sizeof(char); //provides an endpoint where the code stops encrypting the message
    //char output[n];
    int k = 4; //k is the key value that will decide how many characters the rotation cipher will rotate
    
        for(i = 0; i < n; i++)  {
        
            if((input[i] >= 97) && (input[i] <= 122)) {
                input[i] = input[i] - 32;
            }        
        
            if((input[i] >= 65) && (input[i] <= 90)) {
                input[i] = input[i] - 13; //shifts the value to a mulitple of 26
                input[i] = (input[i] + k) % 26; //does the rotation/encryption of the input to the value of k times
                input[i] = input[i] + 65; //puts the value of the input back to the ascii range of the alphabet  
            }

        printf("%c", input[i]);
    }

return 0;

}
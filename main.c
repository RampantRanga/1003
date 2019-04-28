/*ENGG1003 - programming assignment 1, English text ciphers.
the following code runs 2 encryption and 2 decryption methods, the first encryption method is a rotation encryption and the second uses substitution.
the code can also run a rotation decryption and a substitution decryption but can only be done so using the same key that was used for the encryption.
the following code allows the user to choose between 4 tasks that each implement a function for encryption or decryption of a piece of text.
when the user clicks run, the compiler will display a message and prompt the user to act, it will display four options and assign each one a number.
for he user to select which task they would like to run, they must read the compiler message clearly then press the number on the keyboard that matches
the task they wish to implement and press enter. if task one or two are selected then the next prompt will ask for the text that will be either 
encrypted or decrypted. the user must then type the text into the compiler and press enter. the next message will ask for a key, the user then needs
to type a key value from 1-26 and press enter. the following message will be the result of the function they selected. If the user selects task 3 or 4
the following message will be the same and ask for a piece of text and then it will ask for the key however the key this time  must be implemented as
the alphabet in random order for the substitution. the code will then use that key and implement the encryption or decryption and print the message to
the screen.*/

void task1(char input[1024], int i, int k); //function declerations
void task2(char input[1024], int k, int i);
void task3(char input[1024], char key[26], int i, int m);
void task4(char input[1024], char key[26], int i, int n, char alpha[26]);

#include <stdio.h> //this allows for the use of standard input and output functions
#include <string.h> //this allows for the use of functions for strings

int main() {
    int t; //t is the value used for the switch that decides which task/function the code will run
    char input[1024]; //string with a maximum number of characters set to 250, this can be increased or decreased by changing the number inside the brackets
    char key[26]; //used in task 3 and 4 for the substitution key
    char alpha[26] = "abcdefghijklmnopqrstuvwxyz"; //used in task 4 for decryption
    int i = 0; //i is the position of a character inside a string
    int k;//k is the key value that will decide how many characters the rotation cipher will rotate
    int m = 0; //used in task 3 for substitution equations
    int n = 0; //used in task 4 for substitution decryption
    
    printf("Which task do you want to run?\nRotary Encryption = 1\nRotary Decryption = 2\nSubstitution Encryption = 3\nSubstitution Decryption = 4\n");
    scanf("%d", &t); //scan user input from the compiler and assigns it to t
    
    switch(t) {
        
        case 1: //rotary encryption
            task1(input, i, k); //calling the function
            return 0; //return 0 is included at the end of each case to tell the code to end here otherwise it would then run the following 3 tasks
        case 2: //rotary decryption
            task2(input, k, i);
            return 0;
        case 3: //substitution encryption
            task3(input, key, i, m);
            return 0;
        case 4: //Substitution decryption
            task4(input, key, i, n, alpha);
            return 0;
        default:
        printf("Invalid Operation"); //the default case is included to return a message to the user if they incorrectly select which task they want to execute
    
            return 0;
    }

}


/*task 1 is the rotation encryption, it works by taking the alphabet and shifting the letters along a certain number of times, for example:
abcdefghijklmnopqrstuvwxyz when shifted along 3 times it appears as defghijklmnopqrstuvwxyzabc, when it reaches the end of the alphabet
the cipher loops back around to the beginning hence the name rotation encryption. This encryption is achieved using the following function
and works by firstly converting the letters from lowercase to uppercase when scanned from the compiler using the ascii values and an if
statement, the task then changes the value of the input to a multiple of 26 and adds the key to it. the key is scanned from the user and
determines how many times the alphabet rotates along. The function then takes the modulus of input + k and adds 65 to it to return the ascii
value back to the alphabet and is then printed to the compiler. All this is done inside a for loop that increase the value of i inside input[i]
which shifts the code along the string of characters inputted by the user until it reaches the end of the string according to strlen. The function
also uses an if statement that tells it to only implement the encryption if the input is a capital letter which prevents the code from encryption
numerals, symbols and characters.*/

void task1(char input[1024], int i, int k) { //function body
    
    printf("Running Rotary Encryption\n");
        printf("Please input code for encryption:\n");
        scanf(" %[^\n]s", input); //scanning plain text as a string, the use of " %[^\n]s" scans the string until it reaches a new line character and includes whitespace 
        printf("Please insert the Encryption Key:\n");
        scanf("%d", &k); //scanning value of k from the user interface
            for(i = 0; i < strlen(input); i++)  { //loop increases the value of i each time which shifts it to the next character in the string, the loop will continue until it reaches the end of the string using the function strlen
        
                if((input[i] >= 97) && (input[i] <= 122)) {
                    input[i] = input[i] - 32; //takes values that are lower case and coverts them to uppercase
                }        
        
                if((input[i] >= 65) && (input[i] <= 90)) {
                    input[i] = input[i] - 13; //shifts the value to a multiple of 26
                    input[i] = (input[i] + k) % 26; //takes the value of the input and adds k then takes the remainder when divided by 26
                    input[i] = input[i] + 65; //puts the value of the input back to the ascii range of the alphabet to be printed back to the compiler
                }

                printf("%c", input[i]); //"%c" tells the printf function to print the character value of input[i] to the compiler
            
            }
            
    printf("%c", 10);         

}

/*Task 2 is the rotation decryption, it works the same way as task 1 however it does the opposite and rotates the input back to the original text,
it does this simply by instead of adding k to the input value it subtracts it.*/

void task2(char input[1024], int k, int i) {
    
    printf("Running Rotary Decryption\n");
        printf("Please input code for Decryption:\n");
        scanf(" %[^\n]s", input);
        printf("Please insert the Decryption Key:\n");
        scanf("%d", &k); //scanning value of k
             for(i = 0; i < strlen(input); i++)  { //loop works the same as in task 1
        
                if((input[i] >= 97) && (input[i] <= 122)) {
                    input[i] = input[i] - 32; //lowercase to uppercase
                }        
        
                if((input[i] >= 65) && (input[i] <= 90)) {
                    input[i] = input[i] - 13; //shifts the value to a multiple of 26
                    input[i] = (input[i] - k + 26) % 26; //does the same as in the encryption however the key value is subtracted to revert the letters back to their original values
                    input[i] = input[i] + 65; //puts the value of the input back to the ascii range of the alphabet  
                }

                printf("%c", input[i]);
            
            }

    printf("%c", 10);

}

/*task 3 is the Substitution Encryption, the substitution method takes letters and randomly assigns them new letters, for example:
abcdefghijklmnopqrstuvwxyz is randomly assigned as qwertyuiopasdfghjklzxcvbnm which unless you have the key can be very difficult to solve.
the following function firstly scans a piece of code from the user to be encrypted then allows the user to input their own random order of
letters and is scanned as a string, the code then makes all letters uppercase and implements the encryption. The encryption works by taking 
the input and subtracts a value of 65 from it, this brings it down the ascii scale to a range of 0 to 25. the code then makes the input letter
equal to the letter in the key that is in the m'th position that was inputted by the user. this is all run inside a for loop the same as in task 1.*/

void task3(char input[1024], char key[26], int i, int m) {
    
    printf("Running Substitution Encryption\n");
        printf("Please input code for Encryption:\n");
        scanf(" %[^\n]s", input); //scans plain text for encryption
        printf("Please input Substitution Key:\n");
        scanf("%s", key); //scans Substitution encryption cipher from the user
            
            for(i = 0; i < strlen(input); i++)  { //loop works the same as seen in task 1 and 2
                
                if((input[i] >= 97) && (input[i] <= 122)) {
                    input[i] = input[i] - 32; //lowercase to uppercase
                }
                
                if((input[i] >= 65) && (input[i] <= 90)) {
                m = input[i]; //assigns input[i] to m for following equations
                m = m - 65; //brings m to a value in between 0 to 25
                input[i] = key[m]; //assigns the key[m] value back to input[i] for printing
                
                }
                
                if((input[i] >= 97) && (input[i] <= 122)) {
                input[i] = input[i] - 32; //lowercase to uppercase
                }
                
                printf("%c", input[i]);
                    
            }

    printf("%c", 10);

}

/*task 4 is the Substitution Decryption, this does the reverse of task 3. firstly it scans both the cipher text and key from the user, after
converting the letters to all uppercase the code then runs a second for loop inside the original one, this time using n as the argument.
the code then makes the values of the key all uppercase and runs an if statement that states when the input value is equal to the key at n, 
then the input is assigned the letter in the alphabet that sits at the n'th position. the output is then converted back to uppercase and printed
to the compiler.*/

void task4(char input[1024], char key[26], int i, int n, char alpha[26]) {
    
    printf("Running Substitution Decryption\n");
        printf("Please input code for Decryption:\n");
        scanf(" %[^\n]s", input); //scanning the input as a string
        printf("Please input Substitution Key:\n");
        scanf("%s", key); //scanning key from user for decryption
            for(i = 0; i < strlen(input); i++)  { //loop runs the same as in tasks 1, 2 and 3
                
            if((input[i] >= 97) && (input[i] <= 122)) {
                input[i] = input[i] - 32; //lowercase to uppercase
            }
                
            if((input[i] >= 65) && (input[i] <= 90)) {
                for(n=0; n < 26; n++) { //loops through each character inputted by the user
                        
                        if((key[n] >= 97) && (key[n] <= 122)) {
                            key[n] = key[n] - 32; //lowercase to uppercase for the key when typed by the user
                        }
                
                        if(input[i] == key[n]) { //when the input character is equal to the key character the if then changes the input[i] value to the correct letter in the alphabet
                            input[i] = alpha[n]; //alpha[n] is the alphabet which is initialised at the top of the code
                        }
                        
                }
                
                if((input[i] >= 97) && (input[i] <= 122)) { 
                    input[i] = input[i] - 32; //lowercase to uppercase
                }
            }    
                
            printf("%c", input[i]);
        }    

    printf("%c", 10);

}

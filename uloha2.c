#include <stdio.h>
#include <string.h>


int main(void){
    // 17, because of the newline character('\n') that is added automatically with the function fgets() (if the length of user's input is atleast 2 less than max array size), and the null terminator('\0')
    const int MAX_TEXT_LENGTH = 17; 

    char text[MAX_TEXT_LENGTH];
    char reversed_text[MAX_TEXT_LENGTH];
    int text_size;

    printf("Arbitrary text: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    // if the user inputs 16 charcters, the last one (17th one) will be a null terminator, therfore the newline character will not be added to the array, due to the lack of space
    // if there isn't a newline character before the null terminator, the program will stop and return an error.
    if(text[strlen(text) - 1] != '\n'){   
        fprintf(stderr, "ERROR: Max text length exceeded!\n");
        return 1;
    }

    else if(strlen(text) == 1){ // 1, because there will always be a newline character due to the fgets() function
        fprintf(stderr, "ERROR: No text inserted!\n");
        return 1;
    }
    text[strlen(text) - 1] = '\0';  // replacing new line character with null terminator (basically just moving null terminator one index to the left/lower)
    text_size = strlen(text);

    for(int index = text_size - 1; index >= 0; index--){  // reversing the text and storing the reversed text into a new array
        reversed_text[text_size - index - 1] = text[index];
    }
    reversed_text[text_size] = '\0'; // adds a null terminator to the end of the array to prevent unexpected behaviour if the length of the array is smaller than the maximum array length
    for(int position = 0; position < text_size; position++){  // comparison of the two texts
        if(text[position] != reversed_text[position]){
            printf("Your text is not a palindrome, first difference is on the %d. index/%d. character.\n", position, position + 1);
            printf("'%c' isn't equal to '%c'\n", text[position], reversed_text[position]);
            break;
        }
        else if(position == text_size - 1){
            printf("Your text is a palindrome!\n");
        }
    }
    printf("%s\n%s\n", text, reversed_text);
    return 0;
}
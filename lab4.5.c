    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

    int noNumbers(char str[], int len){
        for (int i = 0; i < len; i++){
            if (isdigit(str[i])){
                return 0;
            }
        }
        return 1;
    }

    char mostCommonCharacter(char str[]) {
        int count[256] = {0}; // Array to store the frequency of each character
        int max_count = 0;     // Variable to store the highest frequency
        char most_common = '\0'; // Variable to store the most common character

        // Count each character's frequency
        for (int i = 0; str[i] != '\0'; i++) {
            count[(int)str[i]]++; // Increment frequency of the character
            // Update most_common if the current character's frequency is the highest
            if (count[(int)str[i]] > max_count) {
                max_count = count[(int)str[i]];
                most_common = str[i];
            }
        }

        return most_common;
    }

    int main(){
        char str[100];
        printf("Enter the input string (no digits allowed)\n");
        scanf("%s", str);
        int len = strlen(str);
        
        if (noNumbers(str, len)){
            printf("The string does not contain numbers\n");
            printf("The string is %d characters long\n", len);
            printf("The first character is '%c'\n", str[0]);
            printf("The most common character is '%c'\n", mostCommonCharacter(str));
        }
        else{
            printf("The string contains digits and thus does not pass the criteria");
        }
    }
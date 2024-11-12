#include <stdio.h>

#define MAX_NUMBERS 20
#define MIN_VALUE 1
#define MAX_VALUE 100

double mean(int numbers[MAX_NUMBERS], int count){
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += numbers[i];
    }
    return (double)total / count;
}

double median(int numbers[MAX_NUMBERS], int count){
    if (count % 2 == 0) {
        return (numbers[count / 2 - 1] + numbers[count / 2]) / 2.0  ;
    } else {
        return numbers[count / 2];
    }
}

int mode(int numbers[MAX_NUMBERS], int count) {
    int frequency[MAX_VALUE + 1] = {0};
    int maxFrequency = 0;
    int modeValue = -1;

    for (int i = 0; i < count; i++) {
        frequency[numbers[i]]++;
    }

    for (int i = MIN_VALUE; i <= MAX_VALUE; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            modeValue = i;
        }
    }

    return (maxFrequency > 1) ? modeValue : -1;
}

int range(int numbers[MAX_NUMBERS], int count){
    return numbers[count - 1] - numbers[0];
}

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;

    printf("Enter up to 20 numbers between 1 and 100 in ascending order (enter -1 to stop):\n");

    while (count < MAX_NUMBERS) {
        int num;
        printf("Enter number %d: ", count + 1);
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (num < MIN_VALUE || num > MAX_VALUE) {
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }

        if (count > 0 && num < numbers[count - 1]) {
            printf("Please enter a number in ascending order.\n");
            continue;
        }

        numbers[count++] = num;
    }

    printf("\nYou entered %d numbers:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%3d ", numbers[i]);
    }
    printf("\n");
    printf("The mean of the sequence is %.2f\n", mean(numbers, count));
    printf("The median of the sequence is %.2f\n", median(numbers, count));
    printf("The mode of the sequence is %d\n", mode(numbers, count));
    printf("The range of the sequence is %d\n", range(numbers, count));
    
    return 0;
}
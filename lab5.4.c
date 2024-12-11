int sum(int *start, int *end) {
    int total = 0;
    while (start < end) {
        total += *start++; /* add value to total              */    }
    return total;
}

void main(){
    int arr[] = {5,4,3,7,8,4,8};
    printf("The total is %d", sum(arr, arr+7));
}
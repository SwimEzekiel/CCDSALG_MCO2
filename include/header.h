typedef char string[257];

typedef struct { //Value inside of the node itself.
    int i;       //Allows for multiple data types as to not overcomplicate other functions
    char c;
    char s[3];
} Value;

typedef struct {
    int *intArr;
    char *charArr;
} HeapArray;

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *data;
    int len;
    int cap;
} MaE;

/*
    Error
*/
void
init(MaE *arr, int cap) {
    arr->len = 0;
    arr->cap = cap;

    arr->data = malloc(arr->cap * sizeof(int));
}

/*
 Error
*/
void
add(MaE *arr, int val) {
    if (arr->len >= arr->cap) {
        arr->cap = arr->cap << 1;
        
        printf("LEN %d, CAP: %d \n", arr->len, arr->cap);
        
        int *r = realloc(arr->data, arr->cap * sizeof(int));
        if (!r) {
            fprintf(stderr, "Memory realloc failed\n");
            exit(1);
        }
        
        arr->data = r;
    }

    arr->data[arr->len++] = val;
}

int
get_index(MaE *arr, int s_value) {
    int index = -1;
    
    for(int i = 0; i <= arr->len; i++) {
        if (arr->data[i] == s_value) {
            index = i;
            break;
        }
    }
    
    return index;
}

/*
    Add free, delete, insert
*/
int
main() {
    MaE arr;

    init(&arr, 2);

    // For TEST NOT SORT
    for (int i = 1; i <= 30; i++) {
        add(&arr, i);
    }
    
    int index_v = get_index(&arr, 6);
    
    printf("INDEX %d", index_v);
}
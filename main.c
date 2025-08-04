#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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
    if (!arr->data) {
        fprintf(stderr, "Memory malloc failed\n");
        exit(1);
    }
}

/*
 Error
*/
void
add(MaE *arr, int val) {
    if (arr->len >= arr->cap) {
        arr->cap = arr->cap << 1;
                
        int *r = realloc(arr->data, arr->cap * sizeof(int));
        if (!r) {
            fprintf(stderr, "memory realloc failed\n");
            exit(1);
        }
        
        arr->data = r;
    }

    arr->data[arr->len++] = val;
}

int
get_index(MaE *arr, int s_value) {
   for(int i = 0; i < arr->len; i++) {
        if (arr->data[i] == s_value) {
            return i;
        }
    }
    
    return -1;
}

void
delete_value(MaE *arr, int d_value) {
    int index = get_index(arr, d_value);
    
    if (index > -1) {
        for (int i = (index + 1); i < arr->len; i++) {
            arr->data[i - 1] = arr->data[i];
        }

        arr->len = arr->len - 1;
    }
}

/*
 Add CAP >
 Add ele last
 */
void 
insert_by_index(MaE *arr, int i_value, int index) {
    assert(index >= 0);
    
    for (int i = (arr->len - 1); i >= index; i--) {
        arr->data[i + 1] = arr->data[i];
    }

    arr->len = arr->len + 1;
    arr->data[index] = i_value;
}

/*
    Add free
*/
int
main() {
    MaE arr;

    init(&arr, 10);

    // For TEST NOT SORT
    for (int i = 1; i <= 5; i++) {
        add(&arr, i);
    }
    
    int index_v = get_index(&arr, 6);
    
    insert_by_index(&arr, 6, -1);
    delete_value(&arr, 1);
}
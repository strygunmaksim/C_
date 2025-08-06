#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
    int *data;
    int len;
    int cap;
} MaE;

void
expansion_cap(MaE *arr) {
    arr->cap << 1;

    int *r = realloc(arr, arr->cap * sizeof(int));

    if (!r) {
        fprintf(stderr, "Memory malloc failed\n");
        exit(1);
    }

    arr->data = r;
}

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
        expansion_cap(arr);
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

void 
insert_by_index(MaE *arr, int i_value, int index) {
    assert(index >= 0);
    
    if (arr->len >= arr->cap) {
        expansion_cap(arr);
    }

    if (index <= (arr->len - 1)) {
        for (int i = (arr->len - 1); i >= index; i--) {
            arr->data[i + 1] = arr->data[i];
        }

        arr->len = arr->len + 1;
        arr->data[index] = i_value;
    } else {
        arr->len = arr->len + 1;
        arr->data[arr->len - 1] = i_value;
    }
}


/**/
void 
print_MaE(MaE *arr, char *pos) {
    printf("%s\n", pos);

    printf("LENGTH: %d \n", arr->len);

    for (int i = 0; i < arr->len; i++) {
        printf("EL: %d ", arr->data[i]);
    }
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
}
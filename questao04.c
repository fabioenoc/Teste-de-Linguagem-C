#include <stdio.h>
#include <stdlib.h>

int *merge_lists(int **listas, int k) {
    int *merged_list = (int*) malloc(k * sizeof(int));
    int *pointers = (int*) calloc(k, sizeof(int));
    int i, smallest_val, smallest_idx;

    for (i = 0; i < k; i++) {
        pointers[i] = 0;
    }

    i = 0;

    while (1) {
        smallest_val = __INT_MAX__;
        smallest_idx = -1;

        for (i = 0; i < k; i++) {
            if (pointers[i] < sizeof(listas[i])/sizeof(int) && listas[i][pointers[i]] < smallest_val) {
                smallest_val = listas[i][pointers[i]];
                smallest_idx = i;
            }
        }

        if (smallest_idx == -1) {
            break;
        }

        merged_list[i] = smallest_val;
        pointers[smallest_idx]++;
    }

    return merged_list;
}

int main() {
    int k = 3;
    int *listas[3] = { (int[]) {1, 3, 8}, (int[]) {1, 3, 6}, (int[]) {8, 9} };
    int *merged_list = merge_lists(listas, k);
    int i;

    for (i = 0; i < sizeof(merged_list)/sizeof(int); i++) {
        printf("%d ", merged_list[i]);
    }

    free(merged_list);

    return 0;
}

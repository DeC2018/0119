#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int* result = (int*)malloc((rowIndex + 1) * sizeof(int));
    result[0] = 1;
    if (rowIndex == 0) {
        *returnSize = 1;
        return result;
    }
    
    result[1] = 1;
    for (int i = 1; i < rowIndex; i++) {
        int* row = (int*)malloc((i + 2) * sizeof(int));
        row[0] = 1;
        for (int j = 0; j < i; j++) {
            row[j + 1] = result[j] + result[j + 1];
        }
        row[i + 1] = 1;
        free(result);
        result = row;
    }
    
    *returnSize = rowIndex + 1;
    return result;
}

// Helper function to print a row of Pascal's triangle
void printRow(int* row, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", row[i]);
        if (i + 1 < size) printf(",");
    }
    printf("]\n");
}

int main() {
    int returnSize;

    int rowIndex1 = 3;
    printf("Input: rowIndex = %d\n", rowIndex1);
    int* row1 = getRow(rowIndex1, &returnSize);
    printf("Output: ");
    printRow(row1, returnSize);
    free(row1);

    int rowIndex2 = 0;
    printf("Input: rowIndex = %d\n", rowIndex2);
    int* row2 = getRow(rowIndex2, &returnSize);
    printf("Output: ");
    printRow(row2, returnSize);
    free(row2);

    int rowIndex3 = 1;
    printf("Input: rowIndex = %d\n", rowIndex3);
    int* row3 = getRow(rowIndex3, &returnSize);
    printf("Output: ");
    printRow(row3, returnSize);
    free(row3);

    return 0;
}

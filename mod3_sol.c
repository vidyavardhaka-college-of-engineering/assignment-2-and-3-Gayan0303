#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 11


int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % TABLE_SIZE;
    return x;
}

void insert(int hashTable[], int key) {
    int homeSlot = h1(key);
    int currentSlot = homeSlot;
    while (hashTable[currentSlot] != -1) {
        currentSlot = (currentSlot + 1) % TABLE_SIZE;
    }
    hashTable[currentSlot] = key;
}


void printHashTable(int hashTable[]) {
    printf("Final Hash Table:\n");
    printf("Slot: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Contents: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", hashTable[i]);
        }
    }
    printf("\n");
}

int main() {
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; 
    }

    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        insert(hashTable, keys[i]);
    }

    printHashTable(hashTable);

    return 0;
}

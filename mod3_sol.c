#include <stdio.h>
#include <stdlib.h>
#define M 11 

int h1(int key) 
{
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % M;
    return x;
}
void linear_probing(int *hash_table, int key)
{
    int index = h1(key);
    int original_index = index;
    while (hash_table[index] != -1) 
    {
        index = (index + 1) % M;
        if (index == original_index) 
        {
            printf("Hash table is full\n");
            return;
        }
    }
    hash_table[index] = key;
}

void print_table(int *hash_table) 
{
    printf("Slot:");
    for (int i = 0; i < M; i++) 
    {
        printf(" %d", i);
    }
    printf("\nContents:");
    for (int i = 0; i < M; i++) 
    {
        if (hash_table[i] != -1)
            printf(" %d", hash_table[i]);
        else
            printf(" -");
    }
    printf("\n");
}
int main() 
{
    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    int hash_table[M];
    for (int i = 0; i < M; i++) 
    {
        hash_table[i] = -1;
    }
    
    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
    {
        linear_probing(hash_table, keys[i]);
    }
    print_table(hash_table);
    return 0;
}

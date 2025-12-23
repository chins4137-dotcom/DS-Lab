#include <stdio.h>
#define MAX 100
int hashTable[MAX];
int m;
int hashFunction(int key){
    return key % m;}
void insert(int key){
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != -1)
    {
        index = (index + 1) % m;

        if (index == startIndex)
        {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }

    hashTable[index] = key;}
void display(){
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] == -1)
            printf("Address %d : Empty\n", i);
        else
            printf("Address %d : %d\n", i, hashTable[i]);
    }}
int main()
{
    int n, key;
    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
    printf("Enter number of employee records: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter 4-digit employee key: ");
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}

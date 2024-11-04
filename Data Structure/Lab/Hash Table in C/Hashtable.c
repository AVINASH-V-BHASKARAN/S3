#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
struct DataItem {
    int data;   
    int key;
};
struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
int hashCode(int key)
{
    return key % SIZE;
}
struct DataItem *search(int key) { 
    int hashIndex = hashCode(key);  
    while(hashArray[hashIndex] != NULL) {	
        if(hashArray[hashIndex]->key == key)
            return hashArray[hashIndex]; 
        ++hashIndex;
        hashIndex %= SIZE;
    }        	
    return NULL;        
}

void insert(int key, int data) {
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;  
    item->key = key;
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        ++hashIndex;
        hashIndex %= SIZE;
    }	
    hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
    int key = item->key;
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL) {	
        if(hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex]; 
            hashArray[hashIndex] = dummyItem; 
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }      
    return NULL;        
}

void display() {
    for(int i = 0; i < SIZE; i++) {	
        if(hashArray[i] != NULL)
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
        else
            printf(" ~~ ");
    }	
    printf("\n");
}

int main() {
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem->data = -1;  
    dummyItem->key = -1; 
    int choice, key, data;
    while (1) {
        printf("\n1. Insert a key-value pair\n2. Search for a key\n3. Display hash table\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &data);
                insert(key, data);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                struct DataItem* item = search(key);
                if(item != NULL) {
                    printf("Element found: Key = %d, Value = %d\n", item->key, item->data);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 3:
                printf("Current state of hash table:\n");
                display();
                break;
            case 4:
                free(dummyItem);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}


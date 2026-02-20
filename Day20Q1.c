#include <stdio.h>
#include <stdlib.h>

struct Node {
    long long key;
    int count;
    struct Node *next;
};

#define HASH_SIZE 10007

struct Node* hash_table[HASH_SIZE];

int get_hash(long long key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}

void insert(long long key) {
    int h = get_hash(key);
    struct Node* temp = hash_table[h];
    while (temp) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = key;
    new_node->count = 1;
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

int get_count(long long key) {
    int h = get_hash(key);
    struct Node* temp = hash_table[h];
    while (temp) {
        if (temp->key == key) return temp->count;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long current_sum = 0;
    long long total_subarrays = 0;

    insert(0);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        current_sum += val;

        total_subarrays += get_count(current_sum);
        insert(current_sum);
    }

    printf("%lld\n", total_subarrays);

    return 0;
}

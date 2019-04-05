#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  /* printf("weights %d, length: %d limit: %d\n", weights, length, limit); */
  HashTable *ht = create_hash_table(16);
  /* printf("hash table data: %d\n", ht->storage[7]); */
  for(int i = 0; i < length ; i ++) {
    unsigned int index = hash(weights[i], length);
    if(ht->storage[index] == '\0') {
      LinkedPair *new_pair = create_pair(weights[i], i);
      /* printf("found a zero\n"); */
      ht->storage[index] = new_pair;
      /* printf("key: %d value: %d", ht->storage[index]->key, ht->storage[index]->value); */
    } else {
      int diff = limit - weights[i];
      /* printf("diff %d\n", diff); */
      printf("the value at diff %d\n", ht->storage[diff]->value);
      /* printf("have to check to see if threere's a LL \n"); */



    }
    /* printf("index: %d\n", index); */
    /* printf("hash table data: %d\n", ht->storage[index]); */
  }
  // YOUR CODE HER\nE

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif

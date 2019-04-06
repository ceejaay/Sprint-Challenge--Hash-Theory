#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{

  HashTable *ht = create_hash_table(16);
  for(int i = 0; i< length; i ++ ) {
    if(ht->storage[i] == '\0') {
      hash_table_insert(ht, weights[i], i);
    }

    }

    /* printf("results of 4 => %d            ", hash_table_retrieve(ht, 4)); */

    for(int i = 0; i<length; i++) {
      int difference = limit - weights[i];
      printf("diff: %d         ", difference);
      printf("index value: %d         ", weights[i] );
      printf("index: %d         ", i );
      int result = hash_table_retrieve(ht, difference);
      printf("result: %d\n", result);
      /* printf("hash from result: %d\n", hash_table_retrieve(ht, result)); */
      if(result > -1) {
        Answer * ans = malloc(sizeof(Answer));
        ans->index_1 = result;
        ans->index_2 = i;
      return ans;
      }
        /* printf("not the one: %d\n", result); */

      /* printf("index: %d, diff: %d\n", hash_table_retrieve(ht, difference), difference); */
    }

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
  /* int weights_1 = {9}; */
  /* Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9); */
  /* print_answer(answer_1);  // NULL */

  /* /1* // TEST 2 *1/ */
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  int weights_22[] = {5, 5};
  Answer* answer_22 = get_indices_of_item_weights(weights_22, 2, 10);
  print_answer(answer_22);  // {1, 0}
  /* // TEST 3 */
  /* int weights_3[] = {4, 6, 10, 15, 16}; */
  /* Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21); */
  /* print_answer(answer_3);  // {3, 1} */

  /* // TEST 4 */
  /* int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40}; */
  /* Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7); */
  /* print_answer(answer_4);  // {6, 2} */

  return 0;
}
#endif

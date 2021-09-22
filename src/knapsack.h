#ifndef __KNAPSACK__
#define __KNAPSACK__


#include "item.h"


typedef struct knapsack_t {
    float max_cap;
    float weight;
    float value;
    item_list_t* item_list;
} knapsack_t;


knapsack_t* new_knapsack();
void store_item(item_t*, knapsack_t*);
int check_add_item(item_t*, knapsack_t*);

void print_knapsack(knapsack_t*);


/* ___SOLVERS___ */
void greedy(knapsack_t*, item_list_t*);
void partially_greed(knapsack_t*, item_list_t*);
void viable_random(knapsack_t*, item_list_t*);
void random_without_check(knapsack_t*, item_list_t*);


#endif

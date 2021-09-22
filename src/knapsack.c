#include "knapsack.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define TRUE 1
#define FALSE 0
#define PERCENTAGE 80/100.0


/* ___KNAPSACK___ */
knapsack_t* new_knapsack(){

	knapsack_t* knapsack;
	knapsack = (knapsack_t*) malloc(sizeof(knapsack_t));

	knapsack->max_cap = 0;
	knapsack->weight = 0;
	knapsack->value = 0;
	knapsack->item_list = new_item_list();

	return knapsack;
}

void print_knapsack(knapsack_t* knapsack){

	printf("\n%s\n%s\n%s\n%s\n",
		"/------------------------------\\",
		"|-------- STORED ITEMS --------|",
		"\\------------------------------/",
		"|ID\t|Weight\t|Value\t|Profit");
	print_list(knapsack->item_list);
	printf("\n");
	printf("%s%.2f\n", "Knapsack weight: ", knapsack->weight);
	printf("%s%.2f\n", "Knapsack value: ", knapsack->value);
	printf("%s\n", 
		knapsack->weight <= knapsack->max_cap ?
		"VIABLE SOLUTION!!" :
		"NON-VIABLE SOLUTION!!");
	printf("\n");
}

int check_add_item(item_t* item, knapsack_t* knapsack){

	return ((item->weight + knapsack->weight) <= knapsack->max_cap) ? TRUE : FALSE; 
}

void store_item(item_t* item, knapsack_t* knapsack){
	add_item(item, knapsack->item_list);
	knapsack->weight += item->weight;
	knapsack->value += item->value;
}


/* ___SOLVERS___ */
void greedy(knapsack_t* knapsack, item_list_t* item_list){

	sort_list(item_list);

	while (knapsack->weight < knapsack->max_cap && item_list->size > 0){

		item_t* item = get_by_index(0, item_list);

		if (check_add_item(item, knapsack))
			store_item(item, knapsack);
	}
}

void partially_greed(knapsack_t* knapsack, item_list_t* item_list){

	srand(time(NULL));
	int percentage = (int) item_list->size * PERCENTAGE;
	sort_list(item_list);

	while (knapsack->weight < knapsack->max_cap && item_list->size > 0){
	
		if (percentage > item_list->size)
			percentage = item_list->size;

		int pick = rand() % (percentage);

		item_t* item = get_by_index(pick, item_list);

		if (check_add_item(item, knapsack))
			store_item(item, knapsack);
	}
}

void viable_random(knapsack_t* knapsack, item_list_t* item_list){

	srand(time(NULL));

	while (knapsack->weight < knapsack->max_cap && item_list->size > 0){

		int pick = rand() % item_list->size;

		item_t* item = get_by_index(pick, item_list);

		if (check_add_item(item, knapsack))
			store_item(item, knapsack);
	}
}

void random_without_check(knapsack_t* knapsack, item_list_t* item_list){

	srand(time(NULL));

	while (knapsack->weight < knapsack->max_cap && item_list->size > 0){

		int pick = rand() % item_list->size;

		item_t* item = get_by_index(pick, item_list);

		store_item(item, knapsack);
	}
}

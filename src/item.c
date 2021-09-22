#include "item.h"
#include <stdlib.h>
#include <stdio.h>


/* ___ITEM___ */
item_t* new_item(float weight, float value){

	item_t* item;
	item = (item_t*) malloc(sizeof(item_t));

	item->weight = weight;
	item->value = value;
	item->profit = value/weight;

	return item;
}


/* ___LIST___ */
item_list_t* new_item_list(){

	item_list_t* item_list;
	item_list = (item_list_t*) malloc(sizeof(item_list_t));

	item_list->size = 0;
	item_list->list = NULL;

	return item_list;
}

void print_list(item_list_t* item_list){

	for (int i = 0; i < item_list->size; i++)
		printf("%i\t%.2f\t%.2f\t%.2f\n", 
			i, item_list->list[i].weight, item_list->list[i].value, item_list->list[i].profit);
}

void add_item(item_t* item, item_list_t* item_list){

	int len = item_list->size;

	item_t* list = (item_t*) malloc((len+1) * sizeof(item_t));

	for (int i = 0; i < len; i++)
		list[i] = item_list->list[i];

	list[len] = *item;

	item_t* aux_list = item_list->list;

	item_list->list = list;
	item_list->size++;

	free(aux_list);
}

item_t* get_by_index(int index, item_list_t* item_list){

	item_t item_aux = item_list->list[index];
	item_t* item = new_item(item_aux.weight, item_aux.value);
	remove_item(index, item_list);

	return item;
}

void remove_item(int index, item_list_t* item_list){

	int len = item_list->size;

	item_t* list = (item_t*) malloc((len-1) * sizeof(item_t));

	for (int i = 0; i < index; i++)
		list[i] = item_list->list[i];
	for (int i = index; i < (len - 1); i++)
		list[i] = item_list->list[i+1];

	item_t* aux_list = item_list->list;

	item_list->list = list;
	item_list->size--;

	free(aux_list);
}

int compare(const void* a, const void* b){	// compare funct for qsort

	item_t* item_a = (item_t*) a;
	item_t* item_b = (item_t*) b;

	if (item_a->profit < item_b->profit)
		return 1;
	if (item_a->profit > item_b->profit)
		return -1;
	return 0;
}

void sort_list(item_list_t* item_list){
	
	qsort(item_list->list, item_list->size, sizeof(item_t), compare);
}

#ifndef __ITEM__
#define __ITEM__


typedef struct item_t {
	float weight;
	float value;
	float profit;
} item_t;

typedef struct item_list_t {
	item_t* list;
	int size;
} item_list_t;


/* ___ITEM___ */
item_t* new_item(float, float);


/* ___LIST___ */
item_list_t* new_item_list();
void print_list(item_list_t*);
void add_item(item_t*, item_list_t*);
item_t* get_by_index(int, item_list_t*);
void remove_item(int, item_list_t*);
void sort_list(item_list_t*);


#endif

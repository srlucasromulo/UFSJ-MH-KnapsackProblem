#include "knapsack.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define UPPER(c) (c = toupper(c))

#define FILES_FOLDER "./files/"
#define EXAMPLE_FILE "example.txt"
#define GREEDY_FLAG "-G"
#define PARTIALLY_FLAG "-P"
#define VIABLE_RAN_FLAG "-V"
#define RANDOM_FLAG "-R"


void load_file(FILE*, knapsack_t*, item_list_t*);


int main (int argc, char* argv[]) {

	if (argc > 3 || argc < 2) {
		printf("%s\n", "INVALID NUMBER OF ARGUMENTS!!");
		exit(1);
	}

	char* filename;
	filename = (char*) malloc(50 * sizeof(char));
	strcpy(filename, FILES_FOLDER);

	if (argc == 2)
		strcat(filename, EXAMPLE_FILE);
	else
		strcat(filename, argv[2]);

	FILE* file = fopen(filename, "r");
	if (!file) {
		printf("%s\n", "FILE NOT FOUND!!");
		exit(1);
	}

	knapsack_t* knapsack = new_knapsack();
	item_list_t* item_list = new_item_list();

	load_file(file, knapsack, item_list);

	UPPER(argv[1][1]);

	if ( !strcmp(argv[1], GREEDY_FLAG) )
		greedy(knapsack, item_list);
	else if ( !strcmp(argv[1], PARTIALLY_FLAG) )
		partially_greed(knapsack, item_list);	
	else if ( !strcmp(argv[1], VIABLE_RAN_FLAG) )
		viable_random(knapsack, item_list);
	else if ( !strcmp(argv[1], RANDOM_FLAG) )
		random_without_check(knapsack, item_list);
	else {
		printf("%s\n", "INVALID FLAG!!");
		exit(1);
	}

	print_knapsack(knapsack);

	fclose(file);
}


void load_file(FILE* file, knapsack_t* knapsack, item_list_t* item_list){

	int max_cap, list_size;

	fscanf(file, "%i %i\n", &max_cap, &list_size);

	knapsack->max_cap = max_cap;

	for (int i = 0; i < list_size; i++) {
		float weight, value;
		fscanf(file, "%f %f\n", &weight, &value);

		item_t* item = new_item(weight, value);
		add_item(item, item_list);
	}
}

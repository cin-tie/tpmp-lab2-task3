#include <stdio.h>
#include <string.h>
#include "../include/marshrut.h"

// Initialization of marshruts array
void init_marshruts(MARSHRUT marshruts[], int *count){
	(void)marshruts;
	*count = 0;
}

// Add a new marshrut to the array
int add_marshrut(MARSHRUT marshruts[], int *count, MARSHRUT new_marshrut){
	if(*count >= MAX_MARSHRUTS){
		return 0; // Array is full
	}

	marshruts[*count] = new_marshrut;
	(*count)++;
	return 1; // Success
}

// Finding minimum length marshrut
MARSHRUT* find_min_length_marshrut(MARSHRUT marshruts[], int count){
	if(count <= 0){
		return NULL; // No marshruts in array
	}

	MARSHRUT *min = &marshruts[0];
	
	for(int i = 1; i < count; ++i){
		if(marshruts[i].length < min->length){
			min = &marshruts[i];
		}
	}
	
	return min; // Finded marshrut
}

// Sort marshruts array by length
void sort_by_length(MARSHRUT marshruts[], int count){
	for(int i = 0; i < count - 1; ++i){
		for(int j = 0; j < count - i - 1; ++j){
			if(marshruts[i].length > marshruts[j].length){
				// Swap marshruts
				MARSHRUT temp = marshruts[j];
				marshruts[j] = marshruts[j + 1];
				marshruts[j + 1] = temp;
			}
		}	
	}
}

// Find marshruts by start/end point
void find_by_point(MARSHRUT marshruts[], int count, const char *point, 
                   MARSHRUT results[], int *result_count){
	*result_count = 0;

	for(int i = 0; i < count; ++i){
		if(strcmp(marshruts[i].start, point) == 0 || 
			strcmp(marshruts[i].end, point) == 0){
			results[*result_count] = marshruts[i];
			(*result_count)++;
		}
	}

	// Results in the results array
}

// Input a marshrut from keyboard
void input_marshrut(MARSHRUT *m){
	printf("Enter marshrut number: ");
	scanf("%d", &m->number);
	
	printf("Enter start point: ");
	scanf("%s", m->start);

	printf("Enter end point: ");
	scanf("%s", m->end);

	printf("Enter length: ");
	scanf("%f", &m->length);
}

// Print a single marshrut
void print_marshrut(const MARSHRUT *m){
	printf("%-5d | %-20s | %-20s | %-8.2f\n", 
		m->number, m->start, m->end, m->length);
}

// Print all marshruts
void print_all_marshruts(const MARSHRUT marshruts[], int count){
	if(count == 0){
		printf("No marshruts to display");
		return;
	}

	printf("\n%-5s | %-20s | %-20s | %-8s\n", 
		"Num", "Start", "End", "Length");
	printf("------+----------------------+----------------------+----------\n");
	for (int i = 0; i < count; i++) {
		print_marshrut(&marshruts[i]);
	}
	printf("\n");
}

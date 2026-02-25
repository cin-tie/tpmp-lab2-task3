#ifndef MARSHRUT_H
#define MARSHRUT_H

#define MAX_MARSHRUTS 10
#define MAX_NAME_LEN 50

// Marshrut structure
typedef struct {
	int number;			// Number of marshrut
	char start[MAX_NAME_LEN];	// Start of marshrut
	char end[MAX_NAME_LEN];		// End of marshrut
	float length;			// Length of marshrut
} MARSHRUT;

// Functions of server
void init_marshruts(MARSHRUT marshruts[], int *count);
int add_marshrut(MARSHRUT marshruts[], int *count, MARSHRUT new_marshrut);
MARSHRUT* find_min_length_marshrut(MARSHRUT marshruts[], int count);
void sort_by_length(MARSHRUT marshruts[], int count);
void find_by_point(MARSHRUT marshruts[], int count, const char *point, 
                   MARSHRUT results[], int *result_count);

// Functions of client
void input_marshrut(MARSHRUT *m);
void print_marshrut(const MARSHRUT *m);
void print_all_marshruts(const MARSHRUT marshruts[], int count);

#endif

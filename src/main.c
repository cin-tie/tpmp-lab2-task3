#include <stdio.h>
#include <../include/marshrut.h>

void display_menu(void){
	printf("\n=== MARSHROUT MANAGEMENT SYSTEM ===\n");
	printf("1. Add new marshrut\n");
	printf("2. Find marshrut with minimum length\n");
	printf("3. Sort marshruts by length\n");
	printf("4. Find marshruts by point\n");
	printf("5. Display all marshruts\n");
	printf("0. Exit\n");
	printf("Choice: ");
}

int main(void){
	MARSHRUT marshruts[MAX_MARSHRUTS];
	int count = 0;
	int choice;

	init_marshruts(marshruts, &count);

	do{
		display_menu();
		scanf("%d", &choice);
		
		switch (choice){
			case 1: {
				if (count >= MAX_MARSHRUTS) {
					printf("Cannot add more marshruts. Maximum %d reached.\n", MAX_MARSHRUTS);
					 break;
				}
                
               	 		MARSHRUT new_marshrut;
                		input_marshrut(&new_marshrut);
                
                		if (add_marshrut(marshruts, &count, new_marshrut)) {
                    			printf("Marshrut added successfully.\n");
                		} else {
                    			printf("Failed to add marshrut.\n");
                		}
                		break;
            		}
            
            		case 2: {
                		MARSHRUT *min = find_min_length_marshrut(marshruts, count);
                		if (min) {
                    			printf("\nMarshrut with minimum length:\n");
                    			printf("%-5s | %-20s | %-20s | %-8s\n", 
                           		"Num", "Start", "End", "Length");
                    			printf("------+----------------------+----------------------+----------\n");
                    			print_marshrut(min);
                		} else {
                   	 		printf("No marshruts available.\n");
                		}
                		break;
            		}
            
            		case 3: {
                		sort_by_length(marshruts, count);
                		printf("Marshruts sorted by length.\n");
                		print_all_marshruts(marshruts, count);
                		break;
            		}
            
            		case 4: {
                		char point[MAX_NAME_LEN];
                		MARSHRUT results[MAX_MARSHRUTS];
                		int result_count;
                	
                		printf("Enter point to search: ");
                		scanf("%s", point);
                
                		find_by_point(marshruts, count, point, results, &result_count);
                
                		if (result_count > 0) {
                    			printf("\nMarshruts starting or ending at '%s':\n", point);
                    			printf("%-5s | %-20s | %-20s | %-8s\n", 
                           		"Num", "Start", "End", "Length");
                    			printf("------+----------------------+----------------------+----------\n");
                    			for (int i = 0; i < result_count; i++) {
                        			print_marshrut(&results[i]);
                   	 		}
                		} else {
                    			printf("No marshruts found starting or ending at '%s'.\n", point);
                		}
                		break;
            		}
            
            		case 5: {
                		print_all_marshruts(marshruts, count);
                		break;
            		}
            
            		case 0: {
                		printf("Exiting program.\n");
                		break;
            		}
            
            		default: {
                		printf("Invalid choice. Please try again.\n");
            		}
		}
	} while(choice != 0);

	return 0;
}

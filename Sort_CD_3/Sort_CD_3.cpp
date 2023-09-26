#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <intrin.h>

#define N 10
#define LL long long

#pragma intrinsic(__rdtsc)

	
struct list {
	int chislo;
	list* next_list;
};

struct double_list {
	int chislo;
	double_list* next_list_left;
	double_list* next_list_right;
};

//void insert_sort(int arrive[], int n) {
//	
//	int new_element, location;
//	for (int i = 1; i < n; i++) {
//		new_element = arrive[i];
//		location = i - 1;
//		while (location >= 0 && arrive[location] > new_element) {
//			arrive[location + 1] = arrive[location];
//			location--;
//		}
//		arrive[location + 1] = new_element;
//	}
//	
//
//}

list* create_list(void) {
	
	int n;

	//list* fp_list = (list*)malloc(sizeof(list));
	FILE* input;
	input = fopen("input.txt", "r");
	fscanf(input, "%d", &n);
	//int cnt = 0;
	list* start = NULL; list* start_next = NULL;

	list* fp_list = (list*)malloc(sizeof(list));
	fscanf(input, "%d", &(fp_list->chislo));
	fp_list->next_list = NULL;
	start = fp_list;
	start_next = start;
	//printf("%d\n", fp_list->chislo);
	while (!feof(input)) {
		
		list* fp_list = (list*)malloc(sizeof(list));
		fscanf(input, "%d", &(fp_list->chislo));
		start_next->next_list = fp_list;
		fp_list->next_list = NULL;
		start_next = fp_list;
		
		//fp_list->next_list = (start);
		//(start) = fp_list;
		//printf("%d", fp_list->chislo);
	}
	fclose(input);
	return start;
}

double_list* create_double_list(void) {

	int n;
	FILE* input;
	input = fopen("input.txt", "r");
	//int cnt = 0;

	fscanf(input, "%d", &n);
	double_list* start = NULL; double_list* start_0 = NULL;

	double_list* fp_list = (double_list*)malloc(sizeof(double_list));
	fscanf(input, "%d", &(fp_list->chislo));
	fp_list->next_list_left = NULL;
	fp_list->next_list_right = NULL;
	start = fp_list;
	start_0 = start;

	//printf("%d\n", fp_list->chislo);
	while (!feof(input)) {

		double_list* fp_list = (double_list*)malloc(sizeof(double_list));
		start->next_list_right = fp_list;

		fscanf(input, "%d", &(fp_list->chislo));
		
		fp_list->next_list_left = start;
		
		start = fp_list;
		//printf("%d", fp_list->chislo);
	}
	start->next_list_right = NULL;
	fclose(input);
	return start_0;
}

int* create_array(void)
{
	FILE* input;
	int n = 0;
	input = fopen("input.txt", "r");
	
	fscanf(input, "%d", &n);

	int* arrive = (int*)malloc(n * sizeof(int));

	int i = 0;
	while (!feof(input)) {
		fscanf(input, "%d", &arrive[i]);
		i++;
	}
	fclose(input);
	return arrive;
	
}

void print_out_array(int arrive[])
{
	FILE* input;
	int n = 0;
	input = fopen("input.txt", "r");
	fscanf(input, "%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%d ", arrive[i]);
	}
	printf("\n");
}

void insert_sort(int* a, int n) {
	for (LL i = 1; i < n; i++) {
		LL j = i, x = a[i];
		while (j > 0 && x < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = x;
	}
}

void print_out_list(list* start) {

	list* nachalo = start;
	while (nachalo != NULL) {
		printf("%d ", nachalo->chislo);
		nachalo = nachalo->next_list;
	}
	printf("\n");
}

void print_out_double_list(double_list* start) {

	double_list* nachalo = start;
	while (nachalo != NULL) {
		printf("%d ", nachalo->chislo);
		nachalo = nachalo->next_list_right;
	}
	printf("\n");
}

void insert_sort_list(list* start) {

	list* cur_node, * sorted_root = start;
	start = start->next_list;
	sorted_root->next_list = NULL;

	while (start != NULL) {
		cur_node = start;
		start = start->next_list;

		list* iter_node = sorted_root;
		while (iter_node->next_list != NULL && cur_node->chislo > iter_node->next_list->chislo) {
			iter_node = iter_node->next_list;
		}

		cur_node->next_list = iter_node->next_list;
		iter_node->next_list = cur_node;
	}

}

void insert_sort_double_list(double_list* start) {

	double_list* sorted_root = start;
	start = start->next_list_right;

	while (start != NULL) {
		double_list* cur_node = start;
		start = start->next_list_right;

		double_list* iter_node = cur_node->next_list_left;
		while (iter_node != NULL && iter_node->chislo > cur_node->chislo) {
			iter_node = iter_node->next_list_left;
		}

		if (cur_node->next_list_left != NULL) cur_node->next_list_left->next_list_right = cur_node->next_list_right;
		if (cur_node->next_list_right != NULL) cur_node->next_list_right->next_list_left = cur_node->next_list_left;

		cur_node->next_list_right = iter_node->next_list_right;
		if (iter_node->next_list_right != NULL) iter_node->next_list_right->next_list_left = cur_node;
		iter_node->next_list_right = cur_node;
		cur_node->next_list_left = iter_node;
	
	
		/*if (iter_node != NULL) {
			cur_node->next_list_right = iter_node->next_list_right;
			if (iter_node->next_list_right != NULL) iter_node->next_list_right->next_list_left = cur_node;
			iter_node->next_list_right = cur_node;
			cur_node->next_list_left = iter_node;
		}
		else {
			cur_node->next_list_left = NULL;
			cur_node->next_list_right = sorted_root;
			sorted_root->next_list_left = cur_node;
			sorted_root = cur_node;
		}*/

	}

}

void clear_list(list* start)
{
	list* start_0;
	while (start != NULL) {
		start_0 = start->next_list;
		free(start);
		start = start_0;
	}
}

void clear_double_list(double_list* start) {

	double_list* start_0;
	while (start != NULL) {
		start_0 = start->next_list_right;
		free(start);
		start = start_0;
	}

}

LL search_cnt(void) {
	LL cnt = 0;
	FILE* input;
	input = fopen("input.txt", "r");
	fscanf(input, "%d", &cnt);
	fclose(input);
	return cnt;
}

void create_random_numbers(void) {
	FILE* input;
	printf("Choose long of arrive: ");
	input = fopen("input.txt", "w");
	int n, starter = 0;
	scanf("%d", &n);
	fprintf(input, "%d\n", (n + 1));
	fprintf(input, "%d ", starter);
	for (int i = 0; i < n; i++) {
		fprintf(input, "%d ", rand());
	}
	fclose(input);
}


int main(void)
{
	
	list* start; double_list* start_double_list; int* start_array;

	srand(time(NULL));

	create_random_numbers();

	unsigned __int64 start_time, end_time, spent_time;
	unsigned __int64 AVG_TIME[3] = { 0, 0, 0 };		// 0 - массив; 1 - односвязный список; 2 - двусвязный список;
	unsigned __int64 __rdtsc();

	int cnt = search_cnt();
	//printf("%d\n", cnt);



	int count;
	printf("Select number of mes: ");
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		//printf("11");
		start_array = create_array();
		//print_out_array(start_array);
		//printf("\n\n\n------");
		start_time = __rdtsc();
		insert_sort(start_array, cnt);
		end_time = __rdtsc();
		//print_out_array(start_array);
		spent_time = end_time - start_time;
		AVG_TIME[0] += spent_time;
		free(start_array);
		

		start = create_list();
		start_time = __rdtsc();
		insert_sort_list(start);
		end_time = __rdtsc();
		spent_time = end_time - start_time;
		AVG_TIME[1] += spent_time;
		clear_list(start);


		start_double_list = create_double_list();
		start_time = __rdtsc();
		insert_sort_double_list(start_double_list);
		end_time = __rdtsc();
		spent_time = end_time - start_time;
		AVG_TIME[2] += spent_time;
		clear_double_list(start_double_list);
		
	}

	printf("%d - array\n%d - list\n%d - double_list\n", (AVG_TIME[0] / count), (AVG_TIME[1] / count), (AVG_TIME[2] / count));


	//start = create_list();						// list
	//print_out_list(start);
	//insert_sort_list(start);
	//print_out_list(start);

	
	//start_double_list = create_double_list();		// double_list
	//print_out_double_list(start_double_list);
	//insert_sort_double_list(start_double_list);
	//print_out_double_list(start_double_list);

	//
	//start_array = create_array();					// array
	//print_out_array(start_array);
	//insert_sort(start_array);
	//print_out_array(start_array);


}

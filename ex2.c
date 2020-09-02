#include <stdio.h>
void swap(int *a, int* b);
void bubble_sort(int arr[], int size);
void print_array(int arr[], int size);
int main(){
	int a[10] = {1, 2, 3, 4, 5, 6, 6 , 7, -1, 0};
	
	bubble_sort(a, 10);
    print_array(a, 10);

}

void swap(int *a, int* b){
	int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[], int size){
    //int size = sizeof(arr) / sizeof *arr;

    for(int i = 0; i < size - 1; i++){
        for(int j = i; j < size; j++){
            if (arr[j] < arr[i]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
void print_array(int arr[], int size){
    //int size = sizeof(arr) / sizeof *arr;
    for(int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}
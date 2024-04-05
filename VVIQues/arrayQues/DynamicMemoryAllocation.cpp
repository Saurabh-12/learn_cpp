# include <iostream>
# include <stdlib.h>

using namespace std;




int main () {

// example of malloc 
int *p = (int *) malloc(5 * sizeof(int)); // pointer p is an array of 5 elements, that created dynamically

//or create a float array of 5 elements length and then pass it to the malloc function to create dynamically and assign it to the pointer fa
float *fa, floatArr[5];
fa = (float *) malloc(sizeof(floatArr));

// Adding elements to the array
if (p == NULL || fa == NULL) {
    cout << "Memory not allocated";
    return 0;
} else {
//Adding elements to the array
for (int i = 0; i < 5; i++) {
    p[i] = i + 1;
    fa[i] = i + 1.5;
}

}

// Printing the elements of the array
for (int i = 0; i < 5; i++) {
    cout << p[i] << " ";
}
printf("\n");
for (int i = 0; i < 5; i++) {
    cout << fa[i] << " ";
}
printf("\n");

// Access elements of the array
cout << "Element at index 2: " << *p+2 << endl;
printf("Element at index 2 : %0.3f", *fa+2);
printf("\n");


// example of calloc
int *q = (int *) calloc(5, sizeof(int));
double *da = (double *) calloc(5, sizeof(double));

if (q == NULL || da == NULL) {
    cout << "Memory not allocated";
    return 0;
} else {
// Adding elements to the array
for (int i = 0; i < 5; i++) {
    q[i] = i + 3;
    da[i] = i + 2.578;
}
}

// Printing the elements of the array
for (int i = 0; i < 5; i++) {
    cout << q[i] << " ";
}
printf("\n");
for (int i = 0; i < 5; i++) {
     printf("%.3lf ",da[i]);   
}  
printf("\n");  

// example of realloc
int *r = (int *)realloc(p, 10 * sizeof(int));
if ( r == NULL) {
    cout << "Memory not allocated";
    return 0;
}
printf("Size of the array: %ld\n", sizeof(r)/sizeof(r[0]));
//print element of pointer r
for(int i = 0; i < 10; i++) {
    printf("%d ", r[i]);
}
printf("\n");


free(r); // freeing the memory allocated to the pointer r
free(q); // freeing the memory allocated to the pointer q
//free(da); // freeing the memory allocated to the pointer da
//free(p); // freeing the memory allocated to the pointer p
free(fa); // freeing the memory allocated to the pointer fa

// Dynamically allocate a 2-D array using pointer to an array
//int **arr = (int **) malloc(3 * sizeof(int *));

int i, j, rows;
int (*arr)[4];

printf("Enter number of rows: ");
scanf("%d", &rows);

arr = (int(*) [4]) malloc(rows * 4 * sizeof(int[4]));

for (i = 0; i < rows; i++) {
    for (j = 0; j < 4; j++) {
        printf("Enter element array[%d][%d] : ", i, j);
        scanf("%d", &arr[i][j]);
    }
}

// print the matrix
for (i = 0; i < rows; i++) {
    for (j = 0; j < 4; j++)
        printf("%5d ", arr[i][j]);
    printf("\n");
}

free(arr); // freeing the memory allocated to the pointer arr


  return 0;
}
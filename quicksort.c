/*
 * =====================================================================================
 *
 *       Filename:  quicksort.c
 *
 *    Description:  Quicksort 
 *
 *        Version:  1.0
 *        Created:  26/03/2013 14:26:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitor Freitas (vfs), vitorfs@gmail.com
 *        Company:  Universidade Federal de Juiz de Fora (UFJF)
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int *x, int *y) {
  int z = *x;
  *x = *y;
  *y = z;
}

int partition(int *array, int p, int r) {
  int pivot, i, j;

  pivot = array[r];
  i = p - 1;

  for (j = p ; j < r ; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[r]);

  return i + 1;
}

void quicksort(int *array, int p, int r) {
  int q;
  if (p <= r) {
    q = partition(array, p, r);
    quicksort(array, p, q - 1);
    quicksort(array, q + 1, r);
  }
}

double sort(int *array, int size) {
  clock_t end, start;
  double elapsed;

  start = clock();
  quicksort(array, 0, size - 1);
  end = clock();
  
  elapsed = (double) (end - start) / CLOCKS_PER_SEC;

  return elapsed;
}

void init_array(int *array, int size) {
  srand(time(NULL));
  int i;
  for (i = 0 ; i < size ; i++)
    array[i] = rand()%size;
}

void print_array(int *array, int size) {
  int i;
  for (i = 0 ; i < size ; i ++) {
    printf("[%d]", array[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    int size;
    size = atoi(argv[1]);

    if (size > 1) {
      int *array = malloc(size * sizeof(int));
      int print = 0;
      double elapsed;

      init_array(array, size);
      if (argc > 2 && strcmp(argv[2], "-p") == 0) print = 1;
      
      if (print) print_array(array, size);
      elapsed = sort(array, size);
      if (print) print_array(array, size);
      
      printf("Quicksort took %f seconds to sort %d elements.\n", elapsed, size);
      
      free(array);

      return 0;
    }
    else {
      printf("The array must have atleast size 2 to be sorted.\n");
      return -1;
    }
  }
  else {
    printf("The program expects atleast one argument.\n");
    return -1;
  }
}

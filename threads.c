#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*THIS IS SHIVUM*/

/*
  This is the lock that we are using to synchronize threads
 */
static pthread_mutex_t mutex;

/*start at lowest possible value*/
static int max  = -21747483648;
static int sum = 0;

void *counter(void *args) {
   int i;

   for (i = 0; i < LOOPS; i++) {
      pthread_mutex_lock(&mutex);
      count++;
      pthread_mutex_unlock(&mutex);
   }
   printf("Executed %d times\n", i);

   return NULL;
}

int main(int *argv) {
   int num_elements = argv[1], num_threads = argv[2], seed = argv[3], task = argv[4], i = 0, j = 0, counter;
   char print_results = argv[5];
   int array[num_elements];
   
   pthread_t tids[num_threads];
   pthread_mutex_init(&mutex, NULL);

   /*divides the array into separate threads*/
   for (i = 0; i < num_threads; i++){
      if(i == num_threads - 1){
	 pthread_create(&tids[i], NULL, local_sum, last_thread_size(num_elements, num_threads));
      }
      else{
	 pthread_create(&tids[i], NULL, local_sum, common_thread_size(num_elements, num_threads));
      }
   }
   

   /* pthread_create(&tids[0], NULL, counter, NULL);(
   pthread_create(&tids[1], NULL, counter, NULL);
   pthread_join(tids[0], NULL);
   pthread_join(tids[1], NULL);
   printf("Count: %d\n", count);

   pthread_mutex_destroy(&mutex);*/

   return 0;
}


void *localSum(void *num_elements){
   int elements = *((int*)num_elements),  array[elements], i;
    for(i = 0; i < elements; i++){
      pthread_mutex_lock(&mutex);
      sum += array[i];
      pthread_mutex_unlock(&mutex);
	
    }

    printf("sum = %d\n", sum);
    return NULL;
}

void * localMax(void *num_elements){
    int elements = *((int*)num_elements),  array[elements], i;
    for(i = 0; i < elements; i++){
      array[i] = 
	
    }
    }
    return max;
}
int commmon_thread_size(int pop_count, int thread_count){
    return pop_count / thread_count;
}

int last_thread_size(int pop_count, int thread_count){
    return pop_count - (pop_count / thread_count) * (thread_count - 1);
}

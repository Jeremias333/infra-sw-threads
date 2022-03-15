#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define QTD_THREADS 3

int* values;
int qtd_in = 0;
pthread_t threads[QTD_THREADS];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void in_qtd(){
	scanf("%d", &qtd_in);
}

void in_values(){
	// pthread_mutex_lock(&lock);
	//Extract values
	in_qtd();

	int cont = 0;
	int tempValue;

	// int values[qtd_in];

	values = calloc(qtd_in, sizeof(int));

	while (scanf("%d", &tempValue) != EOF) {
		// printf("%d\n", tempValue);
		// printf("valor do cont: %d\n", cont);
		values[cont] = tempValue;
		cont++;
		if (cont > (qtd_in-1)){
			break;
		}
	}

	// pthread_mutex_unlock(&lock);
}

void* average(void *args){
	int sum = 0;
	int mean = 0;
	for(int i=0; i < qtd_in; i++){
		sum += values[i];
	}
	mean = sum/qtd_in;
	printf("The average value is %d\n", mean);
}


void* minimum(void *args){
	int minimumAct = values[0];

	for(int i=0; i < qtd_in; i++){
		if (minimumAct >= values[i]){
			minimumAct = values[i];
		}
	}
	printf("The minimum value is %d\n", minimumAct);
}

void* maximum(void *args){
	int maximumAct = values[0];

	for(int i=0; i < qtd_in; i++){
		if (maximumAct <= values[i]){
			maximumAct = values[i];
		}
	}
	printf("The maximum value is %d\n", maximumAct);
}

void makeThreads(){
	pthread_create(&(threads[0]), NULL, average, NULL);
	pthread_create(&(threads[1]), NULL, minimum, NULL);
	pthread_create(&(threads[2]), NULL, maximum, NULL);
}

void runThreads(){
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
}

int main(){
	
	//first thread
	// in_values();

	//second thread
	// int averageResult = average();
	// printf("The average value is %d\n", averageResult);

	//thierd
	// int mininumResult = minimum();
	// printf("The minimum value is %d\n", mininumResult);

	//fourt
	// int maximumResult = maximum();
	// printf("The maximum value is %d\n", maximumResult);

	// for (int i=0; i < qtd_in; i++){
	// 	printf("%d\n",values[i]);
	// }

	in_values();

	makeThreads();
	runThreads();


	free(values);
	return 0;

}

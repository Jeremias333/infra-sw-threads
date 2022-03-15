#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define QTD_THREADS 4

int* values;
int qtd_in = 0;
pthread_t threads[QTD_THREADS];

void in_qtd(){
	scanf("%d", &qtd_in);
}

int in_values(){
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
}

int average(){
	int sum = 0;
	int mean = 0;
	for(int i=0; i < qtd_in; i++){
		sum+=values[i];
	}
	mean = sum/qtd_in;
	return mean;
}


int minimum(){
	return 0;
}

int maximum(){
	return 0;
}

int main(){
	
	//first thread
	in_values();

	//second thread
	int averageResult = average();
	printf("The average value is %d\n", averageResult);

	//thierd
	int mininumResult = minimum();
	printf("The minimum value is %d\n", mininumResult);

	//fourt
	int maximumResult = maximum();
	printf("The maximum value is %d\n", maximumResult);

	// for (int i=0; i < qtd_in; i++){
	// 	printf("%d\n",values[i]);
	// }


	free(values);
	return 0;

}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/********************/
/*
  Par
	KHELIL Mohamed Wael
	KERIM Yahia
	SIL2 - TPGO 2018/2019
*/
struct _Item{
    unsigned int weight;
    unsigned int value;
}typedef Item;

struct _Data{
    unsigned int numberOfObjects;
    Item* objects;
}typedef Data;

struct _Solution{
    bool *X;
    unsigned int value;
}typedef Solution;


/*******************/

Item obj[4] = {{2, 3}, {4, 5}, {2, 1}, {3, 2}};

static unsigned int NUMBER_OF_OBJECTS = 4;

static unsigned int MAXIMAL_WEIGHT = 7;

Data *data;


/********************/


void printSolution(Solution* sol, unsigned int numberOfObjects){
    printf("\nPrinting the solution ...\n");
    for(unsigned int i = 0; i < numberOfObjects; i++) {
        printf("| \t%d \t|\n", sol->X[i]);
    }
    printf("DONE\n");
}
Solution* initSolution(unsigned int length){
    Solution *sol = malloc(sizeof(Solution));
    sol->X = calloc(length, sizeof(bool));
    sol->value = 0;
    return sol;
}
Solution* f(unsigned int n,unsigned int maxWeight) {

    Solution *f1;
    Solution *f2;

    if (n <= 0)
        return initSolution(data->numberOfObjects);
    else {
        //On suppose que l'object i n'est pas pris
        f1 = f(n - 1, maxWeight);
        if(maxWeight < data->objects[n - 1].weight)
            return f1;
        else{
            //On suppose que l'object i est pris
            f2 = f(n - 1, maxWeight - data->objects[n - 1].weight);
            f2->value += data->objects[n - 1].value;
        }
        if (f1->value >= f2->value) {
            free(f2);
            return f1;
        } else {
            f2->X[n-1] = true;
            free(f1);
            return f2;
        }
    }
}
/********************************/
Solution* cloneSolution(Solution* sol){
    Solution *solC = malloc(sizeof(Solution));
    solC->value = sol->value;

    solC->X = malloc(data->numberOfObjects*sizeof(bool));
    for(unsigned int i = 0; i < data->numberOfObjects ;i++) {
        solC->X[i] = sol->X[i];
    }

    return solC;
};
Solution* fDynamique(unsigned int n,unsigned int maxWeight) {

    Solution *tabF[n + 1][maxWeight + 1];
    Solution *f1;
    Solution *f2;

       for(unsigned int i = 0; i < n + 1; i++){
           for(unsigned int j = 0; j < maxWeight + 1; j++) {

               if (i == 0) {
                tabF[i][j] = initSolution(data->numberOfObjects);
            }
            else {
                //On suppose que l'object i n'est pas pris
                if(j < data->objects[i - 1].weight) {

                    tabF[i][j] = cloneSolution(tabF[i - 1][ j]);

                }else{
                    //On suppose que l'object i est pris
                    f1 = cloneSolution(tabF[i-1][j]);

                    f2 = cloneSolution(tabF[i-1][j - data->objects[i-1].weight]);
                    f2->value = f2->value + (data->objects[i - 1].value);
                    if (f1->value >= f2->value) {
                        tabF[i][j] = f1;
                        free(f2);
                    } else {
                        tabF[i][j] = f2;
                        tabF[i][j]->X[i - 1] = true;

                        free(f1);
                    }
                }

            }
        }
    }
    return tabF[n][maxWeight];

}

int main() {

    Solution* optimalSolution;

    data = malloc(sizeof(Data));
    data->numberOfObjects = NUMBER_OF_OBJECTS;
    data->objects = &obj;

    optimalSolution = f(NUMBER_OF_OBJECTS, MAXIMAL_WEIGHT);
    printSolution(optimalSolution, NUMBER_OF_OBJECTS);
    printf("\nThe optimal value = %u ", optimalSolution->value);

    optimalSolution = fDynamique(NUMBER_OF_OBJECTS, MAXIMAL_WEIGHT);
    printSolution(optimalSolution, NUMBER_OF_OBJECTS);
    printf("\nThe optimal value = %u ", optimalSolution->value);

    free(data);

}

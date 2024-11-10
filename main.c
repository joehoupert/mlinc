#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1415926535

float training_data[][2] = {
    {0, 0},
    {1, 1*PI},
    {2, 2*PI},
    {3, 3*PI},
    {4, 4*PI},
    {5, 5*PI},
};

#define TD_SIZE sizeof(training_data)/sizeof(training_data[0])


float rand_float(void){
    return (float)rand()/(float)(RAND_MAX);
}

/* Use MSE to determine cost, TODO: implement other means? */
float cost(float r){
    float cost = 0.0f;

    for(int i = 0; i < TD_SIZE; i++){
        float x = training_data[i][0];
        float y = x*r;
        float delta = y - training_data[i][1];
        cost = delta*delta;

        //printf("%f, %f\n",y, training_data[i][1]);
    }
    cost /= TD_SIZE;
    return cost;
}

int main(void){

    /*
     * Let's train a neuron!
     *
     * First iteration: just guess a random number
     * y = x*random_number
     * x = training_data[][0]
     *
     * Then determine cost (loss?) via MSE
     *
     */

    //seed yr random generator
    srand(time(0));

    float r = rand_float() * 10.0f;

    float epsilon = 1e-3;

    printf("Cost: %f\n",cost(r));
    printf("Cost: %f\n",cost(r+epsilon));

    return 0;
}

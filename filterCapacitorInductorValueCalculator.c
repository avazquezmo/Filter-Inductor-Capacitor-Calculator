/* Final Project */
/* Axel Vazquez */
/* 02/12/2018 */

#include <stdio.h>

    /* Prototype Functions */
void printGreeting();
float calcFreq(float cutOff, float PI, int choiceFrequency);

    /* Main Function */
int main(){
        /* Declaring variables */
    char resistors[13][5];
    int resistances[1];
    float inductor[13], capacitor[13];    //Inductor and capacitor values.
    float Fc;    //cut-off frequency.
    int filterChoice, frequencyChoice;
    int j;
    float pi = 3.1416;

        /* Welcoming */
    printGreeting();//calling function for greeting

        /* Cut-off frequency user input */
    printf("To begin, please enter the cut-off frequency of your filter:\n");
    scanf("%f",&Fc);
    printf("Indicate the type of cut-off frequency that you have entered:\n");
    printf("    (1)-Angular frequency (rad/sec)\n");
    printf("    (2)-Normal frequency (Hz)\n");
    scanf("%d",&frequencyChoice);

        /* Menu validation input */
    while (frequencyChoice < 1 || frequencyChoice > 2){
        printf("Invalid input, please select one of the options from the menu\n");
        printf("    1. Angular frequency (rad/sec)\n");
        printf("    2. Normal frequency (Hz)\n");
        scanf("%d", &frequencyChoice);
    }//end of while loop

        /* Converting to normal frequency */
    Fc = calcFreq(Fc,pi,frequencyChoice);//calling function to convert frequency

            /* Filter menu display */
        printf("To begin, please indicate the number of the circuit you desire to work with:\n");
        printf("    1. First order RC (resistor-capacitor) filter\n");
        printf("    2. First order RL (resistor-inductor) filter\n");
        scanf("%d", &filterChoice);

            /* Menu validation input */
        while (filterChoice < 1 || filterChoice > 2){
            printf("Invalid input, please select one of the options from the menu\n");
            printf("    1. First order RC (resistor-capacitor) filter\n");
            printf("    2. First order RL (resistor-inductor) filter\n");
            scanf("%d", &filterChoice);
        }//end of while loop

            /* Reading data from file */
        FILE *fp;// define pointer variable of type FILE

            /* Open data file associated with fp in read mode */
        fp=fopen("final project data.txt", "r");

            /* Check if open was successful */
        if (fp == NULL){//not successful
            printf("Program cannot open the file\n");
            return -1;//indication of problem in file reading
        }//end of if

        else{
                /* Electric components calculation */
            if(filterChoice == 1){
                printf("Reading the resistor values, please stand by...\n");
                for(j = 0;j < 13;j++){
                    fscanf(fp,"%s",&resistors[j]);
                    fscanf(fp,"%d",&resistances[j]);
                        /* Echo-print */
                    printf("%s = %d\n", resistors[j], resistances[j]);
                }//end of for
                printf("\n");
                    /* Calculating Values */
                printf("The values of the capacitors needed and their respecting resistors are:\n");
                printf("Capacitors(Farads)   Resistors(Ohms)\n");
                for(j = 0;j < 13;j++){
                    capacitor[j] = 1.0/(2*pi*Fc*resistances[j]);
                    printf("%.6f                  %d\n",capacitor[j],resistances[j]);
                }//end of for
            }//end of if
            else{
                printf("Reading the resistor values, please stand by...\n");
                for(j = 0;j < 13;j++){
                    fscanf(fp,"%s",&resistors[j]);
                    fscanf(fp,"%d",&resistances[j]);
                        /* Echo-print */
                    printf("%s = %d\n", resistors[j], resistances[j]);
                    inductor[j] = resistances[j]/(2*pi*Fc); // inductor values calculations
                }//end of for
                printf("\n");
                    /* Calculating Values */
                printf("The values of the inductors needed and their respecting resistors are:\n");
                printf("Inductors(Henrries)   Resistors(Ohms)\n");
                for(j = 0;j < 13;j++){
                    printf("  %.6f                    %d\n",inductor[j],resistances[j]);
                }//end of for
            }//end of else
        }//end of else
    return 0;
}//end of main

    /* Functions */
    //function for greeting
void printGreeting(){
    printf("Welcome, this program will help you calculate the value for inductors or capacitors needed\n");
    printf("for active-first order filter.\n");
    printf("\n");
}//end of function

    //function for frequency conversion
float calcFreq(float cutOff, float PI, int choiceFrequency){
    if ( choiceFrequency == 1){
        cutOff = cutOff/(2*PI);
    }//end of if
    return cutOff;
}// end of function

#include <stdio.h>

int main() {
    char name[30], noIC[12];
    double height, weight;
    double bmi;

    // Input Name: User Enter Name
    printf("Enter your Name: ");
    scanf("%s", name);

    // Input IC: User Enter noIC Number
    printf("Enter your IC Number: ");
    scanf("%s", noIC);

    // Input Height: User Enter Height (unit meter)
    printf("Enter your Height(mtr): ");
    scanf("%lf", &height);

    // Input Weight: User Enter Weight (unit kg)
    printf("Enter your Weight(kg): ");
    scanf("%lf", &weight);

    // Calculation for BMI
    bmi = weight / (height * height);

    // Calculation for Ideal Weight
    double idealWeight = 23 * height * height;

    // Output Name and IC: Display Name and noIC
    printf("\nName: %s, IC Number: %s\n\n", name, noIC);
    printf("\t== BMI Detail ==\n");

    // Output Weight and Height
    printf("Height:  %5.2lfmtr\n", height);
    printf("Weight:  %5.2lfkg\n", weight);

    // Output BMI
    printf("BMI Calculation: %lf\n\n", bmi);


    // Using if - else statement for BMI status
    if (bmi < 18.5) {
        printf("Status: Underweight\n");
        printf("Weight to Gain: %5.2lfkg\n", idealWeight - weight);
    } else if (bmi < 25.0) {
        printf("Status: Normal weight\n");
    } else if (bmi < 30.0) {
        printf("Status: Overweight\n");
         printf("Weight to Lose: %5.2lfkg\n", weight - idealWeight);
    } else {
        printf("Status: Obesity\n");
        printf("Weight to Lose: %5.2lfkg\n", weight - idealWeight);
    }



    return 0;
}

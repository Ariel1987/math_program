/*
 ============================================================================
 Name        : math_program.c
 Author      : ariel
 Version     : 1.0
 Description : Program for math operations
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int startProgram();
int choices();
int secondaryMenu();
int square();
int sum();
int oddNums();
int power();
int bestSell();
int grades();
int sumOfEvens();
int factorial();
int multiplesOfTwoNumbers();
int isNumTriangular();

int main(void) {
	startProgram();
	return 0;
}

int choices() {

	printf("********** MATH PROGRAM **********\n");
	printf("\nWhat kind of math operation would you like to do?\n");
	printf("\n1 - Square of an integer\n");
	printf("2 - Sum of the first n positive numbers\n");
	printf("3 - First n odd positive numbers\n");
	printf("4 - N to the power of X\n");
	printf("5 - Best sale of a store\n");
	printf("6 - Best and worst grades in a class\n");
	printf("7 - Sum of even positive numbers\n");
	printf("8 - Factorial\n");
	printf("9 - Multiple numbers\n");
	printf("10 - Triangular numbers\n");
	printf("Option: ");

	int option;
	scanf("%d", &option);

	return option;
}

int startProgram() {

	int option = choices();

	switch(option) {
	case 1:
		square();
		choices();
		break;
	case 2:
		sum();
		choices();
		break;
	case 3:
		oddNums();
		choices();
		break;
	case 4:
		power();
		choices();
		break;
	case 5:
		bestSell();
		choices();
		break;
	case 6:
		grades();
		choices();
		break;
	case 7:
		sumOfEvens();
		choices();
		break;
	case 8:
		factorial();
		choices();
		break;
	case 9:
		multiplesOfTwoNumbers();
		choices();
		break;
	case 10:
		isNumTriangular();
		choices();
		break;
	default:
		printf("\nInexistent option\n\n");
		choices();
		break;
	}

	return 0;
}

int secondaryMenu() {

	printf("Would you like to continue with this operation?");
	printf("\n1 - Yes");
	printf("\n2 - No");
	printf("\nOption: ");

	int option;
	scanf("%d", &option);

	return option;
}

int square() {

	printf("\n---------- Find out the square ----------\n");
	int number,
		squareOfNum;

	printf("\nEnter a positive number: ");
	scanf("%d", &number);

	if(number == 0) {
		squareOfNum = 0;
	} else {
		squareOfNum = number * number;
	}
	printf("\nThe square of %d is %d\n\n", number, squareOfNum);

	int option = secondaryMenu();

	switch(option) {
	case 1:
		square();
		break;
	case 2:
		startProgram();
		break;
	default:
		printf("Inexistent option");
		secondaryMenu();
	}

	return 0;
}

int sum() {

	int number,
		sum = 0;

	printf("\nEnter a positive number to know the sum of its first positive numbers: ");
	scanf("%d", &number);

	for (int i = 0; i <= number; i++) {
		sum += i;
	}
	printf("\nThe sum of the first %d positive numbers is %d\n", number, sum);

	return 0;
}

int oddNums() {

	int number,
		odds = 1;

	printf("\nEnter a positive number n to print the first n odd numbers: ");
	scanf("%d", &number);

	printf("The first %d positive odd numbers are ", number);
	for (int i = 0; i < number; i++) {
		printf("%d ", odds);
		odds = odds + 2;
	}

	return 0;
}

int power() {

	int number,
		power,
		result = 1;

	printf("\nEnter two positive numbers: ");
	scanf("%d %d", &number, &power);

	for (int i = 0; i < power; i++) {
		result = number * result;
	}
	printf("%d ", result);

	return 0;
}

int bestSell() {

	int march = 31;
	int sales[march];

	for (int i = 0; i < march; i++) {
		printf("\nEnter the sales for day %d: ", i + 1);
		scanf("%d", &sales[i]);
	}

	int bestSell = 0,
		day;

	for (int i = 0; i < march - 1; i++) {
		if (sales[i] > bestSell) {
			bestSell = sales[i];
			day = i + 1;
		}
	}
	printf("The best sell was on %d of March of %d dollars\n", day, bestSell);

	return 0;
}

int grades() {

	int students = 0, i;
	float grades[students];

	printf("\nEnter the number of students in class: ");
	scanf("%d", &students);

	for (i = 0; i < students; i++) {
		printf("\nThe grade from student %d is: ", i + 1);
		scanf("%f", &grades[i]);
	}

	float highestGrade = grades[0],  lowestGrade = grades[0];
	for (i = 1; i < students; i++) {
		if (grades[0] < grades[i]) {;
			highestGrade = grades[i];
		} else {
			lowestGrade = grades[i];
		}
	}
	printf("\nLowest grade is %f: ", lowestGrade);
	printf("\nHighest grade is %f: ", highestGrade);

	return 0;
}

int sumOfEvens() {

	int sizeOfArray = 0, sequence[sizeOfArray];

	printf("\nEnter number of integers you would like to put in sequence: ");
	scanf("%d", &sizeOfArray);

	for (int i = 0; i < sizeOfArray; i++) {
		printf("\nEnter your integers: ");
		scanf("%d", &sequence[i]);
	}

	int sum = 0;
	for (int i = 0; i < sizeOfArray; i++) {
		if (sequence[i] % 2 == 0) {
			sum += sequence[i];
		}
	}
	printf("\nThe sum of the even numbers you entered is %d", sum);

	return 0;
}

int factorial() {

	int number, factorial = 1;
	printf("\nEnter a number to find its factorial: ");
	scanf("%d", &number);

	for (int i = 0; i < number - 1; i++) {
		factorial = factorial * (number - i);
	}
	printf("\nThe factorial of %d is %d", number, factorial);

	return 0;
}

int multiplesOfTwoNumbers() {

	int n, num1, num2;
	printf("\nEnter three positive numbers: ");
	scanf("%d %d %d", &n, &num1, &num2);

	int result = 0;
	for (int i = 0; i < n; i++) {
		if (result % num1 == 0 || result % num2 == 0) {
			printf("%d ", result);
		} else {
			i--;
		}

		result++;
	}

	return 0;
}

int isNumTriangular() {

	int num, i;
	printf("\nEnter a positive integer: ");
	scanf("%d", &num);

	for (i = 1; i * (i + 1) * (i + 2) < num; i++);
	if (i * (i + 1) * (i + 2) == num) {
		printf("\n%d is a triangular number", num);
	} else {
		printf("\n%d is not a triangular number", num);
	}

	return 0;
}

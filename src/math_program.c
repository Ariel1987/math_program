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
int secondaryMenu(int (*f)(int));
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
	printf("11 - Exit\n");
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
	case 11:
		printf("\nThat's it for today!\n");
		exit(0);
		break;
	default:
		printf("\nInexistent option\n\n");
		choices();
		break;
	}

	return 0;
}

int secondaryMenu(int (*function)()) {

	printf("\n\nWould you like to continue with this operation?");
	printf("\n1 - Yes");
	printf("\n2 - No");
	printf("\n3 - Exit");
	printf("\nOption: ");

	int option;
	scanf("%d", &option);

	switch(option) {
	case 1:
		function();
		break;
	case 2:
		startProgram();
		break;
	case 3:
		printf("\nThat's it for today!\n");
		exit(0);
		break;
	default:
		printf("\nInexistent option\n\n");
		startProgram();
	}

	return 0;
}

int square() {

	printf("\n---------- Find out the square ----------\n");
	int number,
		squareOfNum;

	printf("\nEnter a positive number: ");
	scanf("%d", &number);

	squareOfNum = number * number;

	printf("\nThe square of %d is %d\n\n", number, squareOfNum);

	secondaryMenu(square);

	return 0;
}

int sum() {

	printf("\n---------- Sum of first n positive numbers ----------\n");

	int number,
		sumOfNums = 0;

	printf("\nEnter a positive number to know the sum of its former numbers: ");
	scanf("%d", &number);

	for (int i = 0; i <= number; i++) {
		sumOfNums += i;
	}
	printf("\nThe sum of the first %d positive numbers is %d\n", number, sumOfNums);

	secondaryMenu(sum);

	return 0;
}

int oddNums() {

	printf("\n---------- Find the first n odd numbers ----------\n");

	int number,
		odds = 1;

	printf("\nEnter a positive number n to print the first n odd numbers: ");
	scanf("%d", &number);

	printf("The first %d positive odd numbers are ", number);
	for (int i = 0; i < number; i++) {
		printf("%d ", odds);
		odds = odds + 2;
	}

	secondaryMenu(oddNums);

	return 0;
}

int power() {

	printf("\n---------- N to the power of X ----------\n");

	int number,
		power,
		result = 1;

	printf("\nEnter two positive numbers: ");
	scanf("%d %d", &number, &power);

	for (int i = 0; i < power; i++) {
		result = number * result;
	}
	printf("%d ", result);

	secondaryMenu(power);

	return 0;
}

int bestSell() {

	printf("\n---------- Best sale of the month ----------\n");

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

	secondaryMenu(bestSell);

	return 0;
}

int grades() {

	printf("\n---------- Best grade in class ----------\n");

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

	secondaryMenu(grades);

	return 0;
}

int sumOfEvens() {

	printf("\n---------- Sum of even numbers ----------\n");

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

	secondaryMenu(sumOfEvens);

	return 0;
}

int factorial() {

	printf("\n---------- Factorial ----------\n");

	int number, factorial = 1;
	printf("\nEnter a number to find its factorial: ");
	scanf("%d", &number);

	for (int i = 0; i < number - 1; i++) {
		factorial = factorial * (number - i);
	}
	printf("\nThe factorial of %d is %d", number, factorial);

	secondaryMenu(factorial);

	return 0;
}

int multiplesOfTwoNumbers() {

	printf("\n---------- N numbers multiples of X and Y ----------\n");

	int n, x, y;
	printf("\nEnter a positive number for n: ");
	scanf("%d", &n);
	printf("\nEnter a positive number for x: ");
	scanf("%d", &x);
	printf("\nEnter a positive number for y: ");
	scanf("%d", &y);

	printf("\nThe %d numbers that are multiples of %d and/or %d are ", n, x, y);
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (result % x == 0 || result % y == 0) {
			printf("%d ", result);
		} else {
			i--;
		}
		result++;
	}

	secondaryMenu(multiplesOfTwoNumbers);

	return 0;
}

int isNumTriangular() {

	printf("\n---------- Find out if a number is multiplied by three consecutive numbers ----------\n");

	int num, i;
	printf("\nEnter a positive integer: ");
	scanf("%d", &num);

	for (i = 1; i * (i + 1) * (i + 2) < num; i++);
	if (i * (i + 1) * (i + 2) == num) {
		printf("\n%d is a triangular number", num);
	} else {
		printf("\n%d is not a triangular number", num);
	}

	secondaryMenu(isNumTriangular);

	return 0;
}

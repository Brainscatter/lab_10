// lab10.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include "math.h"
#include "malloc.h"
#include "string.h"

double* pointsLenght(double* pointsCoord, int pointsAmount) {
	double* pointsLenght = (double*)malloc(pointsAmount * (pointsAmount - 1) * sizeof(double) + 1);
	int pointCounter;
	int lenghtCounter;
	int k;
	for (pointCounter = 0; pointCounter < pointsAmount; pointCounter ++) {
		k = 0;
		for (lenghtCounter = 0; lenghtCounter < pointsAmount; lenghtCounter++) {
			if (pointCounter == lenghtCounter) {
				k = 1;
			}
			if (pointCounter != lenghtCounter) {
				pointsLenght[pointCounter * pointsAmount + lenghtCounter - k] = sqrt(pow(pointsCoord[lenghtCounter * 2] - pointsCoord[pointCounter * 2], 2) + pow(pointsCoord[lenghtCounter * 2 + 1] - pointsCoord[pointCounter * 2 + 1], 2));
			}
		}
	}

	return pointsLenght;
}

double* inputPointsCoord(int pointsAmount) {
	double* pointsCoord = (double*)malloc(pointsAmount * 2 * sizeof(double) + 1);
	int pointCounter;
	for (pointCounter = 0; pointCounter < pointsAmount; pointCounter++) {
		printf("%d point:\n", pointCounter + 1);
		printf("input x coordinate: ");
		scanf("%lf", pointsCoord + pointCounter * 2);
		printf("input y coordinate: ");
		scanf("%lf", pointsCoord + pointCounter * 2 + 1);
	}
	return pointsCoord;
}

int* returnMassWithNum(int number) {
	int numAmount = 0;
	int counter;
	int* numeralsCopy = (int*)malloc(0);
	int* numerals = (int*)malloc(0);
	int* numFin;

	while (number > 0) {
		_memccpy(numeralsCopy, numerals, 'A', sizeof(int) * numAmount);
		numerals = (int*)realloc(numerals, (numAmount + 1) * sizeof(int) + 1);
		_memccpy(numerals, numeralsCopy, 'A', sizeof(int) * (numAmount));
		numeralsCopy = (int*)realloc(numerals, (numAmount + 1) * sizeof(int) + 1);
		numerals[numAmount] = number % 10;
		number = number / 10;
		numAmount++;
	}
	for (counter = 0; counter < numAmount; counter++) {
	}

	numFin = (int*)malloc(sizeof(int) * numAmount + 1);

	for (counter = 0; counter < numAmount; counter++) {
		numFin[counter] = numerals[numAmount - 1 - counter];
	}
	return numFin;
}

int main(){
	double* pointsCoord;
	int pointsAmount;
	int pointCounter;
	int lenghtCounter;
	double* pointsLenghts;
	int number;
	int numCounter;
	int* numerals;
	int numAmount;

	printf("input points amount: ");
	scanf("%d", &pointsAmount);

	pointsCoord = inputPointsCoord(pointsAmount);
	pointsLenghts = pointsLenght(pointsCoord, pointsAmount);

	for (pointCounter = 0; pointCounter < pointsAmount; pointCounter ++) {
		printf("\n");
		for (lenghtCounter = 0; lenghtCounter < pointsAmount - 1; lenghtCounter ++) {
			printf("%lf  ", pointsLenghts[pointCounter * pointsAmount + lenghtCounter]);
		}
	}
	printf("\n");
	free(pointsCoord, pointsLenghts);

	printf("input the number, wich you want to transformate into massife: ");
	scanf("%d", &number);
	


	numerals = returnMassWithNum(number);
	numCounter = 0;
	while (numerals[numCounter] >= 0){
		printf("numeral %d is: %d\n", numCounter + 1, numerals[numCounter]);
		numCounter++;
	}

    return 0;
}



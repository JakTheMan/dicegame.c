#include "dicegame.h"
#include <stdlib.h>
#include <stdio.h>

//Returns a rand. num. between min and max
int getRandomNumber(int min, int max){
	return(rand() % (max - min + 1))+min;
}

//Returns a round type due to rand. probability
ROUNDTYPE getRoundType(){
	int probability = getRandomNumber(0,9);
	if(probability < 2){
		return BONUS;
	}
	else if(probability < 5){
		return DOUBLE;
	}
	else{
		return REGULAR;
	}
}

//Returns the num of points for given type of round
int getRoundPoints(ROUNDTYPE roundType){
	int points = 0;
	switch(roundType){
	case BONUS:
		points = 200;
		break;
	case DOUBLE:
		points = getRandomNumber(1,10) * 20;
		break;
	case REGULAR:
		points = getRandomNumber(1,10) * 10;
		break;
}
	return points;
}

//Prints points of players
void printPlayerPoints(int p1, int p2){
	printf("P1: %d\n" , p1);
	printf("p2: %d\n" , p2);
}

//Prints info about the round
void printRoundInfo(ROUNDTYPE t, int dice, int points){
	const char *round_type_string;
	switch(t){
	case BONUS:
		round_type_string = "BONUS";
		break;
	case DOUBLE:
		round_type_string = "DOUBLE";
		break;
	case REGULAR:
		round_type_string = "REGULAR";
		break;
	}



	printf("Type	: %s\n" , round_type_string);
	printf("DICE	: %d\n" , dice);
	printf("POINTS	: %d\n" , points);
}

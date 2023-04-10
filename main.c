#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int main(){

    //random num gen
    srand(time(NULL));

    int num_rounds, p1_points = 0, p2_points = 0, dice, points;
    int i = 1;
    //randomly picks a player
    int current_player = (getRandomNumber(0,1) ==0 ) ? 1 : 2;

    //Prints the output
    printf("Enter the number of rounds: ");
    scanf("%d" , &num_rounds);
    printf("P1 : %d\n" , p1_points);
    printf("P2 : %d\n" , p2_points);

    //loops that goes through each round
    for( i = 1; i <= num_rounds; i++){
        printf("\nROUND %d\n--------\n" , i);
        printf("Player : %d\n" , current_player);
        //rolls a dice
        dice = getRandomNumber(1,6);
        //calculates points
        points = getRoundPoints(getRoundType());
        //if player earns points
        if((current_player == 1 && dice % 2 ==1) || (current_player == 2 && dice % 2 == 0)){
            if(current_player == 1){
                p1_points += points;

            }else{
                p2_points += points;
            }
            //prints points earned
            printf("Score : %d\n" , points);
        } else{
            printf("No points earned.\n");
        }
        //print value of dice
        printf("Dice : %d\n" , dice);
        //print p1 final score
        printf("P1 : %d\n" , p1_points);
        //print p2 finial score
        printf("P2 : %d\n" , p2_points);
        //switches players turn
        current_player = current_player == 1 ? 2 : 1;
    }

    //prints finial score header
    printf("\nFINAL SCORE\n--------\n");
    printf("P1 : %d\n" , p1_points);
    printf("P2 : %d\n" , p2_points);

    //determins winner
    if(p1_points > p2_points){
        printf("Player 1 wins!\n");
    }
    else if(p2_points > p1_points){
        printf("Player 2 wins!\n");
    }
    else{
        printf("It's a tie!\n");
    }

    return 0;    
}

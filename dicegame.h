#ifndef DICEGAME_H
#define DICEGAME_H

typedef enum {
    BONUS,
    DOUBLE,
    REGULAR
} ROUNDTYPE;
//Function prototypes
int getRandomNumber(int min, int max);
ROUNDTYPE getRoundType();
int getRoundPoints(ROUNDTYPE roundType);
void printPlayerPoints(int p1, int p2);
void printRoundInfo(ROUNDTYPE t, int dice, int points);

#endif
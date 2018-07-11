//
// Created by thomas on 5/25/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define JAN_DAYS 31
#define FEB_DAYS 28
#define MAR_DAYS 31
#define APR_DAYS 30
#define MAY_DAYS 31
#define JUN_DAYS 30
#define JUL_DAYS 31
#define AUG_DAYS 31
#define SEP_DAYS 30
#define OCT_DAYS 31
#define NOV_DAYS 30

typedef struct { int day; int month; int year;} Geburtstag;

int alterInTagen(Geburtstag* const date, int refYear){
    int diffYear;
    int diffYearInDays;
    int date_monthInDays;

    diffYear = refYear-date->year;
    diffYearInDays = diffYear*365;

    switch(date->month){
        case 2: date_monthInDays = JAN_DAYS;
            break;
        case 3: date_monthInDays = JAN_DAYS+FEB_DAYS;
            break;
        case 4: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS;
            break;
        case 5: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS+APR_DAYS;
            break;
        case 6: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS+APR_DAYS+MAY_DAYS;
            break;
        case 7: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS+APR_DAYS+MAY_DAYS+JUN_DAYS;
            break;
        case 8: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS+APR_DAYS+MAY_DAYS+JUN_DAYS+JUL_DAYS;
            break;
        case 9: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS+APR_DAYS+MAY_DAYS+JUN_DAYS+JUL_DAYS+AUG_DAYS;
            break;
        case 10: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS+APR_DAYS+MAY_DAYS+JUN_DAYS+JUL_DAYS+AUG_DAYS+SEP_DAYS;
            break;
        case 11: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS+APR_DAYS+MAY_DAYS+JUN_DAYS+JUL_DAYS+AUG_DAYS+SEP_DAYS+OCT_DAYS;
            break;
        case 12: date_monthInDays = JAN_DAYS+FEB_DAYS+MAR_DAYS+APR_DAYS+MAY_DAYS+JUN_DAYS+JUL_DAYS+AUG_DAYS+SEP_DAYS+OCT_DAYS+NOV_DAYS;
            break;
        default: date_monthInDays = 0;
            break;
    }
    if(diffYear < 0){
        return diffYearInDays-date_monthInDays-date->day;
    }
    return diffYearInDays+date_monthInDays+date->day;
}

int myRand(int untereGrenze, int obereGrenze){
    srand((unsigned int)time(0));
    return rand() % (obereGrenze + 1 - untereGrenze) + untereGrenze;
}

Geburtstag *randomGeburtstag(unsigned int len){
    Geburtstag *results;
    results = (Geburtstag*) malloc(sizeof(int) * len);

    return results;
}

void printGeburtstag(Geburtstag *const dates, unsigned int len, int refYear){
    //bislang noch mit mit Vorsicht zu geniessen
    int *alter;
    for (int i = 0; i<=len; i++){
        alter[i]=alterInTagen(dates,refYear);
        if (alter[i]<0){
            printf("Das Alter in Tagen ist: %d", abs(alter[i]));
        }else{
            printf("Das Alter in Tagen ist: %d", alter[i]);
        }
    }
}

//Hilfsfunktion fuer qsort
int compareGeburtstage(const void *geb1, const void *geb2){
    int const year = 1900;
    int alterGeb1;
    int alterGeb2;

    alterGeb1 = abs(alterInTagen(geb1, year));
    alterGeb2 = abs(alterInTagen(geb2, year));

    if (alterGeb1 < alterGeb2){
        return -1;
    }
    else if (alterGeb2 < alterGeb1){
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]){

}
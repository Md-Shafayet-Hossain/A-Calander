#include <stdio.h>
#include <stdlib.h>
int getTheFirstWeakDayOfTheYear(int year){
int day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
return day;
}

int main(){
    system("Color 0F");
    char *month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysInMonth[]={31, 28, 31, 30, 31, 30 , 31 , 31, 30, 31 , 30, 31};
    int i, j, totalDays, weekDay=0, spaceCounter=0, year;

    printf("Enter the year: ");
    scanf("%d", &year);
    printf("\n---------------------%d-------------------", year);
    if(year%4==0 && year%100!=0 || year%400==0){   //Leap year concept
        daysInMonth[1]=29;
    }

    weekDay=getTheFirstWeakDayOfTheYear(year); //Get The First day of the year

    for(i=0;i<12;i++){
        printf("\n\n\n*****************%s******************\n",month[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");

        totalDays= daysInMonth[i];
        for(spaceCounter=1; spaceCounter<=weekDay; spaceCounter++){
            printf("      ");
        }

        for(j=1; j<= totalDays; j++){

            printf("%6d", j);
            weekDay++;
            if(weekDay>6){
                    weekDay=0;
            printf("\n");

            }
        }
    }

    return 0;

}

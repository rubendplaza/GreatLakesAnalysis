#include <stdio.h>
#include <stdlib.h>

void printLake(int lakeNum){

    if(lakeNum == 0){
        printf("Lake Superior ");
    }
    else if(lakeNum == 1){
        printf("Lake Michigan ");
    }
    else if(lakeNum == 2){
        printf("Lake Huron ");
    }
    else if(lakeNum == 3){
        printf("Lake Erie ");
    }
    else if(lakeNum == 4){
        printf("Lake Ontario ");
    }
    else if(lakeNum == 5){
        printf("Lake St.Clair ");
    }
    else{
        printf(" No Such Lake ");
    }

}

int findWarmest(double arr[]){

    double warmestTemp = arr[0];
    int warmest = 0;
    int i;

    for(i = 0; i < 6; i++){

        if(arr[i] > warmestTemp){

            warmestTemp = arr[i];
            warmest = i;

        }

    }

    return warmest;

}

int findColdest(double arr[]){

    double coldestTemp = arr[0];
    int coldest = 0;
    int i;

    for(i = 0; i < 6; i++){

        if(arr[i] < coldestTemp){

            coldestTemp = arr[i];
            coldest = i;

        }

    }

    return coldest;

}

//takes the total average and compares the individual averages to that
void aboveBelowAverage(double arr[], double avgTemp){

    int i;

    for(i = 0; i < 6; i++){

        if(arr[i] > avgTemp){

            printLake(i);
            printf("Is Above The Average Temp Of All Lakes.\n\n");

        }
        else if(arr[i] < avgTemp){

            printLake(i);
            printf("Is Below The Average Temp Of All Lakes.\n\n");

        }
        else{
            printLake(i);
            printf("Is Equal To The Average Temp Of All Lakes.\n\n");
        }

    }

}

//yearly average function
double yearlyAverage(double arr[]){

    double avg = 0;
    double sum = 0;
    int i;

    for(i = 0; i < 365; i++){

        sum += arr[i];

    }

    avg = sum/365;

    return(avg);

}

//compares each array index, looking for the greatest
int findWarmestDay(double arr[]){

    int warmDay;
    int i;
    double warmestTemp = arr[0];

    for(i = 0; i < 365; i++){

        if(arr[i] > warmestTemp){

            warmestTemp = arr[i];
            warmDay = i+1;

        }

    }

    return warmDay;
}

//just does comparisons for each array index
int findColdestDay(double arr[]){

    int coldDay;
    int i;
    double coldestTemp = arr[0];

    for(i = 0; i < 365; i++){

        if(arr[i] < coldestTemp){

            coldestTemp = arr[i];
            coldDay = i+1;

        }

    }

    return coldDay;
}

void printDayDate(int day){

    if(day < 32){
        printf("January, %d", day);
    }
    else if(day < 60){
        printf("February, %d", day-31);
    }
    else if(day < 91){
        printf("March, %d", day-59);
    }
    else if(day < 121){
        printf("April, %d", day-90);
    }
    else if(day < 152){
        printf("May, %d", day-120);
    }
    else if(day < 182){
        printf("June, %d", day-151);
    }
    else if(day < 213){
        printf("July, %d", day-181);
    }
    else if(day < 244){
        printf("August, %d", day-212);
    }
    else if(day < 274){
        printf("September, %d", day-243);
    }
    else if(day < 305){
        printf("October, %d", day-273);
    }
    else if(day < 335){
        printf("November, %d", day-304);
    }
    else if(day < 366){
        printf("December, %d", day-334);
    }

}

//calculates the summer avg temps using array indexes as days
double calculateSummerAverage(double arr[]){

    double sum = 0;
    double avg = 0;
    int i;
    int sumDays = 0;

    for(i = 171; i < 265; i++){

        sum += arr[i];
        sumDays++;

    }

    avg = sum/sumDays;

    return avg;
}

//calculates winter average temps using array indexes as days
double calculateWinterAverage(double arr[]){

    double sum = 0;
    double avg = 0;
    int i;
    int sumDays = 0;

    for(i = 0; i < 365; i++){

        if((i < 79) || (i > 353)){

            sum += arr[i];
            sumDays++;

        }

    }

    avg = sum/sumDays;

    return avg;

}

//sorting an array from greatest to least coldest/warmest
void warmestToColdest(double arr[]){

    int orderOfLakes[] = {0, 1, 2, 3, 4, 5};
    int orderTemp;
    double temp;
    int i;
    int j;

    for(i = 0; i < 6; i++){
        for(j = i + 1; j < 6; j++){

            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                orderTemp = orderOfLakes[i];
                orderOfLakes[i] = orderOfLakes[j];
                orderOfLakes[j] = orderTemp;

            }

        }
    }

    printf("The order of lakes in descending order:\n\n");
    for(i = 0; i < 6; i++){

        printLake(orderOfLakes[i]);
        printf("%5.2lf\n", arr[i]);

    }
    printf("\n");

}

void swimmableDays(double arr[]){

    int i;
    int ctr = 0;

    for(i = 0; i < 365; i++){

        if(arr[i] > 20.0){
            ctr++;
        }

    }

    printf("%d", ctr);

}

void frozenDays(double arr[]){

    int i;
    int ctr = 0;

    for(i = 0; i < 365; i++){

        if(arr[i] < 0.0){
            ctr++;
        }

    }

    printf("%d", ctr);

}

int main()
{

    /*Variables*/
    char ch;
    int year;
    int day;
    int lakeNumber;
    int a;

    /*Calculations*/
    double superiorAvg;
    double michiganAvg;
    double huronAvg;
    double erieAvg;
    double ontarioAvg;
    double stClairAvg;

    double totalAvg;

    int superiorWarmDay;
    int michiganWarmDay;
    int huronWarmDay;
    int erieWarmDay;
    int ontarioWarmDay;
    int stClairWarmDay;

    int superiorColdDay;
    int michiganColdDay;
    int huronColdDay;
    int erieColdDay;
    int ontarioColdDay;
    int stClairColdDay;

    /*Arrays*/
    double superiorArr[365];
    double michiganArr[365];
    double    huronArr[365];
    double     erieArr[365];
    double  ontarioArr[365];
    double  stClairArr[365];

    double yearlyAverageArr[6];

    double warmestWaterTemps[6];
    double coldestWaterTemps[6];

    double summerAvgTemps[6];
    double winterAvgTemps[6];

    double summerWarmestToColdest[6];
    double winterWarmestToColdest[6];

    //START OF PROGRAM
    //Reading in file
    FILE *ptr = fopen("./LakeData.txt", "r");

    if(ptr == NULL){
        printf("FAILED TO OPEN FILE.\n");
    }
    else{
        printf("SUCCESSFULLY OPENED THE FILE.\n");
    }
    printf("20");
    while((ch = getc(ptr)) != EOF){

        for(a = 0; a < 365; a++){

            fscanf(ptr,"%d%d%lf%lf%lf%lf%lf%lf", &year, &day, &superiorArr[a], &michiganArr[a], &huronArr[a], &erieArr[a], &ontarioArr[a], &stClairArr[a]);
            printf("%d %3d %5.2lf %5.2lf %5.2lf %5.2lf %5.2lf %5.2lf\n",  year, day, superiorArr[a], michiganArr[a], huronArr[a], erieArr[a], ontarioArr[a], stClairArr[a]);

        }//for loop for days / index of arrays
    }//while loop

    printf("\n");

    //File closed
    fclose(ptr);

    //Calculates Averages for each lake
    superiorAvg = yearlyAverage(superiorArr);
    michiganAvg = yearlyAverage(michiganArr);
    huronAvg = yearlyAverage(huronArr);
    erieAvg = yearlyAverage(erieArr);
    ontarioAvg = yearlyAverage(ontarioArr);
    stClairAvg = yearlyAverage(stClairArr);

    //Prints out those averages
    printf("Lake Superior Yearly Average Water Temperature: %5.2lf\n\n", superiorAvg);
    printf("Lake Michigan Yearly Average Water Temperature: %5.2lf\n\n", michiganAvg);
    printf("Lake Huron Yearly Average Water Temperature: %5.2lf\n\n", huronAvg);
    printf("Lake Erie Yearly Average Water Temperature: %5.2lf\n\n", erieAvg);
    printf("Lake Ontario Yearly Average Water Temperature: %5.2lf\n\n", ontarioAvg);
    printf("Lake St.Clair Yearly Average Water Temperature: %5.2lf\n\n", stClairAvg);

    //Calculated the average of all lakes
    totalAvg = (superiorAvg+michiganAvg+huronAvg+erieAvg+ontarioAvg+stClairAvg)/6;

    //Prints the total average
    printf("The Total Yearly Average For Every Lake: %5.2lf\n\n", totalAvg);

    //Array of all averages
    yearlyAverageArr[0] = superiorAvg;
    yearlyAverageArr[1] = michiganAvg;
    yearlyAverageArr[2] = huronAvg;
    yearlyAverageArr[3] = erieAvg;
    yearlyAverageArr[4] = ontarioAvg;
    yearlyAverageArr[5] = stClairAvg;

    //Finds the warmest lake
    lakeNumber = findWarmest(yearlyAverageArr);
    printf("The Warmest Lake Is ");
    printLake(lakeNumber);
    printf("\n\n");

    //Finds the coldest lake
    lakeNumber = findColdest(yearlyAverageArr);
    printf("The Coldest Lake Is ");
    printLake(lakeNumber);
    printf("\n\n");

    //Prints the lakes above and below average
    aboveBelowAverage(yearlyAverageArr, totalAvg);

    //gets all the warmest days of each lake
    superiorWarmDay = findWarmestDay(superiorArr);
    michiganWarmDay = findWarmestDay(michiganArr);
    huronWarmDay = findWarmestDay(huronArr);
    erieWarmDay = findWarmestDay(erieArr);
    ontarioWarmDay = findWarmestDay(ontarioArr);
    stClairWarmDay = findWarmestDay(stClairArr);

    printf("The warmest day for Lake Superior is: ");
    printDayDate(superiorWarmDay);
    printf("\n");
    printf("The warmest day for Lake Michigan is: ");
    printDayDate(michiganWarmDay);
    printf("\n");
    printf("The warmest day for Lake Huron is: ");
    printDayDate(huronWarmDay);
    printf("\n");
    printf("The warmest day for Lake Erie is: ");
    printDayDate(erieWarmDay);
    printf("\n");
    printf("The warmest day for Lake Ontario is: ");
    printDayDate(ontarioWarmDay);
    printf("\n");
    printf("The warmest day for Lake St.Clair is: ");
    printDayDate(stClairWarmDay);
    printf("\n");

    //gets all the coldest days of each lake
    superiorColdDay = findColdestDay(superiorArr);
    michiganColdDay = findColdestDay(michiganArr);
    huronColdDay = findColdestDay(huronArr);
    erieColdDay = findColdestDay(erieArr);
    ontarioColdDay = findColdestDay(ontarioArr);
    stClairColdDay = findColdestDay(stClairArr);

    printf("The coldest day for Lake Superior is: ");
    printDayDate(superiorColdDay);
    printf("\n");
    printf("The coldest day for Lake Michigan is: ");
    printDayDate(michiganColdDay);
    printf("\n");
    printf("The coldest day for Lake Huron is: ");
    printDayDate(huronColdDay);
    printf("\n");
    printf("The coldest day for Lake Erie is: ");
    printDayDate(erieColdDay);
    printf("\n");
    printf("The coldest day for Lake Ontario is: ");
    printDayDate(ontarioColdDay);
    printf("\n");
    printf("The coldest day for Lake St.Clair is: ");
    printDayDate(stClairColdDay);
    printf("\n");

    //puts all the warmest temps of each lake into an ordered array
    warmestWaterTemps[0] = superiorArr[superiorWarmDay-1];
    warmestWaterTemps[1] = michiganArr[michiganWarmDay-1];
    warmestWaterTemps[2] = huronArr[huronWarmDay-1];
    warmestWaterTemps[3] = erieArr[erieWarmDay-1];
    warmestWaterTemps[4] = ontarioArr[ontarioWarmDay-1];
    warmestWaterTemps[5] = stClairArr[stClairWarmDay-1];

    //sends all the warmest temps to a function to find the warmest lake
    lakeNumber = findWarmest(warmestWaterTemps);
    printf("The lake with the warmest overall temp is ");
    printLake(lakeNumber);
    printf("\n\n");

    //puts all the coldest temps of each lake into an ordered array
    coldestWaterTemps[0] = superiorArr[superiorColdDay-1];
    coldestWaterTemps[1] = michiganArr[michiganColdDay-1];
    coldestWaterTemps[2] = huronArr[huronColdDay-1];
    coldestWaterTemps[3] = erieArr[erieColdDay-1];
    coldestWaterTemps[4] = ontarioArr[ontarioColdDay-1];
    coldestWaterTemps[5] = stClairArr[stClairColdDay-1];

    //sends all the coldest temps to a function to find the coldest lake
    lakeNumber = findColdest(coldestWaterTemps);
    printf("The lake with the coldest overall temp is ");
    printLake(lakeNumber);
    printf("\n\n");

    //the averages of winter/summer temps for each lake
    printf("The average summer temperature for Lake Superior is %5.2lf degrees\n\n", calculateSummerAverage(superiorArr));
    printf("The average summer temperature for Lake Michigan is %5.2lf degrees\n\n", calculateSummerAverage(michiganArr));
    printf("The average summer temperature for Lake Huron is %5.2lf degrees\n\n", calculateSummerAverage(huronArr));
    printf("The average summer temperature for Lake Erie is %5.2lf degrees\n\n", calculateSummerAverage(erieArr));
    printf("The average summer temperature for Lake Ontario is %5.2lf degrees\n\n", calculateSummerAverage(ontarioArr));
    printf("The average summer temperature for Lake St.Clair is %5.2lf degrees\n\n", calculateSummerAverage(stClairArr));

    printf("The average winter temperature for Lake Superior is %5.2lf degrees\n\n", calculateWinterAverage(superiorArr));
    printf("The average winter temperature for Lake Michigan is %5.2lf degrees\n\n", calculateWinterAverage(michiganArr));
    printf("The average winter temperature for Lake Huron is %5.2lf degrees\n\n", calculateWinterAverage(huronArr));
    printf("The average winter temperature for Lake Erie is %5.2lf degrees\n\n", calculateWinterAverage(erieArr));
    printf("The average winter temperature for Lake Ontario is %5.2lf degrees\n\n", calculateWinterAverage(ontarioArr));
    printf("The average winter temperature for Lake St.Clair is %5.2lf degrees\n\n", calculateWinterAverage(stClairArr));

    //puts the average summer temps of each lake into an ordered array
    summerAvgTemps[0] = calculateSummerAverage(superiorArr);
    summerAvgTemps[1] = calculateSummerAverage(michiganArr);
    summerAvgTemps[2] = calculateSummerAverage(huronArr);
    summerAvgTemps[3] = calculateSummerAverage(erieArr);
    summerAvgTemps[4] = calculateSummerAverage(ontarioArr);
    summerAvgTemps[5] = calculateSummerAverage(stClairArr);

    //puts the average winter temps of each lake into an ordered array
    winterAvgTemps[0] = calculateWinterAverage(superiorArr);
    winterAvgTemps[1] = calculateWinterAverage(michiganArr);
    winterAvgTemps[2] = calculateWinterAverage(huronArr);
    winterAvgTemps[3] = calculateWinterAverage(erieArr);
    winterAvgTemps[4] = calculateWinterAverage(ontarioArr);
    winterAvgTemps[5] = calculateWinterAverage(stClairArr);

    //sends the average summer temps to be put in order from warmest to coldest
    printf("FOR SUMMER AVERAGE TEMPS:\n");
    warmestToColdest(summerAvgTemps);

    //sends the average winter temps to be put in order from warmest to coldest
    printf("FOR WINTER AVERAGE TEMPS:\n");
    warmestToColdest(winterAvgTemps);

    //send the temperatures of each lake into a function that checks for temps > 20
    printf("The number of swimmable days in Lake Superior is: ");
    swimmableDays(superiorArr);
    printf("\n\n");
    printf("The number of swimmable days in Lake Michigan is: ");
    swimmableDays(michiganArr);
    printf("\n\n");
    printf("The number of swimmable days in Lake Huron is: ");
    swimmableDays(huronArr);
    printf("\n\n");
    printf("The number of swimmable days in Lake Erie is: ");
    swimmableDays(erieArr);
    printf("\n\n");
    printf("The number of swimmable days in Lake Ontario is: ");
    swimmableDays(ontarioArr);
    printf("\n\n");
    printf("The number of swimmable days in Lake St.Clair is: ");
    swimmableDays(stClairArr);
    printf("\n\n");

    //sends the temps of each lake into a function that checks for temps < 0
    //SPOILER, they never fall below zero thus never freeze
    printf("The number of frozen days in Lake Superior is: ");
    frozenDays(superiorArr);
    printf("\n\n");
    printf("The number of frozen days in Lake Michigan is: ");
    frozenDays(michiganArr);
    printf("\n\n");
    printf("The number of frozen days in Lake Huron is: ");
    frozenDays(huronArr);
    printf("\n\n");
    printf("The number of frozen days in Lake Erie is: ");
    frozenDays(erieArr);
    printf("\n\n");
    printf("The number of frozen days in Lake Ontario is: ");
    frozenDays(ontarioArr);
    printf("\n\n");
    printf("The number of frozen days in Lake St.Clair is: ");
    frozenDays(stClairArr);
    printf("\n\n");

    //End of program
    return 0;
}

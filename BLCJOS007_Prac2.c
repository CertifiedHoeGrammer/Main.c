#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TITLE "DECIMAL TO RADIX-i CONVERTER"
#define AUTHOR "Joshua Black"
#define YEAR 2022

const char DEC_2_RADIX_MAP[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char* decToRadixI(int decValue, int radValue);
char* appendCharToString(char* originalString, char Character);


int main()
{
printf("*****************************\n");
printf("%s,\n", TITLE);
printf("Written by: %s\n", AUTHOR);
printf("Date: %d\n", YEAR);
printf("*****************************\n");

    int decimalNumber;
    int radixNumber; //declaring variable to store user values
    while(1==1) //infinite loop
    {

        printf("%s","Enter a decimal number: ");
        scanf("%d", &decimalNumber);
        if (decimalNumber < 0)
            {break;} // Exit loop if entered value is below zero
        else
        {printf("The number you have entered is %d\n", decimalNumber);}

        printf("Enter a radix number for the converter between 2 and 16: ");
        scanf("%d", &radixNumber);
       
        if(radixNumber < 0)
        {break;} // Exit loop if radix umber is less than zero

        printf("The radix you have entered %d\n", radixNumber);
        
        float log2Number = log2(decimalNumber); //Get the log 2 of the number
        printf("The log2 of the number is %4.2f\n", log2Number);

        int decOverRadix = decimalNumber/radixNumber;
        printf("The integer result of the number divided by %d is %d \n", radixNumber,decOverRadix);

        int remDecimalOverRemainder = decimalNumber%radixNumber;
        printf("The remainder is %d \n", remDecimalOverRemainder);

        char* radixIValue = decToRadixI(decimalNumber,radixNumber);
        printf("\nThe radix-%d value is %s",radixNumber, radixIValue);
    
        printf("\n");
    }
    printf("EXIT");
    return 0;
}

char* decToRadixI(int decValue, int radValue)
{
char* radixINumber = "";  // declare the variable to store final answer

    if (decValue == 0)
    {
        radixINumber = "0"; //Fail safe for if program functions incorrectly 
        return radixINumber; // Exit the function if an error occurs
    }
    if(decValue < 0)
    {
        radixINumber = "Error! \nDecimal Number should be greater than 0"; // Another fail safe
        return radixINumber; //Exit the function if the error occurs
    }
    if ((radValue <2) || (radValue>16))
    {
        radixINumber = "Error! \nRadix Number should be between 2 and 16"; // Another fail safe
        return radixINumber; //Exit function if error occurs
    }
int quotient = decValue;
int rem;
char radixNumberCharacter;

while(quotient > 0)
    {
        rem = quotient % radValue; //Gets remainder
        quotient = quotient/radValue;
        radixNumberCharacter = DEC_2_RADIX_MAP[rem];
        radixINumber = appendCharToString(radixINumber, radixNumberCharacter);
    }
strrev(radixINumber);
return radixINumber;
}


char* appendCharToString(char* originalString, char Character)
{
    int ogLength = strlen(originalString); // Calculate length of original String
    char* tempString = malloc(ogLength+1); //Temporary String
    tempString[ogLength] = Character; // copy original string into the tempString
    tempString[ogLength+1] = '\0'; // add a null character
    return tempString;
}


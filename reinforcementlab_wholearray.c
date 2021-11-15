//SENG3400
//Reinforcement Lab 1 - C, Arrays, Pipes, Fork
//Bethany Hampton

//below because we're printing stuff to the screen (printf)
#include <stdio.h>

int main()
{
    int numbers[] = { 2, 4, 6, 8, 10};

    //if we don't intiliaze our variables it can pick up a previous value
    int sum = 0;

    //this is telling us the size of the array, how many bits it is
    //size = 16 / 4 = 4 
    int size = sizeof(numbers) / sizeof(int);

    {
        //for loop to iterate through the entire length of the array
        //this is why we set i beginning at one and less than size
        for (int i = 0; i < size; i++)
        {
            //getting the sum of the array
            //this will iterate until given the above parameters until we meet the above conditions
            sum = sum + numbers[i];
        }
        //displaying the result
        printf(" \n-----------OUTPUT-----------\n");
        //getting the average from the sum
        printf("Array average is: %d\n", sum/size);
    }
}
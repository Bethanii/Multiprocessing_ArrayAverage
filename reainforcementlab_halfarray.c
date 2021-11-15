//SENG3400
//Reinforcement Lab 1 - C, Arrays, Pipes, Fork
//Bethany Hampton

//using <stdio.h> allows us to use the print function
#include <stdio.h>
//uni standard has pipe command
#include <unistd.h> 
  
int main()
{
   //location zero and location one
   //we are allocating memory here
   int fd[2], i = 0;

   //we are now passing this memory location into pipe
   //something that someone can read or write to
   //fd[0] = read side of the pipe
   //fd[1] = write side of the pipe
   pipe(fd);

   //Creating a duplicate of the current running process
   int id = fork(); 
   //initializing and setting array
   int numbers[] = {2, 4, 6, 8};
  
   //Get size of the array itself (how many bits it is)
   int size = sizeof(numbers) / sizeof(int);

   //Setting a variable to half of this size
   int half = size/2;

   //PARENT
   if(id > 0)
    {
      //closing standard output
      close(0);
  
      //not using the write end, so closing it
      close(fd[1]); 
  
      //setting the size recieved from child
      int recieved[20];
      
      //the data that is being read from the child is being put at the recieved memory location
      //the last parameter is telling it the size
      int n = read(fd[0], recieved, sizeof(recieved));

      //initializing total
      int total = 0;

       //for loop iterating through the array beginning at half point
        for (int i = half; i < size; i++)
        {
            //getting total
            total = total + numbers[i];
        }

        //average = total number divded by half
        int parentAverage = total/half;

        //getting the average of both halfs from the whole array
        //dividing by two because we are using one number from parent half and one number from child half
        int totalAvg = (recieved[0] + parentAverage)/2;

        //displaying results
        printf(" \n--------------------OUTPUT--------------------\n");
        printf("Parent average of half: %d\n", parentAverage);
        printf("Child average of half: %d\n", recieved[0]);
        printf("Combined average of both halves: %d\n ", totalAvg);
    }
    //CHILD
    else if( id == 0 ) 
    {      
    //intializing total
    int total = 0;

    //for loop iterating through the array beginning at zero going until the half point
    for (int i = 0; i < half; i++)
    {
        //getting total
        total = total + numbers[i];
    } 

    //getting average
    //putting this in array format to sent to parent
    //Will read the value at index 0
    int average[] = {total/half};

    //not using the read end, so closing it
    close(fd[0]); 
  
    //closing standard output
    close(1);    
  
    //duplicating write side
    dup(fd[1]);

    //feeding the pipe characters, pointing to the start of the array in memory
    //right parameter: pass to the right side of the pipe the memory location identified by message array
    //middle parameter: & character does pointing
    //left parameter: how many characters I want to send
    write(1, average, sizeof(average));
  } 
  //signaling if there is a problem
  else 
  {
      printf("Error with the fork()");
      //return back a one if there is an error
      //letting the os know that there was an error and that it couldnt complete
      return 1;
  }
} 
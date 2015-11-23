//create file 
// asks for amount of points to generate and generates numbers from -1000000 to 1000000
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<iostream>

struct Points
{
  int x;
  int y;
};
int main()
{
  std::ofstream out;
 
  srand(time(NULL));
  
  int numpoints;//number of coordinates to generate
  int numgen; // random number
  int sign; // negative or positive
  std::cout<<"Number of points to generate: "<<std::endl;
  std::cin>>numpoints;
  out.open("output.txt");
  Points point[numpoints]; // array of points
   
  for(int i =0; i <numpoints; i++) 
     {
       sign = rand() % 2;   //random sign 0 = -, 1 = +
       numgen = rand() % 1000001;   //rand num between 0 to 1000000
       if (sign == 0)      //generate a number for x
	 {
	   numgen = numgen * -1;
	   point[i].x = numgen;
	 }
       else
	 {
	   point[i].x = numgen;
	 }
       sign = rand() % 2;
       numgen = rand() % 1000001; //generate a number for y
       if (sign == 0)
	 {
	   numgen = numgen * -1;
	   point[i].y = numgen;
	 }
       else
	 {
	   point[i].y = numgen;
	 }
       out<<"{"<<point[i].x<<","<<point[i].y<<"}\n";//output to file {x,y}
     }
  out.close();
   return 0;      
}


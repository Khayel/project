//brute force solution to closest pair prblem
/* get x and ys of a point for each point after it until the end of the fileget its distance ... if it is less then the minimum distance save the points otherwise continue

 */
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<cmath>
struct Points{ //struct of points
  int x;
  int y;
  };

// implementation of distance formula
long distance(int x1, int y1, int x2, int y2)
  
{ return sqrt( pow((x2-x1), 2) + pow((y2-y1),2));}

//gets the x and y from string with structure {x,y} requires c++11 support g++ -std=c++0x for compilation
void getxy(std::string point, int &x, int &y)
{
  int index;   // index of comma seperating x and y coord
  for (int i =0; i < point.length();i++)
    {
      if(point[i+1] == ',')
	{
	  index = i+1;
	  break;
	}
    }
  
  std::string tx = "";
  std::string ty ="";
  for(int i = 1; i <index; i++)   //isolate x and y from curly braces and comma
    {tx = tx + point[i];}
  for(int i  = index+1; i <point.length()-1; i++)
    {ty = ty + point[i];}
  x = std::stoi(tx);   //convert strings to int requires c++11 support
  y = std::stoi(ty);
}

int main() {
 
  long min;  //minimum distance
  int pin = 0;   //iterator for getting inputs
  int x1,y1;   // temporary number holders
  std::string a;   //holder for line of text
  std::ifstream takeinput;
  int pnum;   //number of points
  std::cout<<"Number of points: ";
  std::cin>>pnum;
  Points p[pnum];   //stores points
  std::string filename = "output" + static_cast<std::ostringstream*>( &(std::ostringstream() << pnum))->str() + ".txt";
  
  takeinput.open(filename.c_str());
  while(takeinput>>a)   //take a line of input until the no more can be taken get x and yvalues and place them in the pnum array;
    {
 
 
      getxy(a,x1,y1);
      p[pin].x = x1;
      p[pin].y = y1;
      pin++;
    }
  
    takeinput.close();
    Points minp1,minp2;
    min = distance(p[0].x,p[0].y,p[1].x,p[1].y);
    //check the points for distance
    for(int i = 0; i <pnum; i++)
      {
	for(int j = i+1; j<pnum; j++)
	  {
	    if (distance(p[i].x,p[i].y,p[j].x,p[j].y) < min)
	      {
		std::cout<<"New closestpair";
		min = distance(p[i].x,p[i].y,p[j].x,p[j].y);
		std::cout<<min;
		minp1 = p[i];
		minp2 = p[j];
	      }
	  }
      }
    std::cout<<"{"<<minp1.x<<","<<minp1.y<<"} and {"<<minp2.x<<','<<minp2.y<<"} are the closest pair with distance: "<<min<<std::endl;
	  
    return 0;
}

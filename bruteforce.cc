//brute force solution to closest pair prblem
/* get x and ys of a point for each point after it until the end of the fileget its distance ... if it is less then the minimum distance save the points otherwise continue

 */
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
void getxy(std::string point, int &x, int &y)
{
  int index;// index of comma
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
  for(int i = 1; i <index; i++)
    {tx = tx + point[i];}
  for(int i  = index+1; i <point.length()-1; i++)
    {ty = ty + point[i];}
  
  std::cout<<tx<<std::endl<<ty;
   x = atoi(tx);
  //y = atoi(ty);
};
int main() {
  int min;
  int x1,x2,y1,y2;
  std::string a;
  std::ifstream takeinput;
  takeinput.open("output.txt");
  //while(takeinput>>a)
  // {
  takeinput>>a;
     getxy(a,x1,y1);
     //  std::cout<<x1<<y1;
  
     //  }
  return 0;
}

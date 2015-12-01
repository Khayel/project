//divide and conquer solution to closest pair problem

//distance between two points
// d= squareroot( x2-x1)^2  + (y2-y1)^2 )
//algo
/*
vector<Point> s1     divide points into  all coords with +x(s1) and -x(s2)
vector<Point> s2
for each x in file input do
  if (file input == positive)
     place in s2
  if(file input == negative
     place in s1
recursively-- get minimum distance

find min dist in s1 and s2

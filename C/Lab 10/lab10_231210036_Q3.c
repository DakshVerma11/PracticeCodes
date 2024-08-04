/*Write a program to enter to Cartesian coordinate points and display the Euclidean distance between them using structure pointer function concept .
Code by - Daksh Verma 
Roll No - 231210036*/

#include <stdio.h>
#include<math.h>

typedef struct Point {
  float x;
  float y;
} Point;

double dist(Point *p1, Point *p2) {
  double dx = ((double)p1->x - (double)p2->x);
  double dy = ((double)p1->y - (double)p2->y);
  return sqrt(dx*dx + dy*dy);
}

int main() {
  Point p1, p2;

  printf("Enter the coordinates of the first point(seperated by a space): ");
  scanf("%f %f", &p1.x, &p1.y);

  printf("Enter the coordinates of the second point (seperated by a space): ");
  scanf("%f %f", &p2.x, &p2.y);

  double distance = dist(&p1, &p2);
  printf("The Euclidean distance between the two points is: %f units\n", distance);

  return 0;
}


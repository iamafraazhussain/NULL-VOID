#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct
{
    int xCoordinate, yCoordinate;
} Point;



int orientation(Point p, Point q, Point r)
{
    int value = (q.yCoordinate - p.yCoordinate) * (r.xCoordinate - q.xCoordinate) - (q.xCoordinate - p.xCoordinate) * (r.yCoordinate - q.yCoordinate);
    
    // For co-linear points
    if (value == 0) return 0;

    // For clockwise pairs
    else if (value > 0) return 1;

    // For counter-clockwise pairs
    else return 2;
}

int comparePoints(const void* vp1, const void* vp2)
{
    Point* pointOne = (Point*)vp1;
    Point* pointTwo = (Point*)vp2;
    int currentOrientation = orientation((Point){0, 0}, *pointOne, *pointTwo);
    if (currentOrientation == 0)
    {
        int distanceOne = pointOne -> xCoordinate * pointOne -> xCoordinate + pointOne -> yCoordinate * pointOne -> yCoordinate;
        int distanceTwo = pointTwo -> xCoordinate * pointTwo -> xCoordinate + pointTwo -> yCoordinate * pointTwo -> yCoordinate;
        return distanceOne - distanceTwo;
    }
    else return (currentOrientation == 2) ? -1 : 1;
}

void printConvexHull(Point* points, int numberOfPoints)
{
    // When there aren't enough ponts for a convex hull
    if (numberOfPoints < 3) return;

    qsort(points, numberOfPoints, sizeof(Point), comparePoints);

    int hull[numberOfPoints];
    int top = 2;
    hull[0] = 0;
    hull[1] = 1;
    for (int index = 2; index < numberOfPoints; index++)
    {
        while (top > 0 && orientation(points[hull[top - 1]], points[hull[top]], points[index]) != 2) top--;
        hull[++top] = index;
    }

    printf("Smallest convex polygon: ");
    for (int index = 0; index <= top; index++) printf("(%d, %d) ", points[hull[index]].xCoordinate, points[hull[index]].yCoordinate);
    printf("\n");
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int numberOfPoints, index;
    printf("Enter the number of points: ");
    scanf("%d", &numberOfPoints);

    Point* points = malloc(numberOfPoints * sizeof(Point));
    for (index = 0; index < numberOfPoints; index++)
    {
        printf("Enter the coordinates of point %d: ", index + 1);
        scanf("%d %d", &points[index].xCoordinate, &points[index].yCoordinate);
    }

    printConvexHull(points, numberOfPoints);

    free(points);
    return 0;
}

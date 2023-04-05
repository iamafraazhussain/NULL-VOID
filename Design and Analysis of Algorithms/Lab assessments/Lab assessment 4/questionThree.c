#include <stdio.h>
#include <stdlib.h>



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

void printConvexHull(Point* points, int numberOfPoints)
{    
    // When there aren't enough ponts for a convex hull
    if (numberOfPoints < 3) return;

    int* hull = malloc(numberOfPoints * sizeof(int));
    int leftmost = 0;
    for (int index = 1; index < numberOfPoints; index++)  if (points[index].xCoordinate < points[leftmost].xCoordinate) leftmost = index;

    int p = leftmost, q;
    int index = 0;
    do
    {
        hull[index++] = p;
        q = (p + 1) % numberOfPoints;
        for (int secondaryIndex = 0; secondaryIndex < numberOfPoints; secondaryIndex++) if (orientation(points[p], points[secondaryIndex], points[q]) == 2) q = secondaryIndex;
        p = q;
    }
    while (p != leftmost);

    printf("\nSmallest convex polygon: ");
    for (int index = 0; index < numberOfPoints; index++)
    {
        int secondaryIndex = hull[index];
        printf("(%d, %d) ", points[secondaryIndex].xCoordinate, points[secondaryIndex].yCoordinate);
    }
    printf("\n");

    free(hull);
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int numberOfPoints;
    printf("Enter the number of points: ");
    scanf("%d", &numberOfPoints);

    Point* points = malloc(numberOfPoints * sizeof(Point));
    for (int index = 0; index < numberOfPoints; index++)
    {
        printf("Enter the coordinates of point %d: ", index + 1);
        scanf("%d %d", &points[index].xCoordinate, &points[index].yCoordinate);
    }

    printConvexHull(points, numberOfPoints);

    free(points);
    return 0;
}

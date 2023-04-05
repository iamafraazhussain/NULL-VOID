#include<stdio.h>
 



int costMatrix[10][10], visitedNode[10], numberOfCities, cost = 0;
 
void travellingSalesmanProblem()
{
    int index, secondryIndex;
    
    printf("Enter the number of cities: ");
    scanf("%d", &numberOfCities);
    
    printf("\nEnter the cost matrix...\n");
    
    for(index = 0; index < numberOfCities; index++)
    {
        printf("Enter the cost from city %d to other cities: ", index + 1);
        
        for( secondryIndex = 0; secondryIndex < numberOfCities; secondryIndex++) scanf(" %d", &costMatrix[index][secondryIndex]);
        
        visitedNode[index] = 0;
    }
}
 
void minimumCost(int city)
{
    int index, cityID;
    
    visitedNode[city] = 1;
    
    printf("%d -> ", city + 1);
    cityID = least(city);
    
    if(cityID == 999)
    {
        cityID = 0;
        cost += costMatrix[city][cityID];
        return;
    }
    
    minimumCost(cityID);
}
 
int least(int number)
{
    int index, newCity = 999, minimumValue = 999, kMinimumValue;
    
    for(index = 0; index < numberOfCities; index++)
    {
        if((costMatrix[number][index] != 0) && (visitedNode[index] == 0))
        if(costMatrix[number][index] + costMatrix[index][number] < minimumValue)
        {
            minimumValue = costMatrix[index][0] + costMatrix[number][index];
            kMinimumValue = costMatrix[number][index];
            newCity = index;
        }
    }
    
    if(minimumValue != 999) cost += kMinimumValue;
    
    return newCity;
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");
    
    travellingSalesmanProblem();
    
    printf("\n\nThe Path is:\n");
    minimumCost(0);
    
    printf("\nThe minimum cost to travel all the cities was calculated to be: %d", cost);
    
    return 0;
}
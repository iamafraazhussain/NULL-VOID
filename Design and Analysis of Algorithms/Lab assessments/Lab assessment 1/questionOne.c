#include <stdio.h>



struct studentDetails
{
    int studentID, studentScore;
};

void main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int studentCount, highestScore, lowestScore, highestScoreStudent, lowestScoreStudent;

    printf("Enter the total number of students: ");
    scanf("%d", &studentCount);
    printf("\n");
    struct studentDetails studentDetail[studentCount];

    for (int index = 0; index < studentCount; index++)
    {
        studentDetail[index].studentID = index + 1;
        printf("Enter the score of student %d: ", index + 1);
        scanf("%d", &studentDetail[index].studentScore);
    }

    highestScore = studentDetail[0].studentScore;
    highestScoreStudent = studentDetail[0].studentID;
    lowestScore = studentDetail[0].studentScore;
    lowestScoreStudent = studentDetail[0].studentID;
    for (int index = 0; index < studentCount; index++)
    {
        if (studentDetail[index].studentScore > highestScore)
        {
            highestScore = studentDetail[index].studentScore;
            highestScoreStudent = studentDetail[index].studentID;
        }
        if (studentDetail[index].studentScore < lowestScore)
        {
            lowestScore = studentDetail[index].studentScore;
            lowestScoreStudent = studentDetail[index].studentID;
        }
    }

    printf("\nThe highest score was %d by student %d", highestScore, highestScoreStudent);
    printf("\nThe lowest score was %d by student %d", lowestScore, lowestScoreStudent);
}
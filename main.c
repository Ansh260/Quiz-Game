#include <stdio.h>
#include <string.h>

int login()
{
    char username[] = "admin";
    char password[] = "123";

    char inputUsername[100];
    char inputPassword[100];

    printf("Hello!\n");
    printf("Enter your Username: ");
    scanf("%s", &inputUsername);

    printf("Enter your Password: ");
    scanf("%s", &inputPassword);

    if (!strcmp(username, inputUsername) && !strcmp(password, inputPassword))
    {
        printf("Login Succesful\n\n");
        return 1;
    }
    printf("Login Failed!\n");
    return 0;
}

int questions()
{

    int numberOfQuestions = 5;
    int score = 0;
    int inputAnswer;

    typedef struct question
    {
        int questionid;
        char question[1000];
        char option1[200];
        char option2[200];
        char option3[200];
        char option4[200];
        int answer;
    } Quiz;

    Quiz Sports[numberOfQuestions];
    strcpy(Sports[0].question, " Best Player in the world");
    strcpy(Sports[0].option1, "AB Devilliers");
    strcpy(Sports[0].option2, "Virat");
    strcpy(Sports[0].option3, "Sachin");
    strcpy(Sports[0].option4, "Dravid");
    Sports[0].answer = 2;

    strcpy(Sports[1].question, " Most Popular Sport in the world");
    strcpy(Sports[1].option1, "Football");
    strcpy(Sports[1].option2, "Cricket");
    strcpy(Sports[1].option3, "Basketball");
    strcpy(Sports[1].option4, "Rugby");
    Sports[1].answer = 1;

    for (int i = 0; i < numberOfQuestions; i++)
    {

        printf("Question %d : %s\n", i+1,Sports[i].question);
        printf("Option 1 : %s\n", Sports[i].option1);
        printf("Option 2 : %s\n", Sports[i].option2);
        printf("Option 3 : %s\n", Sports[i].option3);
        printf("Option 4 : %s\n \n", Sports[i].option4);
        printf("Enter answer: ");
        scanf("%d", &inputAnswer);
        if (inputAnswer == Sports[i].answer)
        {
            printf("Correct Answer! :) \n \n");
            score++;
        }
        else
        {
            printf("Incorrect Answer :( \n \n");
            score--;
        }
    }
    printf("Your Scorecard: %d \n",score);
}

int main()
{
    if (login())
    {
        printf("Select your Field Of Interest: \n");
        int length = 5;
        char fieldOfInterest[5][100] = {"Sports", "Entertainment", "Spirituality", "Technology", "Finance"};
        for (int i = 0; i < length; i++)
        {
            printf("%d->%s\n", i + 1, fieldOfInterest[i]);
        }printf("\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        printf("Hello! Welcome to your quiz on the topic of %s!\n \n", fieldOfInterest[choice - 1]);
        questions();
    }
    return 0;
}
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

    strcpy(Sports[2].question, "Who won the 10th Italian Open title in 2021?");
    strcpy(Sports[2].option1, "Novack Djokovic");
    strcpy(Sports[2].option2, "Rafael Nadal");
    strcpy(Sports[2].option3, "Dominic Thiem");
    strcpy(Sports[2].option4, "Stefanos Tsitsipas");
    Sports[2].answer = 2;

    strcpy(Sports[3].question, "In cricket which of the following fielding positions is behind the batsman?");
    strcpy(Sports[3].option1, "Mid-wicket");
    strcpy(Sports[3].option2, "First slip");
    strcpy(Sports[3].option3, "Cover");
    strcpy(Sports[3].option4, "Mid-off");
    Sports[3].answer = 2;

    strcpy(Sports[4].question, "Neeraj Chopra won India’s first-ever Olympic Gold Medal in which of the following sports?");
    strcpy(Sports[4].option1, "400m Hurdle");
    strcpy(Sports[4].option2, "Javelin throw");
    strcpy(Sports[4].option3, "Long Jump");
    strcpy(Sports[4].option4, "High Jump");
    Sports[4].answer = 2;

    Quiz Entertainment[numberOfQuestions];
    strcpy(Entertainment[0].question, "Who among the followings has been awarded the best director award by the Dadasaheb Phalke International Film Festival Awards 2022?");
    strcpy(Entertainment[0].option1, "Ken Ghosh");
    strcpy(Entertainment[0].option2, "Vishal Bharadwarj");
    strcpy(Entertainment[0].option3, "Anurag Kashyap");
    strcpy(Entertainment[0].option4, "S.S.Raja Mauli");
    Entertainment[0].answer = 2;

    strcpy(Entertainment[1].question, "Which of the following has bagged the ‘Best International Film’ award at the 6th Hollywood Critics Association (HCA) Film Awards?");
    strcpy(Entertainment[1].option1, "RRR");
    strcpy(Entertainment[1].option2, "KGF Chapter 2");
    strcpy(Entertainment[1].option3, "Pushpa:The Rise");
    strcpy(Entertainment[1].option4, "Brahmastra");
    Entertainment[1].answer = 2;

    strcpy(Entertainment[2].question, "Which album has won the 'Album of the Year' Grammy award 2022?");
    strcpy(Entertainment[2].option1, "We Are");
    strcpy(Entertainment[2].option2, "My Love");
    strcpy(Entertainment[2].option3, "Help Yourself");
    strcpy(Entertainment[2].option4, "This Time Tomorrow");
    Entertainment[2].answer = 2;

    strcpy(Entertainment[3].question, "Which of the following song has won the Best original song award at Oscar 2023?");
    strcpy(Entertainment[3].option1, "Naacho Naacho");
    strcpy(Entertainment[3].option2, "Yaara Teri Meri Yaari");
    strcpy(Entertainment[3].option3, "Neendraan Ni Aandiyaa");
    strcpy(Entertainment[3].option4, "Naatu Naatu");
    Entertainment[3].answer = 2;

    strcpy(Entertainment[4].question, "Who won the Best Playback Singer at the 2024 Filmfare Awards in the male and female categories?");
    strcpy(Entertainment[4].option1, "Bhupinder Babbal and Shilpa Rao");
    strcpy(Entertainment[4].option2, "Arjit Singh and Shilpa Rao");
    strcpy(Entertainment[4].option3, "Sonu Nigam and Shreya Ghoshal");
    strcpy(Entertainment[4].option4, "Bhupinder Babbal and Shreya Ghoshal");
    Entertainment[4].answer = 2;

    Quiz Spirituality[numberOfQuestions];
    strcpy(Spirituality[0].question, "Bhagavad Gita was spoken. -years ago by Lord Krishna");
    strcpy(Spirituality[0].option1, "5000");
    strcpy(Spirituality[0].option2, "500");
    strcpy(Spirituality[0].option3, "200");
    strcpy(Spirituality[0].option4, "50000");
    Spirituality[0].answer = 1;

    strcpy(Spirituality[1].question, "There are verses in Bhagavad Gita:");
    strcpy(Spirituality[1].option1, "7000");
    strcpy(Spirituality[1].option2, "1800");
    strcpy(Spirituality[1].option3, "700");
    strcpy(Spirituality[1].option4, "108");
    Spirituality[1].answer = 3;

    strcpy(Spirituality[2].question, "Number of Chapters in Bhagavad Gita:");
    strcpy(Spirituality[2].option1, "77");
    strcpy(Spirituality[2].option2, "18");
    strcpy(Spirituality[2].option3, "70");
    strcpy(Spirituality[2].option4, "108");
    Spirituality[2].answer = 2;

    strcpy(Spirituality[3].question, "Bhagavad Gita was spoken at the battlefield of:");
    strcpy(Spirituality[3].option1, "Hiroshima Nagasaki");
    strcpy(Spirituality[3].option2, "Kurukshetra");
    strcpy(Spirituality[3].option3, "Lanka");
    strcpy(Spirituality[3].option4, "Vrindawan");
    Spirituality[3].answer = 2;

    strcpy(Spirituality[4].question, "Bhagavad Gita is also known as:");
    strcpy(Spirituality[4].option1, "GitoPaveda");
    strcpy(Spirituality[4].option2, "Upnisad Gita");
    strcpy(Spirituality[4].option3, "Gitopanisad");
    strcpy(Spirituality[4].option4, "Holy Book");
    Spirituality[4].answer = 3;

    Quiz Technology[numberOfQuestions];
    strcpy(Technology[0].question, "What is part of a database that holds only one type of information?");
    strcpy(Technology[0].option1, "Report");
    strcpy(Technology[0].option2, "Field");
    strcpy(Technology[0].option3, "Recond");
    strcpy(Technology[0].option4, "File");
    Technology[0].answer = 1;

    strcpy(Technology[1].question, "Most modern TV's draw power even if turned off. The circuit the power is used in does what function?");
    strcpy(Technology[1].option1, "Sound");
    strcpy(Technology[1].option2, "Remote contro");
    strcpy(Technology[1].option3, "Color balance");
    strcpy(Technology[1].option4, "High voltage");
    Technology[1].answer = 1;

    strcpy(Technology[2].question, "Which is a type of Electrically-Erasable Programmable Read-Only Memory?");
    strcpy(Technology[2].option1, "Flash");
    strcpy(Technology[2].option2, "Flange");
    strcpy(Technology[2].option3, "Fury");
    strcpy(Technology[2].option4, "Fram");
    Technology[2].answer = 1;

    strcpy(Technology[3].question, "The most common format for a home video recorder is VHS. VHS stands for...?");
    strcpy(Technology[3].option1, "Video Home System");
    strcpy(Technology[3].option2, "Very high speed");
    strcpy(Technology[3].option3, "Video horizontal standard");
    strcpy(Technology[3].option4, "Voltage house standard");
    Technology[3].answer = 1;

    strcpy(Technology[4].question, "Programming a robot by physically moving it through the trajectory you want it to follow is called:");
    strcpy(Technology[4].option1, "contact sensing control");
    strcpy(Technology[4].option2, "continous-path control");
    strcpy(Technology[4].option3, "robot vision control");
    strcpy(Technology[4].option4, "pick-and-place control");
    Technology[4].answer = 1;

    Quiz Finance[numberOfQuestions];
    strcpy(Finance[0].question, "Which of the following is not a direct tax?");
    strcpy(Finance[0].option1, "Sales tax");
    strcpy(Finance[0].option2, "Income tax");
    strcpy(Finance[0].option3, "Wealth tax");
    strcpy(Finance[0].option4, "Estate duty");
    Finance[0].answer = 1;

    strcpy(Finance[1].question, "The Indian economy is");
    strcpy(Finance[1].option1, "capitalist");
    strcpy(Finance[1].option2, "socialistic");
    strcpy(Finance[1].option3, "Mixed");
    strcpy(Finance[1].option4, "Federal");
    Finance[1].answer = 1;

    strcpy(Finance[2].question, "The economic liberalization was introduced in");
    strcpy(Finance[2].option1, "1991");
    strcpy(Finance[2].option2, "1990");
    strcpy(Finance[2].option3, "1985");
    strcpy(Finance[2].option4, "1988");
    Finance[2].answer = 1;

    strcpy(Finance[3].question, "The National Stock Exchange (NSE) is located at");
    strcpy(Finance[3].option1, "Mumbai");
    strcpy(Finance[3].option2, "New Delhi");
    strcpy(Finance[3].option3, "Madras");
    strcpy(Finance[3].option4, "Calcutta");
    Finance[3].answer = 1;

    strcpy(Finance[4].question, "Development means economic growth with");
    strcpy(Finance[4].option1, "price stability");
    strcpy(Finance[4].option2, "social change");
    strcpy(Finance[4].option3, "inflation");
    strcpy(Finance[4].option4, "deflation");
    Finance[4].answer = 1;


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

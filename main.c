#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define QUESTIONS_FILE "questions.csv"
#define MAX_CATEGORY_LENGTH 200
#define MAX_QUESTION_LENGTH 1000
#define MAX_OPTION_LENGTH 200
#define MAX_LINE_LENGTH 1024

typedef struct Question
{
    char category[MAX_CATEGORY_LENGTH];
    int id;
    char question[MAX_QUESTION_LENGTH];
    char option1[MAX_OPTION_LENGTH];
    char option2[MAX_OPTION_LENGTH];
    char option3[MAX_OPTION_LENGTH];
    char option4[MAX_OPTION_LENGTH];
    int answer;
} question;

question *Questions = NULL;
char (*fieldOfInterest)[MAX_CATEGORY_LENGTH] = NULL;
int MAX_QUESTIONS = 0;
int MAX_CATEGORIES = 0;

void loadQuestions();
void selectCategory();
void displayQuestions(char *selectedCategory);
void clearScreen();
void delay(int number_of_seconds);
int countLinesInCSV(const char *filename);
void loadCategoriesFromFile(const char *filename);

int main()
{
    clearScreen();
    MAX_QUESTIONS = countLinesInCSV(QUESTIONS_FILE) - 1;
    if (MAX_QUESTIONS > 0)
    {
        Questions = malloc(sizeof(question) * MAX_QUESTIONS);
        loadCategoriesFromFile(QUESTIONS_FILE);
        loadQuestions();
        selectCategory();
        free(Questions);
        free(fieldOfInterest);
    }
    else
    {
        printf("No questions found in the file.");
    }
    delay(3000);
    return 0;
}

void loadQuestions()
{
    FILE *file = fopen(QUESTIONS_FILE, "r");
    if (file == NULL)
    {
        printf("File could not be opened.");
        return;
    }
    char buffer[MAX_LINE_LENGTH];

    fgets(buffer, MAX_LINE_LENGTH, file);

    for (int line_count = 0; line_count < MAX_QUESTIONS; line_count++)
    {
        if (fgets(buffer, MAX_LINE_LENGTH, file))
        {
            buffer[strcspn(buffer, "\n")] = '\0';
            char *category = strtok(buffer, ",");
            char *id_str = strtok(NULL, ",");
            char *questionText = strtok(NULL, ",");
            char *option1 = strtok(NULL, ",");
            char *option2 = strtok(NULL, ",");
            char *option3 = strtok(NULL, ",");
            char *option4 = strtok(NULL, ",");
            char *answer_str = strtok(NULL, ",");

            int id = atoi(id_str);
            int answer = atoi(answer_str);

            strncpy(Questions[line_count].category, category, MAX_CATEGORY_LENGTH - 1);
            Questions[line_count].category[MAX_QUESTION_LENGTH - 1] = '\0';
            strncpy(Questions[line_count].question, questionText, MAX_QUESTION_LENGTH - 1);
            Questions[line_count].question[MAX_QUESTION_LENGTH - 1] = '\0';
            strncpy(Questions[line_count].option1, option1, MAX_OPTION_LENGTH - 1);
            Questions[line_count].option1[MAX_OPTION_LENGTH - 1] = '\0';
            strncpy(Questions[line_count].option2, option2, MAX_OPTION_LENGTH - 1);
            Questions[line_count].option2[MAX_OPTION_LENGTH - 1] = '\0';
            strncpy(Questions[line_count].option3, option3, MAX_OPTION_LENGTH - 1);
            Questions[line_count].option3[MAX_OPTION_LENGTH - 1] = '\0';
            strncpy(Questions[line_count].option4, option4, MAX_OPTION_LENGTH - 1);
            Questions[line_count].option4[MAX_OPTION_LENGTH - 1] = '\0';

            Questions[line_count].id = id;
            Questions[line_count].answer = answer;
        }
        else
        {
            printf("Error: Unexpected end of file.");
            break;
        }
    }
    fclose(file);
}

void selectCategory()
{
    printf("Select your Field of Interest\n\n");
    for (int i = 0; i < MAX_CATEGORIES; i++)
    {
        printf("%d) \x1B[33m%s\x1B[0m\n\n", i + 1, fieldOfInterest[i]);
    }

    int choice;
    printf("Enter your choice (1-%d): ", MAX_CATEGORIES);
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    if (choice < 1 || choice > MAX_CATEGORIES)
    {
        printf("Invalid choice. Exiting.\n");
        return;
    }

    int flag = 0;
    printf("\nHello! Welcome to your quiz on the topic of \x1B[33m%s\x1B[0m!\n\n", fieldOfInterest[choice - 1]);
    printf("Enter 1 to start! \n\n");

    while (flag != 1)
    {
        scanf("%d", &flag);
        if (flag == 1)
        {
            clearScreen();

            printf("Starting in \x1B[33m3\x1B[0m...");
            delay(1000);
            clearScreen();
            printf("Starting in \x1B[33m2\x1B[0m...");
            delay(1000);
            clearScreen();
            printf("Starting in \x1B[33m1\x1B[0m...");
            delay(500);
            clearScreen();
            displayQuestions(fieldOfInterest[choice - 1]);
        }
    }
}

void displayQuestions(char selectedCategory[])
{
    int score = 0;
    int inputAnswer;
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        if (strcmp(selectedCategory, Questions[i].category) == 0)
        {
            printf("Question ID: \033[0;36m%d\033[0m", Questions[i].id);
            printf("                                   Current Score: \033[38;2;150;255;150m%d\033[0m\n", score);
            printf("Category: \x1B[33m%s\x1B[0m\n\n", Questions[i].category);
            printf("Question: %s\n\n", Questions[i].question);
            printf("Options:\n\n 1. %s\n\n 2. %s\n\n 3. %s\n\n 4. %s\n\n", Questions[i].option1, Questions[i].option2, Questions[i].option3, Questions[i].option4);
            printf("Enter answer (1-4) or 0 to skip: ");
            scanf("%d", &inputAnswer);
            if (inputAnswer == Questions[i].answer)
            {
                printf("\x1B[32mCorrect! :) \x1B[0m\n\n");
                score += 4;
            }
            else if (inputAnswer == 0)
            {
                printf("Skipped.\n\n");
            }
            else
            {
                printf("\x1B[31;1mIncorrect :< \x1B[0m\n\n");
                score--;
            }
            delay(700);
            clearScreen();
        }
    }
    if (score > 0)
    {
        printf("%s", "Quiz Completed!\n\n");
        printf("Your Score: \x1B[32m%d\x1B[0m\n\n", score);
    }
    else
    {
        printf("%s", "Quiz Completed!\n\n");
        printf("Your Score: \x1B[31;1;1m%d\x1B[0m\n\n", score);
    }
}

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\x1B[1;1H\x1B[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, strlen(CLEAR_SCREEN_ANSI));
}

void delay(int milli_seconds)
{
    struct timespec ts;
    ts.tv_sec = milli_seconds / 1000;
    ts.tv_nsec = (milli_seconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

int countLinesInCSV(const char *filename)
{
    int lines = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return 0;
    }
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file))
    {
        lines++;
    }
    fclose(file);
    return lines;
}

void loadCategoriesFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File could not be opened.");
        return;
    }
    char buffer[MAX_LINE_LENGTH];
    char categories[MAX_QUESTIONS][MAX_CATEGORY_LENGTH];
    MAX_CATEGORIES = 0;
    fgets(buffer, MAX_LINE_LENGTH, file);
    while (fgets(buffer, MAX_LINE_LENGTH, file))
    {
        char *category = strtok(buffer, ",");

        int exists = 0;
        for (int i = 0; i < MAX_CATEGORIES; i++)
        {
            if (strcmp(categories[i], category) == 0)
            {
                exists = 1;
                break;
            }
        }
        if (!exists)
        {
            strncpy(categories[MAX_CATEGORIES], category, MAX_CATEGORY_LENGTH - 1);
            categories[MAX_CATEGORIES][MAX_CATEGORY_LENGTH - 1] = '\0';
            MAX_CATEGORIES++;
        }
    }

    fieldOfInterest = malloc(MAX_CATEGORIES * sizeof(*fieldOfInterest));
    for (int i = 0; i < MAX_CATEGORIES; i++)
    {
        strncpy(fieldOfInterest[i], categories[i], MAX_CATEGORY_LENGTH);
    }
    fclose(file);
}

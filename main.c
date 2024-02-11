#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define QUESTIONS_FILE "questions.csv"

#define MAX_QUESTIONS 25   // Change this if more questions are added.
#define MAX_CATEGORY_LENGTH 200
#define MAX_QUESTION_LENGTH 1000
#define MAX_OPTION_LENGTH 200
#define MAX_LINE_LENGTH 1024
#define MAX_CATEGORIES 5   // Change this if another category is added. Also include the category in the fieldOfInterest array.


typedef struct Question {
    char category[MAX_CATEGORY_LENGTH];
    int id;
    char question[MAX_QUESTION_LENGTH];
    char option1[MAX_OPTION_LENGTH];
    char option2[MAX_OPTION_LENGTH];
    char option3[MAX_OPTION_LENGTH];
    char option4[MAX_OPTION_LENGTH];
    int answer;
} question;

question Questions[MAX_QUESTIONS];
char fieldOfInterest[MAX_CATEGORIES][MAX_CATEGORY_LENGTH] = {"Sports", "Entertainment", "Spirituality", "Technology", "Finance"};

void loadQuestions();
void selectCategory();
void displayQuestions(char *selectedCategory);
void clearScreen();
void delay(int number_of_seconds);

 int main() {
    loadQuestions();
    selectCategory();
    return 0;
}

void loadQuestions() {
    FILE *file = fopen(QUESTIONS_FILE, "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return;
    }
    int line_count = 0;
    char buffer[MAX_LINE_LENGTH];

    fgets(buffer, MAX_LINE_LENGTH, file);
    while (fgets(buffer, MAX_LINE_LENGTH, file) && line_count < MAX_QUESTIONS) {
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
        Questions[line_count].category[MAX_CATEGORY_LENGTH - 1] = '\0';
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

        line_count++;
    }
    fclose(file);
}

void selectCategory() {
    printf("Select your Field Of Interest: \n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("%d->%s\n", i + 1, fieldOfInterest[i]);
    }
    printf("\n");

    int choice;
    printf("Enter your choice (1-5): ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return;
    }

    if (choice < 1 || choice > MAX_CATEGORIES) {
        printf("Invalid choice. Exiting.\n");
        return;
    }

    printf("\nHello! Welcome to your quiz on the topic of %s!\n\n", fieldOfInterest[choice - 1]);
    
    delay(1000);
    clearScreen();
    printf("Starting in 3...");
    delay(1000);
    clearScreen();
    printf("Starting in 2...");
    delay(1000);
    clearScreen();
    printf("Starting in 1...");
    delay(500);
    clearScreen();
    displayQuestions(fieldOfInterest[choice - 1]);
}

void displayQuestions(char selectedCategory[]) {
    int score = 0;
    int inputAnswer;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (strcmp(selectedCategory, Questions[i].category) == 0) {
            printf("Question ID: %d", Questions[i].id);
            printf("                                   Current Score: %d\n\n",score);
            printf("Category: %s\n", Questions[i].category);
            printf("Question: %s\n", Questions[i].question);
            printf("Options:\n 1. %s\n 2. %s\n 3. %s\n 4. %s\n", Questions[i].option1, Questions[i].option2, Questions[i].option3, Questions[i].option4);
            printf("Enter answer (1-4) or 0 to skip: ");
            scanf("%d", &inputAnswer);
            if (inputAnswer == Questions[i].answer) {
                printf("Correct!\n\n");
                score += 4;
            }
            else if (inputAnswer == 0) {
                printf("Skipped.\n\n");
                continue;
            }
            else {
                printf("Incorrect :(\n\n");
                score -= 1;
            }
            delay(700);
            clearScreen();
        }
    }
    printf("Your Score: %d\n\n", score);
}

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\x1b[1;1H\x1b[2J";
  ssize_t bytes_written = write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, strlen(CLEAR_SCREEN_ANSI));

  if (bytes_written == -1) {
    perror("Failed to clear screen");
  }
}

void delay(int milli_seconds)
{
    struct timespec ts;
    ts.tv_sec = milli_seconds / 1000;
    ts.tv_nsec = (milli_seconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

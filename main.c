#include <stdio.h>
#include <string.h>

int login(){
    char username[] = "admin";
    char password[] = "123";

    char inputUsername[100];
    char inputPassword[100];

    printf("Hello!\n");
    printf("Enter your Username: ");
    scanf("%s",&inputUsername);

    printf("Enter your Password: ");
    scanf("%s",&inputPassword);

    if (!strcmp(username,inputUsername) && !strcmp(password,inputPassword)){
        printf("Login Succesful\n");
        return 1;
    }
    printf("Login Failed!\n");
    return 0;
}

int main(){
    if(login()){
        printf("Select your Field Of Interest: \n");
        int length = 5;
        char fieldOfInterest[5][100] = {"Sports", "Entertainment", "Spirituality","Technology","Finance"};
        for(int i = 0; i < length; i++){
            printf("%d->%s\n",i+1,fieldOfInterest[i]);
        }
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);

        printf("Hello! Welcome to your quiz on the topic of %s!", fieldOfInterest[choice-1]);
    }
    return 0;
}
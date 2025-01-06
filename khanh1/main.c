#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    User users[50];
    int userCount = 0;
    int choice, role;
    loadFile(users, &userCount);

    do {
        menuStart();  // Hi?n th? menu b?t d?u
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                account(&role);  // X�c d?nh vai tr� ngu?i d�ng
                if (role == 1) {
                    do {
                        menuAdmin();  // Hi?n th? menu cho qu?n tr? vi�n
                        printf("Enter your choice: ");
                        scanf("%d", &choice);

                        switch (choice) {
                            case 1: 
                                addUser(users, &userCount);  
                                break;
                            case 2: 
                                printUser(users, userCount);  
                                break;
                            case 3: 
                                searchUserByName(users, userCount);  
                                break;
                            case 4:
                                searchUserByID(users, userCount);  
                                break;
                            case 5:
                                lockUnlockUser(users, userCount);  
                                break;
                            case 6:
                                sortUsersByName(users, userCount);  
                                break;
                            case 7:
                                saveFile(users, userCount); 
                                break;
                            case 0:
                                printf("Returning to the main menu...\n");
                                break;
                            default: 
                                printf("Invalid choice. Please try again.\n"); 
                                break;
                        }
                    } while (choice != 0); 
                }
                break;

            case 2:
                printf("User menu not yet implemented.\n");
                break;

            case 3:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}


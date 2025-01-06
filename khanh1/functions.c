#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
void menuStart() {
    system("cls");
    printf("\n***Bank Management System Using C***\n");
    printf("\n        CHOOSE YOUR RULE\n");
    printf(" ==============================\n");
    printf(" [1] Admin.\n");
    printf(" [2] User.\n");
    printf(" [0] Exit the Program.\n");
    printf(" ==============================\n");                                         
}
void menuAdmin() {
    system("cls");
    printf("\n***Bank Management System Using C***\n");
    printf("\n             MENU\n");
    printf("   ==========================\n");
    printf("   [1] Add a new user.\n");
    printf("   [2] Show all users.\n");
    printf("   [3] Search User by Name.\n");
    printf("   [4] Search User By ID.\n");
    printf("   [5] Lock(unlock) an user.\n");
    printf("   [6] Sort users list.\n");
    printf("   [7] Save File.\n");
    printf("   [0] Exit.\n");
    printf("   ==========================\n");
}
void addUser(User users[50], int *userCount) {
    system("cls");
    printf("*** Add a New User ***\n");
    do {
        printf("Enter the ID: ");
        scanf("%s", users[*userCount].id);
        if (strlen(users[*userCount].id) > 20) {
            printf("ID is too long, please re-enter.\n");
            continue;
        }
        if (isDuplicate(users, *userCount, users[*userCount].id, NULL, NULL, NULL)) {
            printf("ID already exists, please re-enter ID.\n");
            continue;
        }
        break;
    } while (1);
    getchar();
    do {
        printf("Enter the name: ");
        fgets(users[*userCount].name, sizeof(users[*userCount].name), stdin);
        users[*userCount].name[strcspn(users[*userCount].name, "\n")] = '\0';
        if (strlen(users[*userCount].name) == 0) {
            printf("Name cannot be the same. Please re-enter.\n");
        }
    } while (strlen(users[*userCount].name) == 0);
    do {
        printf("Enter the phone (10 digits): ");
        scanf("%s", users[*userCount].phone);
        if (!isValidPhoneNumber(users[*userCount].phone)) {
            printf("Invalid phone number. Please enter all 10 numbers.\n");
            continue;
        }
        if (isDuplicate(users, *userCount, NULL, users[*userCount].phone, NULL, NULL)) {
            printf("Phone number already exists, please re-enter.\n");
            continue;
        }
        break;
    } while (1);
    do {
        printf("Enter the email: ");
        scanf("%s", users[*userCount].email);
        if (!isValidEmail(users[*userCount].email)) {
            printf("Invalid email, please enter the correct format example@example.com.\n");
            continue;
        }
        if (isDuplicate(users, *userCount, NULL, NULL, users[*userCount].email, NULL)) {
            printf("Email already exists, please re-enter.\n");
            continue;
        }
        break;
    } while (1);
    do {
        printf("Enter the username: ");
        scanf("%s", users[*userCount].username);
        if (strlen(users[*userCount].username) > 15) {
            printf("Username is too long!\n");
            continue;
        }
        if (isDuplicate(users, *userCount, NULL, NULL, NULL, users[*userCount].username)) {
            printf("Username already exists, please re-enter.\n");
            continue;
        }
        break;
    } while (1);
    strcpy(users[*userCount].status, "Open");
    do {
        printf("Enter the gender (0: Male, 1: Female): ");
        if (scanf("%d", &users[*userCount].gender) != 1 || (users[*userCount].gender != 0 && users[*userCount].gender != 1)) {
            printf("Invalid data please enter 0 (Male) or 1 (Famale).\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    } while (1);
    do {
        printf("Enter the date of birth (dd mm yyyy): ");
        if (scanf("%d %d %d", &users[*userCount].day, &users[*userCount].month, &users[*userCount].year) != 3 ||
            !isValidDate(users[*userCount].day, users[*userCount].month, users[*userCount].year)) {
            printf("Invalid date of birth, please re-enter.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    } while (1);
    do {
        printf("Enter the balance: ");
        if (scanf("%lf", &users[*userCount].balance) != 1 || users[*userCount].balance < 0) {
            printf("Invalid balance please enter a non-negative number.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    } while (1);
    (*userCount)++;
    printf("\nUser added successfully!\n");
    handleAdminMenuOrExit();
}
void printUser(User users[50], int userCount) {    
	system("cls");   
    printf("|============|====================|========================|=====================|===============|========|\n");
    printf("| ID         | Name               | Email                  |  Phone              |  Date         | Status |\n");
    printf("|============|====================|========================|=====================|===============|========|\n");
	int i;
    for (i = 0; i <userCount ; i++) {
    	printf("| %-10s | %-18s | %-22s | %-19s |  %-02d/%-02d/%-02d   | %-6s |\n",
       users[i].id, users[i].name, users[i].email, 
       users[i].phone, users[i].day, users[i].month, 
       users[i].year, users[i].status);

    }
    printf("|------------|--------------------|------------------------|---------------------|---------------|--------|\n");
    
   handleAdminMenuOrExit();
}
int isDuplicate(User users[], int userCount, const char* id, const char* phone, const char* email, const char* username) {
	int i;
    for ( i = 0; i < userCount; i++) {
        if ((id && strcmp(users[i].id, id) == 0) ||
            (phone && strcmp(users[i].phone, phone) == 0) ||
            (email && strcmp(users[i].email, email) == 0) ||
            (username && strcmp(users[i].username, username) == 0)) {
            return 1;  // Trùng
        }
    }
    return 0;
}
int isValidPhoneNumber(const char* phone) {
    if (strlen(phone) != 10) return 0;
    int i;
    for (i = 0; i < 10; i++) {
        if (!isdigit(phone[i])) {
            return 0;
        }
    }
    return 1;
}
int isValidEmail(const char* email) {
    if (strchr(email, '@') && strchr(email, '.')) {
        return 1;
    }
    return 0;
}
int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;   
    return 1; 
}
void account(int *a) {
    system("cls");
    char stk[20], mk[20];
    do {
        printf("login Name Admin(2006): ");
        scanf("%s", stk);
        printf("Password Admin(2006): ");
        scanf("%s", mk);
        if (strcmp(stk, "2006") == 0 && strcmp(mk, "2006") == 0) {
            printf("Log in successfully\n");
            *a = 1;
            break;
        } else {
            printf("Account or password is incorrect, please try again.\n");
            *a = 0;
            continue;
        }
    } while (*a == 0);
}
void lockUnlockUser(User users[], int userCount) {
    char searchID[20];
    int found = 0;
    system("cls");
    printf("*** Lock/Unlock User ***\n");
    printf("Enter the ID of the user to lock/unlock: ");
    getchar();
    fgets(searchID, sizeof(searchID), stdin);
    searchID[strcspn(searchID, "\n")] = '\0';
	int i;
    for ( i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, searchID) == 0) {
            found = 1;
            printf("\nUser found:\n");
            printf("ID: %s\n", users[i].id);
            printf("Name: %s\n", users[i].name);
            printf("Status: %s\n", users[i].status);
            if (strcmp(users[i].status, "Locked") == 0) {
                printf("The user is currently locked. Do you want to unlock this user? (y/n): ");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    strcpy(users[i].status, "Open");
                    printf("User has been unlocked successfully.\n");
                } else {
                    printf("No changes were made.\n");
                }
            } else if (strcmp(users[i].status, "Open") == 0) {
                printf("The user is currently open. Do you want to lock this user? (y/n): ");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    strcpy(users[i].status, "Locked");
                    printf("User has been locked successfully.\n");
                } else {
                    printf("No changes were made.\n");
                }
            }
		printf("|============|====================|========================|=====================|===============|========|\n");
	    printf("| ID         | Name               | Email                  |  Phone              |  Date         | Status |\n");
	    printf("|============|====================|========================|=====================|===============|========|\n");
	    for (i = 0; i < userCount; i++) {
	    	printf("| %-10s | %-18s | %-22s | %-19s |  %-02d/%-02d/%-02d   | %-6s |\n",
	       users[i].id, users[i].name, users[i].email, 
	       users[i].phone, users[i].day, users[i].month, 
	       users[i].year, users[i].status);
	    }
	    printf("|------------|--------------------|------------------------|---------------------|---------------|--------|\n");
            break;
        }
    }
    if (!found) {
        printf("\nNo user found with the ID '%s'.\n", searchID);
    }
	handleAdminMenuOrExit();
}
void sortUsersByName(User users[50], int userCount) {
    int choice;
    system("cls");
    printf("\n*** Sort Users by Name ***\n");
    printf("1. Sort Users by Name (A-Z)\n");
    printf("2. Sort Users by Name (Z-A)\n");
    printf("Enter the Choice: ");
    scanf("%d", &choice);

    if (userCount <= 1) {
        printf("Not enough users to sort.\n");
        handleAdminMenuOrExit();
        return;
    }
    // Bubble Sort 
    int i, j;
    for (i = 0; i < userCount - 1; i++) {
        for (j = 0; j < userCount - i - 1; j++) {
            int comparisonResult = strcmp(users[j].name, users[j + 1].name);
            if ((choice == 1 && comparisonResult > 0) || (choice == 2 && comparisonResult < 0)) {
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
    system("cls"); 
    printf("*** Users Sorted by Name ***\n");
    printf("|============|====================|========================|=====================|===============|========|\n");
    printf("| ID         | Name               | Email                  |  Phone              |  Date         | Status |\n");
    printf("|============|====================|========================|=====================|===============|========|\n");

    for (i = 0; i < userCount; i++) {
        printf("| %-10s | %-18s | %-22s | %-19s |  %-02d/%-02d/%-02d   | %-6s |\n",
               users[i].id, users[i].name, users[i].email, 
               users[i].phone, users[i].day, users[i].month, 
               users[i].year, users[i].status);
    }
    printf("|------------|--------------------|------------------------|---------------------|---------------|--------|\n");
    handleAdminMenuOrExit();
}
void searchUserByID(User users[], int userCount) {
    char searchID[20];
    int found = 0; 
    system("cls");
    printf("*** Search User by ID ***\n");
    printf("Enter the ID to search: ");
    getchar(); 
    fgets(searchID, sizeof(searchID), stdin);
    searchID[strcspn(searchID, "\n")] = '\0';  
	int i;
    for ( i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, searchID) == 0) {
            printf("\nSearch Results:\n");
            printf("|============|====================|========================|=====================|===============|========|\n");
            printf("| ID         | Name               | Email                  | Phone               | Date          | Status |\n");
            printf("|============|====================|========================|=====================|===============|========|\n");
            printf("| %-10s | %-18s | %-22s | %-19s |  %-02d/%-02d/%-02d   | %-6s |\n",
                   users[i].id, users[i].name, users[i].email,
                   users[i].phone, users[i].day, users[i].month,
                   users[i].year, users[i].status);
            printf("|------------|--------------------|------------------------|---------------------|---------------|--------|\n");
            found = 1; 
            break; 
        }
    }
    if (!found) {
        printf("\nNo user found with the ID '%s'.\n", searchID);
    }

    handleAdminMenuOrExit(); 
}


void searchUserByName(User users[50], int userCount) {
    char searchName[50];
    int found = 0;
    int i, j;
    system("cls");
    printf("*** Search User by Name ***\n");
    printf("Enter the name to search: ");
    getchar();
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 
    for (i = 0; searchName[i]; i++) {
        searchName[i] = tolower((unsigned char)searchName[i]);
    }
    printf("\nSearch Results:\n");
   	printf("|============|====================|========================|=====================|===============|========|\n");
    printf("| ID         | Name               | Email                  |  Phone              |  Date         | Status |\n");
    printf("|============|====================|========================|=====================|===============|========|\n");
    for (i = 0; i < userCount; i++) {
    	char userNameLower[50];
        strcpy(userNameLower, users[i].name);
        for (j = 0; userNameLower[j]; j++) {
            userNameLower[j] = tolower((unsigned char)userNameLower[j]);
        }
        if (strstr(userNameLower, searchName) != NULL) {
    	printf("| %-10s | %-18s | %-22s | %-19s |  %-02d/%-02d/%-02d   | %-6s |\n",
       users[i].id, users[i].name, users[i].email, 
       users[i].phone, users[i].day, users[i].month, 
       users[i].year, users[i].status);
       found = 1;
		}
    }
    printf("|------------|--------------------|------------------------|---------------------|---------------|--------|\n");
    if (!found) {
        printf("\nNo user found with the name '%s'.\n", searchName);
    }
    handleAdminMenuOrExit();
}
void handleAdminMenuOrExit() {
    char choice;
    do {
        printf("Go back to Admin Menu (b) or Exit (0): ");
        scanf(" %c", &choice);
        if (choice == 'b' || choice == 'B') {
            return; 
        } else if (choice == '0') {
            exit(0);
        } else {
            printf("Invalid choice. Please enter 'b' to go back or '0' to exit.\n");
        }
    } while (1);
}

void saveFile(User users[], int userCount) {
    FILE *file = fopen("datanew.dat", "wb"); 
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&userCount, sizeof(int), 1, file);
    fwrite(users, sizeof(User), userCount, file);
    printf("User details saved successfully.\n");
    fclose(file);
}

void loadFile(User users[], int *userCount) {
    FILE *file = fopen("datanew.dat", "rb");  
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }   
    fread(userCount, sizeof(int), 1, file);
    fread(users, sizeof(User), *userCount, file);
    printf("User details loaded successfully.\n");
    fclose(file);
}






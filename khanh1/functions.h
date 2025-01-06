#include"dataType.h"

void menuStart();
void menuAdmin();
void addUser(User users[50], int *userCount);
void printUser(User users[50], int userCount);
int isDuplicate(User users[], int userCount, const char* id, const char* phone, const char* email, const char* username);
int isValidPhoneNumber(const char* phone);
int isValidEmail(const char* email);
int isValidDate(int day, int month, int year);
void account(int *a);
void lockUnlockUser(User users[], int userCount);
void sortUsersByName(User users[50], int userCount);
void searchUserByID(User users[], int userCount);
void searchUserByName(User users[50], int userCount);
void handleAdminMenuOrExit();
void saveFile(User users[], int userCount);
void loadFile(User users[], int *userCount);
int userLogin(User users[], int userCount);
void changePassword(User *user);
void displayUserDetails(User users[], int userCount);

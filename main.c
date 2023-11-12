
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOATS 100

struct Boat {
    char name[50];
    int id;
};

struct User {
    char username[50];
    char password[50];
};

struct Boat boats[MAX_BOATS];
int num_boats = 0;

struct User users[] = {
    {"user1", "password1"},
    {"user2", "password2"},
    {"user3", "password3"}
};
int num_users = 3;

int login() {
    char username[50];
    char password[50];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

void add_boat() {
    if (num_boats >= MAX_BOATS) {
        printf("Error: Maximum number of boats reached.\n");
        return;
    }

    struct Boat boat;

    printf("Enter boat name: ");
    scanf("%s", boat.name);

    printf("Enter boat id: ");
    scanf("%d", &boat.id);

    boats[num_boats++] = boat;

    printf("Boat added successfully.\n");
}

void delete_boat() {
    int id;

    printf("Enter boat id: ");
    scanf("%d", &id);

    for (int i = 0; i < num_boats; i++) {
        if (boats[i].id == id) {
            for (int j = i; j < num_boats - 1; j++) {
                boats[j] = boats[j + 1];
            }

            num_boats--;

            printf("Boat deleted successfully.\n");

            return;
        }
    }

    printf("Error: Boat not found.\n");
}

void list_boats() {
    printf("Boats:\n");

    for (int i = 0; i < num_boats; i++) {
        printf("%d: %s\n", boats[i].id, boats[i].name);
    }
}

int main() {
    if (!login()) {
        printf("Error: Invalid username or password.\n");
        return 1;
    }

    while (1) {
        printf("\n1. Add boat\n");
        printf("2. Delete boat\n");
        printf("3. List boats\n");
        printf("4. Exit\n");

        int choice;

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_boat();
                break;
            case 2:
                delete_boat();
                break;
            case 3:
                list_boats();
                break;
            case 4:
                return 0;
            default:
                printf("Error: Invalid choice.\n");
        }
    }
}

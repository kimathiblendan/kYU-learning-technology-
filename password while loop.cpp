#include <stdio.h>
#include <string.h>

int main() {
    char password[20];

    printf("Enter password: ");
    scanf("%s", password);

    while (strcmp(password, "1234") != 0) {
        printf("Incorrect password. Try again: ");
        scanf("%s", password);
    }

    printf("Access Granted ✅\n");
    return 0;
}

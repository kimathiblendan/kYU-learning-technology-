#include <stdio.h>

int main() {
    FILE *file;
    char title[100];

    printf("Enter the title of the borrowed book: ");
    fgets(title, sizeof(title), stdin);

    file = fopen("borrowed_books.txt", "a"); // Append mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fputs(title, file);
    fclose(file);

    printf("Book title successfully");

	return 0;}
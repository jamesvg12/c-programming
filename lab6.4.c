#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[40];
    char author[40];
    float price;
} Book;

typedef struct {
    long offset;
} Index;

void createIndexes(FILE *fp, Index *titleIndex, Index *authorIndex, Index *priceIndex, int count);
void sortIndexesByField(FILE *fp, Index *index, int count, int field);
void displayBooks(FILE *fp, Index *index, int count);
void saveIndexesToFile(const char *filename, Index *index, int count);
int loadIndexesFromFile(const char *filename, Index *index, int maxCount);

#define MAX_BOOKS 100

int main(void) {
    FILE *fp;
    int bookCount = 0;
    Book books[MAX_BOOKS];
    Index titleIndex[MAX_BOOKS], authorIndex[MAX_BOOKS], priceIndex[MAX_BOOKS];
    int indexesLoaded = 0;

    fp = fopen("book.dat", "rb+");
    if (!fp) {
        fp = fopen("book.dat", "wb+");
        if (!fp) {
            perror("Unable to open or create book.dat");
            return 1;
        }
    }

    fseek(fp, 0, SEEK_END);
    bookCount = ftell(fp) / sizeof(Book);
    if (bookCount > MAX_BOOKS) {
        printf("Too many books in the file. Maximum supported is %d.\n", MAX_BOOKS);
        fclose(fp);
        return 1;
    }

    indexesLoaded = loadIndexesFromFile("title.idx", titleIndex, bookCount) &&
                    loadIndexesFromFile("author.idx", authorIndex, bookCount) &&
                    loadIndexesFromFile("price.idx", priceIndex, bookCount);

    if (!indexesLoaded) {
        createIndexes(fp, titleIndex, authorIndex, priceIndex, bookCount);
        sortIndexesByField(fp, titleIndex, bookCount, 0); // Sort by title
        sortIndexesByField(fp, authorIndex, bookCount, 1); // Sort by author
        sortIndexesByField(fp, priceIndex, bookCount, 2); // Sort by price
    }

    int choice;
    do {
        printf("\nBook Management System\n");
        printf("1. Add a new book\n");
        printf("2. Display books sorted by title\n");
        printf("3. Display books sorted by author\n");
        printf("4. Display books sorted by price\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (bookCount >= MAX_BOOKS) {
                printf("Cannot add more books. Maximum capacity reached.\n");
                continue;
            }

            Book newBook;
            printf("Enter title: ");
            getchar();
            fgets(newBook.title, sizeof(newBook.title), stdin);
            strtok(newBook.title, "\n");

            printf("Enter author: ");
            fgets(newBook.author, sizeof(newBook.author), stdin);
            strtok(newBook.author, "\n");

            printf("Enter price: ");
            scanf("%f", &newBook.price);

            fseek(fp, 0, SEEK_END);
            fwrite(&newBook, sizeof(Book), 1, fp);

            titleIndex[bookCount].offset = bookCount * sizeof(Book);
            authorIndex[bookCount].offset = bookCount * sizeof(Book);
            priceIndex[bookCount].offset = bookCount * sizeof(Book);
            bookCount++;

            sortIndexesByField(fp, titleIndex, bookCount, 0);
            sortIndexesByField(fp, authorIndex, bookCount, 1);
            sortIndexesByField(fp, priceIndex, bookCount, 2);

            printf("Book added successfully.\n");
        } else if (choice == 2) {
            printf("\nBooks sorted by title:\n");
            displayBooks(fp, titleIndex, bookCount);
        } else if (choice == 3) {
            printf("\nBooks sorted by author:\n");
            displayBooks(fp, authorIndex, bookCount);
        } else if (choice == 4) {
            printf("\nBooks sorted by price:\n");
            displayBooks(fp, priceIndex, bookCount);
        }
    } while (choice != 0);

    saveIndexesToFile("title.idx", titleIndex, bookCount);
    saveIndexesToFile("author.idx", authorIndex, bookCount);
    saveIndexesToFile("price.idx", priceIndex, bookCount);

    fclose(fp);
    printf("Goodbye!\n");

    return 0;
}

void createIndexes(FILE *fp, Index *titleIndex, Index *authorIndex, Index *priceIndex, int count) {
    for (int i = 0; i < count; i++) {
        titleIndex[i].offset = i * sizeof(Book);
        authorIndex[i].offset = i * sizeof(Book);
        priceIndex[i].offset = i * sizeof(Book);
    }
}

void sortIndexesByField(FILE *fp, Index *index, int count, int field) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            Book book1, book2;

            fseek(fp, index[i].offset, SEEK_SET);
            fread(&book1, sizeof(Book), 1, fp);
            fseek(fp, index[j].offset, SEEK_SET);
            fread(&book2, sizeof(Book), 1, fp);

            int compare = 0;
            if (field == 0) {
                compare = strcmp(book1.title, book2.title);
            } else if (field == 1) {
                compare = strcmp(book1.author, book2.author);
            } else if (field == 2) {
                compare = (book1.price > book2.price) - (book1.price < book2.price);
            }

            if (compare > 0) {
                Index temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
}

void displayBooks(FILE *fp, Index *index, int count) {
    for (int i = 0; i < count; i++) {
        Book book;

        fseek(fp, index[i].offset, SEEK_SET);
        fread(&book, sizeof(Book), 1, fp);

        printf("Title: %s, Author: %s, Price: $%.2f\n",
               book.title, book.author, book.price);
    }
}

void saveIndexesToFile(const char *filename, Index *index, int count) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error saving index");
        return;
    }
    fwrite(index, sizeof(Index), count, fp);
    fclose(fp);
}

int loadIndexesFromFile(const char *filename, Index *index, int maxCount) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return 0;
    }
    int count = fread(index, sizeof(Index), maxCount, fp);
    fclose(fp);
    return count > 0;
}

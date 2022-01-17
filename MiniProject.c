#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
  char title[30];
  char author[30];
  char genre[30];
  float price;
}Book;

//Global pointer for book
Book *book;

int count=0;
int size;

//Add Book
void addBook()
{
  system("cls");
  printf("\n\t\t\t                  *** Add a New Book Detail ***");
  printf("\nEnter Book Title: ");
  gets(book[count].title);
  printf("\nEnter Book Author: ");
  fflush(stdin);
  gets(book[count].author);
  printf("\nEnter Book Genre: ");
  gets(book[count].genre);
  printf("\nEnter Book Cost: ");
  scanf("%f",&book[count].price);
  count++;
}

//Show Books
void showBooks()
{
  int i;
  system("cls");
  printf("\n\t\t\t                               Book Details");
  printf("\n\n\t\t---------------------------------------------------------------------------------------");
  printf("\n\t\tBook Title\t\tBook Author\t\tBook Genre\t\tBook Price");
  printf("\n\t\t---------------------------------------------------------------------------------------");
  for (i=0; i<count; i++)
  {
    printf("\n\t\t%-12s",book[i].title);
    printf("\t\t%-12s",book[i].author);
    printf("\t\t%-12s",book[i].genre);
    printf("\t\t%-12.2f",book[i].price);
  }
}

//Search Book
void searchBook()
{
  char bookTitle[30];
  int i;
  printf("\nEnter Book Title to be Searched: ");
  gets(bookTitle);
  for(i=0; i<count; i++)
  {
    if(stricmp(book[i].title,bookTitle)==0)
    {
      system("cls");
      printf("\n\t\t\t******** Book Details ********");
      printf("\n\n\t\tBook Title : %s", book[i].title);
      printf("\n\t\tBook Author : %s", book[i].author);
      printf("\n\t\tBook Genre : %s", book[i].genre);
      printf("\n\t\tBook Cost : %.2f\n", book[i].price);
    }
  }
}

//Remove Book
void deleteBook()
{
  char bookTitle[30];
  int i,j;
  printf("\nEnter Book Title to be Removed: ");
  gets(bookTitle);
  for(i=0; i<count; i++)
  {
    if(stricmp(book[i].title,bookTitle)==0)
    {
      system("cls");
      printf("\n\t\t\t******** Remove Book Details ********");
      printf("\n\n\t\tBook Title : %s", book[i].title);
      printf("\n\t\tBook Author : %s", book[i].author);
      printf("\n\t\tBook Genre : %s", book[i].genre);
      printf("\n\t\tBook Cost : %.2f\n", book[i].price);
        for(j=i; j<count; j++)
        {
            book[i]=book[i+1];
        }
      count--;
      return;
    }
  }
}

//Update Book
void updateBook()
{
  char bookTitle[30];
  int i,j;
  printf("\nEnter Book Title to be Updated: ");
  gets(bookTitle);
  for(i=0; i<count; i++)
  {
    if(stricmp(book[i].title,bookTitle)==0)
    {
      system("cls");
      printf("\n\t\t\t******** Book Details ********");
      printf("\n\n\t\tBook Title : %s", book[i].title);
      printf("\n\t\tBook Author : %s", book[i].author);
      printf("\n\t\tBook Genre : %s", book[i].genre);
      printf("\n\t\tBook Cost : %.2f\n", book[i].price);

      printf("\n\t\t\t******** Add New Book Details ********");
      printf("\nEnter Book Title: ");
      gets(book[i].title);
      printf("\nEnter Book Author: ");
      fflush(stdin);
      gets(book[i].author);
      printf("\nEnter Book Genre: ");
      gets(book[i].genre);
      printf("\nEnter Book Cost: ");
      scanf("%f",&book[i].price);
    }
  }
}

//Main
void main()
{
  int choice;
  printf("\nEnter total number of books you want to add in the library: ");
  scanf("%d",&size);
  //Setting Dynamic Array Size
  book = (Book*) malloc(sizeof(Book)*size);

  do
  {
    system("cls");
    printf("\n1.Add Book\n2.Show All Books\n3.Search a Book\n4.Update Books\n5.Delete a Book\n6.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
      case 1:
        addBook();
        break;
      case 2:
        showBooks();
        break;
      case 3:
        searchBook();
        break;
      case 4:
        updateBook();
        break;
      case 5:
        deleteBook();
        break;
      case 6:
        return;
    }
    getch();
  }while(1);
}

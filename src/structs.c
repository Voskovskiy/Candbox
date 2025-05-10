#include <stdio.h>

struct Book
{
  char title[50];
  char author[50];
  int yearOfPublication;
};

struct Car
{
  char model[50];
  int year;
  float price;
};

void printDescriptionForBook(struct Book book);
void printDescriptionForCar(struct Car car);

int main()
{
  struct Book aBook = {"War for the Oaks", "Emma Bull", 2001};
  struct Car mercedes = {"Mercedes Benz GLS SUV", 2025, 89200};
  struct Car bmw = {"BMW X1", 2022, 30500};

  printDescriptionForBook(aBook);
  printDescriptionForCar(mercedes);
  printDescriptionForCar(bmw);

  return 0;
}

void printDescriptionForBook(struct Book book)
{
  printf("%s written by %s, published %d\n", book.title, book.author, book.yearOfPublication);
}

void printDescriptionForCar(struct Car car)
{
  printf("%s build at %d, sold for $%.2f\n", car.model, car.year, car.price);
}
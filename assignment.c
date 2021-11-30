#include <stdio.h>
#include <stdbool.h>

struct product{
  int importflag;
  int taxflag;
  int amount;
  float price;
  char name[20];
} ;
typedef struct product Product;

float taxsum(struct product a);
void printRecipe(struct product b);

int main(){
  float sum = 0;
  float sumtax = 0;
  struct product product1 = {0, 0, 1, 12.49,"book"};
  struct product product2 = {0, 1, 1, 14.99, "music CD"};
  struct product product3 = {0, 0, 1, 0.85, "chocolate bar"};


  sumtax += taxsum(product1);
  sumtax += taxsum(product2);
  sumtax += taxsum(product3);
  sum = product1.price + product2.price + product3.price + sumtax;

  printRecipe(product1);
  printRecipe(product2);
  printRecipe(product3);

  printf("Sales Taxes: %.2f\n", sumtax);
  printf("Total: %.2f\n", sum );
}

float taxsum(struct product a){
  if (a.taxflag == 1) {
    return a.price*0.1;
  }
    return 0;
}

void printRecipe(struct product a){
  printf("%d %s\t", a.amount, a.name);
  printf("%.2f\n", a.price + taxsum(a));
}

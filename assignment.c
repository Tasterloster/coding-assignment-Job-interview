#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct product{
  int importflag;
  int taxflag;
  int amount;
  float price;
  char name[20];
} ;

float taxsum(struct product a);
void printRecipe(struct product b);
void input1();
void input2();
void input3();

int main(){
  input1();
  input2();
  input3();
  }

float taxsum(struct product a){
  float tax = 0;
  if(a.importflag == 1){
    tax += a.price*0.05;
  }
  if(a.taxflag == 1){
    tax += a.price*0.1;
  }
  return ceilf(tax*20)/20;
}

void printRecipe(struct product a){
  if(a.importflag == 1){
    printf("%d imported %s\t", a.amount, a.name);
  }
  else printf("%d %s\t", a.amount, a.name);
  printf("%.2f\n", a.price + taxsum(a));
}

void input1(){
  float sum = 0;
  float sumtax = 0;
  struct product product1 = {0, 0, 1, 12.49,"book"};
  struct product product2 = {0, 1, 1, 14.99, "music CD"};
  struct product product3 = {0, 0, 1, 0.85, "chocolate bar"};

  sumtax += taxsum(product1);
  sumtax += taxsum(product2);
  sumtax += taxsum(product3);
  sum = product1.price + product2.price + product3.price + sumtax;
  printf("Output 1:\n");
  printRecipe(product1);
  printRecipe(product2);
  printRecipe(product3);
  printf("Sales Taxes: %.2f\n", sumtax);
  printf("Total: %.2f\n\n", sum);

  }

void input2(){
  float sum = 0;
  float sumtax = 0;
  struct product product1 = {1, 0, 1, 10.00,"box of chocolates"};
  struct product product2 = {1, 1, 1, 47.50, "bottle of perfume"};

  sumtax += taxsum(product1);
  sumtax += taxsum(product2);
  sum = product1.price + product2.price + sumtax;
  printf("Output 2:\n");
  printRecipe(product1);
  printRecipe(product2);

  printf("Sales Taxes: %.2f\n", sumtax);
    printf("Total: %.2f\n\n", sum);

  }

void input3(){
  float sum = 0;
  float sumtax = 0;
  struct product product1 = {1, 1, 1, 27.99,"bottle of perfume"};
  struct product product2 = {0, 1, 1, 18.99, "bottle of perfume"};
  struct product product3 = {0, 0, 1, 9.75, "headache pills"};
  struct product product4 = {1, 0, 1, 11.25, "box of chocolates"};

  sumtax += taxsum(product1);
  sumtax += taxsum(product2);
  sumtax += taxsum(product3);
  sumtax += taxsum(product4);
  sum = product1.price + product2.price + product3.price + product4.price + sumtax;
  printf("Output 3:\n");
  printRecipe(product1);
  printRecipe(product2);
  printRecipe(product3);
  printRecipe(product4);

  printf("Sales Taxes: %.2f\n", sumtax);
  printf("Total: %.2f\n\n", sum);

  }

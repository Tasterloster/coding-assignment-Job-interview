#include <stdio.h>
#include <stdbool.h>

struct product{
  int importflag;
  int taxflag;
  float price;
} ;


int main(){
  float sum = 0;
  float sumtax = 0;
  struct product book = {0, 0, 12.49};
  struct product musiccd = {0, 1, 14.99};
  struct product chocobar = {0, 0, 0.85};

  sumtax += taxsum(book);
  sumtax += taxsum(musiccd);
  sumtax += taxsum(chocobar);
  sum = book.price + musiccd.price + chocobar.price;

  printf("Sales Taxes: %f\n", sumtax);
  printf("Total: %f\n", sum );
}

float taxsum(struct product a){
  float sum;
  If(a.taxflag == 1) sum += a.price*.1;
  If(a.importflag == 1) sum += a.price*.05;
  return sum;
}

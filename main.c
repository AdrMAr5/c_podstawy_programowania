#include <stdio.h>
#include <math.h>

int main() {
    float a;
    int x;
    float p;
    printf("price: ");
    scanf("%f", &a);
    printf("quantity: ");
    scanf("%d", &x);
    printf("VAT tax: ");
    scanf("%f", &p);

    float value = a*x;
    printf("RECEIPT\n");
    printf("Total netto value is %.2f. \n",roundf(value*100)/100);
    float vat_value = p*value/100;
    printf("Tax value: is %.2f. \n", roundf(vat_value*100)/100);
    float total_brutto_value = value + vat_value;
    printf("Total brutto value is %.2f. \n", roundf(total_brutto_value*100)/100);

    return 0;
}

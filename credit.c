#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int main(void){
    long credit_number;
    string credit;
    int count, credit_value, credit_value_sum, last_digit;
    int credit_sum = 0;

    do
    {
        credit = get_string("Insira o número do cartão: ");
        credit_number = strtol(credit, NULL, 10);
    }
    while(credit_number <= 0);

    count = strlen(credit);

    for(int i = 0; i < count; i = i + 2)
    {
        credit_value = credit[i] - '0';
        credit_value = credit_value * 2;
        credit_value_sum = 0;
         while (credit_value != 0)
         {
            credit_value_sum += credit_value % 10;
            credit_value = credit_value / 10;
         }
        credit_sum = credit_sum + credit_value_sum;
    }

    for(int j = 1; j < count; j = j + 2)
    {
        credit_value = credit[j] - '0';
        credit_sum = credit_sum + credit_value;
    }

    last_digit = credit_sum % 10;

    printf("O Cartão digitado foi: %s\n", credit);
    printf("O Cartão tem %i digitos\n", count);
    printf("O algoritmo de Luh é igual a: %i\n", credit_sum);

    if(last_digit != 0)
    {
        printf("INVALID\n");
    } else if(count == 15 && credit[0] == '3' && (credit[1] == '4' || credit[1] == '7'))
        {
            printf("Cartão AMEX\n");
        } else if(count == 16 && credit[0] == '5' && (credit[1] == '1' || credit[1] == '2' || credit[1] == '3' || credit[1] == '4' || credit[1] == '5'))
            {
                printf("Cartão MASTERCARD\n");
            } else if((count == 13 || count == 16) && credit[0] == '4')
                {
                    printf("Cartão VISA\n");
                } else
                    {
                        printf("INVALID\n");
                    }
}

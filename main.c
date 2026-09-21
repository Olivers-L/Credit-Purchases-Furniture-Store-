#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    
  
    int    choice, ok, retry;
    int    approved = 0;        
    double income, price, rate, installment;
    int    term;

    do {
        printf("1) Credit application\n");
        printf("2) Payment calculation\n");
        printf("0) Exit\n");
        printf("Choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input\n");
        while (getchar() != '\n');
        choice = -1;
    }

        switch (choice) {

        case 1:
        do {
            ok = 1;

            printf("Monthly income: ");
            scanf("%lf", &income);
            if (income <= 0) {
                printf("Error: income must be greater than 0.\n");
                ok = 0;
            }

            printf("Furniture price: ");
            scanf("%lf", &price);
            if (price <= 0) {
                printf("Error: price must be greater than 0.\n");
                ok = 0;
            }

            printf("Term in months (6/12/24/36): ");
            scanf("%d", &term);
            if (term != 6 && term != 12 && term != 24 && term != 36) {
                printf("Error: term must be 6, 12, 24 or 36.\n");
                ok = 0;
            }

            if (ok == 0) {
                printf("Try again? (1 = yes, 0 = no): ");
                scanf("%d", &retry);
            }
        } while (ok == 0 && retry == 1);

        if (ok == 1) {
            switch (term) {
                case 6:  rate = 5;  break;
                case 12: rate = 7;  break;
                case 24: rate = 9;  break;
                case 36: rate = 11; break;
            }

            installment = (price + price * rate / 100) / term;

            if (installment <= income * 0.30) {
                approved = 1;
                printf("Credit approved.\n");
                printf("Term: %d months, rate: %.0f%%\n", term, rate);
                printf("Monthly installment: %.2f EUR\n", installment);
            } else {
                approved = 0;
                printf("Credit rejected: installment %.2f EUR exceeds 30%% of income (%.2f EUR).\n",
                    installment, income * 0.30);
            }
        }
        break;

        case 2: {
            printf("In Construction...\n");
            break;
        }
           
        case 0:
            printf("Goodbye\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
        

        } while (choice != 0);

    return 0;
}

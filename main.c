#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Some values for testing: 
Income	Price	Term	Rate	Expected installment
2000	2000	6	    5%	    €350.00
2000	3000	12	    7%	    €267.50
1800	5000	24	    9%	    €227.08
2500	8000	36	    11%	    €246.67

Rejection: Income: 1000; Price: 5000; Term: 6 */


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
            double interestAmount;
            double totalRepayment;
            double regularInstallment;
            double extraCreditCost;
            double remainingBalance;

            switch (approved) {
            case 0:
                printf("No approved credit exists.\n");
                printf("Complete the credit application first. \n");
                break;
            case 1:
                printf("Approved Credit found.\n");

                switch (price > 0 && income > 0) {
                case 0:
                    printf("ERROR: invalid credit data.\n");
                    break;
                case 1:
                    printf("Credit data is valid.\n");

                    switch ((term == 6 || term == 12 || term == 24 || term == 36) && rate >= 0) {
                    case 0: 
                        printf("ERROR: Invalid repayment conditions.\n");
                        break;
                    case 1:
                        printf("Repayment conditions are valid. \n");

                        interestAmount = price * rate / 100.0;
                        totalRepayment = price + interestAmount;
                        regularInstallment = totalRepayment / term;
                        extraCreditCost = totalRepayment - price;
                        remainingBalance = totalRepayment;

                        switch (totalRepayment >= price) {
                        case 0:
                            printf("ERROR: Calculation error.");
                            break;
                        case 1:
                            regularInstallment = totalRepayment / term;
                            printf("Operation is successful, repayment information ready; directing to Repayment Menu.");
                            
                            /*
                            REPAYMENT CONTROL MENU
                            WILL START HERE
                            */

                            break;
                        }


                        break;
                    }
                }
            }
            // -------------------------------------------
            printf("\n\n--- DEBUG REPAYMENT VALUES ---\n");
            printf("Rate: %.2f%%\n", rate);
            printf("Interest amount: %.2f EUR\n", interestAmount);
            printf("Total repayment: %.2f EUR\n", totalRepayment);
            printf("Regular installment: %.2f EUR\n", regularInstallment);
            printf("Extra credit cost: %.2f EUR\n", extraCreditCost);
            printf("Remaining balance: %.2f EUR\n", remainingBalance);
            printf("---------------------------------\n\n");

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

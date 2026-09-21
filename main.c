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
                printf("Complete the credit application first.\n\n\n");
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
                            printf("Operation is successful, repayment information ready; directing to Repayment Menu.\n");
                            int repaymentChoice;
                            
                                printf("\n\n");
                                printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
                                printf("|                REPAYMENT CONTROL CENTER             |\n");
                                printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
                                printf(" Credit Status : APPROVED\n");
                                printf(" Furniture     : %.2f EUR\n", price);
                                printf(" Term          : %d months\n", term);
                                printf(" Interest Rate : %.0f%%\n", rate);
                                printf("*---*---*---*---*---*---*---*---*---*---*---*---*---*--*\n");
                                printf(" Monthly payment : %10.2f EUR\n", regularInstallment);
                                printf(" Total repayment : %10.2f EUR\n", totalRepayment);
                                printf(" Total interest  : %10.2f EUR\n", interestAmount);
                                printf("*---*---*---*---*---*---*---*---*---*---*---*---*---*--*\n\n");
                                printf("  [1] View repayment summary\n");
                                printf("  [2] Generate full repayment schedule\n");
                                printf("  [3] Inspect a specific installment\n");
                                printf("  [4] View credit cost analysis\n");
                                printf("  [5] Find final payment date\n");
                                printf("  [6] Simulate repayment progress\n");
                                printf("  [7] Re-display credit conditions\n");
                                printf("  [0] Return to main menu\n\n");
                                printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
                             do {
                                 printf("Select an option: ");

                                if (scanf("%d", &repaymentChoice) != 1){
                                    printf("Invalid input. Enter a number from the menu...\n\n");

                                    while (getchar() != '\n');
                                    repaymentChoice = -1;
                                    continue;
                                }

                                switch (repaymentChoice) {
                                case 1:
                                    printf("Repayment summary.\n\n");
                                    break;
                                case 2:
                                    printf("Generate full repayment schedule\n\n");
                                    break;
                                case 3:
                                    printf("Inspect a specific installment\n\n");
                                    break;
                                case 4:
                                    printf("View credit cost analysis\n\n");
                                    break;
                                case 5:
                                    printf("Find final payment date\n\n");
                                    break;
                                case 6:
                                    printf("Simulate repayment progress\n\n");
                                    break;
                                case 7:
                                    printf("Re-display credit conditions\n\n");
                                    break;

                                case 0:
                                    printf("Returning to main menu...\n\n");
                                    break;

                                default:
                                    printf("Invalid option. Please choose a number from the menu.\n\n");
                                    break;
                                    
                                }
                            
                              } while (repaymentChoice != 0);



                            break;
                        }

                        break;
                    }
                }
            }

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

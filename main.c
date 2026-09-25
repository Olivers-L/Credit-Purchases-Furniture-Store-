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

                    switch ((term == 6 || term == 12 || term == 24 || term == 36) && rate > 0) {
                    case 0: 
                        printf("ERROR: Invalid repayment conditions; choose a term from credit application.\n");
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
                                // option 2 & 3 variables:
                                int startMonth;
                                int startYear;
                                int paymentNo;
                                int paymentMonth;
                                int paymentYear;
                                double remaining;
                                double currentPayment;
                                int dateSet = 0;
                                
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
                                    printf("\nRepayment summary.\n\n");
                                    printf("Here is your furniture price: %.2lf EUR\n", price);
                                    printf("Here is your income: %.2lf EUR\n", income);
                                    printf("Here is your repayment term amount: %d\n", term);
                                    printf("Here is your interest rate: %.2lf%%\n", rate);
                                    printf("Here is your total repayment amount: %.2lf\n", totalRepayment);
                                    printf("Here is your :extra credit cost: %.2lf EUR\n", extraCreditCost);
                                    printf("Here is your regular installment: %.2lf EUR\n", regularInstallment);
                                    printf("Returning to Repayment menu...\n\n");
                                 break;
                                case 2:
                                    printf("\nRepayment Schedule:\n\n");

                                    int extra;

                                    while (1) {
                                        printf("Enter first payment month (1-12): ");

                                        if (scanf("%d", &startMonth) != 1) {
                                            printf("Invalid input, enter a number.\n");

                                            while (getchar() != '\n');
                                            continue;
                                        }

                                        extra = getchar();

                                        if (extra != '\n') {
                                            printf("Invalid input, enter only a number.\n");

                                            while (getchar() != '\n');
                                            continue;
                                        }

                                        if (startMonth < 1 || startMonth > 12) {
                                            printf("Invalid month, enter a month from 1 to 12.\n");
                                            continue;
                                        }
                                        break;
                                    }

                                    int extra2;

                                    while (1) {
                                        printf("Enter first payment year: ");
                                    
                                        if (scanf("%d", &startYear) != 1) {
                                            printf("Invalid Input, enter a number.");
                                            while (getchar() != '\n');
                                            continue;
                                        }

                                        extra2 = getchar();

                                        if (extra2 != '\n') {
                                            printf("Invalid input, enter only a number.\n");
                                            while (getchar() != '\n');
                                            continue;
                                        }

                                        if (startYear < 2000 || startYear > 2100) {
                                            printf("Invalid year, enter a valid year. \n");
                                            continue;
                                        }
                                        break;
                                    }
                                    paymentNo = 1;
                                    paymentMonth = startMonth;
                                    paymentYear = startYear;
                                    remaining = totalRepayment;
                                    dateSet = 1;

                                    printf("Schedule starting from %02d/%d\n\n", paymentMonth, paymentYear);
                                break;

                                case 3: {
                                    int installmentNumber;
                                    int targetMonth;
                                    int targetYear;
                                    int counter;
                                    int validInstallment = 0;
                                    int extra3;

                                    if (dateSet == 0) {
                                        printf("No repayment schedule exists yet.\n");
                                        printf("Please generate the repayment schedule first using option 2.\n\n");
                                        break;
                                    }

                                    printf("\nInspect Installment\n\n");

                                    while (validInstallment == 0) {

                                        printf("Enter installment number (1-%d): ", term);

                                        if (scanf("%d", &installmentNumber) != 1) {
                                            printf("Invalid input. Please enter a number.\n");

                                            while (getchar() != '\n') {
                                                // Clear invalid input
                                            }

                                            continue;
                                        }

                                        extra3 = getchar();

                                        while (extra3 == ' ' || extra3 == '\t') {
                                            extra3 = getchar();
                                        }

                                        if (extra3 != '\n') {
                                            printf("Invalid input. Enter only a number.\n");

                                            while (extra3 != '\n') {
                                                extra3 = getchar();
                                            }

                                            continue;
                                        }

                                        /* Number is valid, now check its range */
                                        if (installmentNumber < 1 || installmentNumber > term) {
                                            printf("Invalid installment number. Choose from 1 to %d.\n", term);
                                            continue;
                                        }

                                        validInstallment = 1;
                                    }


                                    targetMonth = startMonth;
                                    targetYear = startYear;
                                    counter = 1;

                                    while (counter < installmentNumber) {

                                        targetMonth++;

                                        if (targetMonth > 12) {
                                            targetMonth = 1;
                                            targetYear++;
                                        }

                                        counter++;
                                    }


                                    remaining = totalRepayment;
                                    counter = 1;

                                    while (counter < installmentNumber) {
                                        remaining = remaining - regularInstallment;
                                        counter++;
                                    }


                                    if (installmentNumber == term) {
                                        currentPayment = remaining;
                                    }
                                    else {
                                        currentPayment = regularInstallment;
                                    }


                                    printf("\nInstallment #%d\n", installmentNumber);
                                    printf("Payment date : %02d/%d\n", targetMonth, targetYear);
                                    printf("Amount       : %.2f EUR\n\n", currentPayment);

                                    break;
                                }

                                case 4: {
                                    double creditCostPercent;
                                    double averageMonthlyCost;

                                    creditCostPercent = (extraCreditCost / price) * 100.0;
                                    averageMonthlyCost = totalRepayment / term;

                                    printf("\n\n");
                                    printf("=============================================\n");
                                    printf("              CREDIT COST ANALYSIS           \n");
                                    printf("=============================================\n");
                                    printf("Furniture price        : %.2f EUR\n", price);
                                    printf("Interest rate          : %.2f%%\n", rate);
                                    printf("Interest amount        : %.2f EUR\n", interestAmount);
                                    printf("Extra credit cost      : %.2f EUR\n", extraCreditCost);
                                    printf("Credit cost percentage : %.2f%%\n", creditCostPercent);
                                    printf("Total repayment        : %.2f EUR\n", totalRepayment);
                                    printf("Average monthly cost   : %.2f EUR\n", averageMonthlyCost);
                                    printf("=============================================\n\n");

                                    break;
                                }
                                case 5: {
                                    int finalMonth;
                                    int finalYear;
                                    int counter;

                                    if (dateSet == 0) {
                                        printf("No repayment schedule exists yet.\n");
                                        printf("Please generate the repayment schedule first using option 2.\n\n");
                                        break;
                                    }

                                    finalMonth = startMonth;
                                    finalYear = startYear;
                                    counter = 1;

                                    while (counter < term) {

                                        finalMonth++;

                                        if (finalMonth > 12) {
                                            finalMonth = 1;
                                            finalYear++;
                                        }

                                        counter++;
                                    }

                                    printf("\n");
                                    printf("=============================================\n");
                                    printf("              FINAL PAYMENT DATE             \n");
                                    printf("=============================================\n");
                                    printf("First payment date : %02d/%d\n", startMonth, startYear);
                                    printf("Repayment term     : %d months\n", term);
                                    printf("Final payment date : %02d/%d\n", finalMonth, finalYear);
                                    printf("=============================================\n\n");

                                    break;
                                }
                                case 6: {
                                    int paidCount;
                                    int remainingInstallments;
                                    double amountPaid;
                                    double simulatedRemaining;

                                    printf("\Repayment Progress Simulation\n\n");

                                    while (1) {
                                        printf("Enter number of installments already paid (0-%d): ", term);

                                        if (scanf("%d", &paidCount) != 1) {
                                            printf("Invalid input. Please enter a number.\n");

                                            while (getchar() != '\n') {
                                                // clear invalid input
                                            }

                                            continue;
                                        }

                                        if (paidCount < 0 || paidCount > term) {
                                            printf("Invalid number. Enter a value from 0 to %d.\n\n", term);
                                            continue;
                                        }

                                        break;
                                    }

                                    amountPaid = regularInstallment * paidCount;
                                    remainingInstallments = term - paidCount;

                                    if (paidCount == term) {
                                        amountPaid = totalRepayment;
                                        simulatedRemaining = 0;
                                    }
                                    else {
                                        simulatedRemaining = totalRepayment - amountPaid;
                                    }

                                    printf("\n");
                                    printf("=============================================\n");
                                    printf("           REPAYMENT PROGRESS                \n");
                                    printf("=============================================\n");
                                    printf("Installments paid      : %d / %d\n", paidCount, term);
                                    printf("Amount paid            : %.2f EUR\n", amountPaid);
                                    printf("Remaining balance      : %.2f EUR\n", simulatedRemaining);
                                    printf("Installments remaining : %d\n", remainingInstallments);

                                    if (simulatedRemaining == 0) {
                                        printf("Credit status          : FULLY REPAID\n");
                                    }
                                    else {
                                        printf("Credit status          : ACTIVE\n");
                                    }

                                    printf("=============================================\n\n");

                                    break;
                                }
                                case 7:

                                    printf("\n");
                                    printf("=============================================\n");
                                    printf("            CREDIT CONDITIONS                \n");
                                    printf("=============================================\n");
                                    printf("Furniture price      : %.2f EUR\n", price);
                                    printf("Monthly income       : %.2f EUR\n", income);
                                    printf("Repayment term       : %d months\n", term);
                                    printf("Interest rate        : %.2f%%\n", rate);
                                    printf("Monthly installment  : %.2f EUR\n", regularInstallment);
                                    printf("=============================================\n\n");
                                    
                                    break;

                                case 0:
                                    printf("Returning to the main menu...\n\n\n");
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

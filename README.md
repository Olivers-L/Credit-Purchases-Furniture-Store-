# Credit Purchases – Furniture Store

A console-based C project developed for the TalTech course
**ICS0004 – Fundamentals of Programming**.

Contributors:
- Bahadir Bora Sevgili — `@bora-sevgili`
- Oliver — `@Olivers-L`

---

The system models installment credit purchases in a furniture store.
It evaluates whether a customer is eligible for credit based on their
income and the furniture price, determines repayment conditions, and
calculates repayment information.

## Current Development Stage

The project is currently being developed for **Checkpoint 1**.

Current functionality includes:

- Credit application
- Credit eligibility checking
- Repayment term and interest rate determination
- Installment calculation
- Total repayment calculation
- Repayment control menu

## Main Scenarios

### 1. Credit Application
The customer enters:
- Monthly income
- Furniture price
- Repayment term

The program determines the interest rate, calculates the monthly
installment and approves or rejects the credit.

### 2. Repayment Calculation
For an approved credit, the program calculates:
- Interest amount
- Total repayment
- Regular monthly installment
- Extra credit cost

The user can then access the Repayment Control Center.

## Repayment Control Center

The repayment section is designed around the following options:

1. View repayment summary
2. Generate full repayment schedule
3. Inspect a specific installment
4. View credit cost analysis
5. Find final payment date
6. Simulate repayment progress
7. Re-display credit conditions
0. Return to main menu

Some repayment functions are still under development.

## Project Constraints

- Implemented in C
- Console-based interface
- Runs on Windows or Linux with a C compiler
- No database
- No connection to real banks, payment systems or external APIs
- TXT/CSV storage will be introduced in later stages

---

## Planned Features

Later checkpoints will extend the system with:

- Repayment schedule generation
- Partner bank selection
- Bank commission calculation
- Late-payment penalties
- Restrictions while penalties are unpaid
- Saving and loading customer, credit and payment data

  ## Development Branches

- `main` – integrated/stable version
- `credit-application-case-1` – credit application and eligibility
- `repayment-scenario` – repayment calculation and repayment menu

#include <stdio.h>

int main()
{
    // ---------- PART A: Employee Salaries ----------
    const int NUM_SALARIES = 50;
    float salaries[50];
    float total = 0, highest = 0, lowest = 0, average;
    float searchValue;
    int found = 0;

    printf("=== PART A: Employee Salaries ===\n");
    for (int i = 0; i < NUM_SALARIES; i++)
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    // Display all captured salaries
    printf("\nEmployee Salaries:\n");
    for (int i = 0; i < NUM_SALARIES; i++)
    {
        printf("%.2f\n", salaries[i]);
    }

    // Calculate total, then average, and find highest/lowest in one pass
    for (int i = 0; i < NUM_SALARIES; i++)
    {
        total = total + salaries[i];

        if (i == 0)
        {
            highest = salaries[i];
            lowest = salaries[i];
        }
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest) lowest = salaries[i];
    }
    average = total / NUM_SALARIES;

    printf("\nAverage salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    // Search for a specific salary the user names
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchValue);

    found = 0;
    for (int i = 0; i < NUM_SALARIES; i++)
    {
        if (salaries[i] == searchValue)
        {
            found = 1;
            printf("Salary found at position %d (Employee %d)\n", i, i + 1);
            break;   // stop looking once we've found it — no need to keep scanning
        }
    }
    if (!found)
    {
        printf("Salary not found.\n");
    }

    // ---------- PART B: Department Budgets ----------
    const int NUM_BUDGETS = 10;
    float budgets[10];
    float budgetTotal = 0, budgetAverage;

    printf("\n=== PART B: Department Budgets ===\n");
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    // Display captured budgets
    printf("\nDepartment Budgets:\n");
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    // Total and average
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        budgetTotal = budgetTotal + budgets[i];
    }
    budgetAverage = budgetTotal / NUM_BUDGETS;

    printf("\nTotal budget: %.2f\n", budgetTotal);
    printf("Average budget: %.2f\n", budgetAverage);

    // Sort budgets from lowest to highest using bubble sort
    // Outer loop: how many "passes" we make through the array
    for (int i = 0; i < NUM_BUDGETS - 1; i++)
    {
        // Inner loop: compares each pair of neighbours and swaps if out of order
        for (int j = 0; j < NUM_BUDGETS - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                float temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted (lowest to highest):\n");
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    // ---------- PART C: Vehicle Registration Numbers ----------
    const int NUM_VEHICLES = 20;
    char registrations[20][20];   // 20 registration numbers, each up to 19 characters
    char searchReg[20];
    int regFound = 0;

    printf("\n=== PART C: Vehicle Registrations ===\n");
    for (int i = 0; i < NUM_VEHICLES; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    // Display all registrations
    printf("\nVehicle Registrations:\n");
    for (int i = 0; i < NUM_VEHICLES; i++)
    {
        printf("%s\n", registrations[i]);
    }

    // Search for a specific registration number
    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);

    regFound = 0;
    for (int i = 0; i < NUM_VEHICLES; i++)
    {
        // strcmp compares two strings; it returns 0 only when they're identical
        if (strcmp(registrations[i], searchReg) == 0)
        {
            regFound = 1;
            printf("Registration found at position %d\n", i);
            break;
        }
    }
    if (!regFound)
    {
        printf("Registration not found.\n");
    }

    return 0;
}
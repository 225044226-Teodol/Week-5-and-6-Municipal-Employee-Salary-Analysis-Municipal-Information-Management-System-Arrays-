#include <stdio.h>

int main()
{
    // We'll capture 50 employee salaries — matches the lab requirement exactly
    const int NUM_EMPLOYEES = 50;

    float salary;      // temporary variable to hold each entry as it's typed in
    float total = 0;   // running total of all salaries — starts at 0 and grows each loop
    float highest = 0;
    float lowest = 0;
    float average;

    // This loop runs once per employee (i = 1 up to 50)
    for (int i = 1; i <= NUM_EMPLOYEES; i++)
    {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        total = total + salary;   // keep adding each salary to the running total

        // On the very FIRST employee only, use their salary to start off both highest and lowest.
        // This avoids the classic bug of starting lowest at 0, which would make 0 always "win"
        // since real salaries are always greater than 0.
        if (i == 1)
        {
            highest = salary;
            lowest = salary;
        }

        // From employee 2 onward, compare against what we've seen so far
        if (salary > highest)
        {
            highest = salary;
        }

        if (salary < lowest)
        {
            lowest = salary;
        }
    }

    average = total / NUM_EMPLOYEES;

    printf("\n--- Salary Report ---\n");
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    return 0;
}
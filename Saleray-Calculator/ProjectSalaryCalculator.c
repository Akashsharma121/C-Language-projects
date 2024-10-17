#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int main() {
    int year, workdays, yoursalary, daysInMonth, presentDays[12], absentDays[12], holidays[12];
    int fullTimeDays[12], halfTimeDays[12], partTimeDays[12];
    float perHourRate, monthlySalary[12], calculatedSalary = 0;
    const char *monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Input year
    printf("Enter year: ");
    scanf("%d", &year);

    // Input how many workdays in your company
    printf("Enter how many workdays in your company: ");
    scanf("%d", &workdays);

    // Input your salary
    printf("Enter your salary: ");
    scanf("%d", &yoursalary);

    // Determine if it's a leap year
    int leapYear = isLeapYear(year);

    // Calculate perHourRate
  perHourRate = (float)yoursalary / (workdays * 8);

    // Input the number of days present, absent, and specific attendance types for each month
    for (int month = 0; month < 12; month++) {
        switch (month + 1) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                daysInMonth = 31;
                break;
            case 4: case 6: case 9: case 11:
                daysInMonth = 30;
                break;
            case 2:
                daysInMonth = leapYear ? 29 : 28;
                break;
        }

        printf("\nFor %s:\n", monthNames[month]);
        printf("Enter the number of days you were present: ");
        scanf("%d", &presentDays[month]);
        
        printf("Enter the number of days you were absent: ");
        scanf("%d", &absentDays[month]);
        
        printf("Enter the number of Full-Time days: ");
        scanf("%d", &fullTimeDays[month]);
        
        printf("Enter the number of Half-Time days: ");
        scanf("%d", &halfTimeDays[month]);
        
        printf("Enter the number of Part-Time days: ");
        scanf("%d", &partTimeDays[month]);

        // Calculate holidays for the month
        holidays[month] = daysInMonth - (presentDays[month] + absentDays[month]);

        // Calculate the monthly salary based on hours worked
        monthlySalary[month] = (fullTimeDays[month] * 8 + halfTimeDays[month] * 4 + partTimeDays[month] * 11) * perHourRate;
        calculatedSalary += monthlySalary[month];
    }
      // Display the centered title
    printf("\n%78s %d\n\n", "Data of this Year", year);

    // Display table header
    printf("\n+-----------+----------------+----------------+--------------+--------------+----------------+---------------+---------------+----------------+\n");
    printf("|   Month   | Days in Month  |  Present Days  | Absent Days  |  Holidays    |  Full-Time     |  Half-Time    |  Part-Time    | Monthly Salary |\n");
    printf("+-----------+----------------+----------------+--------------+--------------+----------------+---------------+---------------+----------------+\n");

    // Initialize totals
    int totalDaysInMonth = 0, totalPresentDays = 0, totalAbsentDays = 0, totalHolidays = 0;
    int totalFullTimeDays = 0, totalHalfTimeDays = 0, totalPartTimeDays = 0;
    float totalMonthlySalary = 0.0f;

    // Display data for each month
    for (int month = 0; month < 12; month++) {
        switch (month + 1) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                daysInMonth = 31;
                break;
            case 4: case 6: case 9: case 11:
                daysInMonth = 30;
                break;
            case 2:
                daysInMonth = leapYear ? 29 : 28;
                break;
        }

        // Update totals
        totalDaysInMonth += daysInMonth;
        totalPresentDays += presentDays[month];
        totalAbsentDays += absentDays[month];
        totalHolidays += holidays[month];
        totalFullTimeDays += fullTimeDays[month];
        totalHalfTimeDays += halfTimeDays[month];
        totalPartTimeDays += partTimeDays[month];
        totalMonthlySalary += monthlySalary[month];

        // Display the month's data
        printf("| %-9s |      %-9d |      %-9d |    %-9d |    %-9d |      %-9d |     %-9d |     %-9d |  %-13.2f |\n",
               monthNames[month], daysInMonth, presentDays[month], absentDays[month], holidays[month], fullTimeDays[month],
               halfTimeDays[month], partTimeDays[month], monthlySalary[month]);
    }

    // Display totals row
    printf("+-----------+----------------+----------------+--------------+--------------+----------------+---------------+---------------+----------------+\n");
    printf("|   Total   |      %-9d |      %-9d |    %-9d |    %-9d |      %-9d |     %-9d |     %-9d |  %-13.2f |\n",
           totalDaysInMonth, totalPresentDays, totalAbsentDays, totalHolidays, totalFullTimeDays, totalHalfTimeDays,
           totalPartTimeDays, totalMonthlySalary);
    printf("+-----------+----------------+----------------+--------------+--------------+----------------+---------------+---------------+----------------+\n");

    // Display the total calculated salary for the year
    printf("\nTotal calculated salary for the year: %.2f\n", totalMonthlySalary);

    return 0;
}

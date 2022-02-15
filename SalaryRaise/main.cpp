#include <iostream>
#include <fstream>
// For joining 2 strings
#include <string>
// formatting (decimals and such eg. column width)
#include <iomanip>

using namespace std;

int main()
{
    // Create Stream Variables
    // Input file stream
    ifstream inFile;
    // Output file stream
    ofstream outFile;

    // Create other variables
    string first_name = "";
    string last_name = "";
    string full_name = "";
    double old_salary = 0;
    double new_salary = 0;
    double raise_percent = 0;

    // Open files input/output
    inFile.open("employees.txt");
    outFile.open("salary_raise.txt");

    // Configure output
    outFile << fixed << showpoint << setprecision(2);
    while(!inFile.eof())
    {
        // Read in first line of data
        inFile >> last_name >> first_name >> old_salary >> raise_percent;

        // Do the math
        new_salary = old_salary*(1+raise_percent/100);
        // Format output
        full_name = first_name + " " + last_name;

        // Output to file
        outFile << setw(20) << left << full_name << setw(10) << left << new_salary << endl;
    }

    return 0;
}

//
//  CW 06
//  Team: return to_sleep
//  Programmers: Elias Consalvo, Chabeli Castano, Sebastian Siman
//  Program displaying sales for a Salsa factory.
//

//Libraries
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//constant

const int MAX_ARR_SIZE = 5;

// function prototypes
void displayTitles ();
void displaySalsa (string salsaType [], const int salsaCost [], const int numJars [], int totalCost []); //  displays the different salsa types as well as the amount bought for each
void displayHighestAndLowestSales (string salsaType [], int totalCost []); // compares the values in the total cost array and determines the highest and lowest
int mostJarsSold (const int numJars [], int& largestNum, int& counter1); // compares the numJars array to find the highest number
int leastJarsSold (const int numJars [], int& smallestNum, int& counter2); // compares the numJars array to find the lowest number


int main()
{
    string salsaType [MAX_ARR_SIZE] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"}; // initializing Salsa flavor names

    int smallestNum = 999; // numbers passed for most and least return functions
    int largestNum = 0;
    int counter1 = 0;
    int counter2 = 0;

    const int salsaCost [MAX_ARR_SIZE] = {1, 2, 5, 7, 4}; // populating the array for the price for each flavor

    const int numJars [MAX_ARR_SIZE] = {15, 10, 18, 8, 25}; // populating the array for the number of each flavor purchased

    int totalCost [MAX_ARR_SIZE] = {};

    displayTitles ();
    displaySalsa (salsaType, salsaCost, numJars, totalCost);

    cout << "\n The flavor that sold the most was " << salsaType[counter1] << ", with " << mostJarsSold(numJars, largestNum, counter1) << " sold." << endl;
    cout << "\n The flavor that sold the least was " << salsaType[counter2] << ", with " << leastJarsSold(numJars, smallestNum, counter2) << " sold." << endl;

    displayHighestAndLowestSales(salsaType, totalCost);


    return 0;
}

void displayTitles () //to display the top of every column
{
      cout << setw (7) << "Name" << setw (10) << "Cost" <<setw (16) << "# Jars" <<setw (19) << "Total Cost\n" <<endl;
}

void displaySalsa (string salsaType [], const int salsaCost [], const int numJars [], int totalCost [])
//to display the number of jars, cost of each one, and to calculate and display the total cost
{
    for (int i=0; i<MAX_ARR_SIZE; i++)
    {
        totalCost [i] = salsaCost [i] * numJars [i];
        //int result = totalCost [i];
        //cout << result <<endl;
    }
    for (int i=0; i<MAX_ARR_SIZE; i++)
    {
        cout << setw (7) << salsaType [i] <<setw (9) <<"$ " <<salsaCost [i] <<setw(15) <<numJars [i] <<setw (16)<<totalCost [i] <<endl;
    }

}

 void displayHighestAndLowestSales (string salsaType [], int totalCost []) // to display the highest and lowest sale in terms of money
{
    int comp = totalCost [0];
    int counter = 0;

    for (int i =0; i<MAX_ARR_SIZE; i++)
    {
        if (totalCost [i] < comp)
        {
            comp = totalCost [i];
            counter = i;
        }
    }
    cout << " \n The lowest selling product was: " << salsaType [counter] <<" sauce, with $ " <<comp <<"." <<endl;
    for (int i =0; i<MAX_ARR_SIZE; i++)
    {
        if (totalCost [i] > comp)
        {
            comp = totalCost [i];
            counter = i;
        }
    }
    cout << " \n The highest selling product was: " << salsaType [counter] <<" sauce, with $ " <<comp <<"." <<endl;
}

int mostJarsSold (const int numJars [], int& largestNum, int& counter1)
{
    for (int i = 0; i < MAX_ARR_SIZE; i++)
    {
        if (numJars[i] > largestNum)
        {
            largestNum = numJars[i];
            counter1++;
        }
    }

    return largestNum;
}

int leastJarsSold (const int numJars [], int& smallestNum, int& counter2)
{
    for (int i = 0; i < MAX_ARR_SIZE; i++)
    {
        if (numJars[i] < smallestNum)
        {
            smallestNum = numJars[i];
            counter2++;
        }
    }

    return smallestNum;
}


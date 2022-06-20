/************************************************
** Author: Andrea Hayes
** Date: May 17, 2020
** Purpose: Find Median, Mode and Average for movies
** Input: Number of students and movies saw
** Processing: arrays
** Output: Average, Median and mode
*************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
//Function Prototypes
double getAverage(int[], int);
int getMode(int[], int);
double getMedian(int[], int);
int getInput();
int main() {
    // Declare Variables
    int stu;
    int* results = nullptr;
    int mode;
    double avg, median;

    // Get input
    cout << "How many students were surveyed? ";
    stu = getInput();
    results = new int[stu];
    for (int i = 0; i < stu; i++) {
        cout << "How many movies did they watch? ";
        *(results + i) = getInput();
    }

    //Call and Display Results
    avg = getAverage(results, stu);
    mode = getMode(results, stu);
    median = getMedian(results, stu);

    cout << "Average: " << avg << endl;
    cout << "Mode: " << mode << endl;
    cout << "Median: " << median << endl;

    return 0;
}
// Function to get movies
int getInput()
{
    int movies;
    do {
        cin >> movies;
        if (movies < 0) {
            cout << "Enter a number greater than 0" << endl;
        }
    } while (movies < 0);
    return movies;
}
//Function to figure average
double getAverage(int arr[], int stu) {
    double total = 0, avg;
    for (int i = 0; i < stu; i++) {
        total += arr[i];
    }
    avg = total / stu;
    return avg;
}
// Function to figure mode
int getMode(int arr[], int stu) {
    int maxNum = -1, maxCount = 0;
    for (int i = 0; i < stu; i++) {
        int currentCount = 0;
        for (int j = 0; j < stu; j++) {
            if (arr[j] == arr[i]) {
                currentCount++;
            }
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxNum = arr[i];
        }
    }
    if (maxCount < 2) {
        return -1;
    }
    return maxNum;
}
// Function to figure median
double getMedian(int arr[], int stu) {

    double median, first, second;

    if (stu % 2 != 0) {
        median = *(arr + (stu - 1) / 2);
    }
    else {
        first = *(arr + ((stu / 2) - 1));
        second = *(arr + (stu / 2));
        median = (first + second) / 2.0;
    }
    return median;

}
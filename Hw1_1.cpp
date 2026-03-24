#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void getData(int arr[], int size) {//to fill the array 
    cout << "Enter " << size << " non-negative integers: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void calculateHistogram(int data[], int size, int histogram[], int maxBins) { //how to 
    for (int i = 0; i < size; i++) {
        int binIndex = data[i] / 10; //this is the calculations of sorting based on the number range
        if (binIndex < maxBins) { 
            histogram[binIndex]++; //expands the size of the array based on if a value fits 
        }
    }
}

void displayHistogram(int histogram[], int maxBins) {
    cout << "Histogram Distribution:" << endl;
    for (int i = 0; i < maxBins; i++) {
        int low = i * 10; //starting number 
        int high = low + 9; //decreasing number
        cout << "Bin " << i + 1 << " (" << low << "..." << high << "): " << histogram[i] << " values" << endl; //displays the bin and the values that are in the bin
    }
}

int main() {
    int size; //variable for determining the number of integers that will be inputted
    cout << "Enter the number of integers: "; //asks the user for their input
    cin >> size; //sorts the input

    int* data = new int[size]; // makes a new array based on the size entered
    getData(data, size);
    
    const int maxBins = 20; //setting the max bins to 20
    int histogram[maxBins] = {0}; // Initialize all to zero

    calculateHistogram(data, size, histogram, maxBins);

    displayHistogram(histogram, maxBins);

    return 0;
}
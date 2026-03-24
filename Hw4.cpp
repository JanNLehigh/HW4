#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class userInput{ //class for the input and the function to set the array 
    public:
    userInput(int input){ //constructor for the User input and sorting
        for (int i = 0;i <100 ; i++){ //for loop to sort the input
            array[i]=input;
            int sortingnumber = input / 10; //using the input of the user, making a sorting number to help make the bin
            for(int j=0; j < 100; j++){ // sets the input to the corresponding bin 
                bin[sortingnumber][j] = array[i];
            }
                cout << "Bin" << sortingnumber <<"=" << array <<endl;
        }
        
    }
    userInput();

    private:
    int input; //variable for the input
    int array[100]; //
    int bin[100][100];
};

int main(){
    int input;
    cout << "Enter an integer" << endl;
    cin >> input;
    userInput getIn(input);
    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int r=1;
string layout[10][4];

class Reserved{
    public:
        Reserved(int input, char seatLetter){ //constructor for the seat reservation 
            if(input <= 10 && input >= 1){ // checks for a valid row input 
                switch(seatLetter){ //checks for a valid seat
                    case 'A': //check if the char of the l
                        if(layout[input-1][0] == "A"){
                            layout[input-1][0] = "X";
                            r=1;
                        }else{
                            r=0;
                        }
                        break;
                    case 'B':
                        if(layout[input-1][1] == "B"){
                            layout[input-1][1] = "X";
                            r=1;
                        }else{
                            r=0;
                        }
                        break;
                    case 'C':
                        if(layout[input-1][2] == "C"){
                            layout[input-1][2] = 'X';
                            r=1;
                        }else{
                            r=0;
                        }
                        break;
                    case 'D':
                        if(layout[input-1][3] == "D"){
                            layout[input-1][3] = 'X';
                            r=1;
                        }else{
                            r=0;
                        }
                        break;
                    default:
                        r=0;
                        break;
                    }
                }else{
                    r=0;
                }
        }
        Reserved();
};
    void display(){ // function for display the seats
            for(int i = 0; i < 10; i++){
                cout << i + 1 << " ";
                for (int j = 0; j < 4; j++){
                    cout << layout[i][j] << " ";
                }
                cout << endl;
            }
        }

    void setup(){
        for(int i = 0; i<10; i++){
            layout[i][0] = 'A';
            layout[i][1] = 'B';
            layout[i][2] = 'C';
            layout[i][3] = 'D';
        }
    }



int main(){ // main function to run the code 
    int numPeople; // variable for the number of people that will be booked
    int row; // variable for the row Number 
    char rowLetter; // variable for the letter seat of the person
    string response; // variable for the rerun response
    setup();
    do{
        cout << "How many seats are you booking?" << endl;
        cin >> numPeople;
        for (int ppl = 0;ppl<numPeople;ppl++){
            cout << "What seat will you like to reserve?" << endl;
            cin >> row;
            cin >> rowLetter;
            do{Reserved edit(row,rowLetter);}while(r==0);
        }
        display();
        cout << "Do you want to reserve another seat?" << endl;
        cin >> response;
    }while(response == "Yes" || response == "Y");
    return 0;
}
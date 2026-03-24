#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
string layout[3][3];
int winCon=1;
string active = "X";
string inactive = "O";

class Game{
    public:
        Game(string input){ //constructor for the seat reservation 
                do{
                    for(int i = 0; i<3; i++){
                        for(int j = 0; j<3;j++){
                            if((layout[i][j] == input)){
                                layout[i][j] = active;
                                r = 1;
                            }else if((layout[i][j] != input &&  layout[i][j] == active)){
                                cout << "You have chose this already" << endl;
                            }else if(layout[i][j] != input &&  layout[i][j] == inactive){
                                cout << "This is taken" <<endl;
                            }
                        }
                    }
                }while(r == 0);
            }
        Game();
    private:
        int r = 0;
        
};
    void change(){

        string temp = active;
        active = inactive;
        inactive = temp;
    }
    void display(){ // function for display the seats
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << layout[i][j] << "   ";
            }
            cout << endl;
        }
    }


    void checkup(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(layout[i][0] == active && layout[i][1] == active && layout[i][2] == active){ //row
                    winCon = 1;
                }else if(layout[0][i] == active && layout[1][i] == active && layout[2][i] == active){ //column
                    winCon = 1;
                }else if((layout[0][0]== active && layout[1][1]== active && layout[2][2]== active) || (layout[0][2]== active && layout[1][1]== active && layout[2][0]== active) ){ //diagonal
                    winCon = 1;
                }else{
                    winCon=0;
                }
            }   
        }
        if(winCon == 1){
            cout << "Winner " << active << endl;
        }
    }

    void setup(){
            layout[0][0] = "1";
            layout[0][1] = "2";
            layout[0][2] = "3";
            layout[1][0] = "4";
            layout[1][1] = "5";
            layout[1][2] = "6";
            layout[2][0] = "7";
            layout[2][1] = "8";
            layout[2][2] = "9";
    }




int main(){ // main function to run the code 
    string input;
    setup();
    display();
    do{
        cout << "Enter your move  "<< active << endl;
        cin >> input;
        Game game(input);
        display();
        checkup();
        change();
    }while(winCon == 0);
    return 0;
}
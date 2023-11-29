#include<iostream>
using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int col;
char token = 'x';
string n1;
string n2;

void fun1(){

    cout<<"   |   |   \n";
    cout<<" "<<space[0][0]<<" | "<<space[0][1]<<" | "<<space[0][2]<<endl;
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<endl;
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<endl;
    cout<<"   |   |   \n";
}

void fun2(){
    int digit;
    if(token=='x'){
        cout<<n1<<" its Your turn, Please enter : ";
        cin>>digit;
    }
    if(token=='0'){
        cout<<n2<<" its Your turn, Please enter : ";
        cin>>digit;
    }

    if(digit==1){
        row=0;
        col=0;
    }
    else if(digit==2){
        row=0;
        col=1;
    }
    else if(digit==3){
        row=0;
        col=2;
    }
    else if(digit==4){
        row=1;
        col=0;
    }
    else if(digit==5){
        row=1;
        col=1;
    }
    else if(digit==6){
        row=1;
        col=2;
    }
    else if(digit==7){
        row=2;
        col=0;
    }
    else if(digit==8){
        row=2;
        col=1;
    }
    else if(digit==9){
        row=2;
        col=2;
    }
    else if(digit<1 || digit>9){
        cout<<"Invalid Input"<<endl;
    }

    //-----------putting x and 0 to spaces-------------

    if(token=='x' && space[row][col]!='x' && space[row][col]!='0'){
        space[row][col] = 'x';
        token='0';
    }
    else if(token=='0' && space[row][col]!='x' && space[row][col]!='0'){
        space[row][col] = '0';
        token = 'x';
    }
    else{
        cout<<"There is no empty space."<<endl;
        fun2();
    }
    fun1();

}

bool fun3(){
    //if the player wins the game.
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
            return true;
        }
    }
    if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[2][0]){
        return true;
    }
    //checking game is still going on or not
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j] != 'x' && space[i][j] != '0'){
                return false;
            }
        }
    }
    //any condition doesn't met that is game is draw.
    return false;
}

int main(){
    cout<<"Enter the name of the first player : ";
    getline(cin,n1);
    cout<<"Enter the name of the second player : ";
    getline(cin,n2);
    cout<<"############################################################################"<<endl;
    cout<<n1<<" is the first player so he/she will start first and take x"<<endl;

    while(!fun3()){
        fun1();
        fun2();
    }
    if(token == 'x'){
        cout<<"Hurray!! "<<endl;
        cout<<n2<<" is the winner"<<endl;
    }
    else if(token == '0'){
        cout<<"Hurray!! "<<endl;
        cout<<n1<<" is the winner"<<endl;
    }
    else{
        cout<<"--------Game Draw!!!---------"<<endl;
    }
}
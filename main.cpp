#include <bits/stdc++.h>
using namespace std;
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
void show_board()
{
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"-----------"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"-----------"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<endl;
    cout<<"   |   |   "<<endl;
}
int countb(char a)
{
    int sum=0;
    for(int i=0;i<9;i++)
    {
        if(board[i]==a)
            sum=sum+1;
    }
    return sum;
}
void computerchoice()
{
    srand(time(0));
    int ch;
    do{
        ch=rand()%10;
    }while(board[ch]!=' ');
    board[ch]='O';
}
void playerchoice()
{
    while(true)
    {
        int ch;
        cout<<"Enter position "<<endl;
        cin>>ch;
        ch--;
        if(ch<0 || ch>8)
        {
            cout<<"Invalid position "<<endl;
        }
        else if(board[ch]!=' ')
        {
            cout<<"Enter unoccupied position "<<endl;
        }
        else{
            board[ch]='X';
            break;
        }
    }
}
void player2choice()
{
    while(true)
    {
        int ch;
        cout<<"Enter position "<<endl;
        cin>>ch;
        ch--;
        if(ch<0 || ch>8)
        {
            cout<<"Invalid position "<<endl;
        }
        else if(board[ch]!=' ')
        {
            cout<<"Enter unoccupied position "<<endl;
        }
        else{
            board[ch]='O';
            break;
        }
    }
}
char winner()
{
    //checking winner horizontally
    if(board[0]==board[1] && board[1]==board[2] && board[0]!=' ')
    {
        return board[0];
    }
    if(board[3]==board[4] && board[4]==board[5] && board[3]!=' ')
    {
        return board[3];
    }
    if(board[6]==board[7] && board[7]==board[8] && board[6]!=' ')
    {
        return board[6];
    }
    //checking vertically
    if(board[0]==board[3] && board[3]==board[6] && board[0]!=' ')
    {
        return board[0];
    }
    if(board[1]==board[4] && board[4]==board[7] && board[1]!=' ')
    {
        return board[1];
    }
    if(board[2]==board[5] && board[5]==board[8] && board[2]!=' ')
    {
        return board[2];
    }
    //checking diagonally
     if(board[0]==board[4] && board[4]==board[8] && board[0]!=' ')
    {
        return board[0];
    }
    if(board[2]==board[4] && board[4]==board[6] && board[1]!=' ')
    {
        return board[2];
    }
    if(countb('X')+countb('O')<9)
    {
        return 'C';
    }
    else{
        return 'D';
    }
}
void multiplayer(){
    string p1,p2;
    cout<<"Enter player1 name:";
    cin>>p1;
    cout<<"Enter player2 name:";
    cin>>p2;
    while(true){
        system("cls");
        show_board();
        if(countb('X')==countb('O'))
        {
            playerchoice();
        }
        else
        {
            player2choice();
        }
        char win=winner();
        if(win=='X')
        {
            system("cls");
            show_board();
            cout<<p1<<" won"<<endl;
            break;
        }
        else if(win=='O')
        {
            system("cls");
            show_board();
            cout<<p2<<" won"<<endl;
            break;
        }
        else if(win=='D')
        {
            system("cls");
            show_board();
            cout<<"match drawn"<<endl;
            break;
        }
    }
}
        
void compvsplayer()
{
    string name;
    cout<<"Enter player name ";
    cin>>name;
    while(true)
    {
        system("cls");
        show_board();
        if(countb('X')==countb('O'))
        {
            playerchoice();
        }
        else
        {
            computerchoice();
        }
        char win=winner();
        if(win=='X')
        {
            system("cls");
            show_board();
            cout<<name<<" won"<<endl;
            break;
        }
        else if(win=='O')
        {
            system("cls");
            show_board();
            cout<<"Computer won"<<endl;
            break;
        }
        else if(win=='D')
        {
            system("cls");
            show_board();
            cout<<"match drawn"<<endl;
            break;
        }
    }
}

int main()
{
    while(true){
        system("cls");
        cout<<"1.Player vs Player"<<endl;
        cout<<"2.Player vs computer"<<endl;
        cout<<"3.Exit"<<endl;
        int op;
        cin>>op;
        switch(op)
        {
            case 1:
                multiplayer();
                break;
            case 2:
                compvsplayer();
                break;
            case 3:
                break;
            default:
                cout<<"Enter valid option"<<endl;
        }
    }
    return 0;
}

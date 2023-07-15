#include<bits/stdc++.h>
using namespace std;

bool valueExists(int arr[],int l,int v){//3 7
    for(int i=0; i<l; i++){
        if(arr[i]==v) return true;//2 4 6 7 7 
    }
    return false;
}

int main(){

    int totalG, flipM, winM, diff=2;
    cout<<"Enter total Games, Money for each flip and Winning Money:";
    cin>>totalG>>flipM>>winM;
    int head[5]; int tail[5];
    int games = 0;

    srand(time(nullptr));

    for(int i=0; i<5; i++){
        int v = rand()%10;
        while(valueExists(head,i,v)){
            v = rand()%10;
        }
        head[i]=v;
    }

    cout<<"head: ";
    for(int i=0; i<5; i++){
        cout<<head[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<5; i++){
        int v = rand()%10;
        while(valueExists(tail,i,v) || valueExists(head,5,v)){
            v = rand()%10;
        }
        tail[i]=v;
    }

    cout<<"tail: ";
    for(int i=0; i<5; i++){
        cout<<tail[i]<<" ";
    }
    cout<<endl;

//---------------------playing tossing game-------------------
    int totalPay = 0;
    while(totalG--){
        int totalT=0, totalH=0, gamePay=0;
        cout<<"GAME-"<<games+1<<": ";
        
        //--------- playing each game until difference between head and tail is 2------
        while(true){
            if(abs(totalT-totalH)==diff) break;
            int v = rand()%10;
            gamePay+=flipM;
            if(valueExists(head,5,v)){
                totalH++;
            }
            else{
                totalT++;
            }
        }

        if(gamePay>winM) cout<<"LOSS"<<endl;
        else if(gamePay<winM) cout<<"WIN"<<endl;
        else cout<<"TIE"<<endl;
        totalPay+=gamePay;
        games++;
    }

    int totalWin = winM*games;
    cout<<"Total Money paid: "<<totalPay<<endl;
    cout<<"Total Money won: "<<totalWin<<endl;
    if(totalPay>totalWin) cout<<"Lost By: "<<abs(totalPay-totalWin)<<endl;
    else if(totalPay<totalWin) cout<<"Won By: "<<abs(totalPay-totalWin)<<endl;
    else  cout<<"Tied By: "<<abs(totalPay)<<endl;

    return 0;
}
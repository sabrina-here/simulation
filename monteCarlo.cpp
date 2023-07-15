#include<bits/stdc++.h>
using namespace std;

bool valueExists(int arr[],int l,int v){
    for(int i=0; i<l; i++){
        if(arr[i]==v) return true;
    }
    return false;
}

int main(){

    int x,y;
    cout<<"Enter the starting position x and y:";
    cin>>x>>y;
    int f,b,l,r;
    cout<<"Enter the probability for forward, back, left and right direction respectively: ";
    cin>>f>>b>>l>>r;

    if(f!=0) f/=10; 
    if(b!=0) b/=10;
    if(l!=0) l/=10;
    if(r!=0) r/=10;

    //---------- Initiating Random values for the four directions according to the probability -------------

    srand(time(nullptr));

    int forward[f];
    for(int i=0; i<f; i++){
        int v = rand()%10;
        while(valueExists(forward,i,v)){
            v = rand()%10;
        }
        forward[i]=v;
    }

    cout<<"forward: ";
    for(int i=0; i<f; i++){
        cout<<forward[i]<<" ";
    }
    cout<<endl;

    int back[b];
     for(int i=0; i<b; i++){
        int v = rand()%10;
        while(valueExists(forward,f,v) || valueExists(back,i,v)){
            v = rand()%10;
        }
        back[i]=v;
    }

    cout<<"back: ";
    for(int i=0; i<b; i++){
        cout<<back[i]<<" ";
    }
    cout<<endl;

    int left[l];
     for(int i=0; i<l; i++){
        int v = rand()%10;
        while(valueExists(forward,f,v) || valueExists(back,b,v) || valueExists(left,i,v)){
            v = rand()%10;
        }
        left[i]=v;
    }

    cout<<"left: ";
    for(int i=0; i<l; i++){
        cout<<left[i]<<" ";
    }
    cout<<endl;

    int right[r];
     for(int i=0; i<r; i++){
        int v = rand()%10;
        while(valueExists(forward,f,v) || valueExists(back,b,v) || valueExists(left,l,v) || valueExists(right,i,v)){
            v = rand()%10;
        }
        right[i]=v;
    }

    cout<<"right: ";
    for(int i=0; i<r; i++){
        cout<<right[i]<<" ";
    }
    cout<<endl;

    //------------ steps calculation---------------

    cout<<"Enter increment/decrement value: ";
    int inc; cin>>inc;
    cout<<"Enter the number of steps: ";
    int q; cin>>q;
    int step=1;
    char pos;

    cout<<"step  random-value  direction  position-x   position-y"<<endl;

    while(q--){
        int s = rand()%10;
        if(valueExists(forward,f,s)){
             y+=inc;
             pos = 'F';
        }
        else if(valueExists(back, b,s)){
            y-=inc;
            pos = 'B';
        }
        else if(valueExists(left,l,s)){
            x-=inc;
            pos = 'L';
        }
        else {
            x+=inc;
            pos = 'R';
        }

        cout<<step<<"         "<<s<<"           "<<pos<<"            "<<x<<"               "<<y<<endl;
        step++;
    }

    cout<<endl;
    cout<<"At the end of "<<step-1<<" steps, the drunkard moves to a position: ("<<x<<","<<y<<")"<<endl;

    return 0;
}
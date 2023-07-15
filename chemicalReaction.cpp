#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"Time Interval: ";
    double inv; cin>>inv;
    cout<<"Initial amount of c1, c2 and c3: ";
    double c1, c2, c3; cin>>c1>>c2>>c3;
    cout<<"Total reaction time: ";
    double totalTime; cin>>totalTime;

    double k1 = 0.025, k2 = 0.01;
    double differentialC1 = k2*c3 - k1*c1*c2;
    double differentialC2 = k2*c3 - k1*c1*c2;
    double differentialC3 = 2*k1*c1*c2 - 2*k2*c3;

    double currentTime = 0;

    cout<<"time"<<"\t"<<"C1"<<"\t"<<"C2"<<"\t"<<"C3"<<endl;
    while(true){
        if(currentTime==totalTime) break;
        cout<<currentTime<<"\t"<<c1<<"\t"<<c2<<"\t"<<c3<<endl;
        double prevC1 = c1, prevC2 = c2, prevC3 = c3;
        currentTime+=inv;
        c1 = c1 + differentialC1*inv;
        c1 = round(c1*100)/100;
        c2 = c2 + differentialC2*inv;
        c2 = round(c2*100)/100;
        c3 = c3 + differentialC3*inv;
        c3 = round(c3*100)/100;
        differentialC1 = k2*c3 - k1*c1*c2;
        differentialC1 = round(differentialC1*100)/100;
        differentialC2 = k2*c3 - k1*c1*c2;
        differentialC2 = round(differentialC2*100)/100;
        differentialC3 = 2*k1*c1*c2 - 2*k2*c3;
        differentialC3 = round(differentialC3*100)/100;
        if(currentTime>totalTime){
            cout<<currentTime<<"\t"<<c1<<"\t"<<c2<<"\t"<<c3<<endl<<endl<<endl;
            cout<<"Average: c1= "<<(c1+prevC1)/2<<" c2= "<<(c2+prevC2)/2<<" c3= "<<(c3+prevC3)/2<<endl;
            break;
        }
    }

    return 0;
}
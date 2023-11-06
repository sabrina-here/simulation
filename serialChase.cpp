#include<bits/stdc++.h>
using namespace std;

void catchPrey(double timeInterval,double speedA,double speedB,double speedC,double speedD,double xa,double ya,double xb,double yb,double xc,double yc,double xd,double yd){

    double distAB, distBC, distCD; 
    double currentTime = 0.1;
    while(currentTime!=timeInterval){
        distAB = sqrt(pow((xa-xb),2) + pow((ya-yb),2));
        distBC = sqrt(pow((xc-xb),2) + pow((yc-yb),2));
        distCD = sqrt(pow((xc-xd),2) + pow((yc-yd),2));

        if(distAB<=5){
            cout<<"A hits B at "<<currentTime-0.1<<" when A is at ("<<xa<<", "<<ya<<") and B is at ("<<xb<<", "<<yb<<") position"<<endl;
            break;
        }
        if(distBC<=5){
            cout<<"B hits C at "<<currentTime-0.1<<" when B is at ("<<xb<<", "<<yb<<") and C is at ("<<xc<<", "<<yc<<") position"<<endl;
            break;
        }
        if(distCD<=5){
            cout<<"C hits D at "<<currentTime-0.1<<" when C is at ("<<xc<<", "<<yc<<") and D is at ("<<xd<<", "<<yd<<") position"<<endl;
            break;
        }

        xa += (speedA*((xb-xa)/distAB)*0.1);
        ya += (speedA*((yb-ya)/distAB)*0.1);
        xb -= (speedB*((xc-xb)/distBC)*0.1);
        yb += (speedB*((yc-yb)/distBC)*0.1);
        xc -= (speedC*((xd-xc)/distCD)*0.1);
        yc += (speedC*((yd-yc)/distCD)*0.1);
        yd += (speedD*0.1);

        currentTime+=0.1;
    }

}

int main(){

    cout<<"Enter time: ";
    double timeInterval; cin>>timeInterval;
    cout<<"Enter speed of A B C and D: ";
    double speedA , speedB , speedC , speedD; cin>>speedA>>speedB>>speedC>>speedD;
    cout<<"Enter initial position of A B C and D: ";
    double xa , ya , xb, yb , xc , yc , xd, yd ; cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;

    catchPrey(timeInterval,speedA,speedB,speedC,speedD,xa,ya,xb,yb,xc,yc,xd,yd);    

    return 0;
}
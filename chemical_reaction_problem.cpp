#include<bits/stdc++.h>

using namespace std;

void CRP(float inC1,float inC2,float inC3,float K1,float K2,float time_interval,float time){
float C1 = inC1, C2 = inC2, C3 = inC3;
float t=0;

   cout<<" Time \t C1 \t C2 \t C3 "<<endl;
   while(true){   //changed the condition 

   cout<<"  "<<t<<"\t"<<fixed<<setprecision(2)<<C1<<"\t"<<C2<<"\t"<<C3<<endl;

   if(t==time) break;

   C1 = inC1 + ((K2*inC3-(K1*inC1*inC2))*time_interval);
   C2 = inC2 + ((K2*inC3-(K1*inC1*inC2))*time_interval);
   C3 = inC3 + ((2*K1*inC1*inC2-(2*K2*inC3))*time_interval);
   t += time_interval;

   if(t>time){
         cout<<"  "<<t<<"\t"<<fixed<<setprecision(2)<<C1<<"\t"<<C2<<"\t"<<C3<<endl<<endl<<endl;
         cout<<"Average: C1= "<<(C1+inC1)/2<<"\t"<<"C2 = "<<(C2+inC2)/2<<"\t"<<"C3 = "<<(C3+inC3)/2<<endl;
         break;
   }

   inC1 = C1;
   inC2 = C2;
   inC3 = C3;

   
}

};

int main(){
float inC1,inC2,inC3;
float K1 =0.025,K2 = 0.01;//its constant . No need to take input.
float time_interval;
float time;

cout<<"Enter values for C1,C2,C3: ";
cin>>inC1>>inC2>>inC3;        

cout<<"Enter Time interval: ";
cin>>time_interval;

cout<<"Enter mixture duration: ";
cin>>time;

CRP(inC1,inC2,inC3,K1,K2,time_interval,time);

   return 0;
}

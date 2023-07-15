#include<bits/stdc++.h>
using namespace std;


int main(){ 

       int x=0, y=0;
       double d;
       int q,k;
       cout<<"Enter the diameter : ";
       cin>>d;
       cout<<endl;
       cout<<"Enter The total number of operations: ";
       cin>>q;
       k=q;

       double r= d/2;
       cout<<"The area of the circle is :pi*"<<r*r<<endl;
       double quadArea = (r*r)/4;   //Area of quadrant (M) *pi
       double sqArea = r*r;     //Area of square(N)
       cout<<"The area of quadrant of a circle will be: pi*"<<quadArea<<endl<<endl;
       double mByN = quadArea/sqArea;

       //Calculation display
       cout<<"M = Points lying inside the curve"<<endl;
       cout<<"N = Points lying inside the square area"<<endl;
       cout<<"Area of quadrant/Area of square= M/N"<<endl;
       cout<<"(pi*"<<quadArea<<")/("<<sqArea<<") = M/N"<<endl;

       int M=0, N=0;

       srand(static_cast<unsigned int>(time(nullptr)));

       cout<<"R1      "<<"R2         "<<"root(r^2 - R1^2)"<<"  IN/OUT  "<<"   M   "<<"   N   "<<endl;

       while(q--){
        
        double r1 =  static_cast<double>(rand()) / RAND_MAX * r;
        r1 = round(r1*1000.0)/1000.0;
        double r2 =  static_cast<double>(rand()) / RAND_MAX * r;
        r2 = round(r2*1000.0)/1000.0;
        double result = sqrt(sqArea-(r1*r1));
        result = round(result*1000.0)/1000.0;
        if(r2<=result) M++;
        N++;
        cout<<r1<<"   "<<r2<<"       "<<result<<"         ";
        (r2<=result)? cout<<"    IN    " : cout<<"   OUT   ";
        cout<<"      "<<M<<"      "<<N<<endl;
       }

    //    final result----------------

    cout<<endl<<endl;
    cout<<"M/N = "<<mByN<<endl;
    double res = (double)M/ (double)N;
    cout<<res<<endl;
    cout<<"Out of "<<N<<" points "<<M<<" lie in the quadrant, giving the value, pi= "<<res/mByN<<endl;

    return 0;
}
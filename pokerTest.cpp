#include<bits/stdc++.h>
using namespace std;
int main(){

    int observedFreq[7];
    cout<<"Enter expected frequencies of five different digits, one pair, two pair, three of a kind, full houses,four of a kind and five of a kind"<<endl;
    for(int i=0; i<7; i++) cin>>observedFreq[i];
    cout<<"Enter critical value: ";
    double criticalValue; cin>>criticalValue;
    int totalRandomNumbers = 10000;
    double expectedFrequency[] = {0.3024, 0.5040, 0.1080, 0.0720, 0.009, 0.0045, 0.00001 };

    cout<<"Five diff\t"<<"One pair\t"<<"Two pair\t"<<"Three kind\t"<<"Full House\t"<<"Four kind\t"<<"Five kind\t"<<endl;
    double result =0;
    double resultArray[7];

    // Expected Frequency pre calculated----------------------
    for(int i=0; i<7; i++){
        cout<<expectedFrequency[i]*totalRandomNumbers<<"\t\t";
        expectedFrequency[i] *= totalRandomNumbers;
    }
    cout<<endl;

    // Observed Frequency given by the user------------------
    for(int i=0; i<7; i++){
        cout<<observedFreq[i]<<"\t\t";
        int n = observedFreq[i]-expectedFrequency[i];
        resultArray[i] = abs(n);
    }
    cout<<endl;

    // Observed Frequency - Expected Frequency-------------------
    for(int i=0; i<7; i++){
        cout<<resultArray[i]<<"\t\t";
        resultArray[i] *= resultArray[i];
    }
    cout<<endl;

    // Square of Observed Frequency - Expected Frequency----------------
    for(int i=0; i<7; i++){
        cout<<resultArray[i]<<"\t\t";
        resultArray[i] /= expectedFrequency[i];
    }
    cout<<endl;

    // (Square of Observed Frequency - Expected Frequency)/Expected freq----------------
    for(int i=0; i<7; i++){
        cout<<resultArray[i]<<"\t";
        result += resultArray[i];
    }
    cout<<endl;

    cout<<"The given Critical value is: "<<criticalValue<<endl;
    if(result<=criticalValue){
        cout<<"The computed value "<<result<<" is less than the critical value "<<criticalValue<<" therefore the given random numbers are independent."<<endl;

    }
    else cout<<"The computed value "<<result<<" is higher than the given critical value "<<criticalValue<<" therefore the given random number are not independent."<<endl;

    return 0;
}
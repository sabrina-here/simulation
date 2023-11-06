#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    int cus;
    double arr_mean,ser_mean;
    double arr_standev,ser_standev;
    double In_arrT;
    double In_serT;
    double  IAT;
    double CAT=0,SB,ST,SE,CWT=0,IT;
    double totaltime =0.0,TCWT=0.0,TIT=0.0,avgWT=0.0,PCU=0;
    cout << "Enter number of customers: ";
    cin >> cus;
    cout << "Enter Mean value and Standard deviation value for arrival: ";
    cin >> arr_mean >> arr_standev;
    cout << "Enter Mean value and Standard deviation value for service: ";
    cin >> ser_mean >> ser_standev;

    vector<double> r1, r2;
    ifstream inputFile("numbers.txt"); // Create ifstream object to open file for r1
    if (inputFile.is_open()) {
        double num;
        while (inputFile >> num) {
            r1.push_back(num);
        }
        inputFile.close();
    } else {
        cout << "File not opened" << endl;
        return 1;
    }

    inputFile.open("numbers2.txt"); // Open a different file for r2
    if (inputFile.is_open()) {
        double num;
        while (inputFile >> num) {
            r2.push_back(num);
        }
        inputFile.close();
    } else {
        cout << "Second file not opened" << endl;
        return 1; // Return a non-zero value to indicate an error
    }

    // Shuffle the numbers randomly
    // random_device rd;
    // mt19937 rng(rd());
    // shuffle(r1.begin(), r1.end(), rng);
    // shuffle(r2.begin(), r2.end(), rng);

    cout << "Random numbers 1: ";
    for (int i = 1; i <= cus; i++) {
        cout << r1[i] << " ";
    }
    cout << endl;

    cout << "Random numbers 2: ";
    for (int i = 1; i <= cus; i++) {
        cout << r2[i] << " ";
    }
    cout << endl;
    cout<<"\n"<<endl;
    cout<<" Arrival NO."<<"\t"<<"r'"<<"\t"<<"IAT"<<"\t"<<"CAT"<<"\t"<<"SB"<<"\t"<<"r''"<<"\t"<<"ST"<<"\t"<<"SE"<<"\t"<<"CWT"<<"\t"<<"IT"<<endl;
   int i;
   for(i=1;i<=cus;i++){
    IAT = arr_mean + arr_standev*r1[i];
    CAT += IAT;
    ST = ser_mean + ser_standev*r2[i];
    SE = SB+ST;
    SB = max(SE,CAT);
    IT = CAT - SE;

    if(CWT>=0.0){
        TCWT += CWT;
    }else{
       CWT = 0.0;
    }
    if(IT>=0.0){
      TIT+= IT;
    }else{
       IT = 0.0;
    }

    cout<<"    "<<i<<"\t"<<r1[i]<<"\t"<<IAT<<"\t"<<CAT<<"\t"<<SB<<"\t"<<r2[i]<<"\t"<<ST<<"\t"<<SE<<"\t"<<CWT<<"\t"<<IT<<endl;

    CWT = SE - CAT;
   }
   avgWT = TCWT/cus;
   PCU = ((SE-TIT)/SE)*100;
   cout<<"\n";
   cout<<"Total time elapsed: "<<CAT<<" minutes"<<endl;
   cout<<"Total Customer waiting Time: "<<TCWT<<" minutes"<<endl;
   cout<<"Total Server idle time: "<<TIT<<" minutes"<<endl;
   cout<<"Average waiting time: "<<avgWT<<" minutes per arrival"<<endl;
   cout<<"Percentage Capacity Utilization: "<<PCU<<"%"<<endl;

    return 0;
}

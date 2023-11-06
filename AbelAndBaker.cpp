#include<bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;

double find_service_time(double num, vector<pair<double, pdd>>& v){
    if (num==0) num = 100;
    for(auto p:v){
        double returnValue = p.first;
        double lowerLimit = p.second.first;
        double upperLimit = p.second.second;
        // cout<<upperLimit<<" "<<lowerLimit<<" ";
        if(num<=upperLimit && num>=lowerLimit) return p.first;
    }
    return 0;
}

int main(){
    vector<pdd> IATarr = {{1,0.25}, {2, 0.40}, {3, 0.20}, {4, 0.15}};
    vector<pdd> abel = {{2, 0.30}, {3, 0.28}, {4, 0.25}, {5, 0.17}};
    vector<pdd> baker = {{3, 0.35}, {4, 0.25}, {5, 0.20}, {6, 0.20}};
    vector<pair<double, pdd>> IATrange;
    vector<pair<double, pdd>> abelRange;
    vector<pair<double, pdd>> bakerRange;

    double cumulative_iat_probability = IATarr[0].second;
    IATrange.push_back({IATarr[0].first, {0, cumulative_iat_probability * 100}});

    double cumulative_abel_probability = abel[0].second;
    abelRange.push_back({abel[0].first, {0, cumulative_abel_probability * 100}});

    double cumulative_baker_probability = baker[0].second;
    bakerRange.push_back({baker[0].first, {0, cumulative_baker_probability * 100}});

    for(int i=1; i<IATarr.size(); i++){

        //-------------calculation for the IAT probability table-----------------
        double upperLimit = cumulative_iat_probability * 100 + 1;
        cumulative_iat_probability += IATarr[i].second;
        double lowerLimit = cumulative_iat_probability * 100;
        //cout<<upperLimit<<" "<<lowerLimit<<" ";
        IATrange.push_back({IATarr[i].first, {upperLimit, lowerLimit}});

        //--------------calculation for Abels probability table----------------------
        double abelUpperLimit = cumulative_abel_probability * 100 +1;
        cumulative_abel_probability += abel[i].second;
        double abelLowerLimit = cumulative_abel_probability * 100;
        abelRange.push_back({abel[i].first, {abelUpperLimit, abelLowerLimit}});

        //---------------calculation for Bakers probability table-----------------
        double bakerUpperLimit = cumulative_baker_probability *100 + 1;
        cumulative_baker_probability += baker[i].second;
        double bakerLowerLimit = cumulative_baker_probability * 100;
        bakerRange.push_back({baker[i].first, {bakerUpperLimit, bakerLowerLimit}});
    }


    //---------------------reading Random Arrival time and Random Service time from file----------------
    vector<double> randomArrival;
    vector<double> randomService;
    ifstream inputFile("randomArrival.txt");
    ifstream inputFile2("randomServiceTime.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open the file randomArrival." << endl;
        return 1;
    }
    if (!inputFile2.is_open()) {
        cout << "Unable to open the file randomServiceTime." << endl;
        return 1;
    }

    double num;
    while (inputFile >> num) {
        randomArrival.push_back(num);
    }
    while (inputFile2 >> num) {
        randomService.push_back(num);
    }

    inputFile.close();
    inputFile2.close();

    //-------------------------MAIN CALCULATION---------------------------
    double random_value_for_arrival = 0;
    double IAT = 0; // time between arrival
    double CAT = 0; // cumulative arrival time
    double random_num_for_service = randomService[0];
    double abelSB = 0; // Abel Service begin time
    double abelST = find_service_time(random_num_for_service, abelRange); //Abel Service time
    double abelSE = abelSB + abelST; // Abel Service End
    double bakerSB = 0;
    double bakerSE = 0;
    double bakerST = 0;
    double WT = 0; //waiting time
    double TS = abelST; //Time spent in system
    double IT = 0; //Idle time

    double waited_customers = 0; // number of customers who waited
    double totalWT = WT; //total waiting time
    double totalIT = IT; // total idle time
    double totalTS = TS; // total time spent in system

    for(int i=0; i<9; i++){
        random_value_for_arrival = randomArrival[i];
        IAT = find_service_time(random_value_for_arrival, IATrange);
        // cout<<IAT<<endl;
        CAT += IAT;
        random_num_for_service = randomService[i+1];
        if(CAT>abelSE){//------------this means abel is free and idle
            IT = CAT - abelSE;
            totalIT += IT;
            abelSB = CAT;
            abelST = find_service_time(random_num_for_service, abelRange);
            abelSE = abelSB + abelST;
            TS = abelST;
            totalTS += TS;
        }
        else if(CAT==abelSE){//----------abel is free(not idle)
            abelSB = CAT;
            abelST = find_service_time(random_num_for_service, abelRange);
            abelSE = abelSB + abelST;
            TS = abelST;
            totalTS += TS;
        }
        else if(CAT>bakerSE){//-----------abel is not free, baker is free and idle
            IT = CAT - bakerSE;
            totalIT += IT;
            bakerSB = CAT;
            bakerST = find_service_time(random_num_for_service, bakerRange);
            bakerSE = bakerSB + bakerST;
            TS = bakerST;
            totalTS += TS;
        }
        else if(CAT == bakerSE){//----------abel not free, baker is free, not idle
            bakerSB = CAT;
            bakerST = find_service_time(random_num_for_service, bakerRange);
            bakerSE = bakerSB + bakerST;
            TS = bakerST;
            totalTS += TS;
        }
        else if(CAT< bakerSE && CAT < abelSE){//-----------abel and baker both are busy
            if(abelSE <= bakerSE){//----------abel will be free first or at the same time , so abel will take the customer
                WT = abelSE - CAT;
                totalWT += WT;
                waited_customers++;
                abelSB = CAT;
                abelST = find_service_time(random_num_for_service, abelRange);
                abelSE = abelSB + abelST;
                TS = abelST + WT;
                totalTS += TS;
            }
            else{//----------------baker will be free first , so baker will take the customer
                WT = bakerSE - CAT;
                totalWT += WT;
                waited_customers++;
                bakerSB = CAT;
                bakerST = find_service_time(random_num_for_service, bakerRange);
                bakerSE = bakerSB + bakerST;
                TS = abelST + WT;
                totalTS += TS;
            }
        }
    }

    cout<<" total idle time: "<<totalIT<<" total time in system: "<<totalTS<<" total waiting time: "<<totalWT<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){

    vector<double> r;
    ifstream inputFile("ksRandNums.txt"); //reading random number from file
    if (inputFile.is_open()) {
        double num;
        while (inputFile >> num) {
            r.push_back(num);
        }
        inputFile.close();
    } else {
        cout << "File not opened" << endl;
        return 1;
    }

    sort(r.begin(),r.end());

    // for(double n:r) cout<<n<<" ";

    int N = r.size();
    // cout<<N<<endl;
    cout<<"Enter critical value: "<<endl;
    double criticalValue ; cin>>criticalValue;

    
    double dPlus= INT_MIN, dMinus= INT_MIN;
    
    for(int i=1, j=0; i<=N; i++, j++){
        double v1 = ((double)i/N) - r[j];
        double v2 = r[j] - (((double)i-1)/N);
        // cout<<v1<<" "<<v2<<endl;
        dPlus = max(dPlus,v1);
        dMinus = max(dMinus, v2);
    }

    cout<<"The computed Maximum of D+ is: "<<dPlus<<endl;
    cout<<"The computed Maximum of D- is: "<<dMinus<<endl;
    double largest_deviation = max(dPlus, dMinus);
    cout<<"The largest deviation is : "<<largest_deviation<<endl;
    cout<<"The critical value is: "<<criticalValue<<endl;
    if(largest_deviation<=criticalValue){
        cout<<"Since the computed value : "<<largest_deviation<<" is less than/equal to the critical value the given random number are uniform"<<endl;
    }
    else{
                cout<<"Since the computed value : "<<largest_deviation<<" is greater than the critical value the given random number are not uniform"<<endl;

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<double> t, xbList, ybList;

    std::ifstream inputFile("bomberPositions.txt"); //Create ifstream object and open the file

    if (inputFile.is_open()) { //check if file is open
        string line;
        getline(inputFile, line);
        stringstream ss(line);
        double num;
        while( ss>>num){
            t.push_back(num);
        }
        string line2;
        getline(inputFile, line2);
        stringstream ss2(line2);
        while( ss2>>num){
            xbList.push_back(num);
        }
        string line3;
        getline(inputFile, line3);
        stringstream ss3(line3);
        while(ss3>>num){
            ybList.push_back(num);
        }        

        inputFile.close(); // Close the file
    } else {
        cout << "Failed to open the file." << endl;
        return 0;
    }

    // for(double n:t) cout<<n<<" ";
    // cout<<endl;
    // for(double n:xb) cout<<n<<" ";
    // cout<<endl;
    // for(double n:yb) cout<<n<<" ";
    // cout<<endl;


    double xf, yf, S, inv;
    cout<<"Fighters Initial position (xf,yf): ";
    cin>>xf>>yf;
    cout<<"Fighters Speed: ";
    cin>>S;
    cout<<"Interval: ";
    cin>>inv;

    //-------- Initial calculations---------------
    double xb = xbList[0];
    double yb = ybList[0];
    double dist = sqrt(pow((yb-yf),2)+ pow((xb-xf),2));
    double sinTheta = (yb-yf)/dist;
    double cosTheta = (xb-xf)/dist;

    //--------printing values for time=0----------
    cout<<endl<<endl;
    cout<<"Time: 0"<<endl;
    cout<<"yb: "<<yb<<endl;
    cout<<"yf: "<<yf<<endl;
    cout<<"xb: "<<xb<<endl;
    cout<<"xf: "<<xf<<endl;
    cout<<"dist: "<<dist<<endl;
    cout<<"sinTheta: "<<sinTheta<<endl;
    cout<<"cosTheta: "<<cosTheta<<endl<<endl<<endl;

    int len = t.size();
    int loopCounter = 1;

    while(loopCounter<=len && dist>10){

        cout<<"Time: "<<loopCounter<<endl;
        yb = ybList[loopCounter]; cout<<"yb: "<<yb<<endl;
        yf = yf + S*sinTheta; cout<<"yf: "<<yf<<endl;
        xb = xbList[loopCounter]; cout<<"xb: "<<xb<<endl;
        xf = xf + S*cosTheta; cout<<"xf: "<<xf<<endl;
        dist = sqrt(pow((yb-yf),2)+ pow((xb-xf),2)); cout<<"dist: "<<dist<<endl;
        sinTheta = (yb-yf)/dist; cout<<"sinTheta: "<<sinTheta<<endl;
        cosTheta = (xb-xf)/dist; cout<<"cosTheta: "<<cosTheta<<endl<<endl<<endl;

        loopCounter+=inv;
    }

    if(dist>10) cout<<"The Bomber escaped"<<endl;
    else{
        cout<<"The fighter is able to destroy the bomber at ";
    cout<<--loopCounter<<" minutes when the distance between them is "<<dist<<" km."<<endl;
    }

    return 0;
}
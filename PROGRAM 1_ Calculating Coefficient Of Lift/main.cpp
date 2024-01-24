#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// reads data from the file and places it vectors angle then coefficient
void readData(const string &filename, vector<double> &angles, vector<double> &coefficients){
    ifstream fin(filename);
    double value;
    if (!fin.is_open()){
        cout << "Error opening " << filename << endl;
    }
    while(fin >> value){
        angles.push_back(value);
        fin >> value;
        coefficients.push_back(value);
    }

    fin.close();
}

double interpolation(double angle, const vector<double> &angles, const vector<double> &coefficients){
    for (unsigned int i = 0; i < angles.size(); i++){
        if (angle == angles[i]){
            return coefficients[i];
        }
    }

    //variable names follow given equation
    double a = angles[0]; //value of biggest min
    int aIndex = 0;       //index of biggest min
    // b = angle
    double c = angles[angles.size() - 1]; //value of smallest max
    int cIndex = angles.size() - 1;       //index of smallest max

    for (unsigned int i = 0; i < angles.size(); i++){ 
        if (angles[i] < angle && angles[i+1] > angle){
            a = angles[i];
            aIndex = i;
            c = angles[i + 1];
            cIndex = i + 1;
        }
    }
    //return f(b) = f(a) +         ((   b  - a) / (c - a)) * (      f(c)           -        f(a)         )
    return (coefficients[aIndex] + ((angle - a) / (c - a)) * (coefficients[cIndex] - coefficients[aIndex]));
}

//returns true if each value of angle vector is larger than the last
bool isOrdered(const vector<double> &angles){
    for (unsigned int i = 1; i < angles.size(); i++){
        // next is less than previous
        if (angles[i] < angles[i -1]){
            return false;
        }
    }
    return true;
}

//changes flight-path angles to ascending order using selection sort
void reorder(vector<double> &angles, vector<double> &coefficients){
    //selection sort
    double minAngle;
    int minIndex;
    double tempAngle;
    double tempCoef;

    for (unsigned int i = 0; i < angles.size(); i++){
        minAngle = angles[i];
        minIndex = i;
        for (unsigned int ii = i; ii < angles.size() ; ii++){
            
            if (angles[ii] < minAngle){
                minAngle = angles[ii];
                minIndex = ii;
            }
        }

        tempAngle = angles[i];
        angles[i] = minAngle;
        angles[minIndex] = tempAngle;

        tempCoef = coefficients[i];
        coefficients[i] = coefficients[minIndex];
        coefficients[minIndex] = tempCoef;
    }
}

int main(int argc, char *argv[]){
    string fileName = argv[1];
    vector<double> angles;
    vector<double> coefficients; 

    ifstream fin(fileName);
    if (!fin.is_open()){
        cout << "Error opening " << fileName << endl;
        fin.close();
        return 0;
    }
    
    readData(fileName,angles,coefficients);

    string input = "";
    double inputAngle;
    if (!isOrdered(angles)){
        reorder(angles,coefficients);
    }else{
        double minAngle = angles[0];
        double maxAngle = angles.back();
        while (input != "No"){
            cout << "Enter an angle:" << endl;
            cin >> inputAngle;
            if (inputAngle >= minAngle && inputAngle <= maxAngle){
                cout << interpolation(inputAngle, angles, coefficients ) << endl;
            }
            cout << "Would you like to calculate again?" << endl;
            cin >> input;
        }
    }

    return 0;

}
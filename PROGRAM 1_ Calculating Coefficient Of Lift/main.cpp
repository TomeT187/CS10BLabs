#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// reads data from the file and places it vectors angle then coefficient
void readData(const string &filename, vector<double> &angles, vector<double> &coefficients){
    ifstream fin(filename);
    double value;
    while(fin >> value){
        angles.push_back(value);
        fin >> value;
        coefficients.push_back(value);
    }

    fin.close();
}
double interpolation(double angle, const vector<double> &angles, const vector<double> &coefficients){
    //return f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a)) or f(b) if exists

    //if b exists return f(b)
    for (unsigned int i = 1; i < angles.size(); i++){
        if (angle == angles[i]){
            return coefficients[i];
        }
    }

    double a = angles[0]; //biggest min
    int aIndex = 0;
    // b = angle
    double c = angles[angles.size() - 1]; //smallest max
    int cIndex = angles.size() - 1;

    for (unsigned int i = 1; i < angles.size(); i++){ 
        if (angles[i] > a && angles[i] < angle){
            a = angles[i];
            aIndex = i;
            c = angles[i + 1];
            cIndex = i + 1;
        }
    }
    //return f(b) = f(a) +         ((   b  - a) / (c - a)) * (      f(c)           -        f(a)         )
    return (coefficients[aIndex] + ((angle - a) / (c - a)) * (coefficients[cIndex] - coefficients[aIndex]));

}

bool isOrdered(const vector<double> &angles){
    for (unsigned int i = 1; i < angles.size(); i++){
        // next is less than previous
        if (angles[i] < angles[i -1]){
            return false;
        }
    }
    return true;
}

//changes flight-path angles to ascending order 
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
    //string fileName = argv[1];
    string fileName = "tunnel2.dat";
    vector<double> angles;
    vector<double> coefficients; 

    readData(fileName,angles,coefficients);
    for (unsigned int i = 0; i < angles.size(); i++){
        cout << angles[i] << " " << coefficients[i] << endl;
    }
    cout << "fisni" << endl;
    reorder(angles,coefficients);
    for (unsigned int i = 0; i < angles.size(); i++){
        cout << angles[i] << " " << coefficients[i] << endl;
    }
    cout << interpolation(8.0, ); // finnish testing
    return 0;

}
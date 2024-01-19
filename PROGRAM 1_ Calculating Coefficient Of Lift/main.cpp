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
double interpolation(double, const vector<double> &, const vector<double> &);

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
void reorder(vector<double> &angles, vector<double> &coefficients);

int main(int argc, char *argv[]){
    string fileName = argv[1];
    vector<double> angles;
    vector<double> coefficients; 

    readData(fileName,angles,coefficients);
    for (unsigned int i = 0; i < angles.size(); i++){
        cout << angles[i] << " " << coefficients[i] << endl;
    }
    cout << "fisni" << endl;

    return 0;

}
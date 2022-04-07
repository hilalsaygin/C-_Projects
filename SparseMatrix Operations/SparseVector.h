#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H

class SparseVector{
public: 
    SparseVector(); // initialize index and data as zero  for 1 demensional vector 
    SparseVector(int vecSize); 
    SparseVector(string &inputFile);
    //void SparseVector(string inputString);

    const SparseVector operator + (const  SparseVector& v2) const; 
    SparseVector operator - ( const SparseVector& v2)  const; 
    SparseVector operator -() const  ;
    SparseVector& operator =( SparseVector& other); 
    void parse_input(stringstream& inputLine); // parse the input as index:data pairs and return the vector size
    void parse_data(string pairs, int& index,double& data); //parse index and data info and returns VectorData object. if input string empty set the data as zero 
    void push_vectorElement(int index, double data);
    void push_data(double data);
    const double dot(const SparseVector &v2);
    double  operator [] (int index) const;
    int getVectorSize();
    void initialize(int vSize);
    friend ostream& operator << (ostream &out, const SparseVector &vec);

private:
    vector<double> dataArray;

};

#endif
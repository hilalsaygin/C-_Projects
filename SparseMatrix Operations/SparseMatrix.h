#include "SparseVector.h"

class SparseMatrix{
   public: 
    SparseMatrix(); // initialize index and data as zero  for 1 demensional vector 
    SparseMatrix(string &inputFile);
    
    const SparseMatrix operator + (  SparseMatrix& other) const; 
    const SparseMatrix operator - (  SparseMatrix& other) const; 
    const SparseMatrix operator - ( ) const;
    SparseVector operator[](int index) ;
    SparseMatrix&  operator =( SparseMatrix& other) ;
    const SparseMatrix transpose(const SparseMatrix& other);
    friend ostream& operator << (ostream &out, const SparseMatrix &matrix);
    const SparseMatrix operator * ( SparseMatrix& m2) ; 
    SparseMatrix transpose();



   private:
    vector<SparseVector> Matrix;
};
#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include "classes"
using namespace std;

int main() {
    try{
        Matrices<int> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
        Matrices<int> sum;
        Matrices<double> sums;
        Matrices<double> test;
        cout << "Working with matrix:" << endl;
        cout << "Matrix m:" << endl << m << endl;
        sum = m + m;
        cout << "Sum of two matrices m:" << endl << sum << endl;
        sum = sum - m;
        cout << "Subtract matrix m from the sume above:" << endl << sum << endl;
        sum = m * m;
        cout << "Multiply two matrices m:" << endl << sum << endl;
        sum = m * 2;
        cout << "Multiply matrix m by 2:" << endl << sum << endl;
        sum = m.adamar(m);
        cout << "Find Adamar composition for matrix m:" << endl << sum << endl;
        cout << "Find trace for matrix m: " << m.trace() << endl;
        cout << "Calculate Frobenius norm for matrix m: " << m.frobenius() << endl;
        cout << "Compute rank of matrix m: " << m.rank() << endl;
        sum = m.transpose();
        cout << "Find transposed matrix for matrix m:" << endl << sum << endl;
        TopTriang<int> t({{1, 1, 1}, {0, 2, 1}, {0, 0, 1}});
        cout << "Create top triangle matrix t:" << endl << t << endl;
        BottomTriang<int> b({{1, 0, 0}, {1, 2, 0}, {9, 7, 1}});
        cout << "Create bottom triangle matrix b:" << endl << b << endl;
        Identical<int> identix({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
        cout << "Create identical matrix b:" << endl << identix << endl;
        Symmetrical<int> sym({{1, 2}, {2, 1}});
        cout << "Determinant of matrix t: " << t.determinant(t.size()) << endl;
        Matrices<double> ms({{1.0, 9.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}});
        cout << "Print matrix ms:" << endl << ms << endl;
        cout << "Create matrix ms:" << endl << ms << endl;
        sums = ms.reverse();
        cout << "Compute reversed matrix of matrix ms:" << endl << sums << endl;
        
        ifstream file;
        file.open("m.txt");
        file >> test;
        file.close();
        cout << "Print matrix that was read from file:" << endl << test << endl;
        
        ofstream files;
        files.open("m.txt");
        files << test;
        files.close();
        
        m.wbin("m1.bin"); //write matrix m into new binary file
        Matrices<int> tests;
        tests.rbin("m1.bin", 3, 3);//read matrix from binary file
        cout << "Matrix that was read from binary file:" << endl << tests << endl;
        
        cout << "Working with vectors:" << endl;
        
        Vectors<int> v({{1}, {2}, {3}});
        Vectors<int> v1({{1}, {2}, {3}, {4}});
        Vectors<int> sample;
        Vectors<int> samples;
        cout << "Print vector v:" << endl << v << endl;
        v = v*2;
        cout << "Multiply vector v by 2:" << endl << v << endl;
        v = v + v;
        cout << "Sum of two vector v:" << endl << v << endl;
        int e = v * v;
        cout << "Scalar of two vectors v: " << e << endl;
        cout << "Find Evklid norm for vector v: " << v.enorm() << endl;
        cout << "Find Max norm for vector v: " << v.maxnorm() << endl;
        cout << "Find cos of angle between the same vector v: " << v.angle(v) << endl;
        file.open("v.txt");
        file >> sample;
        file.close();
        cout << "Vector that was read from file:" << endl << sample << endl;

        files.open("v.txt");
        files << sample;
        files.close();

        sample.wbin("v1.bin");
        samples.rbin("v1.bin", 3, 1);
        cout << "Vector that was read from binary file:" << endl << samples << endl;

        //Exceptions:
        Matrices<double> test1({{1, 2}, {3, 4}});
        Matrices<double> test2({{1, 2}, {3, 4}, {5, 6}});
        //sums = test1 + test2;//not working as it should be
        //test2.determinant(test2.size());//not working as it should be
        cout << "New rank: " << test2.rank() << endl;//working as it should be
        //sample = v + v1;//not working as it should be
        //e = v * v1;//not working as it should be

    }
    catch(int exept){
        if (exept == -1) cout << "This is not a matrix!";
        if (exept == 0) cout << "Wrong shapes of matrices!";
        if (exept == 1) cout << "This is not top triangle matrix!";
        if (exept == 2) cout << "This is not a vector!";
        if (exept == 3) cout << "Wrong shapes of vectors!";
        if (exept == 4) cout << "This is not bottom trinagle matrix!";
        if (exept == 5) cout << "This is not identical matrix!";
        if (exept == 6) cout << "This is not symmetrical matrix!";
    }
    catch (out_of_range err){
        cout << "Ohh... something went wrong! That's what happened: " << err.what() << endl << "It seems you were out of range!" << endl;
    }
  return 0;
}
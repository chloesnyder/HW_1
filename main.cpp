// Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright, Tiantian Liu, Benedict Brown, and Adam Mally
// University of Pennsylvania

// At least some C++ compilers do funny things
// to C's math.h header if you don't define this
#define _USE_MATH_DEFINES

#include "vec4.h"
#include "mat4.h"
#include <iostream>
#include <math.h>
using namespace std;

//TODO: UPDATE THE TESTS!!! To reflect w = 1, only doing data[0]-data[2] for operations

int main() {
    // Add your own tests here
    vec4 a = vec4(1, 2, 3, 1);
    vec4 z = vec4(1, 2, 4, 1);
    vec4 y = vec4(z);
    vec4 x = vec4();

    cout << "Test Cases Part 1:" << endl;
    cout << "test constructor vec4() (should be 0,0,0,0): " << x << endl;
    cout << "test constructor vec4(x,y,z,w) (should be 1,2,3,1): " << z << endl;
    cout << "test copy constructor: " << y << endl;
    //std::cout << y[5] << std::endl; //test assert fail
    cout<< "test [] (should be 4): " << z[2] << endl;
    x=z;
    cout<< "test assignment x=z (should be 1,2,4,1): "  << x << endl;
    cout<< "test equality true: " << (x==z) << endl;
    cout<< "test inequality true: " << (x!=a) << endl;
    cout<< "test equality false: " << (x==a) << endl;
    cout<< "test inequality false: " << (x!=z) << endl;
    a+=y;
    cout<< "test += (should be 2 4 7 1): "  << a << endl;
    a-=z;
    cout<< "test -= (should be 1 2 3 1): "  << a << endl;
    x*=5;
    cout<< "test *= (should be 5 10 20 1): "  << x << endl;
    x/=4;
    cout<< "test /= (should be 1.25 2.5 5 1): "  << x << endl;
    vec4 b = a + a;
    cout<< "test + (should be 2 4 6 1): "  << b << endl;
    b = b - a;
    cout<< "test - (should be 1 2 3 1): "  << b << endl;
    b = z*2;
    cout<< "test * (should be 2 4 8 1): "  << b << endl;
    b = z/1.5;
    cout<< "test / (should be ~ .666 1.333 2.666 1): "  << b << endl;
    float r = dot(vec4(1,2,3,0),vec4(1,2,4,0));
    cout<<"test dot (should be 17): " << r << endl;
    vec4 d = cross(a, vec4(4, 5, 6, 1));
    cout<<"test cross (should be  -3, 6, -3 0): " << d << endl;
    d = cross(vec4(4, 5, 6, 1), a);
    cout<<"test cross reversed(should be  3, -6, 3 0): " << d << endl;
    r = length(a);
    cout<<"test length (should be ~3.87298): " << r << endl;
    b = 2*z;
    cout<< "test scalar (c * v) (should be 2 4 8 1): "  << b << endl << endl;

    mat4 m = mat4();
    mat4 mdiag = mat4(1);
    mat4 mexplicit = mat4(a, x, z, y);
    mat4 mcopy = mat4(mexplicit);
    mat4 m2 = mat4(a, a, a, a);
    cout<< "Test Cases Part 2: " << endl;
    cout<< "test constructor mat4() (should be 4x4 matrix with all 0s): " << m << endl;
    cout<< "test constructor mat4(float diag) (should be 4x4 matrix with 1 diagonal and all 0's): " << mdiag << endl;
    cout<< "test constructor row0-row3: (should output \n 1, 2, 3, 1 \n 1.25, 2.5, 5, 1 \n 1, 2, 4, 1 \n 1, 2, 4, 1): \n" << mexplicit << endl;
    cout<< "test copy constructor (should be same as above): " << mcopy << endl;
    cout<< "test [] operator (should be 1,2,4,1): " << mcopy[3] << endl;
    mat4 rotx = mat4::rotate(30, 1, 0, 0);
    mat4 roty = mat4::rotate(45, 0, 1, 0);
    mat4 rotz = mat4::rotate(60, 0, 0, 1);
    mat4 trans = mat4::translate(2, 4, 2);
    mat4 scal = mat4::scale(2, 2, 5);
    mat4 ident = mat4::identity();
    cout<< "test rotate (should produce rotation matrix 30 degrees about x axis): " << rotx << endl;
    cout<< "test rotate (should produce rotation matrix 45 degrees about y axis): " << roty << endl;
    cout<< "test rotate (should produce rotation matrix 60 degrees about z axis): " << rotz << endl;
    cout<< "test translate(translate matrix for 2, 4, 2): " << trans << endl;
    cout<< "test scale(scale for 2, 2 5): " << scal << endl;
    cout<< "test identity: " << ident << endl;
    m = m2;
    cout<< "test assignment (should print 4 rows of 1, 2, 3, 1): " << m << endl;
    cout<< "test equality true: " << (m==m2) << endl;
    cout<< "test equality false: " << (m==mdiag) << endl;
    cout<< "test inequality true: " << (m!=mdiag) << endl;
    cout<< "test inequality false: " << (m!=m2) << endl;
    cout<< "test += (should output \n 2, 2, 3, 1 \n 1, 3, 3, 1 \n 1, 2, 4, 1 \n 1, 2, 3, 2): \n " << (mdiag+=m) << endl;
    cout<< "test -= (should be 4x4 matrix with all 0's but 1 diagonal): " << (mdiag-=m) << endl;
    cout<< "test *= (should be 4 rows of 3, 6, 9 ,3): " << (m2*=3) << endl;
    cout<< "test /= (should be 4 rows of 1, 2, 3, 1): " << (m2/=3) << endl;
    cout<< "test +=(should be 4x4 matrix of all 0's but 2 diagonal) : " << (mdiag+mdiag) << endl;
    cout<< "test - (should output \n 0, 2, 3, 1 \n 1.25, 1.5, 5, 1 \n 1, 2, 3, 1 \n 1, 2, 4, 0): \n " << (mcopy-mdiag) << endl;
    cout<< "test * (should output \n 2, 4, 6, 2 \n 2.5, 5, 10, 2 \n 2, 4, 8, 2.5 \n 2, 4, 8, 2): \n" << (mcopy*2) << endl;
    cout<< "test / (should be 4 rows of .5, 1, 1.5, .05): " << (m2/2) << endl;
    cout<< "test * matrix mult (should be 4 rows of 1, 2, 3, 1): " << m2*mdiag << endl;
    cout<< "test transpose (should be a row of 1's, then 2's, then 3's then 1's): " << transpose(m2) <<endl;
    cout<< "test column (should be 2, 2.5, 2, 2): " << column(mexplicit, 1) << endl;
    cout<< "test scalar matrix mult (c * m) (should be 4 rows of 2, 4, 6, 2): " << 2*m2 << endl;
    cout<< "test vector/matrix mult v*m (should be 4 15's): " << a*m2 << endl;
}

#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

// Given a vector, rotate it centered from zero point by 45 degree anti-clockwise and move with (1, 2)
// Return final vector
Eigen::MatrixXd calculateWithMatrix(Eigen::MatrixXd m0) {
    float alpha = 45.0 / 180.0 * acos(-1);
    Eigen::MatrixXd m1(3, 3);
    m1 << cos(alpha), -sin(alpha), 1, sin(alpha), cos(alpha), 2, 0, 0, 1;
    return m1 * m0;
}

// Given a vector, rotate it centered from zero point by 45 degree anti-clockwise and move with (1, 2)
// Return final vector
Eigen::Vector2f calculateWithVector(Eigen::Vector2f v0) {
   float x0 = v0.x();
   float y0 = v0.y();

   // First calculate the length of the original vector
   float alpha = 45.0f/180.0f * acos(-1);
   float x1 = x0 * cos(alpha) - y0 * sin(alpha);
   float y1 = x0 * sin(alpha) + y0 * cos(alpha);

   // Finally add it to vector (1, 2)
   Eigen::Vector2f v1(x1, y1);
   Eigen::Vector2f v2(1.0f, 2.0f);
   return v1 + v2;
}

int main(){

    // Basic Example of cpp
    std::cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    std::cout << a << std::endl;
    std::cout << a/b << std::endl;
    std::cout << std::sqrt(b) << std::endl;
    std::cout << std::acos(-1) << std::endl;
    std::cout << std::sin(30.0/180.0*acos(-1)) << std::endl;

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f,2.0f,3.0f);
    Eigen::Vector3f w(1.0f,0.0f,0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;
    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << v * 3.0f << std::endl;
    std::cout << 2.0f * v << std::endl;

    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i,j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    // matrix add i + j
    // matrix scalar multiply i * 2.0
    // matrix multiply i * j
    // matrix multiply vector i * v

    Eigen::Vector2f v0(2.0f, 1.0f);
    std::cout << "Test myself" << std::endl;
    std::cout << "Vector way" << std::endl; 
    std::cout << calculateWithVector(v0) << std::endl;

    // We also use homogenious matrix
    Eigen::MatrixXd m0(3, 1);
    m0 << 2.0, 1.0, 1.0;
    std::cout << "Matrix way" << std::endl;
    std::cout << calculateWithMatrix(m0) << std::endl;
    return 0;
}

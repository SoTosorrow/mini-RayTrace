#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

int main(int argc,char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    // argc:numbe of parameter,if have no parameter,argc = 1(itself)
    // argv[0]  is itself
    // argv[1] first parameter..
    // > ./first_test 45
    bool input_degree = false;
    for(int i=0;i<argc;i++){
    	if(i == 1){
		input_degree = true;
	}
    
    }
    
    /*
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
    std::cout<< i + j <<'\n';
    // matrix scalar multiply i * 2.0
    std::cout<< i * 2.0f <<'\n';
    // matrix multiply i * j
    std::cout<< i * j <<'\n';
    // matrix multiply vector i * v
    std::cout<< i * v <<'\n';
    */

    // create a point(2,1)
    Eigen::Vector3f point(2.0f,1.0f,1.0f);
    Eigen::Matrix3f rotation_matrix;
    Eigen::Matrix3f translation_matrix;
    Eigen::Vector3f translation_point;
    double d = 90.0;
    if(input_degree){
    	d = std::atof(argv[1]);
    }
    std::cout<<"degree:"<<d<<'\n';
    d = d/180.0*M_PI;
  
    // rotation matrix
    rotation_matrix << std::cos(d), -1.0*std::sin(d), 0,
		    std::sin(d), std::cos(d), 0,
		    0, 0, 1;
    // R45(CCW)
    // translation (1,2)
    translation_matrix << 1, 0, 1,
		       	  0, 1, 2,
			  0, 0, 1;
    translation_point = translation_matrix * rotation_matrix * point;
    std::cout<<translation_point << '\n';
    
    
    return 0;
}

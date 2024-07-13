#include "function.h"
#include "Matrix.h"
#include "Simpson.h"

using namespace std;

int main () {

    functionOne fun;

    double integral_0_1 = 2.0;
    double integral_1_1 = M_PI;
    double integral_5_5 = 56.363569;

    ofstream of;

    std::cout << "Numerical series integral m=0 k=1 : " << fun.countIntegralFunction ( 0, 1, 0, M_PI ) << "\t\tShould be : " << integral_0_1 << '\n';
    std::cout << "Numerical series integral m=1 k=1 : " << fun.countIntegralFunction ( 1, 1, 0, M_PI ) << "\tShould be : " << integral_1_1 << '\n';
    std::cout << "Numerical series integral m=5 k=5 : " << fun.countIntegralFunction ( 5, 5, 0, M_PI ) << "\tShould be : " << integral_5_5 << '\n';

    std::cout << "\n";

    of.open ( "../Simp_0_1.txt" );
    std::cout << "Simpson integral m=0 k=1 N=11 : " << Simpson::countCalka(0, M_PI, &fun, 11, 0, 1 ) << '\n';
    std::cout << "Simpson integral m=0 k=1 N=21 : " << Simpson::countCalka(0, M_PI, &fun, 21, 0, 1 ) << '\n';
    std::cout << "Simpson integral m=0 k=1 N=51 : " << Simpson::countCalka(0, M_PI, &fun, 51, 0, 1 ) << '\n';
    std::cout << "Simpson integral m=0 k=1 N=101 : " << Simpson::countCalka(0, M_PI, &fun, 101, 0, 1 ) << '\n';
    std::cout << "Simpson integral m=0 k=1 N=201 : " << Simpson::countCalka(0, M_PI, &fun, 201, 0, 1 ) << '\n';
    std::cout << "\tShould be : " << integral_0_1 << '\n';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 11, 0, 1 ) - integral_0_1) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 21, 0, 1 ) - integral_0_1) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 51, 0, 1 ) - integral_0_1) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 101, 0, 1 ) - integral_0_1) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 201, 0, 1 ) - integral_0_1) << ' ';
    of.close();

    std::cout << '\n';

    of.open ( "../Simp_1_1.txt" );
    std::cout << "Simpson integral m=1 k=1 N=11 : " << Simpson::countCalka(0, M_PI, &fun, 11, 1, 1 ) << '\n';
    std::cout << "Simpson integral m=1 k=1 N=21 : " << Simpson::countCalka(0, M_PI, &fun, 21, 1, 1 ) << '\n';
    std::cout << "Simpson integral m=1 k=1 N=51 : " << Simpson::countCalka(0, M_PI, &fun, 51, 1, 1 ) << '\n';
    std::cout << "Simpson integral m=1 k=1 N=101 : " << Simpson::countCalka(0, M_PI, &fun, 101, 1, 1 ) << '\n';
    std::cout << "Simpson integral m=1 k=1 N=201 : " << Simpson::countCalka(0, M_PI, &fun, 201, 1, 1 ) << '\n';
    std::cout << "\tShould be : " << integral_1_1 << '\n';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 11, 1, 1 ) - integral_1_1) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 21, 1, 1 ) - integral_1_1) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 51, 1, 1 ) - integral_1_1) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 101, 1, 1 ) - integral_1_1) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 201, 1, 1 ) - integral_1_1) << ' ';
    of.close();

    std::cout << '\n';

    of.open ( "../Simp_5_5.txt" );
    std::cout << "Simpson integral m=5 k=5 N=11 : " << Simpson::countCalka(0, M_PI, &fun, 11, 5, 5 ) << '\n';
    std::cout << "Simpson integral m=5 k=5 N=21 : " << Simpson::countCalka(0, M_PI, &fun, 21, 5, 5 ) << '\n';
    std::cout << "Simpson integral m=5 k=5 N=51 : " << Simpson::countCalka(0, M_PI, &fun, 51, 5, 5 ) << '\n';
    std::cout << "Simpson integral m=5 k=5 N=101 : " << Simpson::countCalka(0, M_PI, &fun, 101, 5, 5 ) << '\n';
    std::cout << "Simpson integral m=5 k=5 N=201 : " << Simpson::countCalka(0, M_PI, &fun, 201, 5, 5 ) << '\n';
    std::cout << "\tShould be : " << integral_5_5 << '\n';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 11, 5, 5 ) - integral_5_5) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 21, 5, 5 ) - integral_5_5) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 51, 5, 5 ) - integral_5_5) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 101, 5, 5 ) - integral_5_5) << ' ';
    of << abs ( Simpson::countCalka(0, M_PI, &fun, 201, 5, 5 ) - integral_5_5) << ' ';
    of.close();

    system ( "python3 ../doWykresow/graph.py");
}

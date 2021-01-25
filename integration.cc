#include <iostream>
#include <fstream>
#include <functional>
#include <cmath>
const int DATASIZE = 1000;
const double RHO = 1.225;
const double W = 1;

//Integracao numerica trapezoidal

typedef struct DATA
{
    double u,y;
} DATA;
double dragFunc(DATA datum, double U)
{
     return (RHO*(pow(U,2.0) - pow(datum.u,2.0))*W);
}
double trapezNumInt(DATA *data, double (*func) (DATA, double),double U)
{
    int count = 0;
    double soma = 0;
    double h = (data[1].y-data[0].y);
    while(count < DATASIZE-1)
    {
        soma += (*func) (data[count], U) + (*func)(data[count+1], U); 
        count++;
    }
    double area = h*(((*func)(data[0], U) + (*func)(data[DATASIZE-1], U))/2+soma);
    return area;
}

int main()
{
    //Populando os dados
    DATA U14a0data[DATASIZE];
    DATA U14a4data[DATASIZE];
    DATA U14a8data[DATASIZE];
    DATA U14a12data[DATASIZE];
    DATA U29a0data[DATASIZE];
    DATA U29a4data[DATASIZE];
    DATA U29a8data[DATASIZE];
    DATA U29a12data[DATASIZE];
    

    std::ifstream fileIn;
    fileIn.open("../U14a0");
    for(auto &datum: U14a0data)
    {
        fileIn >> datum.y >> datum.u;
    }
    fileIn.close();

    fileIn.open("../U14a4");    
    for(auto &datum: U14a4data)
    {
        fileIn >> datum.y >> datum.u;
    }
    fileIn.close();

    fileIn.open("../U14a8");    
    for(auto &datum: U14a8data)
    {
        fileIn >> datum.y >> datum.u;
    }
    fileIn.close();

    fileIn.open("../U14a12");    
    for(auto &datum: U14a12data)
    {
        fileIn >> datum.y >> datum.u;
    }
    fileIn.close();
    fileIn.open("../U29a0");
    for(auto &datum: U29a0data)
    {
        fileIn >> datum.y >> datum.u;
    }
    fileIn.close();

    fileIn.open("../U29a4");    
    for(auto &datum: U29a4data)
    {
        fileIn >> datum.y >> datum.u;
    }
    fileIn.close();

    fileIn.open("../U29a8");    
    for(auto &datum: U29a8data)
    {
        fileIn >> datum.y >> datum.u;
    }
    fileIn.close();
    
    fileIn.open("../U29a12");    
    for(auto &datum: U29a12data)
    {
        fileIn >> datum.y >> datum.u;
    }
    fileIn.close();
    //Fim do carregamento dos dados

    //Calculo da integral

    double chord = 0.1;
    double U = 14.8;
    
    auto D1 = trapezNumInt(U14a0data, dragFunc, U);
    auto Cd1 = D1/(0.5*RHO*pow(U,2.0)*W*chord);


    auto D2 = trapezNumInt(U14a4data, dragFunc, U);
    auto Cd2 = D2/(0.5*RHO*pow(U,2.0)*W*chord);
    
    auto D3 = trapezNumInt(U14a8data, dragFunc, U);
    auto Cd3 = D3/(0.5*RHO*pow(U,2.0)*W*chord);

    auto D4 = trapezNumInt(U14a12data, dragFunc, U);
    auto Cd4 = D4/(0.5*RHO*pow(U,2.0)*W*chord);


    chord = 0.5;
    U = 29.6;

    auto D5 = trapezNumInt(U29a0data, dragFunc, U);
    auto Cd5 = D5/(0.5*RHO*pow(U,2.0)*W*chord);

    auto D6 = trapezNumInt(U29a4data, dragFunc, U);
    auto Cd6 = D6/(0.5*RHO*pow(U,2.0)*W*chord);
    
    auto D7 = trapezNumInt(U29a8data, dragFunc, U);
    auto Cd7 = D7/(0.5*RHO*pow(U,2.0)*W*chord);

    auto D8 = trapezNumInt(U29a12data, dragFunc, U);
    auto Cd8 = D8/(0.5*RHO*pow(U,2.0)*W*chord);

    //Escrevendo para um arquivo
    std::ofstream outFile;
    outFile.open("Out");
    outFile << "U14a0: \n" << "\tD = " << D1 << " Cd = " << Cd1 <<std::endl
    << "U14a4: \n" << "\tD = " << D2 << " Cd = " << Cd2 <<std::endl
    << "U14a8: \n" << "\tD = " << D3 << " Cd = " << Cd3 <<std::endl
    << "U14a12: \n" << "\tD = " << D4 << " Cd = " << Cd4 <<std::endl
    << "U29a0: \n" << "\tD = " << D5 << " Cd = " << Cd5 <<std::endl
    << "U29a4: \n" << "\tD = " << D6 << " Cd = " << Cd6 <<std::endl
    << "U29a8: \n" << "\tD = " << D7 << " Cd = " << Cd7 <<std::endl
    << "U29a12: \n" << "\tD = " << D8 << " Cd = " << Cd8 <<std::endl;

    return 0;
}
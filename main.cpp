#include <iostream>
#include <fstream>
#include <iomanip>

double mapVal(double val){
    double map = (((val - 1)*(3.0/4.0))-1);
    return map;
}
int main()
{
    std::string infileName = "data.csv";
    std::ifstream ifstr(infileName);
    std::string  outfileName = "result.csv";
    std::ofstream ofstr(outfileName);

    if(ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }
    ofstr<< "# N Mean" <<std::endl;
    double somma=0;
    int cont=1;
    double val;
    while (ifstr >> val){
        double map=mapVal(val);
        somma+= map;
        double media= somma/cont;
        ofstr << cont << " " << std::setprecision(16) << std::scientific<< media <<std::endl;
        cont++;
    }
    ifstr.close();
    ofstr.close();

    return 0;
}

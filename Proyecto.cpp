///Efrain Robles Pulido
#include <iostream>
#include <cmath>

///Metodo de la biseccion

using namespace std;

float resolverEcuacion(const float& x,const int& opc) {
    switch(opc) {
        case 1:
            return cos(x)-log(x);  ///Para: cos(x) - ln(x)
        case 2:
            return x - 3*sin(x)+1; ///Para: x-3sen(x)+1
        case 3:
            return (x*exp(x))-2; ///Para: xe^x -2
        case 4:
            return pow(x, 3) + (2 * pow(x, 2)) + (10*x) - 20; ///Para: x^3+2x^2+10x-20
        case 5:
            return pow((x+1), 3); ///Para: (x+1)^3
        }
    }


int main() {
    int iterador,EC=0;

    float Xi;///Inferior
    float Xd;///Superior

    float E, errorDeseado; ///Error
    float ultimo_Xm, fXi, fXd, Xm, fXm;

    while(EC<6) {
        printf(
            "\n|------------------------------------------------- Metodo de Biseccion "
            "------------------------------------------------------------|\n\n");
        printf("\tPara: cos(x) - ln(x)\t(1)\n\tPara: x-3sen(x)+1\t(2)"
               "\n\tPara: xe^x -2\t\t(3)\n\tPara: x^3+2x^2+10x-20\t(4)\n\tPara: (x+1)^3\t\t(5)\n\tSalir\t\t\t(6)\n\n");
        printf("Ingrese la ecuacion a resolver: ");
        scanf("%i",&EC);

        if(EC>5) {
            break;
            }

        printf("\n\tIngresa el primer intervalo: ");
        scanf("%f",&Xi);

        printf("\tIngresa el segundo intervalo: ");
        scanf("%f",&Xd);

        printf("\tIngresa el error deseado: ");
        scanf("%f",&errorDeseado);

        float n = (log (Xd-Xi)-log(errorDeseado))/log(2);

        printf("\n\t\t\t\t\tNumero de iteraciones,  n >= %3.5f\n", n);

        printf(
            "\n|-----------------------------------------------------------------------"
            "-----------------------------------------------------------|\n");
        printf(
            "|  i |        Xi       |       Xd        |    f(Xi)        |     f(Xd)       |       Xm   "
            "    |      f(Xm)        |      Error      |\n");
        printf(
            "|-----------------------------------------------------------------------"
            "-----------------------------------------------------------|\n");
        iterador=1;
        E=0;
        ultimo_Xm=0;
        do {
            fXi = resolverEcuacion(Xi,EC);
            fXd = resolverEcuacion(Xd,EC);

            Xm = (Xi + Xd) / 2;
            fXm = resolverEcuacion(Xm,EC);

            E = abs(Xm - ultimo_Xm);

            printf("|%3d | %+12.12f | %+12.12f | %+12.12f | %+12.12f | %+12.12f | %+12.12f "
                   "| %+12.12f |\n",iterador, Xi, Xd, fXi, fXd, Xm, fXm, E);

            iterador++;

            if (signbit(fXm) == signbit(fXi)) {//Si tienen el mismo signo(positivo)
                Xi = Xm;
                }
            else {  //Sino... (negativo)
                Xd = Xm;
                }
            ultimo_Xm = Xm;

            }while (E > errorDeseado);

        printf("\n\t\t\t\t\tXm = %12.5f\n\n",Xm);

        system("Pause");

        }
    }

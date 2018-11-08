#include <iostream>
#include<string>    //Pentru utilizarea sirurilor de caractere
#include<cstdlib>    //Prentru utilizarea numerelor random
#include<ctime>

using namespace std;

void trageLinie(int n,char simbol);
void reguli();
int main()
{
   string JucatorNume;
   int suma; //tine soldul jucatorului
   int sumaPariere;
   int ghicire;
   int generareNumar; //tine numarul generat de calculator
   char alegere;

   srand(time(0));  //generare numar aleatoriu

   trageLinie(60,'_');
   cout<<"\n\n\n\t\tJOC CAZINO\n\n\n";
   trageLinie(60,'_');

   cout<<"\n\nIntroduceti numele dumneavoastra: ";
   getline(cin,JucatorNume);

   cout<<"\n\nIntroduceti suma pentru a juca un joc: $";
   cin>>suma;

    do
    {
        system("cls");
        reguli();
        cout<<"\n\nSoldul dumneavoastra este de $"<<suma<<"\n";
                //Obtineti suma de pariere a jucatorului
        do
        {
            cout<<JucatorNume<<", introduceti bani pentru a paria : $";
            cin>>sumaPariere;
            if(sumaPariere>suma)
                cout<<"Suma dumneavoastra de pariere este mai mare decat soldul actual\n"
                    <<"\nReintroduceti suma de pariere\n";
        }while(sumaPariere>suma);
                //Optineti numerele jucatorului
        do
        {
            cout<<"Ghiciti ce numar ar iesi castigator intre 1 si 10 :";
            cin>>ghicire;
            if(ghicire<=0 || ghicire>10)
                    cout<<"Verificati numarul! Ar trebui sa fie intre 1 si 10\n"
                        <<"\nReintroduceti numarul!\n";
        }while(ghicire<=0 || ghicire>10);
        generareNumar=rand()%10+1;  //Va mentine numarul intreg generat aleator intre 1 si 10
        if(alegere==ghicire)
        {
            cout<<"Mult noroc! Ai castigat $ "<<sumaPariere*10;
            suma=suma+sumaPariere*10;
        }
        else
        {
            cout<<"Ghinion de data aceasta! Ai pierdut $ "<<sumaPariere<<"\n";
            suma=suma-sumaPariere;
        }
        cout<<"\nNumarul castigator a fost : "<<generareNumar<<"\n";
        cout<<"\n"<<JucatorNume<<", Ai $ "<<suma<<"\n";
        if(suma==0)
        {
            cout<<"Nu aveti bani sa jucati!";
            break;
        }
        cout<<"\n\n-->Vrei sa te joci din nou (y/n)?";
        cin>>alegere;
    }while(alegere=='Y'||alegere=='y');
    cout<<"\n\n\n";
    trageLinie(70,'=');
    cout<<"\n\nVa multumim pentru joc. Soldul dumneavoastra este de $ "<<suma<<"\n\n";
    trageLinie(70,'=');

    return 0;
}
void trageLinie(int n,char simbol)
{
    for(int i=0;i<n;i++)
        cout<<simbol;
    cout<<"\n";
}
void reguli()
{
    system("cls");
    cout<<"\n\n";
    trageLinie(80,'-');
    cout<<"\t\tREGULILE JOCULUI\n";
    trageLinie(80,'-');
    cout<<"\t1. Alegeti orice numar intre 1 si 10\n";
    cout<<"\t2. Daca castigi vei primi de 10 ori suma pariata\n";
    cout<<"\t3. Daca pariati pe un numar gresit veti pierde suma pariata\n\n";
    trageLinie(80,'-');
}

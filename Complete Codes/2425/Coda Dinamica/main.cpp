#include<iostream>
using namespace std;
#include "Coda.h"

int menu ()
{
  int caso;
  system("cls");
  cout<<"1) Metti dato in coda\n";
  cout<<"2) Visualizza dato in testa\n";
  cout<<"3) Toglie dato in testa\n";
  cout<<"4) Controllo coda vuota\n";
  cout<<"0) Esci\n";
  cout<<"\n";
  cout<<"Scelta-> ";
  cin>>caso;
  cout<<"\n";
  system("cls");
  return caso;
}

main()
{
 Coda q;
 int scelta;
 
 init(q);
  
 do
 {
  scelta=menu();
  
 switch (scelta)
  {
  case 1:{int dato;
          cout<<"\nInserisci il dato da accodare:\n";
  		  cin>>dato;
          Enqueue(q, dato);
         }break;
  case 2:{if (Empty(q)) cout<<"La coda e` vuota!!\n";
                    else cout<<"\nIl dato in testa e` -> "<<Front(q)<<"\n";
         }break;
  case 3:{if (Empty(q)) cout<<"La coda e` vuota!! Non ci sono dati da togliere\n";
                    else {Dequeue(q);
                          cout<<"il dato e` stato estratto\n";
                         } 
         }break;
  case 4:{if (Empty(q)) cout<<"La coda e` vuota\n";
                    else cout<<"La coda non e` vuota\n";
         }break;
  }
  system("pause");
 }while(scelta!=0);
}
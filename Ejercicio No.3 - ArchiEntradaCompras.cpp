#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Facturas
{
	string nomClien1;
	string nomClien2;
	string apell1;
	string numCedula;
	string nomArti;
	string tipoArti;
	int unidad;
	int valUni;
};

int main()
{
	Facturas Fac[50][3];
	int numClien;
	ifstream Entrada("Datos.txt");
	cout << "Ingresar Numero de Clientes:  ";
	cin >> numClien;
	cout << endl;
	for (int k = 0; k < numClien; k++)
	{
		Entrada >> Fac[k][0].nomClien1;
		Entrada >> Fac[k][0].nomClien2;
		Entrada >> Fac[k][0].apell1;
		Entrada>>Fac[k][0].numCedula;
		for (int j = 0; j < 3;)
		{
			Entrada >> Fac[k][j].nomArti;
			Entrada >> Fac[k][j].tipoArti;
			Entrada >> Fac[k][j].unidad;
		    Entrada >> Fac[k][j].valUni; 
			if (Fac[k][j].tipoArti == "nacional" || Fac[k][j].tipoArti == "Nacional" ||
				Fac[k][j].tipoArti == "importado" || Fac[k][j].tipoArti == "Importado")
			{
				j++;
			}
			else
			{
				cout << endl;
				cout << "  Tipo Articulo no Valido...";
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
	system("cls");

	for (int k = 0; k < numClien; k++)
	{
		string porImp = "";
		int valComp = 0;
		int impComp = 0;
		int pagaComp = 0;
		int totPagar = 0;
		cout << "\t=== Almacen el Pinguino S.A.S ====";
		cout << endl << endl;
		cout << "  Nombre del Cliente :  " << Fac[k][0].nomClien1<<" "<< Fac[k][0].nomClien2<<" "<<Fac[k][0].apell1;
		cout << endl;
		cout << "  Numero de Cedula   :  " << Fac[k][0].numCedula;
		cout << endl << endl;
		cout << "  Unidades" << "\t" << "Nom-Articulo" << "\t" << "Tipo-Arti" << "\t" << "Val-Unitario" << "\t" << "Val-Compra" << "\t" << "Imp-Compra" << "\t" << "Tot-Compra";
		cout << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << setw(5);
			cout << Fac[k][j].unidad;
			cout << setw(18);
			cout << Fac[k][j].nomArti;
			cout << setw(18);
			cout << Fac[k][j].tipoArti;
			cout << setw(15);
			cout << Fac[k][j].valUni;
			if (Fac[k][j].tipoArti == "nacional" || Fac[k][j].tipoArti == "Nacional")
			{
				valComp = (Fac[k][j].valUni * Fac[k][j].unidad);
				porImp = "10%";
				impComp = (valComp * 10) / 100;
				pagaComp = valComp - impComp;
			}
			else
			{
				valComp = (Fac[k][j].valUni * Fac[k][j].unidad);
				porImp = "20%";
				impComp = (valComp * 20) / 100;
				pagaComp = valComp + impComp;
			}
			cout << setw(15);
			cout << valComp;
			cout << setw(10);
			cout << porImp << " " << impComp;
			cout << setw(15);
			cout << pagaComp;
			cout << endl;
			totPagar = totPagar + pagaComp;
		}
		cout << endl;
		cout << "  Tolal Pagar Compra:   " << totPagar;
		cout << endl << endl;
	}
	cout << endl << endl;
	system("pause");
	return 0;
}

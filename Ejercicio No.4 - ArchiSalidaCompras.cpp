#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Facturas
{
	string nomClien;
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
	cout << "Ingresar Numero de Clientes:  ";
	cin >> numClien;
	cout << endl;
	for (int k = 0; k < numClien; k++)
	{
		cout << "Ingresar Nombre del Cliente No." << k + 1 << " :  ";
		rewind(stdin);
		getline(cin, Fac[k][0].nomClien);
		cout << "Ingresar Numero de Cedula:  ";
		cin >> Fac[k][0].numCedula;
		cout << endl;
		for (int j = 0; j < 3;)
		{
			cout << "Ingresar Nombre del Articulo No." << j + 1 << " :  ";
			rewind(stdin);
			getline(cin, Fac[k][j].nomArti);
			cout << "Ingresar Unidades a Comprar:  ";
			cin >> Fac[k][j].unidad;
			cout << "Ingresar Valor Unitario:  ";
			cin >> Fac[k][j].valUni;
			cout << "Ingresar Tipo Articulo(Nacional-Importado):  ";
			cin >> Fac[k][j].tipoArti;
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

	ofstream Salida("Factura.txt");
	for (int k = 0; k < numClien; k++)
	{
		string porImp = "";
		int valComp = 0;
		int impComp = 0;
		int pagaComp = 0;
		int totPagar = 0;
		Salida << "\t=== Almacen el Pinguino S.A.S ====";
		Salida << endl << endl;
		Salida << "  Nombre del Cliente :  " << Fac[k][0].nomClien;
		Salida << endl;
		Salida << "  Numero de Cedula   :  " << Fac[k][0].numCedula;
		Salida << endl << endl;
		Salida << "  Unidades" << "\t" << "Nom-Articulo" << "\t" << "Tipo-Arti" << "\t" << "Val-Unitario" << "\t" << "Val-Compra" << "\t" << "Imp-Compra" << "\t" << "Tot-Compra";
		Salida << endl;
		for (int j = 0; j < 3; j++)
		{
			Salida << setw(5);
			Salida << Fac[k][j].unidad;
			Salida << setw(18);
			Salida << Fac[k][j].nomArti;
			Salida << setw(18);
			Salida << Fac[k][j].tipoArti;
			Salida << setw(15);
			Salida << Fac[k][j].valUni;
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
			Salida << setw(15);
			Salida << valComp;
			Salida << setw(10);
			Salida << porImp << " " << impComp;
			Salida << setw(15);
			Salida << pagaComp;
			Salida << endl;
			totPagar = totPagar + pagaComp;
		}
		Salida << endl;
		Salida << "  Tolal Pagar Compra:   " << totPagar;
		Salida << endl << endl;
	}
	cout << endl << endl;
	system("pause");
	return 0;
}
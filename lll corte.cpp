#include <iostream>

using namespace std;

const int MAX_EMPLEADOS = 100;

class Empleado
{
private:
    int cedula;
    char nombres[50];
    char apellidos[50];
    char cargo[50];
    double salario_base;

public:
    Empleado(int ced, const char *nom, const char *ape, const char *car, double salario)
        : cedula(ced), salario_base(salario)
    {
       
        int i = 0;
        while (nom[i] != '\0' && i < sizeof(nombres) - 1)
        {
            nombres[i] = nom[i];
            i++;
        }
        nombres[i] = '\0';

       
        i = 0;
        while (ape[i] != '\0' && i < sizeof(apellidos) - 1)
        {
            apellidos[i] = ape[i];
            i++;
        }
        apellidos[i] = '\0';

        
        i = 0;
        while (car[i] != '\0' && i < sizeof(cargo) - 1)
        {
            cargo[i] = car[i];
            i++;
        }
        cargo[i] = '\0';
    }

    
    void aplicar_aumento_salario(double aumento_porcentaje)
    {
        double aumento_decimal = aumento_porcentaje / 100.0;
        salario_base *= (1 + aumento_decimal);
    }

   
    double obtener_salario_base() const
    {
        return salario_base;
    }

    
    void imprimir_datos() const
    {
        cout << "Empleado: " << nombres << " " << apellidos << endl;
        cout << "Cédula: " << cedula << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Salario Base: " << salario_base << endl;
    }

    
    bool salario_mayor_20000() const
    {
        return salario_base > 20000.0;
    }
};


Empleado agregar_empleado()
{
    int cedula;
    char nombres[50];
    char apellidos[50];
    char cargo[50];
    double salario_base;

    cout << "Ingrese la cédula del empleado: ";
    cin >> cedula;

    cout << "Ingrese los nombres del empleado: ";
    cin >> nombres;

    cout << "Ingrese los apellidos del empleado: ";
    cin >> apellidos;

    cout << "Ingrese el cargo del empleado: ";
    cin >> cargo;

    cout << "Ingrese el salario base del empleado: ";
    cin >> salario_base;

    return Empleado(cedula, nombres, apellidos, cargo, salario_base);
}


void aumentar_salarios(Empleado empleados[], int num_empleados)
{
    for (int i = 0; i < num_empleados; ++i)
    {
        if (empleados[i].obtener_salario_base() > 10000.0)
        {
            empleados[i].aplicar_aumento_salario(5.0);
        }
        else if (empleados[i].obtener_salario_base() < 10000.0)
        {
            empleados[i].aplicar_aumento_salario(10.0);
        }
    }
}


void mostrar_empleados_salario_mayor_20000(Empleado empleados[], int num_empleados)
{
    cout << "Empleados con salario mayor a 20,000:" << endl;
    for (int i = 0; i < num_empleados; ++i)
    {
        if (empleados[i].salario_mayor_20000())
        {
            empleados[i].imprimir_datos();
            cout << endl;
        }
    }
}


int main()
{
    Empleado;

    int num_empleados;

    cout << "¿Cuántos empleados desea agregar? ";
    cin >> num_empleados;

    for (int i = 0; i < num_empleados; ++i)
    {
        Empleado[i] = agregar_empleado();
    }

    
    aumentar_salarios(Empleado, num_empleados);

    
    mostrar_empleados_salario_mayor_20000(Empleado, num_empleados);

    return 0;
}

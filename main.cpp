#include <iostream>
#include<string>
using namespace std;

class Empleado
{
 private:
    string nombre;
    int legajo;
 public:
    Empleado();
    ~Empleado();
    string getNombre();
    int getLegajo();
    void setNombre(string );
    void setLegajo(int );
    void recibirMensaje(string *mensaje);
    virtual void trabajar()= 0;
};
Empleado :: Empleado(){};
Empleado :: ~Empleado(){};
string Empleado :: getNombre(){
    return nombre;
}
int Empleado :: getLegajo(){
    return legajo;
}
void Empleado :: setNombre(string nuevoNombre){
    nombre = nuevoNombre;
}
void Empleado :: setLegajo(int nuevoLegajo){
    legajo = nuevoLegajo;
}
void Empleado :: recibirMensaje(string *mensaje){
 string mensajeRecibido;
 mensajeRecibido = *mensaje;
 cout <<"El mensaje es: "<< *mensaje <<endl;
}
class Gerente : public Empleado
{
 public:
 Gerente();
 ~Gerente();
 void recibirMensaje();
 void trabajar();

};
Gerente :: Gerente(){}
Gerente :: ~Gerente(){}
void Gerente :: recibirMensaje(){

}
void Gerente :: trabajar(){
    cout<< "En la oficina planificando" <<endl;
}

class Encargado : public Empleado{
 public:
    Encargado();
    ~Encargado();
    void recibirMensaje();
    void trabajar();
};

Encargado :: Encargado(){}
Encargado :: ~Encargado(){}
void Encargado :: recibirMensaje(){}
void Encargado :: trabajar()
{
    cout <<"En el deposito revisando que falta"<<endl;
}

class Vendedor : public Empleado {
 public:
    Vendedor();
    ~Vendedor();
    void recibirMensaje();
    void trabajar();
};
Vendedor :: Vendedor (){}
Vendedor :: ~Vendedor(){}
void Vendedor :: recibirMensaje(){}
void Vendedor :: trabajar(){
    cout<< "En el salon atendiendo" <<endl;
}

class Sucursal
{
 private:
    string nombre;
    Empleado *empleados[10];
 public:
    Sucursal();
    ~Sucursal();
    void setNombre(string);
    string getNombre();
    void ingresarEmpleados(Empleado* empleado);
    void listarEmpleados(Empleado* empleado);
};
Sucursal :: Sucursal(){}
Sucursal ::~Sucursal(){}
void Sucursal :: setNombre(string nNombre){
    nombre = nNombre;
}
string Sucursal :: getNombre(){
    return nombre;
}
void Sucursal :: ingresarEmpleados(Empleado* empleado){
    int i ;
    if (i<10){
        empleados[i]= empleado;
        i++;
    }
    else{
        cout <<"No se pueden ingresar mas empleados" << endl;
    }
}
void Sucursal :: listarEmpleados(Empleado* empleado){
    for (int i = 0; i < 10; i++)
    {
        cout<< "Empleado: " << empleado->getNombre();
        cout << "Legajo del empleado: "<< empleado->getLegajo();
    }
    
}
class Empresa 
{
 private:
    string nombre;
    Sucursal *sucursales[4];
 public:
    Empresa();
    ~Empresa();
    void setNombre(string);
    string getNombre();
    void enviarMensaje(Empleado* empleado);
    void mostrarSucursales(Sucursal* sucursal);

};
Empresa :: Empresa(){};
Empresa :: ~Empresa(){};
void Empresa :: setNombre(string nombreN)
{
    nombre= nombreN;
}
string Empresa :: getNombre(){
    return nombre;
}
void Empresa:: enviarMensaje(Empleado* empleado){

};
void Empresa :: mostrarSucursales(Sucursal* sucursal){
    int i ;
    if (i<4){
        sucursales[i]= sucursal;
        i++;
        for (int i = 0; i < 4; i++)
        {
           cout <<"La sucursal: "<< sucursal->getNombre(); 
        }
        
    }
    else{
        cout <<"Error" << endl;
    }
    
}
void Empresa :: enviarMensaje(Empleado *empleadoMensaje){
    string mensaje ;
    cout << "Ingrese un mensaje: ";
    cin >> mensaje;
    empleadoMensaje->recibirMensaje(&mensaje);
} 


int main(){
 
 Empresa * empresa = new Empresa();
 Sucursal * sucursal;
 Empleado* empleado1;

 empresa->setNombre("Arcoris");
 cout <<"El nombre de la empresa es: "<< empresa->getNombre();

 empresa->mostrarSucursales(sucursal);
 sucursal->ingresarEmpleados(empleado1);
 empleado1->setNombre("juan");
 empleado1->setLegajo(22);
 empresa->enviarMensaje(empleado1);
 empleado1->trabajar();



    return;
}
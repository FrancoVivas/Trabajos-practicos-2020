//Biblioteca de funciones

typedef struct
{
    int id;
    int nombre[51];
    int apellido[51];
    float salario;
    int sector;
    int isEmpty;
}empleado;

int iniciarEmpleado(Empleados lista[], int len);
int agregarEmpleado(Empleados lista[], int len, int id, char nombre, char apellido, float salario, int sector);
int encontrarEmpleadoPorId(Empleados lista[], int len, int id);
int eliminarEmpleado(Empleados lista[], int len, int id);
int ordenarEmpleados(Empleados lista[], int len, int ordenar);
int mostrarEmpleados(Empleados lista[]; int len, int largo);

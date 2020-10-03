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

int iniciarEmpleado(empleado lista[], int len, int value);
int mirarEspacioLibre(empleado lista[], int len);
int agregarEmpleado(empleado lista[], int len, int id, char nombre, char apellido, float salario, int sector);
int encontrarEmpleadoPorId(empleado lista[], int len, int id);
int eliminarEmpleado(empleado lista[], int len, int id);
int mostrarEmpleados(empleado lista[], int len);

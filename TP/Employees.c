#include "Employees.h"
void initEmployees(Employee listadoEmpleados[], int len)
{
    int i;
    int retorno = 0;
    for(i = 0; i < len; i++)
    {
        listadoEmpleados[i].isEmpty = 1;
    }

}

void hardcodearEmployees(Employee listadoEmpleados[], int len)
{
    int id[3] = {0, 1, 2};
    char nombres[][51] = {"Julian", "Roberto", "Laura"};
    char apellidos[][51] = {"Sodo", "Canosa", "Vasquez"};
    float salario[3] = {25800, 12500, 23400};
    int sector[3] = {1, 4, 2};
    int isEmpty[3] = {0};

    for(int i = 0; i<3; i++)
    {
        listadoEmpleados[i].id = id[i];
        strcpy(listadoEmpleados[i].name, nombres[i]);
        strcpy(listadoEmpleados[i].lastName, apellidos[i]);
        listadoEmpleados[i].salary = salario[i];
        listadoEmpleados[i].sector = sector[i];
        listadoEmpleados[i].isEmpty = isEmpty[i];
    }
}

int buscarLugarLibre(Employee listadoEmpleados[], int len)
{
    int posicionVacia = -1;
    int i;
    for(i=0; i<len; i++)
    {
        if(listadoEmpleados[i].isEmpty == 1)
        {
            posicionVacia = i;
            break;
        }
    }
    return posicionVacia;
}

int addEmployee(Employee listadoEmpleados[], int len)
{
    int retorno = -1;
    int posicionLibre = -1;
    posicionLibre  = buscarLugarLibre(listadoEmpleados, len);
    if(posicionLibre != -1)
    {
        listadoEmpleados[posicionLibre].id = posicionLibre;
        listadoEmpleados[posicionLibre].isEmpty = 0;
        printf("Ingrese el nombre del empleado: ");
        fflush(stdin);
        gets(listadoEmpleados[posicionLibre].name);
        printf("\nIngrese el apellido del empleado: ");
        fflush(stdin);
        gets(listadoEmpleados[posicionLibre].lastName);
        printf("\nIngrese el salario del empleado: ");
        scanf("%f", &listadoEmpleados[posicionLibre].salary);
        printf("\nIngrese el sector del empleado: ");
        scanf("%d", &listadoEmpleados[posicionLibre].sector);
        retorno = 0;
    }
    else
    {
        printf("No se encuentran posiciones libres\n");
    }
    return retorno;
}

void printEmployees(Employee listadoEmpleados[], int len)
{
    int hayEmpleados = 0;
    for(int i = 0; i < len; i++)
    {
        if(listadoEmpleados[i].isEmpty == 0)
        {
            printf("\n----------- ID: %d ------------", listadoEmpleados[i].id);
            printf("\nNombre: %s", listadoEmpleados[i].name);
            printf("\nApellido: %s", listadoEmpleados[i].lastName);
            printf("\nSalario: %f", listadoEmpleados[i].salary);
            printf("\nSector: %d", listadoEmpleados[i].sector);
            printf("\n-------------------------------\n");
            hayEmpleados = 1;
        }
    }
    if(hayEmpleados==0)
    {
        printf("\nNo hay empleados\n");
    }
}

void printEmployee(Employee listadoEmpleados[], int len, int id)
{
    int i = findEmployeeById(listadoEmpleados, len, id);
    if(listadoEmpleados[i].isEmpty == 0)
    {
        printf("\n----------- ID: %d ------------", listadoEmpleados[i].id);
        printf("\nNombre: %s", listadoEmpleados[i].name);
        printf("\nApellido: %s", listadoEmpleados[i].lastName);
        printf("\nSalario: %f", listadoEmpleados[i].salary);
        printf("\nSector: %d", listadoEmpleados[i].sector);
        printf("\n-------------------------------\n");
    }
    else
    {
        printf("\nNo hay ningun empleado activo con ese id\n");
    }
}


int findEmployeeById(Employee listadoEmpleados[] , int len ,int id)
{
    int retorno = -1;
    for(int i = 0; i < len; i++)
    {
        if(listadoEmpleados[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int removeEmployee(Employee* listadoEmpleados, int len, int id)
{
    int retorno = -1;
    int index = findEmployeeById(listadoEmpleados,len,id);
    if(index != -1)
    {
        listadoEmpleados[index].isEmpty = 1;
        retorno = 0;
    }
    else
    {
        printf("\nEl id ingresado no pertenece a ningun empleado\n");
    }
    return retorno;
}

int setEmployee(Employee* listadoEmpleados, int len, int id)
{
    int retorno = -1;
    int index = findEmployeeById(listadoEmpleados,len,id);

    printf("\n\n %d \n\n", index);
    if(index != -1)
    {
        int opcionEdicion;
        do
        {
            printEmployee(listadoEmpleados,len,id);
            printf("\nQue desea modificar?\n1-Modificar nombre\n2-Modificar apellido\n3-Modificar salario\n4-Modificar sector\n5-Dejar de modificar\nElegir: ");
            scanf("%d", &opcionEdicion);
            switch(opcionEdicion)
            {
                case 1:setNameEmployee(listadoEmpleados,index); break;
                case 2:setLastNameEmployee(listadoEmpleados,index); break;
                case 3:setSalaryEmployee(listadoEmpleados,index); break;
                case 4:setSectorEmployee(listadoEmpleados,index); break;
            }
        }while(opcionEdicion!=5);
        retorno = 0;
    }
    else
    {
        printf("\nEl id ingresado no pertenece a ningun empleado\n");
    }
    return retorno;
}


int sortEmployees(Employee listadoEmpleados[], int len, int order)
{
    int retorno = -1;
    int i;
    int j;
    Employee aux;
    int idAux;
    if(order == 0)
    {
        for(i = 0; i < len; i++)
        {
            for(j = 0; j<len;j++)
            {
                if((listadoEmpleados[j].sector > listadoEmpleados[j+1].sector))
                {
                    aux = listadoEmpleados[j];
                    idAux = listadoEmpleados[j].id;
                    listadoEmpleados[j] = listadoEmpleados[j+1];
                    listadoEmpleados[j+1] = aux;
                    listadoEmpleados[j+1].id = idAux;
                }
            }
        }
        for(i = 0; i < len; i++)
        {
            for(j = 0; j<len;j++)
            {
                if(strcmp(listadoEmpleados[j].name, listadoEmpleados[j+1].name) > 0)
                {
                    aux = listadoEmpleados[j];
                    idAux = listadoEmpleados[j].id;
                    listadoEmpleados[j] = listadoEmpleados[j+1];
                    listadoEmpleados[j+1] = aux;
                    listadoEmpleados[j+1].id = idAux;
                }
            }
        }
        printf("\nEmpleados ordenados de menor a mayor");
    }
    else if(order == 1)
    {
        for(i = 0; i < len; i++)
        {
            for(j = 0; j<len;j++)
            {
                if(listadoEmpleados[j].sector < listadoEmpleados[j+1].sector)
                {
                    aux = listadoEmpleados[j];
                    idAux = listadoEmpleados[j].id;
                    listadoEmpleados[j] = listadoEmpleados[j+1];
                    listadoEmpleados[j+1] = aux;
                    listadoEmpleados[j+1].id = idAux;
                }
            }
        }
        for(i = 0; i < len; i++)
        {
            for(j = 0; j<len;j++)
            {
                if(strcmp(listadoEmpleados[j].name, listadoEmpleados[j+1].name) < 0)
                {
                    aux = listadoEmpleados[j];
                    idAux = listadoEmpleados[j].id;
                    listadoEmpleados[j] = listadoEmpleados[j+1];
                    listadoEmpleados[j+1] = aux;
                    listadoEmpleados[j+1].id = idAux;
                }
            }
        }
            printf("\nEmpleados ordenados de mayor a menor.");
        }
    else
    {
        printf("\nEl tipo de orden SOLO puede ser cero(de menor a mayor) o 1 (de mayor a menor).");
    }
    return retorno;
}


void setNameEmployee(Employee listadoEmpleado[], int index)
{
    char nuevoNombre[51];
    printf("Ingrese el nuevo nombre: ");
    fflush(stdin);
    gets(nuevoNombre);
    strcpy(listadoEmpleado[index].name, nuevoNombre);
    printf("Nombre modificado satisfactoriamente.");
}
void setLastNameEmployee(Employee listadoEmpleado[], int index)
{
    char nuevoApellido[51];
    printf("Ingrese el nuevo apellido: ");
    fflush(stdin);
    gets(nuevoApellido);
    strcpy(listadoEmpleado[index].lastName, nuevoApellido);
    printf("Apellido modificado satisfactoriamente.");
}
void setSalaryEmployee(Employee listadoEmpleado[], int index)
{
    float nuevoSalario;
    printf("Ingrese el nuevo salario: ");
    scanf("%f", &nuevoSalario);
    listadoEmpleado[index].salary = nuevoSalario;
    printf("Salario modificado satisfactoriamente.");
}
void setSectorEmployee(Employee listadoEmpleado[], int index)
{
    int nuevoSector;
    printf("Ingrese el nuevo sector: ");
    scanf("%d", &nuevoSector);
    listadoEmpleado[index].sector = nuevoSector;
    printf("Sector modificado satisfactoriamente.");
}

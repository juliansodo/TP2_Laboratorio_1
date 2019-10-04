#include "Employees.h"

void main()
{

    Employee ListadoEmpleados[CANTIDAD];
    initEmployees(ListadoEmpleados, CANTIDAD);

    printf("Desea hardcodear empleados? (s/n): ");
    if(getchar()=='s')
    {
       hardcodearEmployees(ListadoEmpleados, CANTIDAD);
    }
    system("cls");
    int opcion;
    int aux;
    do
    {
        printf("\t \t \t Menu\n");
        printf("1-ALTA de empleado\n2-BAJA de empleado\n3-MODIFICACION de empleado\n4-Mostrar todos los empleados\n5-Mostrar un empleado\n6-Ordenar empleados por sector y nombre.\n0-Salir");
        printf("\nElegir: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            if(addEmployee(ListadoEmpleados, CANTIDAD) == 0)
            {
                printf("Empleado creado\n");
            }
            else
            {
                printf("No se pudo crear al empleado\n");
            }
        break;
        case 2:
            printf("Ingrese el id del empleado a eliminar: ");
            scanf("%d", &aux);
            if(removeEmployee(ListadoEmpleados, CANTIDAD, aux) == 0)
            {
                printf("Empleado eliminado\n");
            }
            else
            {
                printf("No se pudo eliminar al empleado\n");
            }
        break;
        case 3:
            printf("Ingrese el id del empleado a modificar: ");
            scanf("%d", &aux);
            if(setEmployee(ListadoEmpleados, CANTIDAD, aux) == 0)
            {
                printf("Empleado modificado \n");
            }
            else
            {
                printf("No se pudo modificar al empleado\n");
            }
        break;
        case 4:
            printEmployees(ListadoEmpleados, CANTIDAD);
        break;
        case 5:
            printf("Ingrese el id del empleado que quiere mostrar: ");
            scanf("%d", &aux);
            printEmployee(ListadoEmpleados, CANTIDAD, aux);
        break;
        case 6:
            printf("Ingrese el tipo de orden. Puede ser cero(de menor a mayor) o 1 (de mayor a menor): ");
            scanf("%d", &aux);
            sortEmployees(ListadoEmpleados, CANTIDAD, aux);
        break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    while(opcion != 0);

}

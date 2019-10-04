#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 1000
#define VACIO 0
#define COMPLETO 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void initEmployees(Employee*, int);

/** \brief Hardcodea tres empleados
 *
 * \param Employee*
 * \param int
 * \return void
 *
 */
void hardcodearEmployees(Employee*, int);

int buscarLugarLibre(Employee*, int);
/** \brief recorre la lista de empleados buscando un espacio vacio
 *
 * \param listado de empleados
 * \param tamaño del array
 * \return el primer indice que encuentre sin datos.
 *
 */

/** \brief Busca un lugar vacío. Pide los datos para crear un nuevo empleado
 *
 * \param Employee*
 * \param int
 * \return int (si estuvo todo ok: 0 | si no se pudo crear al empleado devuelve -1;
 *
 */
int addEmployee(Employee*, int);

/** \brief muestra toda la lista de empleados activos
 *
 * \param Employee*
 * \param int
 * \return void
 *
 */
void printEmployees(Employee*, int);

/** \brief Muestra el empleado cuyo id se envia por parametro.
 *
 * \param Employee*
 * \param int
 * \param int
 * \return void
 *
 */
void printEmployee(Employee*, int , int );

/** \brief Busca un empleado por ID
 *
 * \param Employee*
 * \param int
 * \param int
 * \return int = indice en que se encuentra el id del empleado.
 *
 */
int findEmployeeById(Employee* , int ,int );

/** \brief Eliimina a un empleado(pasandole 1 a isEmpty)
 *
 * \param Employee*
 * \param int
 * \param int
 * \return int = -1 si no se pudo eliminar | 0 si se pudo eliminar.
 *
 */
int removeEmployee(Employee* , int , int );

/** \brief Despliega un menu para modificar un empleado
 *
 * \param Employee*
 * \param int
 * \param int
 * \return int
 *
 */
int setEmployee(Employee* , int , int );

/** \brief Ordena a los empleados por sector y nombre.
 *
 * \param Employee*
 * \param int
 * \param int
 * \return int = -1 si el parametro orden es distinto de 0 y 1
 *
 */
int sortEmployees(Employee*, int , int );

//---------------------------------------------------------------------------->

/*
    Las siguientes funciones modifican los distintos tipos de atributos de los empleados, todas reciben lo mismo, la lista
    y el tamaño, piden el valor y lo modifican.
*/
void setNameEmployee(Employee*, int );
void setLastNameEmployee(Employee*, int );
void setSalaryEmployee(Employee*, int );
void setSectorEmployee(Employee*, int );

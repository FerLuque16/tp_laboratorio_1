typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;

typedef struct
{
    int id;
    char desc[51];
}eSector;

int initEmployees(eEmployee *emp, int len);

int addEmployee(eEmployee *emp, int len, eSector *auxSector, int lenSector);
int removeEmployee(eEmployee emp[],int len ,eSector sec[], int lenSec );
void modifyEmployee(eEmployee emp[],int len, eSector sec [], int lenSector);





void printSector(eSector sec[], int len);
void printEmployee(eEmployee emp,eSector sec[], int lenSec, int formato);
void printAllEmployees(eEmployee listE[], int len, eSector listS[], int lenSector);
void sortEmployee(eEmployee emp[], int len, int order);
void calculateSalaryInfo(eEmployee emp[], int len);
int findEmptyPlace (eEmployee emp[], int len);
int findEmployeeById(eEmployee emp[], int len, int id);

#include "ll.h"

RESULT CreateEmployee()
{
  RESULT result = 0;

  EMPLOYEE *pEmp = NULL;    
  pEmp = (EMPLOYEE *)malloc(sizeof(EMPLOYEE));
  if (pEmp==NULL)
  {
    printf("메모리 할당 실패!\n");
    return ALLOC_FAIL;
  }
  
  pEmp->list.pPrev = NULL;
  pEmp->list.pNext = NULL;

  pEmp->num = 1;
  strcpy(pEmp->name, "유재석");
  pEmp->buseo = 1;
  pEmp->jikguep = 1;

  return NOERROR;
}

int main()
{ 
  LINKED_LIST ll;
  memset(&ll, 0, sizeof(LINKED_LIST));

  




  return 0;
}
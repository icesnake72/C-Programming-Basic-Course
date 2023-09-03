#include "GameUtil.h"

void randomize()
{
  srand((byte)time(NULL));
}

byte findInArray(byte *arr, UINT nSize, byte toFind)
{
  CHECK_PARAM(arr, nSize);
  
  for(UINT i=0; i<nSize; i++)
  {
    if ( arr[i]==toFind )
      return 1;
  }
 
  return 0;
}

byte initRandomValues(byte *arr, UINT nSize, UINT range)
{
  CHECK_PARAM(arr, nSize);

  UINT i=0;
  byte tmp = 0;
  while( i<nSize )
  {
    tmp = (byte)((rand() % range) + 1);
    if ( findInArray(arr, nSize, tmp) )
      continue;

    arr[i++] = tmp;
  }
  
  return nSize;
}

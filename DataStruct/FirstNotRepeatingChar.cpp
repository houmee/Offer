/******************************************************************** 
�޸�ʱ��:        2016/07/22 17:43
�ļ�����:        FirstNotRepeatingChar.cpp
�ļ�����:        huming 
=====================================================================
����˵��:         
--------------------------------------------------------------------- 
�汾���:        
--------------------------------------------------------------------- 
����˵��:         
*********************************************************************/
#include <iostream>

/********************************************************************
*  @name     : FirstNotRepeatingChar    
*  @brief    : �ҵ���һ��ֻ����һ�ε��ַ�
*  @param    : const char * pString 
*  @return   : char
********************************************************************/
char FirstNotRepeatingChar( const char* pString ) //pStringָ���ַ�������޸�
{
  if ( pString == NULL )
    return '\0';

  const int tableSize = 256;
  unsigned int hashTable[tableSize];  //�������鹹��hash��

  for(int i=0; i<tableSize; i++)
    hashTable[i] = 0;

  const char* ptr = pString;
  while( *ptr != '\0' )         //��ÿ���ַ�����asciiֵ%256�浽hash����
  {
    hashTable[*ptr]++;
    ptr++;
  }

  ptr = pString;
  while( *ptr != '\0' )         //���ַ�����ȡ���ִ���
  {
    if ( hashTable[*ptr] == 1 )
      return *ptr;

    ptr++;
  }

  return '\0';
}


/********************************************************************
*  @name     : deleteSameLetter    
*  @brief    : ��sourceStr�а���letterStr�ַ����ַ���ɾ��
*  @param    : char * sourceStr 
*  @param    : const char * letterStr 
*  @return   : char*
********************************************************************/
char* deleteSameLetter( char* sourceStr, const char* letterStr )
{
  if ( letterStr == NULL || sourceStr == NULL )
    return sourceStr;

  const int hashSize = 256;
  unsigned int hashTable[hashSize];   //ΪASCII����hash��

  for (int i=0; i<hashSize; i++)
    hashTable[i] = 0;

  const char* matchPtr = letterStr;
  while( *matchPtr != '\0' )
    hashTable[*(matchPtr++)]++;       //��letterStr����Ҫ��sourceStrɾ�����ַ�����hash��

  char* deletePtr = sourceStr;
  char* searchPtr = sourceStr;
  while( *searchPtr != '\0' )
  {
    if ( hashTable[*searchPtr] != 0 )  //�����sourceStr�д���letterStr�е��ַ�
    {
      deletePtr = sourceStr+1;
      while ( *deletePtr != '\0' )    //ɾ���ַ�
      {
        *deletePtr = *(deletePtr+1);
        deletePtr++;
      }
    }
    searchPtr++;
  }

  return sourceStr;
}


void main()
{
   char* str = "hello world"; 
   std::cout << FirstNotRepeatingChar( str );
}
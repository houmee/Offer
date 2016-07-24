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
*  @name     : removeSameLetterfromMatchStr    
*  @brief    : ��sourceStr�а���letterStr�ַ����ַ���ɾ��
*  @param    : char * sourceStr 
*  @param    : const char * letterStr 
*  @return   : char*
********************************************************************/
char* removeSameLetterfromMatchStr( char* sourceStr, const char* matchStr )
{
  if ( matchStr == NULL || sourceStr == NULL )
    return sourceStr;

  const int hashSize = 256;
  unsigned int hashTable[hashSize];   //ΪASCII����hash��

  for (int i=0; i<hashSize; i++)
    hashTable[i] = 0;

  const char* matchPtr = matchStr;
  while( *matchPtr != '\0' )
    hashTable[*(matchPtr++)]++;       //��letterStr����Ҫ��sourceStrɾ�����ַ�����hash��

  char* deletePtr = sourceStr;
  char* searchPtr = sourceStr;
  while( *searchPtr != '\0' )
  {
    if ( hashTable[*searchPtr] != 0 )  //�����sourceStr�д���letterStr�е��ַ�
    {
      deletePtr = searchPtr;
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

/********************************************************************
*  @name     : RemoveSameLetter    
*  @brief    : ɾ���ַ�������ͬ���ַ�
*  @param    : char * str 
*  @return   : char*
********************************************************************/ 
char* RemoveSameLetter( char* str )
{
  if ( str == NULL )
    return str;

  const int tableSize = 256;
  bool hashTable[tableSize];

  for (int i=0; i<tableSize; i++)
    hashTable[i] = false;

  char* ptr = str;
  while( *ptr != '\0' )
  {
    if ( hashTable[*ptr] )
      hashTable[*ptr] = true;
    else
    {
      //ɾ���ַ�
    }
  }
   
  return str;
}

/********************************************************************
*  @name     : findAnagram    
*  @brief    : �ж��������ʵ���ĸ���ͺ���ĸ���ִ����Ƿ���ͬ
*  @param    : const char * sourceWord 
*  @param    : const char * destWord 
*  @return   : bool
********************************************************************/ 
bool findAnagram( const char* sourceWord, const char* destWord )
{
  if ( sourceWord == NULL || destWord == NULL )
    return false;

  const int hashSize =  256;
  int hashTable[hashSize];
  for (int i=0; i<hashSize; i++)
    hashTable[i] = 0;

  const char* ptr = sourceWord;
  while( *ptr != '\0' )
    hashTable[*(ptr++)]++;

  ptr = destWord;
  while( *ptr != '\0' )
    hashTable[*(ptr++)]--;

  for (int i=0; i<hashSize; i++)
  {
    if ( hashTable[i] != 0 )
    return false;
  }

  return true;
}

char* removeFirstChar( char* str )
{
  if ( str == NULL )
   return str;

  char* ptr = str;
  while( *(ptr+1) != '\0')
  {
    *ptr = *(ptr+1);
    ptr++;
  }
  return str;
}



/********************************************************************
*  @name     : main    
*  @brief    : 
*  @return   : void
********************************************************************/ 
void main()
{
  //////////////////////////////////////////////////////////////////////////
  //Ѱ�ҵ�һ��ֻ����һ�ε��ַ�
  const char* str = "hello world"; 
  std::cout << FirstNotRepeatingChar( str );  //'h'
 
  //////////////////////////////////////////////////////////////////////////
  //Ѱ�ұ�λ��
  char* w1 = "evil";
  char* w2 = "live";
  bool b = false;
  b = findAnagram(w1, w2);  // bΪtrue

  //////////////////////////////////////////////////////////////////////////
   //str = removeFirstChar( str );

}
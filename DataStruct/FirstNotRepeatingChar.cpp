/******************************************************************** 
修改时间:        2016/07/22 17:43
文件名称:        FirstNotRepeatingChar.cpp
文件作者:        huming 
=====================================================================
功能说明:         
--------------------------------------------------------------------- 
版本编号:        
--------------------------------------------------------------------- 
其他说明:         
*********************************************************************/
#include <iostream>

/********************************************************************
*  @name     : FirstNotRepeatingChar    
*  @brief    : 找到第一个只出现一次的字符
*  @param    : const char * pString 
*  @return   : char
********************************************************************/
char FirstNotRepeatingChar( const char* pString ) //pString指针地址不允许修改
{
  if ( pString == NULL )
    return '\0';

  const int tableSize = 256;
  unsigned int hashTable[tableSize];  //利用数组构建hash表

  for(int i=0; i<tableSize; i++)
    hashTable[i] = 0;

  const char* ptr = pString;
  while( *ptr != '\0' )         //将每个字符按照ascii值%256存到hash表中
  {
    hashTable[*ptr]++;
    ptr++;
  }

  ptr = pString;
  while( *ptr != '\0' )         //按字符串读取出现次数
  {
    if ( hashTable[*ptr] == 1 )
      return *ptr;

    ptr++;
  }

  return '\0';
}


/********************************************************************
*  @name     : deleteSameLetter    
*  @brief    : 将sourceStr中包含letterStr字符的字符都删掉
*  @param    : char * sourceStr 
*  @param    : const char * letterStr 
*  @return   : char*
********************************************************************/
char* deleteSameLetter( char* sourceStr, const char* letterStr )
{
  if ( letterStr == NULL || sourceStr == NULL )
    return sourceStr;

  const int hashSize = 256;
  unsigned int hashTable[hashSize];   //为ASCII建立hash表

  for (int i=0; i<hashSize; i++)
    hashTable[i] = 0;

  const char* matchPtr = letterStr;
  while( *matchPtr != '\0' )
    hashTable[*(matchPtr++)]++;       //将letterStr中需要被sourceStr删除的字符存入hash表

  char* deletePtr = sourceStr;
  char* searchPtr = sourceStr;
  while( *searchPtr != '\0' )
  {
    if ( hashTable[*searchPtr] != 0 )  //如果存sourceStr中存在letterStr中的字符
    {
      deletePtr = sourceStr+1;
      while ( *deletePtr != '\0' )    //删除字符
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
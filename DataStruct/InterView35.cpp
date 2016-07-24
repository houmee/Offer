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
*  @name     : removeSameLetterfromMatchStr    
*  @brief    : 将sourceStr中包含letterStr字符的字符都删掉
*  @param    : char * sourceStr 
*  @param    : const char * letterStr 
*  @return   : char*
********************************************************************/
char* removeSameLetterfromMatchStr( char* sourceStr, const char* matchStr )
{
  if ( matchStr == NULL || sourceStr == NULL )
    return sourceStr;

  const int hashSize = 256;
  unsigned int hashTable[hashSize];   //为ASCII建立hash表

  for (int i=0; i<hashSize; i++)
    hashTable[i] = 0;

  const char* matchPtr = matchStr;
  while( *matchPtr != '\0' )
    hashTable[*(matchPtr++)]++;       //将letterStr中需要被sourceStr删除的字符存入hash表

  char* deletePtr = sourceStr;
  char* searchPtr = sourceStr;
  while( *searchPtr != '\0' )
  {
    if ( hashTable[*searchPtr] != 0 )  //如果存sourceStr中存在letterStr中的字符
    {
      deletePtr = searchPtr;
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

/********************************************************************
*  @name     : RemoveSameLetter    
*  @brief    : 删除字符串中相同的字符
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
      //删除字符
    }
  }
   
  return str;
}

/********************************************************************
*  @name     : findAnagram    
*  @brief    : 判断两个单词的字母类型和字母出现次数是否相同
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
  //寻找第一个只出现一次的字符
  const char* str = "hello world"; 
  std::cout << FirstNotRepeatingChar( str );  //'h'
 
  //////////////////////////////////////////////////////////////////////////
  //寻找变位词
  char* w1 = "evil";
  char* w2 = "live";
  bool b = false;
  b = findAnagram(w1, w2);  // b为true

  //////////////////////////////////////////////////////////////////////////
   //str = removeFirstChar( str );

}
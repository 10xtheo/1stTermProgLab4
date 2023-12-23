#include <cctype>
#include <iostream>
#include <sstream>
using namespace std;

int getNumber ()
{
  int a;
  cin >> a;
  while (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cin >> a;
  }
  return a;
}

int lenStr(char* A)
{
  int i;
  for (i = 0; A[i] != 0; ++i);
  return i;
}

int lenStr(string A)
{
  int i;
  for (i = 0; A[i] != '\0'; ++i);
  return i;
}

bool inStr(char A[], char x)
{
  int f = false;
  for (int i = 0; i < lenStr(A); ++i)
    if (A[i] == x)
      f = true;
  return f;
}

bool inArr(char A[], char x, int length)
{
  int f = false;
  for (int i = 0; i < length; ++i)
    if (A[i] == x)
      f = true;
  return f;
}

void removeExtraMarks(char* A)
{
  char marks[] = {' ', ',', '!', '?', ':', ';', '"', '(', ')', '{', '}', '[', ']', '-', '_'};
  int lenMarks = 15; 
  for (int m = 0; m < lenMarks; ++m)
  {
    int j = 0;
    bool lastCharMark = false;
    for (int i = 0 ; A[i] != '\0'; ++i)
    {
      if (inArr(marks, A[i], lenMarks))
      {
        if (!lastCharMark)
        {
          A[j] = A[i];
          j += 1;
          lastCharMark = true;
        }
      } 
      else 
      {
        A[j] = A[i];
        j += 1;
        lastCharMark = false;
      }
    }
    A[j] = '\0';
  }
}

void fixCase(char* A)
{
  char capitalMarks[] = {'.', '!', '?'};
  int lenCapitalMarks = 3;
  if (islower(A[0]))
    A[0] = toupper(A[0]);
  for (int i = 1; i < lenStr(A); ++i)
  {
    if (i != 1 && i != 2)
    {
      if (inArr(capitalMarks, A[i-1], lenCapitalMarks) || inArr(capitalMarks, A[i-2], lenCapitalMarks))
      {
        if (islower(A[i]))
          A[i] = toupper(A[i]);
      }
      else
      {
        if (isupper(A[i]))
          A[i] = tolower(A[i]);
      }
    }
    else
    {
      if (isupper(A[i]))
        A[i] = tolower(A[i]);
    }
  }
}

void verticalOuput(char *A)
{
  char marks[] = {' ', ',', '!', '?', ':', ';', '"', '(', ')', '{', '}', '[', ']', '-', '_'};
  int lenMarks = 15; 
  for (int i = 0; i < lenStr(A); ++i)
  {
    if (inArr(marks, A[i], lenMarks) && (inArr(marks, A[i-1], lenMarks)))
      cout << '\0';
    else if (inArr(marks, A[i], lenMarks))
      cout << endl;
    else
      cout << A[i];
  }
  cout << endl;
}

void linearSearch(char *str, char *subStr)
{
  cout << "Индексы включений введенной подстроки в исходную строку: " << endl;
  int f1 = 0;
  for (int i = 0; str[i] != 0; ++i)
  {
    int f = 0;
    for (int j = 0; subStr[j] != 0; ++j)
    {
      if (str[i+j] != subStr[j])
      {
        f = 1;
        break;
      }
    }
    if (f == 0)
    {
      cout << i << ' ';
      f1 = 1;
    }
  }
  if (f1 == 0)
    cout << "Включения данной подстроки отсутствуют";
  cout << endl;
}

int count(char *array, char aim)
{
  int length = lenStr(array);
  int counter = 0;
  for (int i = 0; i < length; ++i)
  {
    if (array[i] == aim)
    {
      counter += 1;
    }
  }
  return counter;
}

bool stringComparing(char *A, char *B)
{
  int mnLen = (lenStr(A) <= lenStr(B)) ? (lenStr(A)) : (lenStr(B));
  for (int i = 0; i < mnLen; ++i)
  {
    if (A[i] < B[i])
      return true;
    else if (A[i] > B[i])
      return false;
  }
  return true;
}


void shakerSort(string *array, int length)
{
  int start = 0;
  int end = length - 2;
  while (start <= end)
  {
    for (int i = start; i < length - 1 - start; ++i)
    {
      if (array[i] > array[i+1])
        swap(array[i], array[i+1]);
    }
    for (int i = end ; i > 0 + start; --i)
    {
      if (array[i] < array[i-1])
        swap(array[i], array[i-1]);
    }
    start += 1;
    end -= 1;
  }
}

int main()
{
  bool shouldbreak = 0;
  const int N = 1000;
  char A[N];
  cout << "1. Введите новую строку" << endl;
  cin >> A;
  while (!shouldbreak)
  {
    cout << "Выберите пункт работы: " << endl
    << "2. Форматирование строки" << endl
    << "3. Вывод слов строки по алфавиту" << endl
    << "4. Вертикальный вывод слов строки" << endl
    << "5. Поиск включений подстроки в исходную строку" << endl
    << "0. Выход из программы" << endl;
    int choice = getNumber();
    switch (choice)
    {
      case 0:
      {
        shouldbreak = 1;
        break;
      }
      case 2:
      { 
        removeExtraMarks(A);
        fixCase(A);
        cout << A << endl;
        break;
      }
      case 3:
      {
        char marks[] = {' ', ',', '!', '?', ':', ';', '"', '(', ')', '{', '}', '[', ']', '-', '_'};
        int lenMarks = 15;
        removeExtraMarks(A);
        //fixCase(A);
        for (int i = 0; i < lenStr(A); ++i)
        {
          A[i] = tolower(A[i]);
        }
        string line = A;
        int wordsAmount = count(A, ' ')+1;
        string arr[N];
        int i = 0;
        stringstream ssin(line);
        while (ssin.good() && i < wordsAmount)
        {
            ssin >> arr[i];
            ++i;
        }
        shakerSort(arr, wordsAmount);
        for (int i = 0; i < wordsAmount; ++i)
        {
          // cout << arr[i] << ' ';
          for (int j = 0; j < lenStr(arr[i]); ++j)
          {
            if (!inArr(marks, arr[i][j], lenMarks))
              cout << arr[i][j];
          }
          cout << " ";
        }
        cout << endl;
        break;
      }
      case 4:
      {
        removeExtraMarks(A);
        fixCase(A);
        verticalOuput(A);
        break;
      }
      case 5:
      {
        removeExtraMarks(A);
        fixCase(A);
        cout << "Введите подстроку для поиска включений: " << endl;
        char subStr[N];
        cin >> subStr;
        linearSearch(A, subStr);
        break;
      }
    }
  }
  return 0;
}

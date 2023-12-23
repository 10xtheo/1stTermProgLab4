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

int len(char* A)
{
  int i;
  for (i = 0; A[i] != 0; ++i);
  return i;
}

bool in(char A[], char x)
{
  int f = false;
  for (int i = 0; i < len(A); ++i)
    if (A[i] == x)
      f = true;
  return f;
}

void removeExtraMarks(char* A)
{
  char marks[] = {' ', ',', '!', '?', ':', ';', '"', '(', ')', '{', '}', '[', ']', '-', '_'};
  for (int m = 0; m < len(marks); ++m)
  {
    int j = 0;
    bool lastCharMark = false;
    for (int i = 0 ; A[i] != '\0'; ++i)
    {
      if (in(marks, A[i]))
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
  if (islower(A[0]))
    A[0] = toupper(A[0]);
  for (int i = 1; i < len(A); ++i)
  {
    if (i != 1 && i != 2)
    {
      if (in(capitalMarks, A[i-1]) || in(capitalMarks, A[i-2]))
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
  for (int i = 0; i < len(A); ++i)
  {
    if (in(marks, A[i]) && (in(marks, A[i-1])))
      cout << '\0';
    else if (in(marks, A[i]))
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
  int length = len(array);
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
  int mnLen = (len(A) <= len(B)) ? (len(A)) : (len(B));
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
  cin.getline(A, N);
  while (!shouldbreak)
  {
    cout << "Выберите пункт работы: " << endl
    << "2. Форматирование строки" << endl
    << "3. Вывод слов строки по алфавиту" << endl
    << "4. Вертикальный вывод слов строки" << endl
    << "5. Поиск включений подстроки в исходную строку" << endl;
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
        removeExtraMarks(A);
        //fixCase(A);
        for (int i = 0; i < len(A); ++i)
        {
          A[i] = tolower(A[i]);
        }
        string line = A;
        int wordsAmout = count(A, ' ')+1;
        string arr[N];
        int i = 0;
        stringstream ssin(line);
        while (ssin.good() && i < wordsAmout)
        {
            ssin >> arr[i];
            ++i;
        }
        for(i = 0; i < wordsAmout; i++)
        {
            // cout << arr[i] << endl;
        }
        shakerSort(arr, wordsAmout);
        for (int i = 0; i < wordsAmout; ++i)
        {
          cout << arr[i] << ' ';
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

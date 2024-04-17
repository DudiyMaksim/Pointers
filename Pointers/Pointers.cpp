#include <iostream>
using namespace std;


void showarr(int* a, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

//task 1.1
void sort2(int* a, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (a[i] != -1)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                if (a[i] == a[j])
                {
                    a[j] = -1;
                }
            }
        }
    }
}

void sort1(int* a, int sizea, int* b, int sizeb)
{
    for (size_t i = 0; i < sizea; i++)
    {
        if (a[i] != -1)
        {
            for (size_t j = 0; j < sizeb; j++)
            {
                if (a[i] == b[j])
                {
                    b[j] = -1;
                }
            }
        }
    }
}

void s1ps1(int* a, int sizea, int* b, int sizeb) 
{
    for (size_t i = 0; i < sizea; i++)
    {
        if (a[i] == -1)
        {
            for (size_t j = i; j < sizea - 1; j++)
            {
                a[j] = a[j + 1];
            }
            sizea--;
            i--;
        }
    }

    for (size_t i = 0; i < sizeb; i++)
    {
        if (b[i] == -1)
        {
            for (size_t j = i; j < sizeb - 1; j++)
            {
                b[j] = b[j + 1];
            }
            sizeb--;
            i--;
        }
    }
    int* newarr = new int[sizea + sizeb];
    for (size_t i = 0; i < sizea; i++)
    {
        newarr[i] = a[i];
    }
    for (size_t i = 0; i < sizeb; i++)
    {
        newarr[sizea + i] = b[i];
    }
    showarr(newarr, sizea + sizeb);
    delete[] newarr;
}


void first(int* a, int* b, int sizea, int sizeb)
{
    sort2(&a[0], sizea);
    sort2(&b[0], sizeb);
    sort1(&a[0], sizea, &b[0], sizeb);
    s1ps1(&a[0], sizea, &b[0], sizeb);
}

//task 1.2
void second(int* a, int* b, int sizea, int sizeb)
{
    sort2(&a[0], sizea);
    sort2(&b[0], sizeb);
    s1ps1(&a[0], sizea, &b[0], sizeb);
}

//tasl 2.1
void initializations(int* arr, int sizea)
{
    for (size_t i = 0; i < sizea; i++)
    {
        cout << "Enter arr[" << i << "]  : ";
        cin >> arr[i];
    }
}

void deletedarr(int* arr)
{
    delete[] arr;
}

void addinarr(int* arr, int *size)
{
    (*size)+=1;
    cout << "Enter number that need to be add in array : ";
    cin >> arr[(*size)-1];
}

void pasteinarr(int* arr, int* size)
{
    int  ind, a;
    cout << "Enter index : (not index-1)"; cin >> ind;
    *size += 1;
    cout << "Enter number : "; cin >> arr[(*size) - 1];
    for (size_t i = *size; i > ind; i--)
    {
        int temp = arr[i-1];
        arr[i-1] = arr[i-2];
        arr[i - 2] = temp;
    }
    /*arr[ind] = temp;*/
}

void deleteelement(int* arr, int* size, int eldel)
{
    for (size_t i = eldel - 1; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

//task 2.2

int retindex(int a, int* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i]==a)
        {
            return i;
        }
    }
}

bool isitsimplenumber(int a)
{
    for (size_t i = 2; i < a; i++)
    {
        if (a%i==0)
        {
            return false;
        }
    }
    return true;
}

void deletesimplenumber(int* pointertoarr, int* size, int* arr2, int* size2)
{
    int newsize = 0; 

    for (size_t i = 0; i < *size; ++i)
    {
        if (isitsimplenumber(pointertoarr[i])==false)
        {
            pointertoarr[newsize++] = pointertoarr[i];
        }
    }
    *size2 = newsize;
    for (size_t i = 0; i < *size2; i++)
    {
        arr2[i] = pointertoarr[i];
    }
    pointertoarr = &arr2[0];
}

//task 2.3
void  pnn(int* posarr, int* sizepos, int* negarr, int* sizeneg, int* nullarr, int* sizenull, int* origarr, int orgsize)
{
    for (size_t i = 0; i < orgsize; i++)
    {
        if (origarr[i]>0)
        {
            (*sizepos)++;
            posarr[(*sizepos) - 1] = origarr[i];
        }
        else if (origarr[i] < 0)
        {
            (*sizeneg)++;
            negarr[(*sizeneg) - 1] = origarr[i];
        }
        else
        {
            (*sizenull)++;
            nullarr[(*sizenull) - 1] = origarr[i];
            
        }
    }
}

int main()
{
    srand(time(NULL));
    ///*task 1.1*/
    //int N, M;
    //cout << "Enter size of first array(N) : ";
    //cin >> N;
    //cout << "Enter size of second array(M) : ";
    //cin >> M;
    //int* pN = new int[N];
    //int* pM = new int[M];
    //for (size_t i = 0; i < N; i++)
    //{
    //    pN[i] = rand() % 10 + 1;
    //}
    //for (size_t i = 0; i < M; i++)
    //{
    //    pM[i] = rand() % 10 + 1;
    //}
    //showarr(&pN[0], N);
    //showarr(&pM[0], M);
    //first(&pN[0], &pM[0], N, M);
    //delete[] pN;
    //delete[] pM;
    ///*task 1.2*/
    /*int N, M;
    cout << "Enter size of first array(N) : ";
    cin >> N;
    cout << "Enter size of second array(M) : ";
    cin >> M;
    int* pN = new int[N];
    int* pM = new int[M];
    for (size_t i = 0; i < N; i++)
    {
        pN[i] = rand() % 10 + 1;
    }
    for (size_t i = 0; i < M; i++)
    {
        pM[i] = rand() % 10 + 1;
    }
    showarr(&pN[0], N);
    showarr(&pM[0], M);
    second(&pN[0], &pM[0], N, M);
    delete[] pN;
    delete[] pM;*/
    ///*task 2.1*/
    //int N;
    //cout << " Enter the size of array : ";
    //cin >> N;
    //int* arr = new int[N];
    //initializations(&arr[0], N);
    //showarr(&arr[0], N);
    ///*deletedarr(&arr[0]);*/
    ///*addinarr(&arr[0], &N);*/
    ///*pasteinarr(&arr[0], &N);*/
    ///*deleteelement(&arr[0], &N, 3);*/
    //showarr(&arr[0], N);
    //delete[] arr;
    ///*task 2.2*/
    //int size = 10;
    //int* newArray = new int(size);
    //int* pointertoarr = &newArray[0];
    //initializations(&newArray[0], size);
    //int* clearArray = new int(size);
    //deletesimplenumber(pointertoarr, &size, &clearArray[0], &size);
    //showarr(pointertoarr, size);
    //delete[] newArray;
    //delete[] pointertoarr;
    //delete[] clearArray;
    ///*task 2.3*/
    //int arr[10]{ -1,0,3,-4,5,6,0,8,-9,10 };
    //int* pA = &arr[0];
    //int neg=0, pos=0, null=0;
    //int* negarr = new int[neg];
    //int* posarr = new int[pos];
    //int* nullarr = new int[null];
    //pnn(&posarr[0], &pos, &negarr[0], &neg, &nullarr[0], &null, &arr[0], 10);
    //showarr(&negarr[0], neg);
    //cout << endl;
    //showarr(&posarr[0], pos);
    //cout << endl;
    //showarr(&nullarr[0], null);
    //delete[] negarr;
    //delete[] posarr;
    //delete[] nullarr;
}
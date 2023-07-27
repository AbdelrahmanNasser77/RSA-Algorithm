#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#define ll long long
using namespace std;
ll nearestPrime(ll n)
{
    if (n % 2 != 0)
        n -= 2;
    else
        n--;
    int i, j;
    for (i = n; i >= 2; i -= 2) {

        for (j = 3; j <= sqrt(i); j += 2)
        {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            return i;
    }
    return 2;
}
ll Gcd(ll a , ll b)
{
    ll r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ll modularExponentiation(ll base, ll exp, ll mod)
{
    ll result = 1;
    base = base % mod;
    if (base == 0)
        return 0;

    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base ) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
void SplashScreenMessage (int verticalSpaces , int horizintalSpaces , int dotsNum , int waitingTimeMS , string message)
{
    for (int i = 0; i < verticalSpaces; i++)
        cout << "\n";
    for (int i = 0; i < horizintalSpaces; i++)
        cout << "\t";
    cout << message << " ";
    for (int i = 0; i < dotsNum; i++)
    {
        usleep(waitingTimeMS * pow(10 , 5) );
        cout << ".";
    }
    system("cls");
}
void spaces(int n)
{
    for (int i = 0; i < n; i++)
        cout << "\t";
}
void border(int n , string border , string afterBorder)
{
    for (int i =0; i < n; i++)
        cout << border;
    cout << afterBorder;
}
int main()
{
    HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
    int blue = 9 , green = 10 , brightcyan = 11 , red = 12 , cyan = 3 , purple = 5 , yellow = 6 , Default = 7;
    int upperLimitP, upperLimitQ;
    string originalText;
    spaces(5); SetConsoleTextAttribute(t , blue); cout << "RSA Project"; SetConsoleTextAttribute(t , Default); cout << "\n";
    spaces(3); cout << "Done by --> "; SetConsoleTextAttribute(t , green); cout << "Abdelrahman Mohamed Nasser"; SetConsoleTextAttribute(t , Default); cout << " <--" << "\n\n";
    cout << "Enter TWO Distinct Upper Limits for p , q :" << "\n";
    cout << "\t" << "Upper limit for p --> " << "\t";
    cin >> upperLimitP;
    cout << "\t" << "Upper limit for q --> " << "\t";
    cin >> upperLimitQ;
    cout << "\n";
    cin.ignore();
    cout << "Enter"; SetConsoleTextAttribute(t , yellow); cout << " Original "; SetConsoleTextAttribute(t , Default); cout << "Message --> " << "\t";
    getline(cin , originalText);
    ll p , q;
    ll m , n;
    ll e = 2;
    ll d = 1;
    p = nearestPrime(upperLimitP);
    q = nearestPrime(upperLimitQ);
    n = p * q;
    m = (p - 1) * (q - 1);

    while ( Gcd(m,e) != 1){
        e++;
    }
    while ((d * e) % m != 1){
        d++;
    }
    ll originalTextCode[originalText.size()];
    for (int i = 0; i < originalText.size(); i++){
        originalTextCode[i] = originalText[i];
    }
    ll cipherTextCode[originalText.size()];
    for (int i = 0; i < originalText.size(); i++){
        cipherTextCode[i] = modularExponentiation(originalTextCode[i] , e , n);
    }
    string cipherText = "" ;
    for (int i = 0; i < originalText.size(); i++){
        cipherText +=  cipherTextCode[i] ;
    }
    ll decryptedTextCode[originalText.size()];
    for (int i = 0; i < originalText.size(); i++){
        decryptedTextCode[i] = modularExponentiation(cipherTextCode[i] , d , n);
    }
    string decryptedText = "";
    for (int i = 0; i < originalText.size(); i++){
        decryptedText +=  decryptedTextCode[i];
    }
    usleep( 2 * pow(10,5) );
    system("cls");
    SetConsoleTextAttribute(t , green); SplashScreenMessage(12 , 6 , 3 , 3 ,  "Generating KEYS");
    SetConsoleTextAttribute(t , red); SplashScreenMessage(12 , 6 , 3 , 3 ,  "ENCRYPTING MESSAGE");
    SetConsoleTextAttribute(t , brightcyan); SplashScreenMessage(12 , 6 , 3 , 3 ,  "DECRYPTING Message"); SetConsoleTextAttribute(t,Default);
    usleep( 2 * pow(10,5) );
    system("cls");
    spaces(5); SetConsoleTextAttribute(t , blue); cout << "RSA Project" << "\n\n"; SetConsoleTextAttribute(t , Default);
    border(10 , "*" , " "); SetConsoleTextAttribute(t , green); cout << "KEYS "; SetConsoleTextAttribute(t , Default); border(10 , "*" , "\n");
    spaces(1); SetConsoleTextAttribute(t , cyan); border(10, "-" , "\n"); SetConsoleTextAttribute(t , Default);
    spaces(1); cout << "p = " << p << "\n";
    spaces(1); cout << "q = " << q << "\n";
    spaces(1); cout << "n = " << n << "\n";
    spaces(1); cout << "m = " << m << "\n";
    spaces(1); cout << "e = " << e << "\n";
    spaces(1); cout << "d = " << d << "\n";
    spaces(1); SetConsoleTextAttribute(t , cyan); border(10, "-" , "\n"); SetConsoleTextAttribute(t , Default);
    spaces(3); border(10 , "*" , " "); SetConsoleTextAttribute(t , yellow); cout << "ORIGINAL Message "; SetConsoleTextAttribute(t , Default);  border(10 , "*" , "\n");
    spaces(3); SetConsoleTextAttribute(t , cyan); border(originalText.size() , "-" , "\n"); SetConsoleTextAttribute(t , Default);
    spaces(3);  cout << originalText << "\n";
    spaces(3); SetConsoleTextAttribute(t , cyan); border(originalText.size() , "-" , "\n"); SetConsoleTextAttribute(t , Default);
    cout << "\n";
    spaces(3); border(10 , "*" , " "); SetConsoleTextAttribute(t , red); cout << "CIPHER Message "; SetConsoleTextAttribute(t , Default); border(10 , "*" , "\n");
    spaces(3); SetConsoleTextAttribute(t , cyan); border(originalText.size() , "-" , "\n"); SetConsoleTextAttribute(t , Default);
    spaces(3);  cout << cipherText << "\n";
    spaces(3); SetConsoleTextAttribute(t , cyan); border(originalText.size() , "-" , "\n"); SetConsoleTextAttribute(t , Default);
    cout << "\n";
    spaces(3); border(10 , "*" , " "); SetConsoleTextAttribute(t , brightcyan); cout << "DECRYPTED Message "; SetConsoleTextAttribute(t , Default); border(10 , "*" , "\n");
    spaces(3); SetConsoleTextAttribute(t , cyan); border(originalText.size() , "-" , "\n"); SetConsoleTextAttribute(t , Default);
    spaces(3);  cout << decryptedText << "\n";
    spaces(3); SetConsoleTextAttribute(t , cyan); border(originalText.size() , "-" , "\n"); SetConsoleTextAttribute(t , Default);

    // sample input : Hello World! Discrete Math is important subject.

    return 0;
}

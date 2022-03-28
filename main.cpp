#include <iostream>
#include<cctype>
#include<string>
using namespace std;


int main()
{
    /*
     In this code, I treated each letter in its input as a capital letter.
    */
    string message;
    cout<<"Please enter message: "<<endl;
    getline(cin,message); ///To ignore spaces
    int encrypt_or_decipher; ///To know if you want to encrypt or decrypt
    cout<<" if you want to encrypt use 1 if decipher use 2"<<endl;
    cin>>encrypt_or_decipher;
    int shift;
    cout<<"What is the number of shifts which you wants to the right or left?" <<endl;
    cin>>shift;

///To convert the shift to a positive number
    if (shift<-25)
    {
       shift %=26;
    }
    if (shift<0)
    {
       shift = shift + 26;
    }
///encrypt the message
    if(encrypt_or_decipher==1)
    {
    int len1 = message.length();
    string encrypted_message = " ";
    for (int i=0; i< len1; i++)
    {
        message[i]=toupper(message[i]);          ///Convert each letter in the message to uppercase
        if(message[i]==' ')
        {
            encrypted_message+=message[i];
        }
        else if(message[i]!=' ')
        {

        int res1 = int(message[i])-65 + shift;  ///to find the ascii of each letter and shift the number to the new number which is the value of  cipher
        if (res1<26)                           ///When the user enters the conversion value appropriate for the number of characters use
        {
            encrypted_message+=char (res1+65);
        }
        else
        {
            res1%=26;
            encrypted_message+=char (res1+65);
        }
        }
    }
    cout<<"The message after cipher is"<<encrypted_message<<endl;
    }
///decipher the message
    if(encrypt_or_decipher==2)
    {
    int len2 = message.length();
    string decipher_message = " ";
    for (int j =0; j<len2 ;j++)
    {
        message[j]=toupper(message[j]);
        if (message[j]==' ')
        {
            decipher_message+=message[j];
        }
        else if(message[j]!=' ')
        {
        int res2 = int (message[j])-65-shift; ///To find out the value of a character, whether it is 0, 1, etc.
        decipher_message+=char (res2+65);///To convert it back to its value in ASCII and return it to the letter
        }
    }
    cout<<"The message after decipher is "<<decipher_message;
    }
    return 0;
}

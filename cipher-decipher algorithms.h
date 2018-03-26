//FCI - programming 1 - 2018 - Assignment #2
//program name : encryption .cpp
//Last modification date : 2/3/2018
//Belal hammdy 20170077 G1
//Ahmed sayed mansour 20170022 G1
//Abdelrahman sayed ahmed 20170150 G1
//Teaching assistant : Eng./Menna ahmed
//-------------------------------------------


#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


string morsealpha[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
int rail[4][200005];


/*A*/ int affinecipher(string msg, int encodeOrDecode)
{
       if (encodeOrDecode == 1)
    {
           for (int i=0 ; i<(msg.size()) ; i++){
                if(msg[i]>96 && msg[i]<123)
                    msg[i] -=32;
                if (msg[i]>122 || msg[i]<65 || (msg[i]> 90)&& (msg[i]<97 ))
                    continue ;
                else{
                    msg[i]=((msg[i]-65)*5+8)%26 ;
                    msg[i] +=97;
                }
           }
           cout << msg ;
           msg="";
    }
    else
    {
     for (int i=0 ; i<msg.size() ; i++){
                if(msg[i]>96 && msg[i]<123)
                    msg[i] -=32;
                if (msg[i]>122 || msg[i]<65 || (msg[i]> 90)&& (msg[i]<97 ))
                    continue ;
                else{
                    msg[i]-=65;
                    msg[i] =21*((msg[i]+26)-8)%26;
                    msg[i]+=97;
                }
           }
           cout << msg ;
           msg="";   
    }
	return 0;

}
/*M*/ int caesercipher(string inp, int encodeOrDecode , int shnum)
{
	if (encodeOrDecode == 1)
	{
		for (int i = 0; i <= (inp.length()); i++) {
			inp[i] = int((inp[i]));
			if (inp[i] >= 97 && inp[i] <= 122)
				inp[i] -= 32;
			if (inp[i] >= 65 && inp[i] <= 90) {
				inp[i] = inp[i] + shnum;
				while (inp[i]>90)
					inp[i] -= 26;
			}
			cout << (char)(inp[i]);
		}
	}
	else
	{
		for (int i = 0; i <= (inp.length()); i++) {
			inp[i] = int((inp[i]));
			if (inp[i] >= 97 && inp[i] <= 122)
				inp[i] -= 32;
			if (inp[i] >= 65 && inp[i] <= 90) {
				inp[i] = inp[i] - shnum;
				while (inp[i]<65)
					inp[i] += 26;
			}
			cout << (char)(inp[i]);
		}

	}
	cout << endl;

	return 0;

}
/*M*/ int atbashcipher(string inp, int encodeOrDecode)
{
	for (int i = 0; i <= (inp.length()); i++) {
		if (inp[i] == ' ') cout << ' ';
		else {
			inp[i] = int((inp[i]));
			if (inp[i] >= 65 && inp[i] <= 90)
				inp[i] = 155 - inp[i];
			else if (inp[i] >= 97 && inp[i] <= 122)
				inp[i] = 219 - inp[i];
			cout << (char)(inp[i]);
		}
	}
	cout << endl;
	return 0;



}
/*B*/ int rot13cipher(string word, int encodeOrDecode)
{
	string  test;
	int index;
	if (encodeOrDecode == 1)
	{
		test = word;
		for (int i = 0; i<word.size(); i++)
		{
			if (word[i] == toupper(word[i]) && isalpha(word[i]))
			{
				index = (word[i]) + 13;
				if (index>90)
					index -= 26;
			}
			else if (word[i] == tolower(word[i])&&isalpha(word[i])) {
				index = (word[i]) + 13;
				if (index>122)
					index -= 26;
			}
			else
				index = word[i];
			test[i] = char(index);
		}
		cout << test;
	}
	else
	{
		test = word;
		for (int i = 0; i<word.size(); i++)
		{
			if (word[i] == toupper(word[i]) &&isalpha(word[i]) )
			{
				index = (word[i]) - 13;
				if (index<65)
					index += 26;
			}
			else if (word[i] == tolower(word[i]) &&isalpha(word[i]) ) {
				index = (word[i]) - 13;
				if (index<97)
					index += 26;
			}
			else
				index = word[i];
			test[i] = char(index);
		}
		cout << test;
	}
	return 0;

}
/*B*/ int baconiancipher(string word, int encodeOrDecode)
{
	if (encodeOrDecode == 1)
	{
		string  neww, test;
		int index;
		for (int i = 0; i<word.size(); i++)
		{
			if (isalpha(word[i]))
			{
				index = int(tolower(word[i]) - 'a');
				for (int k = 0; k<5; k++)
				{
					if (index & 1)
					{
						test += 'b';
					}
					else
						test += 'a';
					index = (index >> 1);
				}
				swap(test[0], test[4]);
				swap(test[1], test[3]);
				neww += test;
				test = "";
			}
			else
				neww += word[i];
		}
		cout << neww << endl;
	}
	else
	{
		string test, neww;
		int index, counter = 0;
		for (int i = 0; i<word.size(); i++)
		{
			if (tolower(word[i]) != 'a' && tolower(word[i]) != 'b' && word[i] != ' ')
			{
				cout << "Invalid characters..\a \n ";
				neww = "";
				break;
			}

			index = 0;
			if (word[i] == ' ')
			{
				neww += ' ';
				counter--;
			}
			else
				test += tolower(word[i]);

			if ((counter + 1) % 5 == 0 && word[i] != ' ')
			{
				for (int k = 4; k >= 0; k--)
				{
					if (test[k] == 'b')
					{
						index += (1 << abs(k - 4));
					}
				}
				test = "";
				neww += (char(index + 'a'));

			}
			counter++;

		}

		cout << neww << endl;
	}
	return 0;

}
/*M*/ int simplesub(string inp, int encodeOrDecode)
{
	string x1 = "abcdefghijklmnopqrstuvwxyz",  key;
	int x = encodeOrDecode, c = 0;
	for (int i = 0; i <= (inp.length()); i++) {
		inp[i] = int((inp[i]));
		if (inp[i] >= 65 && inp[i] <= 90)
			inp[i] = 32 + inp[i];
		inp[i] = char(inp[i]);
	}
	cout << "write your KEY:" << endl;
	cin >> key;
	for (int i = 0; i <= (key.length()); i++) {
		key[i] = int((key[i]));
		if (key[i] >= 65 && key[i] <= 90)
			key[i] = 32 + key[i];
		key[i] = char(key[i]);
	}
	string x2 = key;
	for (int i = 0; i <= x1.length(); i++) {
		c = 0;
		for (int j = 0; j <= key.length(); j++) {
			if (x1[i] != key[j])
				c += 1;
			if (c == key.length() + 1)
				x2 = x2 + x1[i];
		}
	}
	if (x == 1) {
		for (int h = 0; h <= inp.length(); h++) {
			if (inp[h] == ' ') cout << ' ';
			else for (int s = 0; s <= x2.length(); s++) {
				if (x1[s] == inp[h])
					cout << x2[s];
			}
		}
	}
	else if (x == 2) {
		for (int h = 0; h <= inp.length(); h++) {
			if (inp[h] == ' ') cout << ' ';
			else for (int s = 0; s <= x2.length(); s++) {
				if (x2[s] == inp[h])
					cout << x1[s];
			}
		}
	}
	cout << endl;

	return 0;

}
/*A*/ int polybius(string word, int encodeOrDecode)
{
    char key[5],mat[6][6];
    string code,cypher;
    int choice,q=0;
    for (int j=1 ;j<6; j++){
        for (int i=1 ;i<6; i++){
            mat[j][i]='A'+q;
            q++;
        }
    }
    if (encodeOrDecode==1) {
            cout << "enter your key : ";
            cin >> key;
            code = word;
            for (int i=0; i<code.size();i++){
                code[i]=toupper(code[i]);
            }
            for (int i=1,k=0; i<6; i++,k++){
                mat[0][i]=key[k];
                mat[i][0]=key[k];
            }
            for (int num=0;num<code.size();num++){
                for (int i=1; i<6 ; i++){
                    for (int p=1; p<6 ; p++){

                        if (code[num]=='Z'){
                            cypher+= "64";
                        }
                        else if (code[num] == mat[p][i]){
                            cypher+= key[p-1];
                            cypher+= key[i-1];
                        }
                    }
                }
            }
            cout<<cypher;
            code = "",cypher="";
            key[5]={};
       }
       else
        {
            
           {
            cout <<"enter your key : ";
            cin >>key;
            for (int i=1,k=0; i<6; i++,k++){
                mat[0][i]=key[k];
                mat[i][0]=key[k];
            }
            cypher = word;
            for (int i=0; i<(cypher.size()); i+=2){
                if (cypher[i]=='6' && cypher[i+1]=='4'){
                    code+='Z';
                }
                else if ( cypher[i]==' '){
                    code += ' ';
                    i-=1;
                }
                else {
                        for (int j=0; j<6;j++){
                            for (int f=0; f<6; f++){
                                if (cypher[i] == key[f] && cypher[i+1] == key[j]){
                                    code += mat[f+1][j+1];
                                }
                            }
                        }
                }
            }
            cout << code;
            code = "",cypher="";
            key[5]={};
       }
       }
	return 0;

}
/*B*/ int morsecode(string word, int enDec)
{
	string test;
	int index;
	if (enDec == 1)
	{
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] == ' ')
			{
				cout << "  ";
			}
			else if (isalpha(word[i]))
			{
				cout << morsealpha[int(tolower(word[i]) - 'a')] << " ";
			}
			/*else
			{
			cout << word[i];
			}*/
		}
	}
	else
	{
		string test;
		word = word + " ";
		for (int i = 0; i<word.size(); i++)
		{
			if (word[i] != ' ')
			{
				test = test + word[i];

			}
			else if (word[i] == ' ' && word[i + 1] == ' ' && word[i + 2] == ' ')
			{
				for (int k = 0; k<26; k++)
				{
					if (test == morsealpha[k])
					{
						cout << char(k + 'a');
						test = "";
						break;
					}

				}
				cout << test;
				test = "";
				cout << " ";
			}
			else if (word[i] == ' ')
			{
				for (int k = 0; k<26; k++)
				{
					if (test == morsealpha[k])
					{
						cout << char(k + 'a');
						test = "";
						break;
					}

				}
				cout << test;
				test = "";
			}

		}
	}
	return 0;
}
/*A*/ int xorp(string word, int encodeOrDecode)
{
    char key;
    string code,cypher,msg="";
    if (encodeOrDecode==1)
    {
            cout <<"enter your key : ";
            cin >> key;
            code = word;
            for (int i =0; i<code.size();i++){
                code[i]= char (code[i]^(key));
            }
            cout << "Text : ";
            for (int i=0; i<code.size();i++){
                cout <<char(code[i]+96);
            }
            cout << endl;
            cout << "Hex : ";
            for (int i=0; i<code.size();i++){
                if (int(code[i])<10){
                    cout << '0';
                }
                cout <<hex <<int (code[i]) ;
            }
            cypher="",code="";
    }
    else
    {
         cout << "enter your key : ";
            cin >> key;
            cin.ignore();
            cout << "Enter a message to decipher : \n";
            cin >> hex >> cypher;  
            for (int i=0; i<cypher.size()-1;i+=2){
                    if (cypher[i]>='a'&&cypher[i]<='f'){
                        cypher[i] -= 87;
                    }
                    else cypher[i]-=48;

                    if (cypher[i+1]>='a'&&cypher[i+1]<='f'){
                        cypher[i+1] -= 87;
                    }
                    else cypher[i+1]-=48;

                    code +=cypher[i]*16+cypher[i+1];

            }
            for (int i=0; i<code.size();i++){
                code[i]=code[i]^key;
            }
            cout <<"your msg is : " << code;
            cypher="",code="";
    }
	return 0;

}
/*B*/ int railfence(string word, int encodeOrDecode, int key)
{
	memset(rail, 0, 200005);
	int row = 0, col = 0, index = 0, test = 1;
	if (encodeOrDecode == 1)
	{
		for (int k = 0; k<word.size(); k++)
		{
			rail[abs(row)][abs(col)] = int(word[k]);
			row++;
			col++;
			if (row >= (key - 1))
				row = -row;
		}
		for (int i = 0; i <key; i++)
		{
			for (int j = 0; j<200005; j++)
			{
				if (rail[i][j])
				{
					cout << char(rail[i][j]);
				}
			}
		}
	}
	else if (encodeOrDecode == 2 && key == 3)
	{
		for (int i = 0; i<word.size(); i += 4)
		{
			rail[0][i] = word[index];
			index++;
		}
		for (int i = 1; i<word.size(); i += 2)
		{
			rail[1][i] = word[index];
			index++;
		}
		for (int i = 2; i<word.size(); i += 4)
		{
			rail[2][i] = word[index];
			index++;
		}
		for (int k = 0; k<word.size(); k++)
		{
			cout << char(rail[abs(row)][abs(col)]);
			row++;
			col++;
			if (row >= 2)
				row = -row;
		}

	}
	else {
		for (int i = 0; i<word.size(); i += 6)
		{
			rail[0][i] = word[index];
			index++;
		}
		rail[1][1] = word[index];
		index++;
		for (int i = 1; i<int(word.size()); )
		{
			if (test % 2)
			{
				i += 4;
				if (i >= word.size())
					break;
				rail[1][i] = word[index];
				index++;
			}
			else {
				i += 2;
				if (i >= word.size())
					break;
				rail[1][i] = word[index];
				index++;
			}
			test++;
		}
		test = 1;
		rail[2][2] = word[index];
		index++;
		for (int i = 2; i<int(word.size()); )
		{
			if (test % 2)
			{
				i += 2;
				if (i >= word.size())
					break;
				rail[2][i] = word[index];
				index++;
			}
			else {
				i += 4;
				if (i >= word.size())
					break;
				rail[2][i] = word[index];
				index++;
			}
			test++;
		}
		for (int i = 3; i<word.size(); i += 6)
		{
			rail[3][i] = word[index];
			index++;
		}
		for (int k = 0; k<word.size(); k++)
		{
			cout << char(rail[abs(row)][abs(col)]);
			row++;
			col++;
			if (row >= 3)
				row = -row;
		}


	}
	return 0;

}
int main()
{
	//freopen("D:\\in.txt","r",stdin);
	//freopen("D:\\out2.txt","w",stdout);
	first:
	int typ, cipherOrDecipher, key, choose , shnum;
	string word;
	char rep;
	//taking the order from the user correctly
	while (true)
	{
		cout << "Ahlan ya user ya habibi.\nWhat do you like to do today ? \n\n1- Cipher a message\n2- Decipher a message\n3- End\n";
		cin >> choose;
		if (choose != 1 && choose != 2 && choose!=3)
		{
			cout << "Error .. please enter correct input.\n";
		}
		else
			break;
	}
	//taking the type from the user correctly
	if (choose == 3)
		goto i;
	while (true)
	{
		cout << "Please enter your encryption type : \n0- Affine Cipher. \n1- Caesar Cipher. \n2- Atbash Cipher. \n3- ROT13 Cipher. \n4- Baconian Cipher. \n5- Simple Substitution Cipher. \n6- Polybius Square Cipher. \n7- Morse Code. \n8- XOR Cipher. \n9- Rail-fence Cipher. \n";
		cin >> typ;
		if (typ > 9 || typ < 0)
		{
			cout << "Error Please try again ... \n";
		}
		else
			break;
	}

	//taking Cipher or deCipher from the user correctly
	cipherOrDecipher = choose;
    if (choose==1)
    {
        cout << "Enter a message to cipher : \n" ;
    }
    else if (choose==2 && typ!=8)
    {
        cout << "Enter a message to decipher : \n" ;
    }
    //there is exception in xor problem
    if (choose!=2|| typ!=8){
	cin.ignore(); //to use getline	
	getline(cin, word);
    }
        for (int i = 0 ; i<word.size() ; i++)
    {
        if (!isalpha(word[i]) && word[i]!=' ' && choose==1)
        {
            cout << "There is invalid characters and there might be some errors.\n" ;
            break;
        }
    }
	if (word.size() > 200000 && typ == 9)
	{
		cout << "NO Enough memory to make this process..";
	}

	else if (typ == 0) affinecipher(word, cipherOrDecipher);
	else if (typ == 1)
	{
		cout << "Enter the shift number : ";
		cin >> shnum;
		caesercipher(word, cipherOrDecipher, shnum);
	}
	else if (typ == 2) atbashcipher(word, cipherOrDecipher);
	else if (typ == 3) rot13cipher(word, cipherOrDecipher);
	else if (typ == 4) baconiancipher(word, cipherOrDecipher);
	else if (typ == 5) simplesub(word, cipherOrDecipher);
	else if (typ == 6) polybius(word, cipherOrDecipher);
	else if (typ == 7) morsecode(word, cipherOrDecipher);
	else if (typ == 8) xorp (word, cipherOrDecipher);
	else if (typ == 9)
	{
		while (true)
		{
			cout << "Please enter the key (3 or 4)\n";
			cin >> key;
			if (key == 3 || key == 4)
				break;
			else
				cout << "Error please try again.\n";
		}
		railfence(word, cipherOrDecipher, key);
	}

	cout << endl;
	while (true)
	{
		cout << "Do you want to repeat? (Y/N) : ";
		cin >> rep;
		if (tolower(rep) == 'y')
			goto first;
		if (tolower(rep) == 'n') {
			i:
			system("pause");
			return 0;
		}
		else
			cout << "Error ... try again.";
	}
}





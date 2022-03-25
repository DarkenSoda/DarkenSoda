#include<iostream>
#include<cctype>
#include<string>
using namespace std;

//variables used for storing the message, Keyword
//and the repeated keyword.
string msg;
string keyword;
char repeated[80];

//Takes input from user to decide which operation to do (cipher/decipher)
int input() {
	printf("1 to cipher a message\n2 to decipher a message\n3 to exit\n");
	int inp;
	cin >> inp;
	if (inp <= 3 && inp > 0) return inp;
	else {
		printf("invalid input, enter a number from 1 to 3\n");
		input();
	}
}

//Function for encryption, using operation done on ASCII value of each letter
void encryption(string msg, char* repeat, int len) {
	for (int i = 0; i < len; i++) {
		if (msg[i] < 65 || msg[i] > 90)		//checks if the character is not alpha uppercase
			cout << msg[i];					//in this case, prints the character as it is
		else {						//if the character is alpha
			char enc = ((msg[i] + repeat[i]) % 26) + 65;	//encode the character
			cout << enc;									//prints the encoded character
		}
	}
	cout << endl;
}

//function for decryption, also done on ASCII value of each letter
void decryption(string msg, char* repeat, int len) {
	for (int i = 0; i < len; i++) {
		if (msg[i] < 65 || msg[i]>90)		//checks if the char is not alpha
			cout << msg[i];
		else {
			char dec = msg[i] - repeat[i] + 65;		//decryption
			if (dec < 65) dec += 26;				//if the result value is less than the ASCII range, add 26
			cout << dec;							//print result
		}
	}
	cout << endl;
}

//function to check message length, the message should be 80 characters max
string check_msglen() {
	printf("enter message to cipher/decipher\n");
	string msg;
	getline(cin, msg);
	int len = msg.length();
	if (len > 80) {
		printf("The text is too long, please enter a text of max 80 characters\n");
		return check_msglen();
	}
	else return msg;
}

//function to check Keyword length, Keyword should be 8 characters max
string check_keywordlen() {
	printf("enter keyword\n");
	string keyword;
	getline(cin, keyword);
	int len = keyword.length();
	if (len > 8) {
		printf("Keyword is too long, please enter a keyword of max 8 characters\n");
		return check_keywordlen();
	}
	else return keyword;
}

//main function, calls all the other functions and loops till the user Exit.
int main() {
	while (true) {
		int inp = input();
		if (inp == 1) {
			cin.ignore();
			msg = check_msglen();
			keyword = check_keywordlen();
			int lenm = msg.length();
			int lenk = keyword.length();
			for (int i = 0; i < lenm; i++) {
				msg[i] = toupper(msg[i]);
				cout << msg[i];
			}
			cout << endl;
			for (int i = 0, j = 0; i < lenm; i++, j++) {
				if (j == lenk) j = 0;
				repeated[i] = toupper(keyword[j]);
				cout << repeated[i];
			}
			cout << endl;
			encryption(msg, repeated, lenm);
		}
		if (inp == 2) {
			cin.ignore();
			msg = check_msglen();
			keyword = check_keywordlen();
			int lenm = msg.length();
			int lenk = keyword.length();
			for (int i = 0; i < lenm; i++) {
				msg[i] = toupper(msg[i]);
				cout << msg[i];
			}
			cout << endl;
			for (int i = 0, j = 0; i < lenm; i++, j++) {
				if (j == lenk) j = 0;
				repeated[i] = toupper(keyword[j]);
				cout << repeated[i];
			}
			cout << endl;
			decryption(msg, repeated, lenm);
		}
		if(inp==3) {
			printf("program finished");
			break;
		}
	}
}
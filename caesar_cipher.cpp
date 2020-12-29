#include <iostream>
#include <string>

using namespace std;

void help()
{
	cout << "List of available arguments:\n" << endl;
	cout << "-e | encrypt num text - Encrypts the given text." << endl;
	cout << "-d | decrypt num text - Decrypts the given text." << endl;
	cout << "-h | help             - Displays this screen." << endl;
}

void encrypt(string s, int num)
{
	int i;
	string text = "";

	for (i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
			text += char(int(s[i] + num - 65) % 26 + 65);
		else if (islower(s[i]))
			text += char(int(s[i] + num - 97) % 26 + 97);
		else
			text += s[i];
	}

	cout << text << endl;
}

void decrypt(string s, int num)
{
	int i;
	string text = "";

	for (i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
			text += char(int(s[i] + (26 - num) - 65) % 26 + 65);
		else if (islower(s[i]))
			text += char(int(s[i] + (26 - num) - 97) % 26 + 97);
		else
			text += s[i];
	}

	cout << text << endl;
}

int main(int argc, char *argv[])
{
	int j, num;
	string text = "";
	if (argc > 3)
	{
		for (j = 3; j < argc; j++)
		{
			text += argv[j];
			text += ' ';
		}
		cout << "Input text: " << text << endl;
		num = atoi(argv[2]);

		if (strcmp(argv[1], "encrypt") == 0 || strcmp(argv[1], "-e") == 0)
		{
			cout << "Encrypted text: ";
			encrypt(text, num);
		}
		else if (strcmp(argv[1], "decrypt") == 0 || strcmp(argv[1], "-d") == 0)
		{
			cout << "Decrypted text: ";
			decrypt(text, num);
		}
		else if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0)
		{
			help();
		}
		else
		{
			cout << "Invalid argument." << endl;
			help();
		}
	}
	else
	{
		help();
	}

	return 0;
}

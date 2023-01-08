#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // for transform function

using namespace std;

int main()
{
    string file1_name, file2_name;

    // get the names of the files from the user
    cout << "Enter the name of the first file: ";
    cin >> file1_name;
    cout << "Enter the name of the second file: ";
    cin >> file2_name;

    // open the files in text mode
    ifstream in1("file1_name.txt");
    ifstream in2("file2_name.txt");

    if (!in1 || !in2)
    {
        // one of the files could not be opened
        cout << "Error opening one of the files." << endl;
        return 1;
    }

    // read the contents of the files into strings
    string s1((istreambuf_iterator<char>(in1)), istreambuf_iterator<char>());
    string s2((istreambuf_iterator<char>(in2)), istreambuf_iterator<char>());

    // close the files
    in1.close();
    in2.close();

    // convert the strings to lowercase
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    // compare the strings
    if (s1 == s2)
    {
        cout << "The files are identical." << endl;
    }
    else
    {
        cout << "The files are different." << endl;
    }

    // count the number of words in each file
    int count1 = 0, count2 = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (isspace(s1[i])) count1++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (isspace(s2[i])) count2++;
    }

    // output the number of words in each file
    cout << "The first file has " << count1 << " words." << endl;
    cout << "The second file has " << count2 << " words." << endl;

    return 0;
}

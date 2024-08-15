#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    int n = arr.size();
    int countPlus = 0;
    int countMinus = 0;
    int countZero = 0;
    float ratioPlus = 0.000000;
    float ratioMinus = 0.000000;
    float ratioZero = 0.000000;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            countPlus++;
        } else if (arr[i] < 0)
        {
            countMinus++;
        } else {
            countZero++;
        }
    }

    ratioPlus = static_cast<float>(countPlus) / n;
    ratioMinus = static_cast<float>(countMinus) / n;
    ratioZero = static_cast<float>(countZero) / n;
    

    cout << fixed << setprecision(6) << ratioPlus << endl;
    cout << fixed << setprecision(6) << ratioMinus << endl;
    cout << fixed << setprecision(6) << ratioZero << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

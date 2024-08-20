#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    // Extract hours, minutes, and seconds
    int hours = stoi(s.substr(0, 2));
    int minutes = stoi(s.substr(3, 2));
    int seconds = stoi(s.substr(6, 2));
    
    // Check if it's PM
    bool isPM = (s.substr(8, 2) == "PM");
    
    // Convert to 24-hour format
    if (isPM && hours != 12) {
        hours += 12;
    } else if (!isPM && hours == 12) {
        hours = 0;
    }
    
    // Format the result as a string
    stringstream result;
    result << setfill('0') << setw(2) << hours << ":"
           << setfill('0') << setw(2) << minutes << ":"
           << setfill('0') << setw(2) << seconds;
    
    return result.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
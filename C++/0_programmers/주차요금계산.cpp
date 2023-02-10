#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string str, char Delimiter)
{
    istringstream iss(str);
    string buffer;

    vector<string> result;
    while (getline(iss, buffer, Delimiter))
    {
        result.push_back(buffer);
    }

    return result;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    int car[10000] = {0};
    int car_intime[10000];
    for (int i = 0; i < 10000; i++)
    {
        car_intime[i] = -1;
    }
    for (int i = 0; i < records.size(); i++)
    {
        vector<string> record = split(records[i], ' ');
        string time = record[0];
        int car_n = stoi(record[1]);
        if (record[2] == "IN")
        {
            int hour = stoi(split(time, ':')[0]);
            int minute = stoi(split(time, ':')[1]);
            car_intime[car_n] = hour * 60 + minute;
        }
        else
        {
            int hour = stoi(split(time, ':')[0]);
            int minute = stoi(split(time, ':')[1]);
            car[car_n] += (hour * 60 + minute) - car_intime[car_n];
            car_intime[car_n] = -1;
        }
    }
    for (int i = 0; i < 10000; i++)
    {
        if (car_intime[i] != -1)
            car[i] += (23 * 60 + 59) - car_intime[i];
    }
    for (int i = 0; i < 10000; i++)
    {
        if (car[i] == 0)
            continue;
        if (car[i] <= fees[0])
            answer.push_back(fees[1]);
        else
        {
            int sum = fees[1];
            car[i] -= fees[0];
            sum += (((car[i] - 1) / fees[2]) + 1) * fees[3];
            answer.push_back(sum);
        }
    }
    return answer;
}
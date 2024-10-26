#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
    string lastName;
    string firstName;
    double gpa;
};

double gradeToGPA(const string &grade)
{
    if (grade == "A+")
        return 4.0;
    if (grade == "A")
        return 3.75;
    if (grade == "B+")
        return 3.50;
    if (grade == "B")
        return 3.0;
    if (grade == "C+")
        return 2.50;
    if (grade == "C")
        return 2.0;
    if (grade == "D+")
        return 1.50;
    if (grade == "D")
        return 1.0;
    if (grade == "F")
        return 0.0;
    return 0.0;
}

double calculateGPA(int numSubjects, vector<pair<string, int>> &subjects)
{
    double totalPoints = 0;
    int totalCredits = 0;
    for (const auto &subject : subjects)
    {
        double gpaPoints = gradeToGPA(subject.first);
        totalPoints += gpaPoints * subject.second;
        totalCredits += subject.second;
    }
    return (totalCredits == 0) ? 0 : totalPoints / totalCredits;
}

int partition(vector<Student> &students, int low, int high)
{
    Student pivot = students[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (students[j].gpa < pivot.gpa ||
            (students[j].gpa == pivot.gpa && (students[j].lastName < pivot.lastName ||
                                              (students[j].lastName == pivot.lastName && students[j].firstName < pivot.firstName))))
        {
            i++;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSort(vector<Student> &students, int low, int high)
{
    if (low < high)
    {
        int pi = partition(students, low, high);
        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; i++)
    {
        string lastName, firstName;
        int numSubjects;
        cin >> lastName >> firstName >> numSubjects;

        vector<pair<string, int>> subjects(numSubjects);
        for (int j = 0; j < numSubjects; j++)
        {
            string grade;
            int credits;
            cin >> grade >> credits;
            subjects[j] = make_pair(grade, credits);
        }

        double gpa = calculateGPA(numSubjects, subjects);
        students[i] = {lastName, firstName, gpa};
    }

    quickSort(students, 0, n - 1);

    for (const auto &student : students)
    {
        cout << student.lastName << " " << student.firstName << " "
             << fixed << setprecision(3) << student.gpa << endl;
    }
}

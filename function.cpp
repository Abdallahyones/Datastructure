#include <bits/stdc++.h>
#include "Student.h"
#include "Sorting.h"

bool operator< (const Student& A , const Student& B){
    return A.getGPA() < B.getGPA() ;
}
bool operator<= (const Student& A , const Student& B){
    return A.getGPA() <= B.getGPA() ;
}
bool operator> (const Student& A , const Student& B){
    return A.getGPA() > B.getGPA() ;
}
bool operator>= (const Student& A , const Student& B){
    return A.getGPA() >= B.getGPA() ;
}

vector<Student> readStudentsFromFile(string filename){
    int n = 5 ;
    vector<Student>list ;
    fstream file (filename+".txt");
    // Check if the file is opened successfully
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return list;
    }
    file >> n ;
    while (n--){
        string name , id ;
        float gpa ;
        getline(file , name);  // end line
        getline(file , name);
        file >> id >> gpa ;
        list.emplace_back(name , id , gpa);
    }
    file.close();
    return list;
}
void SortedByGPA() {
    vector<Student>arr = readStudentsFromFile( "students");
    vector<Student>ls = arr;
    int count = 0 ;
    ofstream outfile ("SortedByGPA.txt");
    auto start = std::chrono::high_resolution_clock::now();
    outfile << "Algorithm: Insertion Sort\nNumber of comparisons :" ;
    outfile << insertionSort(ls) << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    outfile << "Running time: " << elapsed.count()*1000 << " milliseconds\n";
    for(auto vl : ls){
        outfile << vl.getName() << ' ' << vl.getID() << ' ' << vl.getGPA() << endl ;
    }

    start = chrono::high_resolution_clock ::now();
    outfile << "\nAlgorithm: Selection Sort\nNumber of comparisons :";
    ls = arr;
    outfile << selectionSort(ls) << '\n';
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    outfile << "Running time: " << elapsed.count()*1000 << " milliseconds\n";
    for(auto vl : ls){
        outfile << vl.getName() << ' ' << vl.getID() << ' ' << vl.getGPA() << endl ;
    }

    start = chrono::high_resolution_clock ::now();
    outfile << "\nAlgorithm: Bubble Sort\nNumber of comparisons :" ;
    ls = arr;
    outfile << bubbleSort(ls) << '\n';
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    outfile << "Running time: " << elapsed.count()*1000 << " milliseconds\n";
    for(auto vl : ls){
        outfile << vl.getName() << ' ' << vl.getID() << ' ' << vl.getGPA() << endl ;
    }
    start = chrono::high_resolution_clock ::now();
    outfile << "\nAlgorithm: Shell Sort\nNumber of comparisons :" ;
    ls = arr;
    outfile << shellSort(ls) << '\n';
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    outfile << "Running time: " << elapsed.count()*1000 << " milliseconds\n";
    for(auto vl : ls){
        outfile << vl.getName() << ' ' << vl.getID() << ' ' << vl.getGPA() << endl ;
    }

    start = chrono::high_resolution_clock ::now();
    outfile << "\nAlgorithm: Merge Sort\nNumber of comparisons :";
    ls = arr;
    outfile << mergeSort(ls) << '\n' ;
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    outfile << "Running time: " << elapsed.count()*1000 << " milliseconds\n";
    for(auto vl : ls){
        outfile << vl.getName() << ' ' << vl.getID() << ' ' << vl.getGPA() << endl ;
    }

    start = chrono::high_resolution_clock ::now();
    outfile << "\nAlgorithm: Quick Sort\nNumber of comparisons :" ;
    ls = arr;
    outfile << quickSort(ls) << '\n';
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    outfile << "Running time: " << elapsed.count()*1000 << " milliseconds\n";
    for(auto vl : ls){
        outfile << vl.getName() << ' ' << vl.getID() << ' ' << vl.getGPA() << endl ;
    }
    outfile.close();
}


int main() {
    SortedByGPA();
    return 0;
}
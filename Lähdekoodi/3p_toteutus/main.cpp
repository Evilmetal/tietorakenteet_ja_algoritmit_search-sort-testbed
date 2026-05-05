#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void introduction()
{
    cout << "Search and Sorting Testbed - Phases 1-2" << endl;
}

// Prints the main menu
void instructions()
{
    cout << endl;
    cout << "1) Linear searching" << endl;
    cout << "2) Binary searching" << endl;
    cout << "3) n^2 type sorting" << endl;
    cout << "4) n * log(n) type of sorting" << endl;
    cout << "5) Sorting algorithms performance inspection" << endl;
    cout << "6) Quit" << endl;
}

// Gets the users menu choice
int get_choice()
{
    int choice;
    cout << endl
         << "Your choice: ";
    cin >> choice;
    return choice;
}

// Returns a sorted list of odd integers
vector<int> generate_search_data(int size)
{
    vector<int> data;
    data.reserve(size);
    for (int i = 0; i < size; ++i)
        data.push_back(2 * i + 1);
    return data;
}

// Returns the index of target if found, otherwise -1
int linear_search(const vector<int> &data, int target)
{
    for (int i = 0; i < static_cast<int>(data.size()); ++i)
    {
        if (data[i] == target)
            return i;
    }
    return -1;
}

// Generates fresh test data, asks for a target value, performs linear search
void run_linear_search()
{
    int size;
    int target;

    cout << "Enter the number of data items: ";
    cin >> size;

    vector<int> data = generate_search_data(size);

    cout << "Enter the target value to search for: ";
    cin >> target;

    int position = linear_search(data, target);

    if (position == -1)
        cout << "Target " << target << " was not found." << endl;
    else
        cout << "Target " << target << " was found at position " << (position + 1)
             << " of " << size << "." << endl;
}

int binary_search(const vector<int> &data, int target)
{
    int left = 0;
    int right = static_cast<int>(data.size()) - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (data[mid] == target)
            return mid;
        if (data[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void run_binary_search()
{
    int size;
    int target;

    cout << "Enter the number of data items: ";
    cin >> size;

    vector<int> data = generate_search_data(size);

    cout << "Enter the target value to search for: ";
    cin >> target;

    int position = binary_search(data, target);

    if (position == -1)
        cout << "Target " << target << " was not found." << endl;
    else
        cout << "Target " << target << " was found at position " << (position + 1)
             << " of " << size << "." << endl;
}

vector<int> generate_random_data(int size)
{
    vector<int> data;
    data.reserve(size);
    for (int i = 0; i < size; ++i)
    {
        data.push_back(rand() % (10 * size));
    }
    return data;
}

void insertion_sort(vector<int> &data)
{
    for (int i = 1; i < static_cast<int>(data.size()); ++i)
    {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}

void run_n2_sorting()
{
    int size;
    int display_count;

    cout << "Enter the number of data items: ";
    cin >> size;

    vector<int> data = generate_random_data(size);

    cout << "Enter the number of items to display: ";
    cin >> display_count;

    cout << "Data before sorting:" << endl;
    for (int i = 0; i < display_count && i < size; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    insertion_sort(data);

    cout << "Data after sorting:" << endl;
    for (int i = 0; i < display_count && i < size; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Handles the users menu choice
void do_choice(int choice)
{
    switch (choice)
    {
    case 1:
        run_linear_search();
        break;
    case 2:
        run_binary_search();
        break;
    case 3:
        run_n2_sorting();
        break;
    case 4:
    case 5:
        cout << "Choice " << choice << " not implemented." << endl;
        break;
    case 6:
        cout << "Quitting..." << endl;
        break;
    default:
        cout << "Please select a valid menu option." << endl;
        break;
    }
}

int main()
{
    introduction();

    bool running = true;
    while (running)
    {
        instructions();
        int choice = get_choice();

        if (choice == 6)
        {
            do_choice(choice);
            running = false;
        }
        else
            do_choice(choice);
    }

    return 0;
}
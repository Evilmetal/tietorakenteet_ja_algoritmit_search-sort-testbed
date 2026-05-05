#include <iostream>
#include <vector>
using namespace std;

void introduction()
{
    cout << "Search and Sorting Testbed - Phase 1" << endl;
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

// Handles the users menu choice
void do_choice(int choice)
{
    switch (choice)
    {
    case 1:
        run_linear_search();
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        cout << "Choice " << choice << " not implemented." << endl;
        break;
    case 6:
        cout << "Goodbye." << endl;
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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Task
{
    string description;
    bool completed;
};

void addTask(vector<Task> &tasks, const string &description);
void viewTasks(const vector<Task> &tasks);
void markAsCompleted(vector<Task> &tasks, int index);
void removeTask(vector<Task> &tasks, int index);

int main()
{
    vector<Task> tasks;

    char choice;

    do
    {
        cout << "===== To-Do List Manager =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            addTask(tasks, description);
            break;
        }
        case '2':
            viewTasks(tasks);
            break;
        case '3':
        {
            int index;
            cout << "Enter the index of the task to mark as completed: ";
            cin >> index;
            markAsCompleted(tasks, index);
            break;
        }
        case '4':
        {
            int index;
            cout << "Enter the index of the task to remove: ";
            cin >> index;
            removeTask(tasks, index);
            break;
        }
        case '5':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

void addTask(vector<Task> &tasks, const string &description)
{
    tasks.push_back({description, false});
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task> &tasks)
{
    cout << "===== Tasks =====" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". ";
        if (tasks[i].completed)
        {
            cout << "[Completed] ";
        }
        else
        {
            cout << "[Pending] ";
        }
        cout << tasks[i].description << endl;
    }
}

void markAsCompleted(vector<Task> &tasks, int index)
{
    if (index >= 1 && index <= static_cast<int>(tasks.size()))
    {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    }
    else
    {
        cout << "Invalid task index! Please try again." << endl;
    }
}

void removeTask(vector<Task> &tasks, int index)
{
    if (index >= 1 && index <= static_cast<int>(tasks.size()))
    {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully." << endl;
    }
    else
    {
        cout << "Invalid task index! Please try again." << endl;
    }
}

# include <iostream>

using namespace std;

void tower_hanoi(int n, char source, char destination, char spare)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from source to spare, using destination as spare
    tower_hanoi(n - 1, source, spare, destination);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move the n-1 disks from spare to destination, using source as spare
    tower_hanoi(n - 1, spare, destination, source);
}

int main()
{
    int n;
    char source, destination, spare;

    cout << "Enter the number of disks to be moved: ";
    cin >> n;

    cout << "Enter the names of pillars (from, to, spare) respectively: ";
    cin >> source >> destination >> spare;

    cout << "Tower of Hanoi moves:" << endl;
    tower_hanoi(n, source, destination, spare);

    return 0;
}

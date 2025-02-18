//Experiment 3

#include <iostream>
#include <mutex>
using namespace std;
struct semaphore
{
    int mutex;
    int rcount;
    int rwait;
    bool wrt;
};
void addReader(struct semaphore *s)
{
    if (s->mutex == 0 && s->rcount == 0)
    {
        cout << "Sorry, File isopen in Write mode.\nNew Reader added to queue." << endl;
        s->rwait++;
    }
    else
    {
        cout << "Reader Process added." << endl;
        s->rcount++;
        s->mutex--;
    }
    return;
}
void addWriter(struct semaphore *s)
{
    if (s->mutex == 1)
    {
        s->mutex--;
        s->wrt = 1;
        cout << "\nWriter Process added." << endl;
    }
    else if (s->wrt)
        cout << "Sorry, Writer already operational." << endl;
    else
        cout << "Sorry, File open in Read mode." << endl;
    return;
}
void removeReader(struct semaphore *s)
{
    if (s->rcount == 0)
        cout << "No readers to remove." << endl;
    else

    {
        cout << "Reader Removed." << endl;
        s->rcount--;
        s->mutex++;
    }
    return;
}
void removeWriter(struct semaphore *s)
{
    if (s->wrt == 0)
        cout << "No Writer to Remove" << endl;
    else
    {
        cout << "Writer Removed" << endl;
        s->mutex++;
        s->wrt = 0;
        if (s->rwait != 0)
        {
            s->mutex -= s->rwait;
            s->rcount = s->rwait;
            s->rwait = 0;
            cout << "waiting Readers Added:" << s->rcount << endl;
        }
    }
}
int main()
{
    struct semaphore S1 = {1, 0, 0};
    while (1)
    {
        cout << "Options" << endl
             << "1. Add Reader." << endl
             << "2. Add Writer." << endl
             << "3. Remove
                Reader."<<endl<<" 4.Remove Writer."<<endl<<" 5. Exit.
             << Choice : "<<endl;
                         int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addReader(&S1);
            break;
        case 2:
            addWriter(&S1);
            break;
        case 3:
            removeReader(&S1);
            break;
        case 4:
            removeWriter(&S1);
            break;
        case 5:
            cout << "\n\tGoodBye!";
            break;
        default:
            cout << "\nInvalid Entry!";
        }
    }
    return 0;
}

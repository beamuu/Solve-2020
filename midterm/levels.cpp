#include <iostream>
using namespace std;

typedef struct task { int task1 , task2 , task3 ; } node;


int main() {

    int n,m,level=1,task1,task2,task3;
    cin >> n >> m;
    
    n--;
    node array[n];
    node task_status;
    node *current_task=array;

    for (int i=0 ; i<n ; i++) {
        cin >> task1 >> task2 >> task3;
        array[i].task1 = task1;
        array[i].task2 = task2;
        array[i].task3 = task3;
    }
    // Set default task status to 0
    task_status.task1=0;
    task_status.task2=0;
    task_status.task3=0;
   
    while (m--) {
        cin >> task1 >> task2 >> task3;
        if (level == n) {continue;}
        if (task1 >= current_task->task1) {task_status.task1 = 1;}
        if (task2 >= current_task->task2) {task_status.task2 = 1;}
        if (task3 >= current_task->task3) {task_status.task3 = 1;}
        if (task_status.task1 && task_status.task2 && task_status.task3) {
            level++;
            task_status.task1=0;
            task_status.task2=0;
            task_status.task3=0;
            current_task++;
        }
    }
    cout << level << endl;
    return 0;

}

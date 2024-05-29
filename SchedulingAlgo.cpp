#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Process
{
    int id;
    int burstTime;
    int arrivalTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int priority;
};

ofstream file("Output.txt");

void displayganttchart(vector<pair<int, int>> gantt)
{
    cout << "\n\tThe Output appended in File.Please Check \"Output.txt\"......";

    ofstream file("Output.txt", ios::app);
    // Printing gantt chart with respect to each time interval
    file << "Gantt Chart\n";
    // cout << "Gantt Chart:" << endl;
    for (int i = 0; i < gantt.size(); i++)
    {
        // printf("%2d ", i + 1);
        file << setfill('0') << setw(2) << gantt[i].second << "\t";
    }
    // cout << endl;
    file << "\n";
    for (int i = 0; i < gantt.size(); i++)
    {
        // cout << "P" << gantt[i] << " ";
        file << "P" << gantt[i].first << "\t";
    }
    cout << endl;
}

void display(Process P[], int totalProcess, float avgwt = 0, float avgtat = 0)
{
    ofstream file("Output.txt", ios::app);
    // sorting to sort according to process-ids
    sort(P, P + totalProcess, [](Process p, Process q)
         { return p.id < q.id; });

    // printing data related to each process without priority
    file << "\n\n\t\t\t The Process Status \n\n";
    file << "Process ID" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(20) << "Completion Time" << setw(20) << "Turn Around Time" << setw(20) << "Waiting Time";
    for (int i = 0; i < totalProcess; ++i)
        file << "\n"
             << P[i].id << setw(20) << P[i].arrivalTime << setw(20) << P[i].burstTime << setw(20)
             << P[i].completionTime << setw(20) << P[i].turnAroundTime << setw(20) << P[i].waitingTime;

    file << "\n\n\t\tAverage Waiting Time: " << avgwt;
    file << "\n\t\tAverage Turn Around Time: " << avgtat;
    file << "\n\n\n";
    file.close();
}

void displaywithPriority(Process P[], int totalProcess, float avgwt = 0, float avgtat = 0)
{
    ofstream file("Output.txt", ios::app);
    // sorting to sort according to process-ids
    sort(P, P + totalProcess, [](Process p, Process q)
         { return p.id < q.id; });

    // printing data related to each process with priority
    file << "\n\n\t\t\t The Process Status \n\n";
    file << "Process ID" << setw(20) << "Arrival Time" << setw(20) << "Burst Time" << setw(15) << "Priority" << setw(20) << "Completion Time" << setw(20) << "Turn Around Time" << setw(20) << "Waiting Time";
    for (int i = 0; i < totalProcess; ++i)
        file << "\n"
             << setfill(' ') << setw(2) << P[i].id << setw(20) << P[i].arrivalTime << setw(20) << P[i].burstTime << setw(20) << P[i].priority << setw(20) << P[i].completionTime << setw(20) << P[i].turnAroundTime << setw(20) << P[i].waitingTime;

    file << "\n\n\t\tAverage Waiting Time: " << avgwt;
    file << "\n\t\tAverage Turn Around Time: " << avgtat;
    file << "\n\n\n";
    file.close();
}

void inputData(Process P[], int &totalProcess)
{
    // getting data of process without priority from user
    int x;
    for (int i = 0; i < totalProcess; i++)
    {
        P[i].id = (i + 1); // creating id for each process from 1
        cout << "\n\t Process ID: ";
        cout << P[i].id;
        cout << "\n\t Enter the Process Arrival Time: ";
        cin >> x;
        P[i].arrivalTime = (x); // assigning it to arrival time variable of that process
        cout << "\n\t Enter the Process Burst Time: ";
        cin >> x;
        P[i].burstTime = (x); // assigning it to burst time variable of that process
    }
}

void inputDataPriority(Process P[], int &totalProcess)
{
    // getting data of process without priority from user
    int x;
    for (int i = 0; i < totalProcess; i++)
    {
        P[i].id = (i + 1); // creating id for each process from 1
        cout << "\n\t Process ID: ";
        cout << P[i].id;
        cout << "\n\t Enter the Process Arrival Time: ";
        cin >> x;
        P[i].arrivalTime = (x); // assigning it to arrival time variable of that process
        cout << "\n\t Enter the Process Burst Time: ";
        cin >> x;
        P[i].burstTime = (x); // assigning it to burst time variable of that process
        cout << "\n\t Enter the Priority: ";
        cin >> x;
        P[i].priority = (x); // assigning it to priority variable of that process
    }
}

void randomGenerate(Process P[], int &totalProcess)
{
    // randomly generate and initailize value of arrival time and burst time using srand() and rand()
    srand(time(NULL));
    for (int i = 0; i < totalProcess; i++)
    {
        P[i].id = (i + 1);
        P[i].arrivalTime = (rand() % (5));
        P[i].burstTime = (rand() % 5 + 2);
        P[i].completionTime = (0);
        P[i].turnAroundTime = (0);
        P[i].waitingTime = (0);
    }
}

void randomGeneratePriority(Process P[], int &totalProcess)
{
    // randomly generate and initailize value of arrival time,priority and burst time using srand() and rand()
    srand(time(NULL));
    for (int i = 0; i < totalProcess; i++)
    {
        P[i].id = (i + 1);
        P[i].arrivalTime = (rand() % (5));
        P[i].burstTime = (rand() % 5 + 2);
        P[i].completionTime = (0);
        P[i].turnAroundTime = (0);
        P[i].waitingTime = (0);
        P[i].priority = (rand() % totalProcess);
    }
}

void readData(string filename, Process P[])
{
    // reading data from file
    fstream fio;
    string line;
    int line_counter = 0;
    fio.open(filename);

    // moving till end of file
    while (!fio.eof())
    {
        int x;
        // copying line from file
        getline(fio, line);
        line_counter += 1;

        if (line_counter > 2)
        {
            // splitting string with anynumber of spaces
            regex pattern("\\s+");

            // pushing splitted into vector
            vector<string> tokens(sregex_token_iterator(line.begin(), line.end(), pattern, -1), sregex_token_iterator());

            // converting string to int
            P[line_counter - 3].id = stoi(tokens[0]);
            x = stoi(tokens[1]);
            P[line_counter - 3].arrivalTime = (x);
            x = stoi(tokens[2]);
            P[line_counter - 3].burstTime = (x);
        }
    }
    fio.close();
}

void readDataPriority(string filename, Process P[])
{
    // reading data from file
    fstream fio;
    string line;
    int line_counter = 0;
    fio.open(filename);
    int processnum;

    while (!fio.eof())
    {
        int x;
        getline(fio, line);
        line_counter += 1;

        if (line_counter > 2)
        {
            // splitting string with anynumber of spaces
            regex pattern("\\s+");

            // pushing splitted into vector
            vector<string> tokens(sregex_token_iterator(line.begin(), line.end(), pattern, -1), sregex_token_iterator());

            // converting string to int
            P[line_counter - 3].id = stoi(tokens[0]);
            x = stoi(tokens[1]);
            P[line_counter - 3].arrivalTime = (x);
            x = stoi(tokens[2]);
            P[line_counter - 3].burstTime = (x);
            x = stoi(tokens[3]);
            P[line_counter - 3].priority = (x);
        }
    }
    fio.close();
}

void FCFS(Process P[], int totalProcess)
{
    vector<pair<int, int>> gantt;
    ofstream file("Output.txt", ios::app);
    file << "\t\t\t*** First Come First Serve ***\n";
    file.close();
    float avgWT = 0, avgTAT = 0;

    // Sorting process the processes according to arrival time
    sort(P, P + totalProcess, [](Process p, Process q)
         { return p.arrivalTime < q.arrivalTime; });

    int gtime = P[0].arrivalTime;
    for (int i = 0, prevEnd = 0; i < totalProcess; i++)
    {
        if (i != 0 && (gtime == P[i - 1].arrivalTime + P[i - 1].burstTime) && gtime < P[i].arrivalTime)
        {
            gtime = P[i].arrivalTime;
        }

        // At time of start take arrival time then previous time
        P[i].completionTime = (max(prevEnd, P[i].arrivalTime) + P[i].burstTime);

        // updating turn around and waiting time
        P[i].turnAroundTime = (P[i].completionTime - P[i].arrivalTime);
        P[i].waitingTime = (P[i].turnAroundTime - P[i].burstTime);
        prevEnd = P[i].completionTime;
        for (int j = 1; j <= P[i].burstTime; j++)
        {
            gtime++;
            gantt.push_back({P[i].id, gtime});
        }
        avgWT += P[i].waitingTime;
        avgTAT += P[i].turnAroundTime;
    }

    avgWT = (float)avgWT / totalProcess;
    avgTAT = (float)avgTAT / totalProcess;

    displayganttchart(gantt);
    display(P, totalProcess, avgWT, avgTAT);
}

void SJF(Process P[], int totalProcess)
{
    vector<pair<int, int>> gantt;
    ofstream file("Output.txt", ios::app);
    file << "\t\t\t*** Shortest Job First ***\n";
    file.close();
    // ofstream file("Output.txt",ios::app);
    int executed = 0; // to keep count how much process is executed

    // to maintaing executed or not
    bool processActive[totalProcess];
    // filling it initaially as not executed
    fill(processActive, processActive + totalProcess, false);

    vector<Process> readyQueue; // maintaining ready queue
    map<int, int> id_ctime;     // maintaining process with completion time
    int gtime = 0;              // initialize clock
    for (int time = 0; executed < totalProcess;)
    {
        for (int i = 0; i < totalProcess; i++)
        {
            if (!processActive[P[i].id - 1] && P[i].arrivalTime <= time)
            {                                      // To check if process is executed before and also whether it has arrived or not
                readyQueue.push_back(P[i]);        // Pushed to ready queue
                processActive[P[i].id - 1] = true; // marking process as executed
            }
        }
        if (readyQueue.size() != 0) // if ready queue is not empty
        {
            // finding position of process with minimum burst time
            vector<Process>::iterator minPosition = min_element(readyQueue.begin(),
                                                                readyQueue.end(), [](Process p, Process q)
                                                                { return p.burstTime < q.burstTime; });
            // let it execute and add time to clock
            time += (*minPosition).burstTime;

            for (int j = 1; j <= (*minPosition).burstTime; j++)
            {
                gtime++;
                gantt.push_back({(*minPosition).id, gtime});
            }

            // update completion time of process
            id_ctime[(*minPosition).id] = time;
            executed++;

            // remove executed element
            readyQueue.erase(minPosition);
        }
        else // if queue empty and not all executed add time to clock
        {
            gtime++;
            time++;
        }
    }

    // calculation
    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < totalProcess; ++i)
    {
        P[i].completionTime = (id_ctime[P[i].id]);
        P[i].turnAroundTime = (P[i].completionTime - P[i].arrivalTime);
        P[i].waitingTime = (P[i].turnAroundTime - P[i].burstTime);
        avgWT += P[i].waitingTime;
        avgTAT += P[i].turnAroundTime;
    }

    avgWT = (float)avgWT / totalProcess;
    avgTAT = (float)avgTAT / totalProcess;

    displayganttchart(gantt);
    display(P, totalProcess, avgWT, avgTAT);
}

void RR(Process P[], int totalProcess)
{
    ofstream file("Output.txt", ios::app);
    file << "\t\t\t*** Round Robin ***\n";
    file.close();
    vector<pair<int, int>> gantt;

    int timeQuanta; // time quanta
    cout << "\n\t Time quantum : ";
    cin >> timeQuanta;

    queue<Process> readyQueue; // mainting ready queue

    // to maintaing in queue or not
    bool inQueue[totalProcess + 1];
    // filling it initaially as not in queue
    fill(inQueue, inQueue + totalProcess + 1, false);

    map<int, int> id_ctime;       // maintaining process with completion time
    int completed = 0, clock = 0; // initializing clock and number of process executed
    int gtime = 0;
    do
    {
        for (int i = 0; i < totalProcess; ++i)
        {
            // if not executed and arrived push to ready queue
            if (!inQueue[P[i].id] && P[i].arrivalTime == clock)
            {
                readyQueue.push(P[i]);
                // mark as arrived in queue
                inQueue[P[i].id] = true;
            }
        }
        // if ready queue is not empty
        if (!readyQueue.empty())
        {
            // first process taken out
            Process p = readyQueue.front();
            readyQueue.pop();

            // exected until min of time quanta of burst time
            int executed = min(timeQuanta, p.burstTime);
            for (int i = 0; i < executed; i++)
            {
                gtime++;
                gantt.push_back({p.id, gtime});
            }

            // reduce executed time quanta
            int b = p.burstTime;
            p.burstTime = (p.burstTime - executed);

            // if not executed and arrived push to ready queue for time exection takes place
            for (int i = clock + 1; i <= clock + executed; ++i)
            {
                for (int j = 0; j < totalProcess; ++j)
                {
                    if (!inQueue[P[j].id] && P[j].arrivalTime == i)
                    {
                        readyQueue.push(P[j]);
                        inQueue[P[j].id] = true;
                    }
                }
            }

            // time added to clock
            clock += executed;

            // if completely executed
            if (p.burstTime == 0)
            {
                completed++;                       // add to executed count
                p.completionTime = (clock);        // update completion time of process
                id_ctime[p.id] = p.completionTime; // make changes in map
            }

            // if not completely executed then repush into ready queue
            else
            {

                readyQueue.push(p);
            }
        }
        // if no process available in queue update clock
        else
        {
            gtime++;
            clock++;
        }
    } while (completed != totalProcess);

    // calculation part
    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < totalProcess; ++i)
    {
        P[i].completionTime = (id_ctime[P[i].id]);
        P[i].turnAroundTime = (P[i].completionTime - P[i].arrivalTime);
        P[i].waitingTime = (P[i].turnAroundTime - P[i].burstTime);
        avgWT += P[i].waitingTime;
        avgTAT += P[i].turnAroundTime;
    }

    avgWT = (float)avgWT / totalProcess;
    avgTAT = (float)avgTAT / totalProcess;

    displayganttchart(gantt);
    display(P, totalProcess, avgWT, avgTAT);
}

void SRTF(Process P[], int totalProcess)
{
    ofstream file("Output.txt", ios::app);
    file << "\t\t\t*** Shortest Remaining Time First ***\n";
    file.close();
    vector<pair<int, int>> gantt;
    vector<Process> readyQueue; // maintaining ready queue

    // to maintaing in queue or not
    bool inQueue[totalProcess];
    // filling it initaially as not in queue
    fill(inQueue, inQueue + totalProcess, false);

    int time = 0, executed = 0; // initializing clock and number of process executed
    map<int, int> id_ctime;     // maintaining process with completion time
    int gtime = 0;
    while (executed != totalProcess) // until all not executed
    {
        // if not executed and arrived push to ready queue
        for (int i = 0; i < totalProcess; i++)
        {
            if ((P[i].arrivalTime <= time) && (inQueue[i] == false))
            {
                readyQueue.push_back(P[i]);
                // availble in queue
                inQueue[i] = true;
            }
        }

        // if not empty
        if (readyQueue.size() != 0)
        {
            // finding process with minimum burst time
            vector<Process>::iterator minPosition = min_element(readyQueue.begin(),
                                                                readyQueue.end(),
                                                                [](Process p, Process q)
                                                                { return p.burstTime < q.burstTime; });
            // reduce burst time by 1
            (*minPosition).burstTime = ((*minPosition).burstTime - 1);
            gtime++;
            gantt.push_back({(*minPosition).id, gtime});
            // increment clock
            time++;

            // if completely executed mark executed and update map
            if ((*minPosition).burstTime == 0)
            {
                id_ctime[(*minPosition).id] = time;
                executed++;
                // remove from queue
                readyQueue.erase(minPosition);
            }
        }
        // if no process in queue add to clock
        else
        {
            gtime++;
            time++;
        }
    }

    // calculation
    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < totalProcess; i++)
    {
        P[i].completionTime = (id_ctime[P[i].id]);
        P[i].turnAroundTime = (P[i].completionTime - P[i].arrivalTime);
        P[i].waitingTime = (P[i].turnAroundTime - P[i].burstTime);
        avgWT += P[i].waitingTime;
        avgTAT += P[i].turnAroundTime;
    }
    avgWT = (float)avgWT / totalProcess;
    avgTAT = (float)avgTAT / totalProcess;

    displayganttchart(gantt);
    display(P, totalProcess, avgWT, avgTAT);
}

void PriorityNP(Process P[], int totalProcess)
{
    fstream file("Output.txt", ios::app);
    file << "\t\t\t*** Non-Preemptive Priority ***\n";
    file.close();
    vector<pair<int, int>> gantt;

    // sorting according to arrival time and decreasing priority
    sort(P, P + totalProcess, [](Process p, Process q)
         { if(p.arrivalTime==q.arrivalTime)
                return p.priority < q.priority; 
        return p.arrivalTime<q.arrivalTime; }); // low value-priority higher

    int gtime = P[0].arrivalTime;
    float avgWT = 0, avgTAT = 0;
    for (int i = 0, prevEnd = 0; i < totalProcess; i++)
    {
        if (i != 0 && (gtime == P[i - 1].arrivalTime + P[i - 1].burstTime) && gtime < P[i].arrivalTime)
        {
            gtime = P[i].arrivalTime;
        }

        P[i].completionTime = (max(prevEnd, P[i].arrivalTime) + P[i].burstTime);
        P[i].turnAroundTime = (P[i].completionTime - P[i].arrivalTime);
        P[i].waitingTime = (P[i].turnAroundTime - P[i].burstTime);
        prevEnd = P[i].completionTime;
        for (int j = 1; j <= P[i].burstTime; j++)
        {
            gtime++;
            gantt.push_back({P[i].id, gtime});
        }
        avgWT += P[i].waitingTime;
        avgTAT += P[i].turnAroundTime;
    }

    avgWT = (float)avgWT / totalProcess;
    avgTAT = (float)avgTAT / totalProcess;

    displayganttchart(gantt);
    displaywithPriority(P, totalProcess, avgWT, avgTAT);
}

void PriorityP(Process P[], int totalProcess)
{
    ofstream file("Output.txt", ios::app);
    file << "\t\t\t*** Preemptive Priority ***\n";
    file.close();
    vector<pair<int, int>> gantt;
    vector<Process> readyQueue; // maintaining queue

    // to maintaing in queue or not
    bool inQueue[totalProcess];
    // filling it initaially as not in queue
    fill(inQueue, inQueue + totalProcess, false);

    map<int, int> id_ctime;     // maintining id and ctime
    int time = 0, executed = 0; // initializing clock and executed
    float avgTAT = 0, avgWT = 0;
    int gtime = 0;
    while (executed != totalProcess) // until not executed
    {
        // if arrived and not in queue
        for (int i = 0; i < totalProcess; i++)
        {
            if ((P[i].arrivalTime <= time) && (inQueue[i] == false))
            {
                readyQueue.push_back(P[i]);
                inQueue[i] = true;
            }
        }

        // if queue not empty
        if (readyQueue.size() != 0)
        {
            // finiding process with minimum priority
            vector<Process>::iterator minPosition = min_element(readyQueue.begin(),
                                                                readyQueue.end(),
                                                                [](Process p, Process q)
                                                                { return p.priority < q.priority; });

            // reduce burst time by 1
            (*minPosition).burstTime = ((*minPosition).burstTime - 1);
            gtime++;
            gantt.push_back({(*minPosition).id, gtime});
            // increment clock
            time++;

            // if executed mark executed and erase from queue
            if ((*minPosition).burstTime == 0)
            {
                id_ctime[(*minPosition).id] = time;
                executed++;
                readyQueue.erase(minPosition);
            }
        }
        // if queue empty add to time
        else
        {
            gtime++;
            time++;
        }
    }

    // calculation part
    for (int i = 0; i < totalProcess; i++)
    {
        P[i].completionTime = (id_ctime[P[i].id]);
        P[i].turnAroundTime = (P[i].completionTime - P[i].arrivalTime);
        P[i].waitingTime = (P[i].turnAroundTime - P[i].burstTime);
        avgWT += P[i].waitingTime;
        avgTAT += P[i].turnAroundTime;
    }

    displayganttchart(gantt);
    displaywithPriority(P, totalProcess, avgWT, avgTAT);
}

void LJF(Process P[], int totalProcess)
{
    vector<pair<int, int>> gantt;
    ofstream file("Output.txt", ios::app);
    file << "\t\t\t*** Longest Job First ***\n";
    file.close();
    // ofstream file("Output.txt",ios::app);
    int executed = 0; // to keep count how much process is executed

    // to maintaing executed or not
    bool processActive[totalProcess];
    // filling it initaially as not executed
    fill(processActive, processActive + totalProcess, false);

    vector<Process> readyQueue; // maintaining ready queue
    map<int, int> id_ctime;     // maintaining process with completion time
    int gtime = 0;              // initialize clock
    for (int time = 0; executed < totalProcess;)
    {
        for (int i = 0; i < totalProcess; i++)
        {
            if (!processActive[P[i].id - 1] && P[i].arrivalTime <= time)
            {                                      // To check if process is executed before and also whether it has arrived or not
                readyQueue.push_back(P[i]);        // Pushed to ready queue
                processActive[P[i].id - 1] = true; // marking process as executed
            }
        }
        if (readyQueue.size() != 0) // if ready queue is not empty
        {
            // finding position of process with minimum burst time
            vector<Process>::iterator minPosition = min_element(readyQueue.begin(),
                                                                readyQueue.end(), [](Process p, Process q)
                                                                { return p.burstTime > q.burstTime; });
            // let it execute and add time to clock
            time += (*minPosition).burstTime;

            for (int j = 1; j <= (*minPosition).burstTime; j++)
            {
                gtime++;
                gantt.push_back({(*minPosition).id, gtime});
            }

            // update completion time of process
            id_ctime[(*minPosition).id] = time;
            executed++;

            // remove executed element
            readyQueue.erase(minPosition);
        }
        else // if queue empty and not all executed add time to clock
        {
            gtime++;
            time++;
        }
    }

    // calculation
    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < totalProcess; ++i)
    {
        P[i].completionTime = (id_ctime[P[i].id]);
        P[i].turnAroundTime = (P[i].completionTime - P[i].arrivalTime);
        P[i].waitingTime = (P[i].turnAroundTime - P[i].burstTime);
        avgWT += P[i].waitingTime;
        avgTAT += P[i].turnAroundTime;
    }

    avgWT = (float)avgWT / totalProcess;
    avgTAT = (float)avgTAT / totalProcess;

    displayganttchart(gantt);
    display(P, totalProcess, avgWT, avgTAT);
}

void LRTF(Process P[], int totalProcess)
{
    vector<pair<int, int>> gantt;
    ofstream file("Output.txt", ios::app);
    file << "\n\t\t\t*** Longest Remaining Time First ***\n";
    file.close();
    vector<Process> readyQueue; // maintaining ready queue

    // to maintaing in queue or not
    bool inQueue[totalProcess];
    // filling it initaially as not in queue
    fill(inQueue, inQueue + totalProcess, false);

    map<int, int> id_ctime;     // maintaining id and ctime
    int time = 0, executed = 0; // initializing clock and executed
    float avgTAT = 0, avgWT = 0;
    int gtime = 0;
    while (executed != totalProcess) // until not executed
    {
        // if arrived and not in queue
        for (int i = 0; i < totalProcess; i++)
        {
            if ((P[i].arrivalTime <= time) && (inQueue[i] == false))
            {
                readyQueue.push_back(P[i]);
                inQueue[i] = true;
            }
        }

        // if queue not empty
        if (readyQueue.size() != 0)
        {
            // finding element with largest time
            vector<Process>::iterator minPosition = min_element(readyQueue.begin(),
                                                                readyQueue.end(),
                                                                [](Process p, Process q)
                                                                {return p.burstTime > q.burstTime; });
            
            // reduce burst time by 1
            (*minPosition).burstTime = ((*minPosition).burstTime - 1);
            gtime++;
            gantt.push_back({(*minPosition).id, gtime});

            // add to clock
            time++;

            // if completely executed mark executed and erase from queue
            if ((*minPosition).burstTime == 0)
            {
                id_ctime[(*minPosition).id] = time;
                executed++;
                readyQueue.erase(minPosition);
            }
        }
        // if not process in queue increase time
        else
        {
            gtime++;
            time++;
        }
    }

    // calculation part
    for (int i = 0; i < totalProcess; i++)
    {
        P[i].completionTime = (id_ctime[P[i].id]);
        P[i].turnAroundTime = (P[i].completionTime - P[i].arrivalTime);
        P[i].waitingTime = (P[i].turnAroundTime - P[i].burstTime);
        avgWT += P[i].waitingTime;
        avgTAT += P[i].turnAroundTime;
    }
    avgWT = (float)avgWT / totalProcess;
    avgTAT = (float)avgTAT / totalProcess;

    displayganttchart(gantt);
    display(P, totalProcess, avgWT, avgTAT);
}

int main()
{
    int schAlgoType, inputType, totalProcess;
    while (1)
    {

        cout << "\n\t \t CPU Scheduling Algorithms\n\n";

        // taking type of scheduling algorithm to select
        cout << "\t 1. First Come First Served (FCFS)\n\t 2. Shortest Job First (SJF)\n\t 3. Round Robin (RR)\n\t 4. Shortest Remaining Time First (SRTF)\n\t 5. Non-Preemptive Priority \n\t 6. Preemptive Priority \n\t 7. Longest Job First (LJF)\n\t 8. Longest Remaining Time First (LRTF) \n\t 9. All\n\t 0. Exit\n";
        cout << "\n\t Which Scheduling Algorithm you want to implement? Enter your choice [0-9] : ";
        cin >> schAlgoType;

        // if exit called end the execution
        if (schAlgoType == 0)
        {
            exit(1);
        }

        // taking type of input
        cout << "\n\t How do to want to give input data for Scheduling? \n\t 1. Manually \t 2.Read Data from File \t 3. Random Generated \n";
        cout << "\n\t Enter your choice [1-3] : ";

        cin >> inputType;

        string fileName;
        if (inputType == 2)
        {
            fstream fio;
            int b = 0;
            while (b != 1)
            {
                cout << "\t Enter file name : ";
                cin >> fileName;
                fio.open(fileName);
                try
                {
                    // handling file exception if file not available
                    if (!fio.is_open())
                    {
                        throw ios_base::failure("Could not open file: " + fileName);
                    }

                    b = 1;
                }

                catch (const ios_base::failure &e)
                {
                    cout << "\n\t File Dosen't exist. Please try again!!\n";
                }
            }

            string line;
            int line_counter = 1;
            int processnum;

            getline(fio, line);
            processnum = stoi(line);
            totalProcess = processnum;
            fio.close();
        }
        else
        {
            cout << "\n\t Enter Number of Jobs : ";
            cin >> totalProcess;
        }

        // declaring array of structure
        Process P[totalProcess];

        // calling function based on type of input
        switch (inputType)
        {
        case 1:
        {
            if (schAlgoType == 5 || schAlgoType == 6 || schAlgoType == 9)
                inputDataPriority(P, totalProcess);
            else
                inputData(P, totalProcess);

            break;
        }
        case 2:
        {
            if (schAlgoType == 5 || schAlgoType == 6 || schAlgoType == 9)
                readDataPriority(fileName, P);
            else
                readData(fileName, P);
            break;
        }
        case 3:
        {
            if (schAlgoType == 5 || schAlgoType == 6 || schAlgoType == 9)
                randomGeneratePriority(P, totalProcess);
            else
                randomGenerate(P, totalProcess);
            break;
        }
        }

        // calling function based on scheduling algorithm
        switch (schAlgoType)
        {
        case 1:
            FCFS(P, totalProcess);
            break;
        case 2:
            SJF(P, totalProcess);
            break;
        case 3:
            RR(P, totalProcess);
            break;
        case 4:
            SRTF(P, totalProcess);
            break;
        case 5:
            PriorityNP(P, totalProcess);
            break;
        case 6:
            PriorityP(P, totalProcess);
            break;
        case 7:
            LJF(P, totalProcess);
            break;
        case 8:
            LRTF(P, totalProcess);
            break;
        case 9:
            FCFS(P, totalProcess);
            SJF(P, totalProcess);
            RR(P, totalProcess);
            SRTF(P, totalProcess);
            PriorityNP(P, totalProcess);
            PriorityP(P, totalProcess);
            LJF(P, totalProcess);
            LRTF(P, totalProcess);
            break;
        }
    }
    return 0;
}

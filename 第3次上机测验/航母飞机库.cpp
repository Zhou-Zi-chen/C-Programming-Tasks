#include <iostream>
#include<string>

using namespace std;

// ----------------------------- Plane Struct -----------------------------

struct Plane {
    string type;
    int id = 0;
    string nickname;
    int takeOffTime = 0;
    int taskTime = 0;
    int landTime = 0;
    int total = 0;
};

// ----------------------------- 已有函数声明【不允许修改】 -----------------------------

void addPlane(Plane* hangar, int count, string type, int id, string nickname);

void setPlane(Plane* hangar, int count, int id, int takeOffTime, int taskTime, int landTime);

Plane* getPlane(Plane* hangar, int count, int id);

void printHangarNormal(Plane* hangar, int count);

void printHangarSchedule(Plane* hangar, int count);

// ----------------------------- 自定义的功能函数声明 -----------------------------




// ----------------------------- main() 函数【不允许修改】 -----------------------------
int main() {
    int N;
    cin >> N;
    string instr;

    Plane hangar[30];
    int count = 0;

    for (int i = 0; i < N; ++i) {
        cin >> instr;
        if (instr == "add") {
            int id;
            string type, nickname;
            cin >> type >> id >> nickname;
            addPlane(hangar, count, type, id, nickname);
            count++;
        }
        else if (instr == "set") {
            int id, takeOffTime, taskTime, landTime;
            cin >> id >> takeOffTime >> taskTime >> landTime;
            setPlane(hangar, count, id, takeOffTime, taskTime, landTime);
        }
        else if (instr == "get") {
            int id;
            cin >> id;
            Plane* plane = getPlane(hangar, count, id);
            printHangarNormal(plane, 1);
        }
        else if (instr == "normal") {
            printHangarNormal(hangar, count);
        }
        else if (instr == "schedule") {
            printHangarSchedule(hangar, count);
        }
    }

    return 0;
}

// ----------------------------- 函数实现 -----------------------------

void addPlane(Plane* hangar, int count, string type, int id, string nickname) {
    hangar[count].type = type;
    hangar[count].id = id;
    hangar[count].nickname = nickname;
    if (type == "battleplane")
    {
        hangar[count].takeOffTime = 2;
        hangar[count].taskTime = 0;
        hangar[count].landTime = 2;
        hangar[count].total = hangar[count].taskTime + hangar[count].landTime + hangar[count].takeOffTime;
    }
    else if (type == "transportplane")
    {
        hangar[count].takeOffTime = 3;
        hangar[count].taskTime = 0;
        hangar[count].landTime = 3;
        hangar[count].total = hangar[count].taskTime + hangar[count].landTime + hangar[count].takeOffTime;
    }
    else
    {
        hangar[count].takeOffTime = 1;
        hangar[count].taskTime = 0;
        hangar[count].landTime = 1;
        hangar[count].total = hangar[count].taskTime + hangar[count].landTime + hangar[count].takeOffTime;
    }
}

void setPlane(Plane* hangar, int count, int id, int takeOffTime, int taskTime, int landTime) {
    int cur = 0;
    while (hangar[cur].id != id && cur < 30)
    {
        cur++;
    }
    if (cur < 30)
    {
        hangar[cur].takeOffTime = takeOffTime;
        hangar[cur].taskTime = taskTime;
        hangar[cur].landTime = landTime;
        hangar[cur].total = hangar[cur].taskTime + hangar[cur].landTime + hangar[cur].takeOffTime;
    }
}

Plane* getPlane(Plane* hangar, int count, int id) {
    int cur = 0;
    while (hangar[cur].id != id && cur < 30)
    {
        cur++;
    }
    Plane* plane = &hangar[cur];
    return plane;
}

void printHangarNormal(Plane* hangar, int count) {
    if (count > 1)
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - 1 - i; j++)
            {
                if (hangar[j].id > hangar[j + 1].id)
                {
                    Plane temp;
                    temp = hangar[j];
                    hangar[j] = hangar[j + 1];
                    hangar[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < count; i++)
        {
            cout << hangar[i].id << " ";
            cout << hangar[i].nickname << " ";
            cout << hangar[i].type << " ";
            cout << hangar[i].takeOffTime << " ";
            cout << hangar[i].taskTime << " ";
            cout << hangar[i].landTime << endl;
        }
    }
    else
    {
        cout << hangar->id << " ";
        cout << hangar->nickname << " ";
        cout << hangar->type << " ";
        cout << hangar->takeOffTime << " ";
        cout << hangar->taskTime << " ";
        cout << hangar->landTime << endl;
    }
}

void printHangarSchedule(Plane* hangar, int count) {
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (hangar[j].type == "transportplane")
            {
                if (hangar[j + 1].type == "battleplane")
                {
                    Plane temp;
                    temp = hangar[j];
                    hangar[j] = hangar[j + 1];
                    hangar[j + 1] = temp;
                }
            }
            else if (hangar[j].type == "helicopter")
            {
                if (hangar[j + 1].type != "helicopter")
                {
                    Plane temp;
                    temp = hangar[j];
                    hangar[j] = hangar[j + 1];
                    hangar[j + 1] = temp;
                }
            }
        }
    }

    int bat = 0, heli = 0, tran = 0;
    for (int i = 0; i < count; i++)
    {
        if (hangar[i].type == "battleplane")
        {
            bat++;
        }
        else if (hangar[i].type == "transportplane")
        {
            tran++;
        }
        else
        {
            heli++;
        }
    }

    for (int i = 0; i < bat - 1; i++)
    {
        for (int j = 0; j < bat - i - 1; j++)
        {
            if (hangar[j].total < hangar[j + 1].total)
            {
                Plane temp;
                temp = hangar[j];
                hangar[j] = hangar[j + 1];
                hangar[j + 1] = temp;
            }
            else if (hangar[j].total == hangar[j + 1].total)
            {
                if (hangar[j].id > hangar[j + 1].id)
                {
                    Plane temp;
                    temp = hangar[j];
                    hangar[j] = hangar[j + 1];
                    hangar[j + 1] = temp;
                }
            }
            else
            {

            }
        }
    }

    for (int i = 0; i < tran - 1; i++)
    {
        for (int j = bat; j < bat + tran - i - 1; j++)
        {
            if (hangar[j].total < hangar[j + 1].total)
            {
                Plane temp;
                temp = hangar[j];
                hangar[j] = hangar[j + 1];
                hangar[j + 1] = temp;
            }
            else if (hangar[j].total == hangar[j + 1].total)
            {
                if (hangar[j].id > hangar[j + 1].id)
                {
                    Plane temp;
                    temp = hangar[j];
                    hangar[j] = hangar[j + 1];
                    hangar[j + 1] = temp;
                }
            }
            else
            {

            }
        }
    }

    for (int i = 0; i < heli - 1; i++)
    {
        for (int j = tran + bat; j < bat + tran + heli - i - 1; j++)
        {
            if (hangar[j].total < hangar[j + 1].total)
            {
                Plane temp;
                temp = hangar[j];
                hangar[j] = hangar[j + 1];
                hangar[j + 1] = temp;
            }
            else if (hangar[j].total == hangar[j + 1].total)
            {
                if (hangar[j].id > hangar[j + 1].id)
                {
                    Plane temp;
                    temp = hangar[j];
                    hangar[j] = hangar[j + 1];
                    hangar[j + 1] = temp;
                }
            }
            else
            {

            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << hangar[i].type << " ";
        cout << hangar[i].id << " ";
        cout << hangar[i].nickname << " ";
        cout << hangar[i].total << endl;
    }
}
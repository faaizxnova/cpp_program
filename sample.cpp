#include <iostream>

using namespace std;

const int MAX_USERS = 100;
const int MIN_LEN = 5;
const int MAX_LEN = 15;
const int MAX_ATTEMPTS = 3;

struct User {
    char username[MAX_LEN + 1];
    char password[MAX_LEN + 1];
    bool isLocked = false;
    int loginAttempts = 0;
};


int getLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

bool areStringsEqual(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return true;
}

void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void security_req() {
    cout << "1.First letter of password should be CAPITAL\n2.Password should contain atleast one special character like (@) and numbers (0 - 9)\n";
}

bool isValidUsername(const char* uname) {
    int len = getLength(uname);
    if (len < MIN_LEN || len > MAX_LEN) return false;
    for (int i = 0; i < len; i++) 
        if (!((uname[i] >= 'a' && uname[i] <= 'z') || 
              (uname[i] >= 'A' && uname[i] <= 'Z') || 
              (uname[i] >= '0' && uname[i] <= '9'))) return false;
    
    return true;
}

string evaluatePassword(const char* pwd, bool& isValid) {
    int len = getLength(pwd);
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (int i = 0; i < len; i++) {
        if (pwd[i] >= 'A' && pwd[i] <= 'Z') hasUpper = true;
        else if (pwd[i] >= 'a' && pwd[i] <= 'z') hasLower = true;
        else if (pwd[i] >= '0' && pwd[i] <= '9') hasDigit = true;
        else hasSpecial = true;
    }

    isValid = (len >= MIN_LEN && hasUpper && hasLower && hasDigit && hasSpecial);
    
    int score = hasUpper + hasLower + hasDigit + hasSpecial;
    if (len < MIN_LEN || score <= 1) return "Weak";
    if (score == 4 && len >= 8) return "Strong";
    return "Moderate";
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    int choice;

    while (true) {
        cout << "\n--- SECURE REGISTRATION SYSTEM ---\n1. Register\n2. Login\n3. System Summary\n4. View Security Requirements\n5. Exit\nChoice: ";
        if (!(cin >> choice)) { 
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        if (choice == 5) break;

        if (choice == 1) {
            char u[50], p[50];
            cout << "Enter Username: "; cin >> u;
            cout << "Enter Password: "; cin >> p;

            bool exists = false;
            for(int i=0; i<userCount; i++) if(areStringsEqual(users[i].username, u)) exists = true;

            bool pwdValid = false;
            evaluatePassword(p, pwdValid);

            if (exists) cout << "Error: Username already exists!\n";
            else if (!isValidUsername(u)) cout << "Error: Invalid username format/length!\n";
            else if (!pwdValid) cout << "Error: Password does not meet security requirements!\n";
            else {
                copyString(users[userCount].username, u);
                copyString(users[userCount].password, p);
                userCount++;
                cout << "Registration Successful!\n";
            }
        } else if (choice == 2) {
            char u[50], p[50];
            cout << "Username: "; cin >> u;
            cout << "Password: "; cin >> p;

            bool found = false;
            for (int i = 0; i < userCount; i++) {
                if (areStringsEqual(users[i].username, u)) {
                    found = true;
                    if (users[i].isLocked) cout << "Account is locked due to multiple failures.\n";
                    else if (areStringsEqual(users[i].password, p)) {
                        cout << "Login Successful!\n";
                        users[i].loginAttempts = 0;
                    } else {
                        users[i].loginAttempts++;
                        cout << "Wrong password! Attempts: " << users[i].loginAttempts << "\n";
                        if (users[i].loginAttempts >= MAX_ATTEMPTS) users[i].isLocked = true;
                    }
                    break;
                }
            }
            if (!found) cout << "User not found.\n";
        } else if (choice == 3) {
            int locked = 0, strong = 0;
            for (int i = 0; i < userCount; i++) {
                if (users[i].isLocked) locked++;
                bool v;
                if (evaluatePassword(users[i].password, v) == "Strong") strong++;
            }
            cout << "\n--- FINAL SUMMARY ---\n";
            cout << "Total Users: " << userCount << "\n";
            cout << "Locked Accounts: " << locked << "\n";
            cout << "Strong Password %: " << (userCount ? (strong * 100 / userCount) : 0) << "%\n";
        } else if(choice == 4) security_req();
    } return 0;
}


// #include <iostream>
// #include <string>
// using namespace std;

// inline string gradeLetter(int s) { return (s >= 80) ? "A" : (s >= 60) ? "B" : "C"; }
// inline string gradeLetter(string sub, int s) { return sub + ": " + gradeLetter(s); }
// int sc[5];

// double semesterAvg(int n) {
//     if (n <= 0) return 0;
//     return (sc[n - 1] + (n - 1) * semesterAvg(n - 1)) / n;
// }

// void updateRecord(string& stu, double& avg) { if (avg >= 85) stu += " - Topper"; }

// int main() {
//     string student = "Vinay", subject;
//     int i;
//     cout << "Subject: "; cin >> subject;

//     for (i = 0; i < 5; i++) {
//         cout << "Quiz " << i + 1 << " score: "; cin >> sc[i];
//         if (sc[i] < 0 || sc[i] > 100) {
//             i--;
//             continue;
//         }
//         cout << gradeLetter(subject, sc[i]) << endl;
//     }
//     double avg = semesterAvg(5);
//     updateRecord(student, avg);

//     cout << "Semester Avg: " << avg << endl;
//     cout << student;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// inline string checkStatus(int s) { return (s >= 10) ? "Regular" : "Irregular"; }
// inline string checkStatus(string g, int s) { return g + ": " + checkStatus(s); }

// int streakDays(int t) {
//     if (t <= 0) return 0;
//     return 1 + streakDays(t - 1);
// }

// void updateMember(string& n, int& c) { if (c >= 12) n += " - Gold"; }

// int main() {
//     string gym;
//     int ses, target;

//     cout << "Gym Name: "; cin >> gym;
//     cout << "Sessions (8-15): "; cin >> ses;
//     if (ses < 8 || ses > 15) return 0;

//     cout << "Target: "; cin >> target;

//     updateMember(gym, ses);

//     cout << checkStatus(gym, ses);
//     cout << ", Streak: " << streakDays(ses) << " days";

//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// inline void printPass(int d) { cout << "Student Pass: ₹" << d * 2 << endl; }
// inline void printPass(string n, int d) { cout << n << "'s Pass (" << d << " days)\n"; }

// int totalKM(int m) {
//     if (m <= 0) return 0;
//     return 25 + totalKM(m - 1);
// }

// void calcFare(int& fare, bool stu) { fare *= (stu ? 2 : 3); }

// int main() {
//     string name;
//     int days, months;
//     bool isStu;

//     cout << "Name: "; cin >> name;
//     cout << "Days (20-30): "; cin >> days;
//     if (days < 20 || days > 30) return 0;

//     cout << "Months: "; cin >> months;
//     cout << "Student? (1-Yes 0-No): "; cin >> isStu;

//     printPass(name, days);
//     if (isStu) printPass(days);
//     int km = totalKM(months), fare = km;
//     calcFare(fare, isStu);

//     cout << "Total KM: " << km << endl;
//     cout << "Fare: ₹" << fare;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// inline int scorePoints(string a) {
//     return 8 + (a[3] - '0') * 2; 
// }
// inline int scorePoints(string a, int b) { return scorePoints(a) + b; }
// int dayScore[7];
// int weekTotal(int d) {
//     if (d <= 0) return 0;
//     return dayScore[d - 1] + weekTotal(d - 1);
// }
// void updateStudent(string& n, int& t) { if (t >= 75) n += " A-Grader"; }

// int main() {
//     string name, asg;
//     int i, bonus;
//     cout << "Enter Student Name: "; cin >> name;
//     for (i = 0; i < 7; i++) {
//         cout << "Day " << i + 1 << " Assignment (Lab1-Lab7): "; cin >> asg;
//         cout << "Bonus (0-5): "; cin >> bonus;
//         if (bonus < 0 || bonus > 5) {
//             i--;
//             continue;
//         }
//         dayScore[i] = scorePoints(asg, bonus);
//         cout << "Points: " << dayScore[i] << endl;
//     }
//     int total = weekTotal(7);
//     updateStudent(name, total);
//     cout << "\nWeek Total: " << total << " pts";
//     cout << "\nStudent: " << name;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// inline double calcCalories(int min) { return min * 5; }

// inline double calcCalories(int min, double wt) { return min * 5 * (wt / 70); }

// double dayCal[5];

// double totalCalories(int day) {
//     if (day <= 0) return 0;
//     return dayCal[day - 1] + totalCalories(day - 1);
// }

// void updateStatus(double& tot, char name[]) {
//     if (tot > 1000)
//         name[0] = 'K', name[1] = 'e', name[2] = 'e', name[3] = 'r', name[4] = 't', name[5] = 'h',
//         name[6] = 'i', name[7] = '-', name[8] = 'F', name[9] = 'i', name[10] = 't', name[11] = '\0';
// }

// int main() {
//     int i, min;
//     double wt;
//     char name[15] = "Keerthi";

//     for (i = 0; i < 5; i++) {
//         cout << "Day " << i + 1 << " minutes walked: ";
//         cin >> min;
//         if (min < 30 || min > 60) {
//             i--;
//             continue;
//         }

//         cout << "Weight (kg): "; cin >> wt;
//         if (wt < 50 || wt > 100) {
//             i--;
//             continue;
//         }

//         dayCal[i] = calcCalories(min, wt);
//         cout << "Day " << i + 1 << ": " << dayCal[i] << " cal\n";
//     }

//     double weekTot = totalCalories(5);
//     updateStatus(weekTot, name);

//     cout << "\nWeek Total: " << weekTot << " cal";
//     cout << "\nStatus: " << name << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// #define MP 30
// #define MC 5

// int main() {
//     int pid[MP], age[MP];
//     int depCnt[4] = {0};
//     int pCnt = 0, critCnt = 0;

//     float avgSum = 0;
//     int avgCnt = 0;

//     while (1) {
//         int i, cyc;
//         cout << "\nPatient ID (0 stop): "; cin >> pid[pCnt];
//         if (!pid[pCnt]) break;

//         cout << "Age: "; cin >> age[pCnt];
//         if (age[pCnt] <= 0) continue;

//         int dep;
//         cout << "Condition (1-Normal 2-Moderate 3-Critical): "; cin >> dep;

//         switch (dep) {
//             case 1:
//                 depCnt[0]++;
//                 break;
//             case 2:
//                 depCnt[1]++;
//                 break;
//             case 3:
//                 depCnt[2]++;
//                 critCnt++;
//                 break;
//             default: continue;
//         }

//         for (cyc = 1; cyc <= MC; cyc++) {
//             float hr, bp;
//             cout << "\nCycle " << cyc << " HR BP: "; cin >> hr >> bp;

//             if (hr <= 0 || bp <= 0) continue;

//             avgSum += hr + bp;
//             avgCnt += 2;

//             if (hr < 40 || hr > 150 || bp < 60 || bp > 180) {
//                 cout << "CRITICAL ALERT!\n";
//                 critCnt++;
//                 break;
//             }
//         }
//         pCnt++;
//     }

//     cout << "\n--- Statistics ---";
//     cout << "\nCritical Patients: " << critCnt;
//     if (avgCnt) cout << "\nAverage Vitals: " << avgSum / avgCnt;
//     cout << "\nDept Normal: " << depCnt[0];
//     cout << "\nDept Moderate: " << depCnt[1];
//     cout << "\nDept Critical: " << depCnt[2];

//     return 0;
// }

// #include <iostream>
// using namespace std;

// #define MC 20
// #define MAX_ATT 3
// #define MIN_BAL 500
// #define WD_LIM 20000
// #define BIG_WD 10000

// int main() {
//     int acc[MC] = {101, 102, 103};
//     int pin[MC] = {1111, 2222, 3333};
//     int bal[MC] = {30000, 15000, 50000};

//     int cust = 3, txCnt = 0, hiRisk = 0;
//     int maxIdx = 0;

//     while (1) {
//         int a, p, i, idx = -1, att = 0;
//         cout << "\nAcc (0 exit): "; cin >> a;
//         if (!a) break;

//         for (i = 0; i < cust; i++) if (acc[i] == a) idx = i;

//         if (idx == -1) continue;

//         while (att < MAX_ATT) {
//             cout << "PIN: "; cin >> p;
//             if (pin[idx] == p) break;
//             att++;
//         }
//         if (att == MAX_ATT) continue;

//         int wdCnt = 0, risk = 0;

//         while (1) {
//             int ch, amt;
//             cout << "\n1.Deposit 2.Withdraw 3.Balance 4.Exit\nChoose : "; cin >> ch;

//             switch (ch) {
//                 case 1:
//                     cout << "\nEnter amount : " ; cin >> amt;
//                     if (amt <= 0) continue;
//                     bal[idx] += amt;
//                     txCnt++;
//                     break;

//                 case 2:
//                     cout << "\nEnter amount : " ; cin >> amt;
//                     if (amt <= 0) continue;
//                     if (amt > WD_LIM || bal[idx] - amt < MIN_BAL) {
//                         risk = 2;
//                         break;
//                     }
//                     bal[idx] -= amt;
//                     txCnt++;
//                     wdCnt++;
//                     if (amt >= BIG_WD || wdCnt >= 3) risk = 1;
//                     break;

//                 case 3:
//                     cout << "Balance: " << bal[idx] << endl; break;

//                 case 4: break;

//                 default: continue;
//             }

//             if (risk == 2) {
//                 hiRisk++;
//                 break;
//             }
//             if (ch == 4) break;
//         }

//         if (bal[idx] > bal[maxIdx]) maxIdx = idx;
//     }

//     cout << "\n--- Summary ---";
//     cout << "\nTotal Transactions: " << txCnt;
//     cout << "\nHigh Risk Customers: " << hiRisk;
//     cout << "\nMax Balance Acc: " << acc[maxIdx];

//     return 0;
// }



// #include <iostream>
// using namespace std;

// #define MS 50
// #define MC 6

// int main() {
//     int sid[MS], sem[MS], scnt = 0;
//     char name[MS][20];
//     int pass = 0, prob = 0, top = -1;
//     float topPer = 0;

//     int cid[MC] = {101, 102, 103, 104, 105, 106};

//     while (1) {
//         int id, i, ok = 1;
//         cout << "\nEnter Student ID (0 stop): "; cin >> id;
//         if (!id) break;

//         for (i = 0; i < scnt; i++) if (sid[i] == id) ok = 0;

//         if (!ok) {
//             cout << "Duplicate ID\n";
//             continue;
//         }

//         sid[scnt] = id;
//         cout << "Name: ";
//         cin >> name[scnt];
//         cout << "Sem(1-8): ";
//         cin >> sem[scnt];
//         if (sem[scnt] < 1 || sem[scnt] > 8) continue;

//         int min = sem[scnt] <= 2 ? 3 : 4;
//         int max = sem[scnt] <= 2 ? 5 : 6;

//         int reg[MC], rcnt = 0;

//         while (1) {
//             int ch;
//             cout << "\n1.Add 2.Del 3.Show 4.Marks 5.Exit\nChoose : "; cin >> ch;

//             if (ch == 1) {
//                 if (rcnt == max) continue;
//                 int c, dup = 0;
//                 cout << "Enter course ID : "; cin >> c;
//                 for (i = 0; i < rcnt; i++) if (reg[i] == c) dup = 1;
//                 if (!dup) reg[rcnt++] = c;
//             } else if (ch == 2) {
//                 int c;
//                 cin >> c;
//                 for (i = 0; i < rcnt; i++) if (reg[i] == c)
//                     for (; i < rcnt - 1; i++) reg[i] = reg[i + 1], rcnt--;
//             } else if (ch == 3) for (i = 0; i < rcnt; i++) cout << reg[i] << " ";

//             else if (ch == 4) {
//                 if (rcnt < min) break;
//                 int m, fcnt = 0;
//                 float sum = 0;
//                 cout << "\nEnter marks (space separated) : ";
//                 for (i = 0; i < rcnt; i++) {
//                     cin >> m;
//                     if (m < 0 || m > 100) continue;
//                     if (m < 40) fcnt++;
//                     sum += m;
//                 }
//                 float per = sum / rcnt;
//                 if (fcnt > 2) {
//                     prob++;
//                     break;
//                 }
//                 if (!fcnt) pass++;
//                 if (per > topPer) topPer = per, top = scnt;
//                 break;
//             } else if (ch == 5) break;
//         }
//         scnt++;
//     }
//     cout << "\nTotal: " << scnt << "\nPassed: " << pass << "\nProbation: " << prob;
//     if (top != -1) cout << "\nTopper: " << name[top] << " " << static_cast<int>(topPer);

//     return 0;
// }

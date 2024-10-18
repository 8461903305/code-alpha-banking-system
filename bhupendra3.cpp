
002
003
004
005
006
007
008
009
010
011
012
013
014
015
016
017
018
019
020
021
022
023
024
025
026
027
028
029
030
031
032
033
034
035
036
037
038
039
040
041
042
043
044
045
046
047
048
049
050
051
052
053
054
055
056
057
058
059
060
061
062
063
064
065
066
067
068
069
070
071
072
073
074
075
076
077
078
079
080
081
082
083
084
085
086
087
088
089
090
091
092
093
094
095
096
097
098
099
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
321
322
323
324
325
326
327
328
329
330
331
332
333
334
335
336
337
338
339
340
341
342
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
 
 
 
class account
{
    int acno;
    char name[50];
    int deposit;
    char type;
public:
    void create_account();
    void show_account() const;
    void modify();
    void dep(int);
    void draw(int);
    void report() const;
    int retacno() const;
    int retdeposit() const;
    char rettype() const;
};
 
void account::create_account()
{
    system("clear");
    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> acno;
    cout << "\n\n\t\t\tPlease Enter the Name of the Account holder Here : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\t\t\tEnter Type of the Account (C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\t\t\tEnter The Initial amount : ";
    cin >> deposit;
    cout << "\n\n\t\t\tAccount Created..";
}
 
void account::show_account() const
{
    cout << "\n\t\t\tAccount No. : " << acno;
    cout << "\n\t\t\tAccount Holder Name : ";
    cout << name;
    cout << "\n\t\t\tType of Account : " << type;
    cout << "\n\t\t\tBalance amount : " << deposit;
}
 
 
void account::modify()
{
    cout << "\n\t\t\tAccount No. : " << acno;
    cout << "\n\t\t\tModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\t\t\tModify Type of Account : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\t\t\tModify Balance amount : ";
    cin >> deposit;
}
 
 
void account::dep(int x)
{
    deposit += x;
}
 
void account::draw(int x)
{
    deposit -= x;
}
 
void account::report() const
{
    cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}
 
int account::retacno() const
{
    return acno;
}
 
int account::retdeposit() const
{
    return deposit;
}
 
char account::rettype() const
{
    return type;
}
 
 
 
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
 
int main()
{
    char ch;
    int num;
    do
    {
        system("CLS");
        cout << "\n\n\t\t\t\t======================\n";
        cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
        cout << "\n\t\t\t\t======================\n";
 
        cout << "\t\t\t\t    ::MAIN MENU::\n";
        cout << "\n\t\t\t\t1. NEW ACCOUNT";
        cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
        cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
        cout << "\n\t\t\t\t4. BALANCE ENQUIRY";
        cout << "\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
        cout << "\n\t\t\t\t6. CLOSE AN ACCOUNT";
        cout << "\n\t\t\t\t7. MODIFY AN ACCOUNT";
        cout << "\n\t\t\t\t8. EXIT";
        cout << "\n\n\t\t\t\tSelect Your Option (1-8): ";
        cin >> ch;
 
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            system("CLS");
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            system("CLS");
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            system("CLS");
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            system("CLS");
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            delete_account(num);
            break;
        case '7':
            system("CLS");
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            modify_account(num);
            break;
        case '8':
            system("CLS");
            cout << "\n\n\t\t\tBrought To You By Ahmad And Abdul Rehman";
            break;
        default:cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}
 
 
void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
    outFile.close();
}
 
void display_sp(int n)
{
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\t\t\tBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
    {
        if (ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\n\t\t\tAccount number does not exist";
}
 
 
 
void modify_account(int n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            cout << "\n\n\t\t\tEnter The New Details of account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur); //fncallat1353
            File.write(reinterpret_cast<char*> (&ac), sizeof(account));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
}
 
 
 
void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
    {
        if (ac.retacno() != n)
        {
            outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    cout << "\n\nRecord Deleted ..";
}
 
 
void display_all()
{
    system("CLS");
    account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "A/c no.      NAME           Type  Balance\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}
 
 
void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n\t\t\tTO DEPOSITSS AMOUNT";
                cout << "\n\n\t\t\tEnter The amount to be deposited: ";
                cin >> amt;
                ac.dep(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\t\t\tTO WITHDRAW AMOUNT";
                cout << "\n\n\t\t\tEnter The amount to be withdraw: ";
                cin >> amt;
                int bal = ac.retdeposit() - amt;
                if (bal < 0)
                    cout << "Insufficience balance";
                else
                    ac.draw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);//fn1353
            File.write(reinterpret_cast<char*> (&ac), sizeof(account));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
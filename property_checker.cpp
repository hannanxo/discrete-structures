#include <iostream>
using namespace std;

void reflex(int setarray[], int Set, int relationarray[], int Relation) //a relation is said to be reflexive if (a,a) ∈ R for every a ∈ A
{
    string flag = "";

    if (Set == 0 && Relation == 0)
    {
        cout << "Given relation is Reflexive" << endl;
        return;
    }

    else if (Set == 0 && Relation != 0)
    {
        for (int i = 0; i < Relation; i++)
        {
            int temp1 = relationarray[1];
            int temp2 = relationarray[i + 1];
            cout << "(" << temp1 << "," << temp2 << ")";
        }

        cout << "Relation is not reflexive" << endl;
        return;
    }

    bool checker = true;

    for (int i = 0; i < Set; i++)
    {
        for (int j = 0; j < Relation - 1; j += 2)
        {
            if (relationarray[j] == relationarray[j + 1])
            {
                if (setarray[i] == relationarray[j])
                {
                    checker = true;
                    break;
                }
                else if (setarray[i] != relationarray[j])
                {
                    checker = false;
                }
            }
        }
        if (checker == true)
        {
            flag = "Given relation is Reflexive";
        }
        else if (checker == false)
        {
            flag = "Given relation is not Reflexive because of these tuples";
            cout << "(" << setarray[i] << "," << setarray[i] << ")" << endl;
        }
    }

    cout << flag << endl;
}

void symmetric(int setarray[], int Set, int relationarray[], int Relation) //a relation is said to be symmetric if (a,b) ∈ R, then (b,a) ∈ R
{
    bool flag = true;

    if (Set == 0 && Relation == 0)
    {
        cout << "Given relation is Symmetric" << endl;
        return;
    }

    else if (Set == 0 && Relation != 0)
    {
        for (int i = 0; i < Relation; i++)
        {
            int temp1 = relationarray[1];
            int temp2 = relationarray[i + 1];
            cout << "(" << temp1 << "," << temp2 << ")";
        }

        cout << "Given relation is not Symmetric" << endl;
        return;
    }

    for (int i = 0; i < Relation; i += 2)
    {

        int temp1 = relationarray[i];
        int temp2 = relationarray[i + 1];

        if (temp1 == temp2)
        {
            flag = true;
        }
        else
        {
            for (int j = 0; j < Relation - 1; j += 2)
            {
                int temp3 = relationarray[j];
                int temp4 = relationarray[j + 1];

                if (temp3 == temp2 && temp4 == temp1)
                {
                    flag = true;
                    break;
                }
                else if (temp3 != temp2 && temp4 != temp1)
                {
                    flag = false;
                }
            }
            if (flag == true)
            {
                cout << "Given relation is Symmetric" << endl;
                break;
            }
            else if (flag == false)
            {
                cout << "Given relation is not Symmetric because these tuples are not found"
                     << " "
                     << "(" << temp2 << "," << temp1 << ")";
            }
        }
    }
}

void antisymmetric(int setarray[], int Set, int relationarray[], int Relation) //a relation is said to be antisymmetric if there exist x,y ∈ A such that (x,y) ∈ R and (y,x) ∈ R but x ≠ y
{
    bool flag = true;
    if (Set == 0 && Relation == 0)
    {
        cout << "Given relation is Anti Symmetric" << endl;
        return;
    }
    else if (Set == 0 && Relation != 0)
    {
        for (int i = 0; i < Relation; i++)
        {
            int temp1 = relationarray[1];
            int temp2 = relationarray[i + 1];
            cout << "(" << temp1 << "," << temp2 << ")";
        }

        cout << "Given relation is not Anti Symmetric" << endl;
        return;
    }

    for (int i = 0; i < Relation; i += 2)
    {
        int temp1 = relationarray[i];
        int temp2 = relationarray[i + 1];
        if (temp1 == temp2)
        {
            flag = true;
        }
        else
        {
            for (int j = 0; j < Relation - 1; j += 2)
            {
                int temp3 = relationarray[j];
                int temp4 = relationarray[j + 1];

                if (temp2 == temp3 && temp1 == temp4)
                {
                    if (temp1 == temp2)
                    {
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                    }
                }
                else if (temp2 != temp3 && temp1 != temp4)
                {
                    flag == true;
                }
            }  
        }
        if (flag == true)
        {
            cout << "Given relation is Anti Symmetric" << endl;
            break;
        }
        else if (flag == false)
        {
            cout << "Given relation is not AntiSymmetric beacuse of the following"
                 << " "
                 << "(" << temp2 << "!=" << temp1 << ")";
            break;
        }
    }
}

//bool isvalid(int Set, int Relation)

int main()
{
    cout << "FIRST CASE" << endl;
    int firstset[6] = {1, 2, 3, 4, 5, 6};
    int firstrelation[14] = {1, 1, 2, 2, 3, 2, 3, 3, 4, 4, 5, 5, 6, 6};

    cout << "Set [";

    for (int i = 0; i < 6; i++)
    {
        cout << firstset[i] << ",";
    }

    cout << "]";
    cout << endl;

    cout << "Relation {";

    for (int i = 0; i < 14; i++)
    {
        cout << firstrelation[i] << ",";
    }

    cout << "}";
    cout << endl;
    cout << endl;

    reflex(firstset, 6, firstrelation, 14);
    cout << endl;
    symmetric(firstset, 6, firstrelation, 14);
    cout << endl;
    cout << endl;
    antisymmetric(firstset, 6, firstrelation, 14);
    cout << endl;

    return 0;
}
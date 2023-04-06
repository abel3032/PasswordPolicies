#include <iostream>
#include <cstring>
#include <ctype.h>
#include <algorithm>
#include <vector>
using namespace std;
class Policy{
protected:
    bool isChecked;
public:
    bool getCheck() const
    {
        return isChecked;
    }
    virtual void check(const string & parola)=0;
};
class LengthPolicy : public Policy{
private:
    uint16_t minLength;
    uint16_t maxLength;
public:
    LengthPolicy(uint16_t arg_minLength)
    {
        minLength=arg_minLength;
        maxLength=255;
    }
    LengthPolicy(uint16_t arg_minLength, uint16_t arg_maxLength)
    {
        minLength=arg_minLength;
        maxLength=arg_maxLength;
    }
    virtual void check(const string & parola)
    {
        if(parola.size()<minLength || parola.size()>maxLength)
            isChecked=false;
        else
            isChecked=true;
    }
};
class ClassPolicy : public Policy{
private:
    uint16_t minClassCount;
public:
    ClassPolicy(uint16_t arg_minClassCount)
    {
        minClassCount=arg_minClassCount;
    }
    virtual void check(const string & parola)
    {
        int n=parola.size();
        int c_lmi=0, c_c=0, c_a=0, c_lma=0;
        int classCount;
        for(int i=0; i<n; i++)
        {
            if(isupper(parola[i]))
            {
                c_lma++;
            }
            if(islower(parola[i]))
            {
                c_lmi++;
            }
            if(isdigit(parola[i]))
            {
                c_c++;
            }
            if(!isalpha(parola[i]) && !isdigit(parola[i]))
            {
                c_a++;
            }
        }
        if(c_lmi>=1)
        {
            c_lmi=1;
        }
        else
            c_lmi=c_lmi;
        if(c_lma>=1)
        {
            c_lma=1;
        }
        else
            c_lma=c_lma;
        if(c_c>=1)
        {
            c_c=1;
        }
        else
            c_c=c_c;
        if(c_a>=1)
        {
            c_a=1;
        }
        else
            c_a=c_a;
        classCount=c_lma+c_c+c_a+c_lmi;
        if(classCount<minClassCount)
            isChecked=false;
        else
            isChecked=true;
    }
};
class IncludePolicy: public Policy {
private:
    char characterType;
public:
    IncludePolicy(char arg_characterType) {
        characterType = arg_characterType;
    }

    virtual void check(const string &parola)
    {
        int n = parola.size(), contor_lower=0, contor_upper=0, contor_numar=0, contor_altele=0;
        for(int i=0; i<n; i++)
        {
            if(characterType=='a')
            {
                if(islower(parola[i]))
                {
                    contor_lower++;
                }
                if(contor_lower>=1)
                    isChecked=true;
                else
                    isChecked=false;
            }
            if(characterType=='A')
            {
                if(isupper(parola[i]))
                {
                    contor_upper++;
                }
                if(contor_upper>=1)
                    isChecked=true;
                else
                    isChecked=false;
            }
            if(characterType=='0')
            {
                if(isdigit(parola[i]))
                {
                    contor_numar++;
                }
                if(contor_numar>=1)
                    isChecked=true;
                else
                    isChecked=false;
            }
            if(characterType=='$')
            {
                if(isdigit(parola[i])==false && isupper(parola[i])==false && islower(parola[i])==false)
                {
                    contor_altele++;
                }
                if(contor_altele>=1)
                    isChecked=true;
                else
                    isChecked=false;
            }

        }
    }
};

class NotIncludePolicy: public Policy{
private:
    char characterType;
public:
    NotIncludePolicy(char arg_characterType)
    {
        characterType=arg_characterType;
    }
    virtual void check(const string &parola)
    {
        int n = parola.size(), contor_lower=0, contor_upper=0, contor_numar=0, contor_altele=0;

        for(int i=0; i<n; i++)
        {
            if(characterType=='a')
            {
                if(islower(parola[i]))
                {
                    contor_lower++;
                }
                if(contor_lower==0)
                    isChecked=true;
                else
                    isChecked=false;
            }
            if(characterType=='A')
            {
                if(isupper(parola[i]))
                {
                    contor_upper++;
                }
                if(contor_upper==0)
                    isChecked=true;
                else
                    isChecked=false;
            }
            if(characterType=='0')
            {
                if(isdigit(parola[i]))
                {
                    contor_numar++;
                }
                if(contor_numar==0)
                    isChecked=true;
                else
                    isChecked=false;
            }
            if(characterType=='$')
            {
                if(isdigit(parola[i])==false && isupper(parola[i])==false && islower(parola[i])==false)
                {
                    contor_altele++;
                }
                if(contor_altele==0)
                    isChecked=true;
                else
                    isChecked=false;
            }

        }
    }

};
class RepetitionPolicy: public Policy{
private:
    uint16_t maxCount;
public:
    RepetitionPolicy(uint16_t arg_maxCount)
    {
        maxCount=arg_maxCount;
    }
    virtual void check(const string & parola)
    {
        int n=parola.size(), contor1=0, max1=0;
        for(int i=0; i<n-1; i++)
        {
            if(parola[i]==parola[i+1])
            {
                contor1++;
            }
            max1=max(contor1, max1);
            if(parola[i]!=parola[i+1])
            {
                contor1=0;
            }
        }
        if(max1+1>maxCount)
            isChecked=false;
        else
            isChecked=true;
    }
};
class ConsecutivePolicy: public Policy{
private:
    uint16_t maxCount;
public:
    ConsecutivePolicy(uint16_t arg_maxCount)
    {
        maxCount=arg_maxCount;
    }
    virtual void check(const string & parola)
    {
        int n=parola.size(), contor1=0, max1=0;
        for(int i=0; i<n-1; i++)
        {
            if(parola[i+1]-parola[i]==1)
            {
                contor1++;
            }
            max1=max(contor1, max1);
            if(parola[i+1]-parola[i]!=1)
            {
                contor1=0;
            }
        }
        if(max1+1>maxCount)
            isChecked=false;
        else
            isChecked=true;
    }
};
string checkPassword(string parola, vector <Policy *> politici)
{
    uint8_t contor=0;
    string s1="OK";
    string s2="NOK";
    for(int i=0; i<politici.size(); i++)
    {
        politici[i]->check(parola);

    }
    for(int i=0; i<politici.size(); i++)
    {
        if(politici[i]->getCheck()==true)
        {
            contor++;
        }
    }
    if(contor==politici.size())
        return s1;
    else
        return s2;
};
int main()
{
    vector <Policy *> politici;
    int n, contor_length=0;
    string politica;
    string parola;
    int min_length, max_length, min_class_count, rmax_count, cmax_count;
    char clasa, nclasa;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>politica;
        if(politica=="length")
        {
            if(scanf("%d %d", &min_length, &max_length)==2)
                politici.push_back(new LengthPolicy(min_length, max_length));
            else
                politici.push_back(new LengthPolicy(min_length));
        }
        if(politica=="class")
        {
            cin>>min_class_count;
            politici.push_back(new ClassPolicy(min_class_count));
        }
        if(politica=="include")
        {
            cin>>clasa;
            politici.push_back(new IncludePolicy(clasa));
        }
        if(politica=="ninclude")
        {
            cin>>nclasa;
            politici.push_back(new NotIncludePolicy(nclasa));
        }
        if(politica=="repetition")
        {
            cin>>rmax_count;
            politici.push_back(new RepetitionPolicy(rmax_count));
        }
        if(politica=="consecutive")
        {
            cin>>cmax_count;
            politici.push_back(new ConsecutivePolicy(cmax_count));
        }
    }
    while (cin >> parola)
    {
        cout<<checkPassword(parola, politici)<<endl;
    }
    return 0;
}
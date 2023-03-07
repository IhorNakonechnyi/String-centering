#include<string>
#include<iostream>
#include<vector>

using namespace std;

vector <string> Centering(string text, int raw)
{
    vector<string> formated_text;
    string substring;
    string word;


    for (size_t i = 0; i < text.length(); i++)
    {
        if (i==(text.length()-1))
        {
            word += text[i];
            if (raw - substring.length() > word.length())
            {
                substring += word;
                formated_text.push_back(substring);
            }
            else
            {
                formated_text.push_back(substring);
                formated_text.push_back(word);
            }
            break;
        }
        if (text[i] != ' ')
        {
            word += text[i];

        }
        else
        {
            if (raw - substring.length() > word.length())
            {
                substring += word + ' ';
                word.erase();
            }
            else
            {
                formated_text.push_back(substring);
                substring.clear();
                substring += word+' ';
                word.clear();
            }
        }

    }

    for (int i = 0; i < formated_text.size(); i++)
    {
        string temp = formated_text.at(i);
        temp.resize(raw, ' ');

        int position_space=0;
        /*
        for (size_t j = 0; j < raw; j++)
        {
            position_space = temp.find_first_of(' ', position_space + 1) + 1;
            temp.insert(position_space, 1, ' ');
            temp.erase(raw, 1);
        }
        */
        
        while (temp[raw-1]==' ')
        {
            if (position_space >= raw)position_space = 0;

            position_space = temp.find_first_of(' ',position_space+1)+1;
            temp.insert(position_space, 1, ' ');
            temp.erase(raw+1, 1);
        }
        

        formated_text.at(i) = temp;
    }
    

    return formated_text;
}


void Display_Formated_Text(vector <string> text)
{
    for (size_t i=0;i<text.size();i++)
    {
        cout << text[i] << endl;
    }
}


int main()
{
    int length_raw=40;
    string input_text = "B only if B also shakes hands with A. In contrast, if an edge from a person A to a person B means that A owes money to B, then this graph is directed, because owing money is not necessarily reciprocated.";
    vector <string> formated_text = Centering(input_text, length_raw);

    Display_Formated_Text(formated_text);

    return 0;
}
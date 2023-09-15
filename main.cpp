#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <typeinfo>

enum class BracketsType
{
    Normal,
    Figure,
    Squared
};

class Text
{
private:
    std::string m_text;
    std::vector<int> m_brackets;
    int open_value, close_value;
    
public:
    Text(const std::string& text)
    {
        m_text = text;
    }

    int is_open_bracket(char element)
    {
        if (element == '(')
            return 1;
        else if (element == '{')
            return 2;
        else if (element == '[')
            return 3;
        else
            return 0;
    }

    int is_close_bracket(char element)
    {
        if (element == ')')
            return 1;
        else if (element == '}')
            return 2;
        else if (element == ']')
            return 3;
        else
            return 0;
    }

    void Check()
    {
        bool flag = true;

        for (int i = 0; i < m_text.size(); i++)
        {
            if (is_open_bracket(m_text[i]) > 0)
                m_brackets.push_back(is_open_bracket(m_text[i]));
            else if (is_close_bracket(m_text[i]) > 0)
            {
                if (m_brackets[m_brackets.size()-1] == is_close_bracket(m_text[i]))
                    m_brackets.pop_back();
                else
                    flag = false;
                    break;
            }
        }
        if (flag == false || m_brackets.size() != 0)
            std::cout << "Строка не существует" << std::endl;
        else
            std::cout << "Строка существует" << std::endl;
    }
};

int main() {

    std::cout << "Введите строку" << std::endl;
    std::string text;
    std::getline(std::cin, text);

    Text text1(text);
    text1.Check();
    return 0;
}

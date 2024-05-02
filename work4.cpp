#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

// �����������
int generateRandomNumber(int maxNumber) {
    return rand() % maxNumber + 1;
}

// ������������
char generateRandomOperator(string operators) {
    int index = rand() % operators.size();
    return operators[index];
}

// ���ɱ��ʽ
string generateExpression(int maxNumber, string operators, bool withParenthesis, bool withDecimal) {
    string expression;

    // ������ɵ�һ������
    int num1 = generateRandomNumber(maxNumber);
    expression += to_string(num1);

    // ������������������
    for (int i = 0; i < 3; ++i) {
        char op = generateRandomOperator(operators);
        int num2 = generateRandomNumber(maxNumber);
        expression += " ";
        expression += op;
        expression += " ";
        expression += to_string(num2);
        // �Ƿ��С����
        if (withDecimal && (rand() % 2 == 0)) {
            expression += "." + to_string(generateRandomNumber(99)); // ����һ��С�������λ�������
        }
        // �Ƿ������
        if (withParenthesis && (rand() % 2 == 0)) {
            expression = "(" + expression + ")";
        }
    }



    

    return expression;
}

// ������Ŀ
void generateQuestions(int numQuestions, int maxNumber, string operators, bool withParenthesis, bool withDecimal) {
    ofstream outfile("questions.txt");

    for (int i = 0; i < numQuestions; ++i) {
        string expression = generateExpression(maxNumber, operators, withParenthesis, withDecimal);
        outfile << expression << " = " << endl;
    }

    outfile.close();
}

int main() {
    srand(time(0)); // �����������

    int numQuestions=10, maxNumber=20;
    string operators="+-*/";
    bool withParenthesis=true, withDecimal=true;

    // ��ȡ�û�����
    cout << "��������Ŀ����: ";
   // cin >> numQuestions;

    cout << "�����������: ";
    //cin >> maxNumber;

    cout << "�������������+ - * /��: ";
    //cin >> operators;

    cout << "�Ƿ�����ţ�1Ϊ�ǣ�0Ϊ��: ";
   // cin >> withParenthesis;

    cout << "�Ƿ���С����1Ϊ�ǣ�0Ϊ��: ";
    //cin >> withDecimal;

    generateQuestions(numQuestions, maxNumber, operators, withParenthesis, withDecimal);

    cout << "��Ŀ���������ļ� questions.txt" << endl;

    return 0;
}

